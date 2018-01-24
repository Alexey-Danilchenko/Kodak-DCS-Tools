/*
    raw_image.cpp - control class that handles display of the raw image and
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

#include <QPainter>
#include <QPaintEvent>

#include <string.h>
#include <math.h>

#if defined( Q_OS_WIN )
#include <omp.h>
#endif

#include "raw_image.h"

// --------------------------------------------------------
//    static data
// --------------------------------------------------------
// array for compressing 16 to 8 bit
byte from12To8[TOTAL_RAW_VALUES];

// --------------------------------------------------------
//    helper functions
// --------------------------------------------------------
#define SQR(x) ((x)*(x))
// gamma 2.2 lower region calculation variables
static double g[5] = {1.0/2.2, 0, 0, 0, 0};
static double bnd[2] = {0,0};

static void initStaticData()
{
    static bool needInit = true;

    if (needInit)
    {
        // init gamma data
        bnd[g[1] >= 1] = 1;
        if (g[1] && (g[1]-1)*(g[0]-1) <= 0)
        {
            for (int i=0; i < 48; i++)
            {
                g[2] = (bnd[0] + bnd[1])/2;
                if (g[0])
                    bnd[(pow(g[2]/g[1],-g[0]) - 1)/g[0] - 1/g[2] > -1] = g[2];
                else
                    bnd[g[2]/exp(1-1/g[2]) < g[1]] = g[2];
            }
            g[3] = g[2] / g[1];
            if (g[0])
                g[4] = g[2] * (1/g[0] - 1);
        }

        for (int i=0; i<TOTAL_RAW_VALUES; i++)
        {
            from12To8[i] = roundToInt((double)i*255/(MAX_RAW_VALUE));
        }

        needInit = false;
    }
}

// Contrast curve
//
// Taken from exploits of Guillermo Luijk and Emil (ejmartin) from
// http://www.luminous-landscape.com/forum/index.php?topic=52364.msg430767
//
// The curve is quite tunable and uses a number of parameters
//    f(x) = ((1-s)*x + s*xA*(x/xA)^V)^(log(yA)/log(xA))
// 
// Parameters:
//     (xA,yA): turning point
//     s: slope at ends
//     V: contrast strength (1-linear, >1 increasing)
//
// The curve is defined as follows on [0..1] interval
//  y = f(x)       for [0..xA)
//  y = 1 - f(1-x) for [xA..1]
//
inline double f_CC(double x, double s, double V, double xA, double yA) 
{
    //  return (1/(1+exp(V*(xA-x)))-1/(1+exp(V)))/(1/(1+exp(V*(xA-1)))-1/(1+exp(V*xA)));
    return pow((1-s)*x + s*xA*pow(x/xA,V), log(yA)/log(xA));
}

// Adjustments calculation for a single point -
// applies black level, gamma, exposure, contrast
inline uint16 adjustSinglePoint(uint16 value, 
                                uint16 blackLevel, 
                                double exposure, 
                                double contrast, 
                                double midpoint, 
                                bool applyGamma,
                                bool blackLevelsZeroed)
{
    const double s = 0.5;  // larger - more contrast slope

    if (value<=blackLevel)
        return 0;

    double val = blackLevelsZeroed
                                ? double(value)/MAX_RAW_VALUE 
                                : double(value-blackLevel)/MAX_RAW_VALUE;
    
    if (val<1)
    {
		val *= exposure;
        if (val>1)
            val = 1;
        if (val < midpoint)
            val = f_CC(val,s,contrast,midpoint,midpoint);
        else
            val = 1- f_CC(1-val,s,contrast,1-midpoint,1-midpoint);

		if (applyGamma)
            val = val < g[3] 
                        ? val*g[1] 
                        : (g[0] 
                            ? pow(val,g[0])*(1+g[4])-g[4]    
                            : log(val)*g[2]+1);
    }
    else
        val = 1;

    return uint16(MAX_RAW_VALUE * val);
}

inline void extractChannel(EChannel ch, 
                           uint16 *chValues, 
                           uint16 *raw, 
                           uint16 width, 
                           uint16 row, 
                           uint16 col, 
                           uint16 blockSize)
{
    uint16 lastRow = row+blockSize;
    uint16 lastCol = col+blockSize;
    for (uint16 rw=row; rw<lastRow; rw++)
        for (uint16 cl=col; cl<lastCol; cl++)
        {
            byte channel = (rw&1)<<1 | cl&1;
            if (channel == ch)
                *chValues++ = raw[rw*width+cl];
        }
}

// --------------------------------------------------------
//    DCSRawImage class
// --------------------------------------------------------
DCSRawImage::DCSRawImage(QWidget *parent)
    : QLabel(parent),
      defects_(0), defSwapRowCol_(false),
      enablePreRemap_(true), enableRows_(true),
      enableCols_(true), enablePoints_(true),
      defPointsCount_(0), defRowsCount_(0), defColsCount_(0),
      curDefSetMode_(M_NONE),
	  width_(0), height_(0), scale_(1),
      pX(0), pY(0),
      pauseUpdates_(false), rawData_(0), rawData8_(0),
      isoCode_(0),
      renderingType_(R_RGB),
      applyGamma_(true),
      blackLevelsZeroed_(true),
      contrast_(0),
      contrMidpoint_(0.5)
{
    initStaticData();
    chnlEnabled[C_GREEN]  = true;
    chnlEnabled[C_RED]    = true;
    chnlEnabled[C_BLUE]   = true;
    chnlEnabled[C_GREEN2] = true;
    
    resetAllCorrections();
    
    setText(tr("Open RAW file with 'Load RAW(s)...'"));
    setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    for (int i=0; i<DCSDefects::ISO_COUNT; i++)
        defectsForIso_[i] = false;
}

DCSRawImage::~DCSRawImage()
{
    delete[] rawData_;
    rawData_ = 0;
    delete[] rawData8_;
    rawData8_ = 0;
}

void DCSRawImage::retranslate()
{
    setText(tr("Open RAW file with 'Load RAW(s)...'"));
}

void DCSRawImage::generateCurves(EChannel channel)
{
    if (channel == C_ALL)
    {
        double contrast = contrast_*10+1;  
        double exposure[4];
        exposure[C_RED]    = exposure_[C_ALL]*exposure_[C_RED];  
        exposure[C_GREEN]  = exposure_[C_ALL]*exposure_[C_GREEN];  
        exposure[C_BLUE]   = exposure_[C_ALL]*exposure_[C_BLUE];  
        exposure[C_GREEN2] = exposure_[C_ALL]*exposure_[C_GREEN2];  
    
        #pragma omp parallel for
        for (int i=0; i<TOTAL_RAW_VALUES; i++)
        {
            chnlCurves_[C_RED][i] = adjustSinglePoint(
                                             i, 
                                             blckLevels_[C_RED],
                                             exposure[C_RED], 
                                             contrast, 
                                             contrMidpoint_, 
                                             applyGamma_,
                                             blackLevelsZeroed_);
            chnlCurves_[C_GREEN][i] = adjustSinglePoint(
                                             i, 
                                             blckLevels_[C_GREEN],
                                             exposure[C_GREEN], 
                                             contrast, 
                                             contrMidpoint_, 
                                             applyGamma_,
                                             blackLevelsZeroed_);
            chnlCurves_[C_BLUE][i] = adjustSinglePoint(
                                             i, 
                                             blckLevels_[C_BLUE],
                                             exposure[C_BLUE], 
                                             contrast, 
                                             contrMidpoint_, 
                                             applyGamma_,
                                             blackLevelsZeroed_);
            chnlCurves_[C_GREEN2][i] = adjustSinglePoint(
                                             i, 
                                             blckLevels_[C_GREEN2],
                                             exposure[C_GREEN2], 
                                             contrast, 
                                             contrMidpoint_, 
                                             applyGamma_,
                                             blackLevelsZeroed_);
        }
    }
    else
    {
        uint16 *chCurve = chnlCurves_[channel];
        double contrast = contrast_*10+1;  
        double exposure = exposure_[C_ALL]*exposure_[channel];  

        #pragma omp parallel for
        for (int i=0; i<TOTAL_RAW_VALUES; i++)
        {
            chCurve[i] = adjustSinglePoint(i, 
                                           blckLevels_[channel],
                                           exposure, 
                                           contrast, 
                                           contrMidpoint_, 
                                           applyGamma_,
                                           blackLevelsZeroed_);
        }
    }
}

QSize DCSRawImage::sizeHint() const
{
    return QSize(width_*scale_, height_*scale_);
}

void DCSRawImage::paintEvent(QPaintEvent *p)
{
    if (!rawData_ && !defects_)
        QLabel::paintEvent(p);
    else
    {
        QPainter painter(this);
        QPen pen(defColour_);

        // set this hint otherwise scaling down raw with only
        // a few channels selected does not work properly
        if (scale_<1.0)
            painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

        painter.scale(scale_, scale_);

        QRect exposedRect = p->rect();
        QRect imageRect = exposedRect;

        // calculate pont offsets
        calcViewpointOffsets();

        // adjust for cases where image is "fit to window"
        exposedRect.adjust(pX,pY,pX,pY);
        
        // the adjust is to account for half points along edges
        exposedRect = painter.matrix().inverted().mapRect(exposedRect).adjusted(-1, -1, 1, 1);
        imageRect   = painter.matrix().inverted().mapRect(imageRect).adjusted(-1, -1, 1, 1);

        if (rawData_)
            painter.drawPixmap(exposedRect, rawPixmap_, imageRect);
        
        if (defects_)
        {
            painter.setPen(pen);
            if (rawData_)
                painter.setBackgroundMode(Qt::TransparentMode);
            else
            {
                painter.setBackgroundMode(Qt::OpaqueMode);
                QBrush bgrBrush(Qt::black);
                painter.setBackground(bgrBrush);
                
            }
            painter.drawPixmap(exposedRect, defBitmap_, imageRect);
        }
    }
}

void DCSRawImage::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);
    
    // calculate point offsets
    calcViewpointOffsets();
}

void DCSRawImage::mouseMoveEvent(QMouseEvent * e)
{
    if (rawData_)
    {
        uint16 col = uint16(double(e->x()-pX)/scale_);
        uint16 row = uint16(double(e->y()-pY)/scale_);
        
        if (col<width_ && row<height_)
            emit imageCursorPosUpdated(row, col);
    }
}

void DCSRawImage::mousePressEvent(QMouseEvent * e)
{
    if (defects_ && curDefSetMode_ != M_NONE)
    {
        uint16 col = uint16(double(e->x()-pX)/scale_);
        uint16 row = uint16(double(e->y()-pY)/scale_);
        
        if (col>=width_ || row>=height_)
            return;
            
        if (defSwapRowCol_)
        {
            // Update col and swap row and col 
            //   for SLR/n/c sensor real orientation should be 
            //   turned 90 degrees counter clockwise
            swap16(row, col);
            row = width_-row-1;
        }

        bool updated = false;

        if (enablePoints_ && curDefSetMode_==M_POINT)
        {
            bool isMarked = defects_->isDefectivePoint(row,col,isoCode_);
            if (updated=defects_->markPoint(!isMarked,row,col,isoCode_))
                updateDefects();
        }
        else if (enableRows_ && curDefSetMode_==M_ROW)
        {
            bool isMarked = defects_->isDefectiveRow(row,isoCode_);
            if (updated=defects_->markRow(!isMarked,row,isoCode_))
                updateDefects();
        }
        else if (enableCols_ && curDefSetMode_==M_COL)
        {
            bool isMarked = defects_->isDefectiveCol(col,isoCode_);
            if (updated=defects_->markCol(!isMarked,col,isoCode_))
                updateDefects();
        }
        
        if (updated)
            emit defectsChanged();
    }
}

void DCSRawImage::setScale(double scale)
{
    if (scale)
    {
        scale_ = scale;
        adjustSize();
        if (rawData_ || defects_)
        {
            repaint();
        }
    }
}

void DCSRawImage::setDefectSettingMode(EDefectMode mode) 
{
    if (defects_)
    {
        if (defSwapRowCol_ && mode==M_ROW)
            curDefSetMode_ = M_COL;
        else if (defSwapRowCol_ && mode==M_COL)
            curDefSetMode_ = M_ROW;
        else
            curDefSetMode_ = mode;

        if (curDefSetMode_==M_NONE)
            setCursor(Qt::ArrowCursor);
        else
            setCursor(Qt::CrossCursor);
    }
    else
        setCursor(Qt::ArrowCursor);
}
    
void DCSRawImage::setRawRenderingType(ERawRendering renderingType)
{
    if (renderingType_ != renderingType)
    {
        renderingType_ = renderingType;
        updateRaw();
        repaint();
    }
}
void DCSRawImage::enableGammaCorrection(bool enable)
{
    if (applyGamma_ != enable)
    {
        applyGamma_ = enable;
        generateCurves();
        updateRaw();
        repaint();
    }
}

void DCSRawImage::enableBlackLevelZeroed(bool enable)
{
    if (blackLevelsZeroed_ != enable)
    {
        blackLevelsZeroed_ = enable;
        generateCurves();
        updateRaw();
        repaint();
    }
}

// reset for exposure and contrast corrections
void DCSRawImage::resetAllCorrections()
{
    exposure_[C_ALL] = 1;
    exposure_[C_GREEN] = 1;
    exposure_[C_RED] = 1;
    exposure_[C_BLUE] = 1;
    exposure_[C_GREEN2] = 1;
    blckLevels_[C_GREEN] = 0;
    blckLevels_[C_RED] = 0;
    blckLevels_[C_BLUE] = 0;
    blckLevels_[C_GREEN2] = 0;
    contrast_ = 0;
    contrMidpoint_ = 0.5;

    generateCurves();
    updateRaw();
    repaint();
}    

// exposure corrections
void DCSRawImage::setExpCorr(double expCorr, EChannel channel)
{
    exposure_[channel] = expCorr;
    generateCurves(channel);
    updateRaw();
    repaint();
}
    
// contrast corrections
void DCSRawImage::setContrCorr(double contrast)
{
    contrast_ = contrast;
    generateCurves();
    updateRaw();
    repaint();
}

void DCSRawImage::setContrMidpoint(double ctrsMidpoint)
{
    contrMidpoint_ = ctrsMidpoint;
    generateCurves();
    updateRaw();
    repaint();
}

void DCSRawImage::setBlack(int blackLevel, EChannel channel)
{
    if (blackLevel!=blckLevels_[channel] && blackLevel<TOTAL_RAW_VALUES)
    {
        blckLevels_[channel] = (uint16)blackLevel;

        generateCurves(channel);
        updateRaw();
        repaint();
    }
}

void DCSRawImage::setWB(double* wb)
{
    exposure_[C_RED] = wb[C_RED];
    exposure_[C_GREEN] = wb[C_GREEN];
    exposure_[C_BLUE] = wb[C_BLUE];
    exposure_[C_GREEN2] = wb[C_GREEN2];
    
    generateCurves();
    updateRaw();
    repaint();
}

// enable/disable channels
void DCSRawImage::enableChannel(bool enable, EChannel channel)
{
    if (channel!=C_ALL)
    {
        chnlEnabled[channel] = enable;
        
        updateRaw();
        repaint();
    }
}

void DCSRawImage::pauseUpdates(bool pauseUpdates)
{
    pauseUpdates_ = pauseUpdates;
    if (!pauseUpdates_)
    {
        updateRaw();
        repaint();
    }
}

void DCSRawImage::setRawImage(uint16* data, uint16 width, uint16 height, uint16 isoCode, double scale)
{
    if (!defects_)
    {
        width_ = width;
        height_ = height;

        // setup bitmap
        defBitmap_ = QBitmap(width_, height_);
    }

    if (isoCode_ != 0)
        isoCode_ = isoCode;
    delete[] rawData_;
    rawData_ = 0;
    delete[] rawData8_;
    rawData8_ = 0;

    rawData_ = new uint16[height_*width_];
    rawData8_ = new byte[height_*width_*3];
    
    // copy the raw data
    memcpy(rawData_, data, height_*width_*sizeof(uint16));
    updateRaw();

    if (scale != 0)
        scale_ = scale;

    if (defects_)
        updateDefects();

    adjustSize();
    repaint();
}

void DCSRawImage::clearRawImage()
{
    if (!defects_)
    {
        width_ = 0;
        height_ = 0;
    }

    isoCode_ = 0;
    delete[] rawData_;
    rawData_ = 0;
    delete[] rawData8_;
    rawData8_ = 0;
 
    repaint();
}

void DCSRawImage::clearDefects()
{
    defects_ = 0;
    defSwapRowCol_ = false;
    
    if (!rawData_)
    {
        width_ = 0;
        height_ = 0;
    }

    // reset editing mode
    setDefectSettingMode(M_NONE);

    adjustSize();
    repaint();
}

void DCSRawImage::setDefectColour(QColor &colour)
{
    defColour_ = colour;
    if (defects_)
        repaint();
}

void DCSRawImage::setIsoCode(uint16 isoCode)
{
    if (isoCode_ != isoCode)
    {
        isoCode_ = isoCode;
        updateDefects();
    }
}

// reloads the current defects if 0
void DCSRawImage::setDefects(DCSDefects* defects, double scale)
{
    defects_ = defects;
    
    defSwapRowCol_ = defects_->getMaxRows() > defects_->getMaxCols();

    // regenerate bitmap
    if (!rawData_)
    {
        width_  = defSwapRowCol_ ? defects_->getMaxRows() : defects_->getMaxCols();
        height_ = defSwapRowCol_ ? defects_->getMaxCols() : defects_->getMaxRows();
        
        defBitmap_ = QBitmap(width_, height_);
    }
    
    // update bitmap
    updateDefectsBitmap();

    if (scale != 0)
        scale_ = scale;

    // reset editing mode
    setDefectSettingMode(M_NONE);

    adjustSize();
    repaint();
}

void DCSRawImage::updateDefectsBitmap()
{
    if (pauseUpdates_ || !defects_)
        return;
    
    defPointsCount_ = 0;
    defRowsCount_ = 0;
    defColsCount_ = 0;

    for (int i=0; i<DCSDefects::ISO_COUNT; i++)
        defectsForIso_[i] = false;

    // update bitmap
    int maxCols = defects_->getMaxCols();
    int maxRows = defects_->getMaxRows();
    
    defBitmap_.clear();
    
    QPainter painter(&defBitmap_);
    QPen pen(Qt::color1);
    painter.setPen(pen);

    // For SLR/n/c sensor real orientation should be turned 
    // 90 degrees counter clockwise - hence the row calculations

    // paint point defects
    if (enablePoints_)
    {
        TDefPointVec::const_iterator pointIt = defects_->getDefPoints().begin();
        TDefPointVec::const_iterator pointEnd = defects_->getDefPoints().end();
    
        while (pointIt != pointEnd)
        {
            if (pointIt->isoCode < DCSDefects::ISO_COUNT)
                defectsForIso_[pointIt->isoCode] = true;
            if (enablePoints_ && isoCode_>=pointIt->isoCode)
                if (enablePreRemap_ || pointIt->newDefect)
                {
                    defPointsCount_++;
                    if (defSwapRowCol_)
                        painter.drawPoint(width_-pointIt->row-1, pointIt->col);
                    else
                        painter.drawPoint(pointIt->col, pointIt->row);
                }
            ++pointIt;
        }
    }

    // paint column defects
    if (enableCols_)
    {
        TDefColVec::const_iterator colIt = defects_->getDefCols().begin();
        TDefColVec::const_iterator colEnd = defects_->getDefCols().end();

        while (colIt != colEnd)
        {
            if (colIt->isoCode < DCSDefects::ISO_COUNT)
                defectsForIso_[colIt->isoCode] = true;
            if (enableCols_ && isoCode_>=colIt->isoCode)
                if (enablePreRemap_ || colIt->newDefect)
                {
                    defColsCount_++;
                    int from = colIt->rowFrom ? colIt->rowFrom : 0;
                    int to = colIt->rowTo ? colIt->rowTo : maxRows;
                    if (defSwapRowCol_)
                        painter.drawLine(width_-from-1, colIt->col, width_-to-1, colIt->col);
                    else
                        painter.drawLine(colIt->col, from, colIt->col, to);
                }
            ++colIt;
        }
    }
    
    // paint row defects
    if (enableRows_)
    {
        TDefRowVec::const_iterator rowIt = defects_->getDefRows().begin();
        TDefRowVec::const_iterator rowEnd = defects_->getDefRows().end();

        while (rowIt != rowEnd)
        {
            if (rowIt->isoCode < DCSDefects::ISO_COUNT)
                defectsForIso_[rowIt->isoCode] = true;
            if (enableRows_ && isoCode_>=rowIt->isoCode)
                if (enablePreRemap_ || rowIt->newDefect)
                {
                    defRowsCount_++;
                    int from = rowIt->colFrom ? rowIt->colFrom : 0;
                    int to = rowIt->colTo ? rowIt->colTo : maxCols;
                    if (defSwapRowCol_)
                        painter.drawLine(width_-rowIt->row-1, from, width_-rowIt->row-1, to);
                    else
                        painter.drawLine(from, rowIt->row, to, rowIt->row);
                }
            ++rowIt;
        }
    }
}

// attempts to autoremap points
bool DCSRawImage::performAvgAutoRemap(double* avgValues, uint16* thresholds)
{
    if (!rawData_ && !defects_)
        return false;

    bool remapped = false;
    for (uint16 row=0; row<height_; row++)
        for (uint16 col=0; col<width_; col++)
        {
            byte channel = (row&1)<<1 | col&1;
            uint16 threshold = thresholds[channel];
            if (threshold>0 && 
                fabs(avgValues[channel]-rawData_[row*width_+col])>threshold)
            {
                uint16 rw = defSwapRowCol_ ? (width_-col-1) : row;
                uint16 cl = defSwapRowCol_ ? row : col;
                if (defects_->markPoint(true,rw,cl))
                    remapped = true;
            }
        }
    
    if (remapped)
        updateDefects();

    return remapped;
}

bool DCSRawImage::performAdaptiveAutoRemap(uint16* thresholds, 
                                           uint16 blockSize, 
                                           bool countOnly,
                                           EChannel ch,
                                           uint32 *counts)
{
    if (counts)
        counts[C_RED]=counts[C_GREEN]=counts[C_BLUE]=counts[C_GREEN2]=0;

    if (!rawData_)
        return false;
    
    if (!countOnly && !defects_)
        return false;

    if (countOnly && !counts)
        return false;

    bool remapped = false;
    
    uint16 chBlockCount = (blockSize*blockSize)>>2;
    //uint16 *values = new uint16[chBlockCount+4];
    uint16 median[4];
    
    // loop through blocks claculating median for all channels in a block and 
    // then marking the defective pixels as those that exceed thresholds 
    // against median
    for (int y=0; y<height_; y+=blockSize)
    {
        uint16 row = uint16(y);
        if (row+blockSize>height_)
            row = height_-blockSize;
        for (int x=0; x<width_; x+=blockSize)
        {
            uint16 values[(MAX_ADAPTIVE_BLOCK*MAX_ADAPTIVE_BLOCK)/4];
            uint16 col = uint16(x);
            if (col+blockSize>width_)
                col = width_-blockSize;
            
            if (ch == C_ALL)
            {
                median[C_RED]=median[C_GREEN]=median[C_BLUE]=median[C_GREEN2]=0;
                extractChannel(C_RED, values, rawData_, width_, row, col, blockSize);
                median[C_RED] = calc_median(values, chBlockCount);
                extractChannel(C_GREEN, values, rawData_, width_, row, col, blockSize);
                median[C_GREEN] = calc_median(values, chBlockCount);
                extractChannel(C_BLUE, values, rawData_, width_, row, col, blockSize);
                median[C_BLUE] = calc_median(values, chBlockCount);
                extractChannel(C_GREEN2, values, rawData_, width_, row, col, blockSize);
                median[C_GREEN2] = calc_median(values, chBlockCount);
            }
            else
            {
                median[ch]=0;
                extractChannel(ch, values, rawData_, width_, row, col, blockSize);
                median[ch] = calc_median(values, chBlockCount);
            }
    
            // walk the block and mark the defects    
            uint16 lastRow = row+blockSize;
            uint16 lastCol = col+blockSize;
            for (uint16 rw=row; rw<lastRow; rw++)
                for (uint16 cl=col; cl<lastCol; cl++)
                {
                    byte channel = (rw&1)<<1 | cl&1;
                    if (ch != C_ALL && ch!=channel)
                        continue;

                    uint16 threshold = thresholds[channel];
                    if (threshold>0 && 
                        abs(median[channel]-rawData_[rw*width_+cl])>threshold)
                    {
                        if (countOnly)
                            counts[channel]++;
                        else
                        {
                            uint16 defRow = defSwapRowCol_ ? (width_-cl-1) : rw;
                            uint16 defCol = defSwapRowCol_ ? rw : cl;
                            if (defects_->markPoint(true,defRow,defCol))
                                remapped = true;
                        }
                    }
                }
        }
    }

    if (remapped)
        updateDefects();

    //delete[] values;

    return remapped;
}

void DCSRawImage::enablePreRemap(bool enable)
{
    if (enablePreRemap_ != enable)
    {
        enablePreRemap_ = enable;
        updateDefects();
    }
}

void DCSRawImage::enableDefPoints(bool enable)
{
    if (enablePoints_ != enable)
    {
        enablePoints_ = enable;
        updateDefects();
    }
}

void DCSRawImage::enableDefCols(bool enable)
{
    if (defSwapRowCol_)
    {
        if (enableRows_ != enable)
        {
            enableRows_ = enable;
            updateDefects();
        }
    }
    else if (enableCols_ != enable)
    {
        enableCols_ = enable;
        updateDefects();
    }
}

void DCSRawImage::enableDefRows(bool enable)
{
    if (defSwapRowCol_)
    {
        if (enableCols_ != enable)
        {
            enableCols_ = enable;
            updateDefects();
        }
    }
    if (enableRows_ != enable)
    {
        enableRows_ = enable;
        updateDefects();
    }
}

// erase enabled defects
void DCSRawImage::eraseEnabledDefects()
{
    if (defects_)
    {
        if (enablePoints_)
            defects_->erasePoints(!enablePreRemap_);

        if (enableCols_)
            if (defSwapRowCol_)
                defects_->eraseRows(!enablePreRemap_);
            else
                defects_->eraseCols(!enablePreRemap_);

        if (enableRows_)
            if (defSwapRowCol_)
                defects_->eraseCols(!enablePreRemap_);
            else
                defects_->eraseRows(!enablePreRemap_);

        updateDefects();
    }
}

void DCSRawImage::updateRaw()
{
    if (pauseUpdates_)
        return;

    #define TO_8_BIT(val) from12To8[(val)]
    
    if (rawData_ && rawData8_)
    {
        // bayer layout is
        //   G R
        //   B G2
        if (renderingType_ == R_RGB)
        {
            byte* pixel = rawData8_;
            for (uint16 row=0; row<height_; row++)
                for (uint16 col=0; col<width_; col++)
                {
                    byte channel = (row&1)<<1 | col&1;
                    switch (channel)
                    {
                        case C_GREEN:
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_RED,row,col+1));
                            *pixel++ = (TO_8_BIT(getRawDataEnabled(C_GREEN,row,col)) +
                                        TO_8_BIT(getRawDataEnabled(C_GREEN2,row+1,col+1))+1)>>1;
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_BLUE,row+1,col));
                            break;
                        case C_RED:
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_RED,row,col));
                            *pixel++ = (TO_8_BIT(getRawDataEnabled(C_GREEN2,row+1,col))+
                                        TO_8_BIT(getRawDataEnabled(C_GREEN,row,col-1))+1)>>1;
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_BLUE,row+1,col-1));
                            break;
                        case C_BLUE:
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_RED,row-1,col+1));
                            *pixel++ = (TO_8_BIT(getRawDataEnabled(C_GREEN,row-1,col))+
                                        TO_8_BIT(getRawDataEnabled(C_GREEN2,row,col+1))+1)>>1;
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_BLUE,row,col));
                            break;
                        case C_GREEN2:
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_RED,row-1,col));
                            *pixel++ = (TO_8_BIT(getRawDataEnabled(C_GREEN2,row,col)) +
                                        TO_8_BIT(getRawDataEnabled(C_GREEN,row-1,col-1))+1)>>1;
                            *pixel++ = TO_8_BIT(getRawDataEnabled(C_BLUE,row,col-1));
                            break;
                    }
                }
        }
        else if (renderingType_ == R_COMPOSITE_COLOUR)
        {
            byte* pixel = rawData8_;
            for (uint16 row=0; row<height_; row++)
                for (uint16 col=0; col<width_; col++)
                {
                    byte channel = (row&1)<<1 | col&1;
                    if (chnlEnabled[channel])
                        switch (channel)
                        {
                            case C_GREEN:
                                *pixel++ = 0;
                                *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                                *pixel++ = 0;
                                break;
                            case C_RED:
                                *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                                *pixel++ = 0;
                                *pixel++ = 0;
                                break;
                            case C_BLUE:
                                *pixel++ = 0;
                                *pixel++ = 0;
                                *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                                break;
                            case C_GREEN2:
                                *pixel++ = 0;
                                *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                                *pixel++ = 0;
                                break;
                        }
                    else
                    {
                        *pixel++ = 0;
                        *pixel++ = 0;
                        *pixel++ = 0;
                    }
                }
        }
        else if (renderingType_ == R_COMPOSITE_GRAY)
        {
            byte* pixel = rawData8_;
            for (uint16 row=0; row<height_; row++)
                for (uint16 col=0; col<width_; col++)
                {
                    byte channel = (row&1)<<1 | col&1;
                    if (chnlEnabled[channel])
                    {
                        *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                        *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                        *pixel++ = TO_8_BIT(getRawData(channel,row,col));
                    }
                    else
                    {
                        *pixel++ = 0;
                        *pixel++ = 0;
                        *pixel++ = 0;
                    }
                }
        }
    
        // update pixmap
        QImage image(rawData8_, width_, height_, 3*width_, QImage::Format_RGB888);
        rawPixmap_.convertFromImage(image);
    }
}
