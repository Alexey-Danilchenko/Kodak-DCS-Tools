/*
    raw_image.h - control class that handles display of the raw image and
                  selected defects.

    Copyright 2013,2014 Alexey Danilchenko
    Written by Alexey Danilchenko

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3, or (at your option)
    any later version with ADDITION (see below).

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, 51 Franklin Street - Fifth Floor, Boston,
    MA 02110-1301, USA.
*/
#ifndef DCS_RAW_IMAGE_H
#define DCS_RAW_IMAGE_H

#include <QBitmap>
#include <QFrame>
#include <QLabel>
#include <QPaintEvent>
#include <QPixmap>
#include <QPoint>
#include <QSize>

#include "defects.h"

#define MAX_RAW_VALUE     4095
#define TOTAL_RAW_VALUES  MAX_RAW_VALUE+1

#define MAX_ADAPTIVE_BLOCK  64

enum ERawRendering {
    R_RGB = 0,
    R_COMPOSITE_COLOUR,
    R_COMPOSITE_GRAY
};

enum EChannel {
    C_GREEN=0,   // 00
    C_RED,       // 01
    C_BLUE,      // 10
    C_GREEN2,    // 11
    C_ALL
};

// constants for various defect setting modes
enum EDefectMode {
    M_NONE=0,
    M_COL,
    M_POINT,
    M_ROW
};
inline int roundToInt(double x){
   return (int)(x+0.5f);
}

inline int roundToInt(float x){
   return (int)(x+0.5);
}

inline uint16 calc_median(uint16 *stack, int count)
{
    int middle = count>>1;

    std::nth_element<uint16*>(stack, stack+middle, stack+count);

    if (count&1)
        return stack[middle];

    // even number - get the other one and average
    int result = stack[middle];
    std::nth_element<uint16*>(stack, stack+middle-1, stack+count);

    return (result+stack[middle-1]+1)>>1;
}

// ------------------------------
//      DCSRawImage class
// ------------------------------
class DCSRawImage : public QLabel
{
    Q_OBJECT

    QPixmap rawPixmap_;
    QBitmap defBitmap_;

    QColor defColour_;

    uint16 width_;
    uint16 height_;

    uint16 isoCode_;
    bool   defectsForIso_[DCSDefects::ISO_COUNT];

    uint16* rawData_;
    byte*   rawData8_;

    ERawRendering renderingType_;

    DCSDefects* defects_;
    bool defSwapRowCol_;
    bool enablePreRemap_;
    bool enableRows_;
    bool enableCols_;
    bool enablePoints_;
    EDefectMode curDefSetMode_;
    int defPointsCount_;
    int defColsCount_;
    int defRowsCount_;

    bool pauseUpdates_;

    double scale_;

    // displaying options
    int pX, pY;

    // channel curves
    uint16 chnlCurves_[4][TOTAL_RAW_VALUES];

    // adjustment parameters
    double contrast_;
    double contrMidpoint_;
    double exposure_[5];
    uint16 blckLevels_[4];
    bool blackLevelsZeroed_;
    bool applyGamma_;

    // per channel enablement
    bool chnlEnabled[4];

public:

    DCSRawImage(QWidget* parent = 0);
    ~DCSRawImage();

    void retranslate();

    inline uint16 getRawValue(uint16 row, uint16 col) {
        return rawData_ ? rawData_[row*width_+col] : 0;
    }

    inline EChannel getRawColor(uint16 row, uint16 col) {
        return EChannel((row&1)<<1 | col&1);
    }

    // raw image setters
    void setRawImage(uint16* data, uint16 width, uint16 height, uint16 isoCode, double scale);
    void clearRawImage();
    bool rawLoaded() { return rawData_!=0; }
    bool hasDefects() { return defects_!=0; }

    // reloads the current defects if 0
    void setDefects(DCSDefects* defects, double scale);
    void updateDefects() {
        updateDefectsBitmap();
        repaint();
    }
    void clearDefects();
    void setDefectColour(QColor &colour);
    void enablePreRemap(bool enable);
    void enableDefPoints(bool enable);
    void enableDefCols(bool enable);
    void enableDefRows(bool enable);
    void setDefectSettingMode(EDefectMode mode);
    void setIsoCode(uint16 isoCode);

    // change current rendering
    void setRawRenderingType(ERawRendering renderingType);

    void pauseUpdates(bool pauseUpdates);

    void setScale(double scale);

    void enableGammaCorrection(bool enable);

    void enableBlackLevelZeroed(bool enable);

    // reset for exposure and contrast corrections
    void resetAllCorrections();

    // exposure corrections
    void setExpCorr(double expCorr, EChannel channel = C_ALL);

    // contrast corrections
    void setContrCorr(double contrast);
    void setContrMidpoint(double ctrsMidpoint);

    // black level
    void setBlack(int blackLevel, EChannel channel = C_ALL);

    // enable/disable channels
    void enableChannel(bool enable, EChannel channel = C_ALL);

    // set expo corrections to specified WB
    void setWB(double* wb);

    // attempts to autoremap points
    bool performAvgAutoRemap(double* avgValues, uint16* thresholds);
    bool performAdaptiveAutoRemap(uint16* thresholds,
                                  uint16 blockSize,
                                  bool countOnly = false,
                                  EChannel ch = C_ALL,
                                  uint32 *counts = 0);

    // erase enabled defects
    void eraseEnabledDefects();

    // getters
    uint16 getRawWidth() { return width_; }
    uint16 getRawHeight() { return height_; }

    int getDefectPoints() { return defPointsCount_; }
    int getDefectRows() { return defSwapRowCol_ ? defColsCount_ : defRowsCount_; }
    int getDefectCols() { return defSwapRowCol_ ? defRowsCount_ : defColsCount_; }
    uint16 getIsoCode() { return isoCode_; }
    bool hasDefectsForIso(uint16 isoCode) {
        return (isoCode<DCSDefects::ISO_COUNT) ? defectsForIso_[isoCode] : false;
    }
    ERawRendering getRawRenderingType() { return renderingType_; }

    // size hint
    QSize sizeHint() const;

Q_SIGNALS:
    void imageCursorPosUpdated(uint16 row, uint16 col);
    void defectsChanged();

private:

    inline uint16 getRawDataEnabled(byte ch, uint16 row, uint16 col) {
        if (chnlEnabled[ch]) {
            return chnlCurves_[ch][rawData_[row*width_+col]];
        }
        return 0;
    }

    inline uint16 getRawData(byte ch, uint16 row, uint16 col) {
        return chnlCurves_[ch][rawData_[row*width_+col]];
    }

    void calcViewpointOffsets() {
        pX=pY=0;
        if (width() >= width_*scale_)
            pX = roundToInt((width()-width_*scale_)/2);
        if (height() >= height_*scale_)
            pY = roundToInt((height()-height_*scale_)/2);
    }
    void paintEvent(QPaintEvent *p);
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent * e);
    void mousePressEvent(QMouseEvent * e);
    void updateRaw();
    void updateDefectsBitmap();
    void generateCurves(EChannel channel = C_ALL);
};

#endif  // DCS_RAW_IMAGE_H

