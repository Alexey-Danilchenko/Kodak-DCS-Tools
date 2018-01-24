/*
    dcs_remap.h - mainform class to deal with QT application

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
#ifndef DCS_REMAP_H
#define DCS_REMAP_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QPoint>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QTranslator>

#include "ifdata.h"
#include "defects.h"

#include "ui_dcs_remap.h"

#define APP_NAME "DCS Remap"

// --------------------------------------------------------
//    Helper integrator class
// --------------------------------------------------------
class SpinBoxSliderIntegrator : public QObject
{
    Q_OBJECT

    QAbstractSlider *slider_;
    QDoubleSpinBox *spinBox_;

    double value_;
    double sliderScale_;
    double initValue_;
    bool lockSetValue_;

    int spinBox2Slide(double spinVal)
    {
        int sliderVal = roundToInt(sliderScale_*spinVal);
        if (sliderVal > slider_->maximum())
            sliderVal -= slider_->maximum() + 1;
        return sliderVal;
    }

    double slide2SpinBox(int sliderVal)
    {
        double spinVal = sliderVal/sliderScale_;
        if (spinVal < spinBox_->minimum())
            spinVal += spinBox_->maximum() + 1;
        return spinVal;
    }

    void valueUpdated()
    {
        if (value_ != spinBox_->value())
        {
            // only emit if value has changed
            value_ = spinBox_->value();
            emit valueChanged(value_);
        }
    }

public:

    SpinBoxSliderIntegrator(QDoubleSpinBox *spinBox, QAbstractSlider *slider, QToolButton *resetButton = 0)
    {
        slider_ = slider;
        spinBox_ = spinBox;

        lockSetValue_ = false;

        sliderScale_ = (double)(slider_->maximum() - slider_->minimum())/(spinBox_->maximum() - spinBox_->minimum());

        initValue_ = spinBox_->value();

        int singleStep = roundToInt(spinBox_->singleStep()*sliderScale_);
        singleStep = singleStep ? singleStep : 1;

        slider_->setSingleStep(singleStep);
        slider_->setPageStep(10*singleStep);

        connect(slider_, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(int)));
        connect(slider_, SIGNAL(sliderMoved(int)), this, SLOT(sliderValueChanged(int)));
        connect(spinBox_, SIGNAL(valueChanged(double)), this, SLOT(spinboxValueChanged(double)));
        
        value_ = spinBox_->value();

        if (resetButton)
            connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));
    }


    double value()
    {
        return value_;
    }

    void setValue(double v)
    {
        spinBox_->setValue(v);
    }

public slots:

    void spinboxValueChanged(double value)
    {
        if (!lockSetValue_)
        {
            lockSetValue_ = true;
            slider_->setValue(spinBox2Slide(value));
            lockSetValue_ = false;
        }

        // notify updated value if slider was not moving
        if (slider_->value() == slider_->sliderPosition())
            valueUpdated();
    }

    void sliderValueChanged(int value)
    {
        if (!lockSetValue_)
        {
            lockSetValue_ = true;
		    spinBox_->setValue(slide2SpinBox(value));
            lockSetValue_ = false;
        }

        // notify updated value if slider was not moving
        if (slider_->value() == value)
            valueUpdated();
    }

    void reset()
    {
        spinBox_->setValue(initValue_);
    }

signals:
    void valueChanged(double value);
};


// --------------------------------------------------------
//    DCSRemap class
// --------------------------------------------------------
class DCSRemap : public QMainWindow
{
	Q_OBJECT
    
    // member variables
    Ui::DCSRemap ui;

    QTranslator translator;

    DCSImagerFile *imagerFile;
    DCSDefects    *defects;
    bool unsavedChanges;
    
    // Defects colour
    QColor defectColour;

    SpinBoxSliderIntegrator* expControls[5];

    SpinBoxSliderIntegrator* wbControls[3];
    
    SpinBoxSliderIntegrator* wbExpControl;

    double camWB[Illuminants_length][4];
    
    // raw per-channel stats
    uint16 maxVal[4];
    uint16 minVal[4];
    double avgVal[4];

    uint16 threshold[4];
    uint32 thrStats[4];
    
    QString curRawPath;
    QString rawFileName;
    QString curIFPath;
    QString ifFileName;
    QString imagerSerial;
    
    QIcon tickIcon;
    QIcon tickEmptyIcon;
    
    double scale;
    int rawIsoSpeed;
    
    int language;
    bool lockModeChange;
    bool lockThresChange;
    bool overrideCursorSet;

public:
	DCSRemap(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~DCSRemap();

private:

    void closeEvent(QCloseEvent *event);

    void retranslate();

    int showMessage(const QString& title,
                    const QString& msgText,
                    const QString& informativeText=tr(""),
                    QMessageBox::Icon icon=QMessageBox::Critical, 
                    QMessageBox::StandardButtons buttons = QMessageBox::NoButton, 
                    QMessageBox::StandardButton defButton = QMessageBox::NoButton);
                    
    void setOverrideCursor(const QCursor& cursor) { 
        if (!overrideCursorSet)
        {
            overrideCursorSet = true;
            QApplication::setOverrideCursor(cursor);
            QApplication::processEvents();
        }
    }

    void restoreOverrideCursor() { 
        if (overrideCursorSet)
        {
            overrideCursorSet = false;
            QApplication::restoreOverrideCursor();
        }
    } 
                     
    void processRawData();
    void resizeEvent(QResizeEvent *event);
    void updateRawStats();
    void updateDefectStats();
    void updateThresholdStats(EChannel channel);
    void updateAutoRemap();
    void updateWidgets();
    int  loadRawStack(uint16* data, uint16 width, uint16 height, QStringList fileNames);
    int  loadRCF(uint16* data, uint16 &width, uint16 &height);
    bool checkUnsavedAndSave();
    bool accepLicense();
    
    void init();

private slots:
    void setRussianLanguage();
    void setEnglishLanguage();

    void openImagerFile();
    bool saveImagerFile();
    void discardChanges();

    void loadRaw();

    void autoRemap();
    void calculateThresholds();
    void deleteShownDefects();

    void changeDefColour(QColor* colour = 0);

    void help();
    void about();

    void zoomFit();
    void zoomFull();
    void zoomIn();
    void zoomOut();
    void setZoomLevel(int cbIndex);
    
    void gammaChecked(int state);
    void blackLevelZeroed(int state);

    void redChecked(int state);
    void greenChecked(int state);
    void blueChecked(int state);
    void green2Checked(int state);
    
    void showPreRemapChecked(int state);
    void showPointsChecked(int state);
    void showRowsChecked(int state);
    void showColsChecked(int state);

    void rawRenderingChanged(bool checked);

    void adjustContrast(int value);
    void adjustContrastMidpoint(int value);
    void adjustExposure(double value);
    void adjustBlack(int value);
    
    void adaptiveRemapModeChecked(int state);
    void adjustAdaptiveBlockSize(int value);
    
    void adjustThreshold(int value);

    void pointDefectModeChecked(bool checked);
    void rowDefectModeChecked(bool checked);
    void colDefectModeChecked(bool checked);

    void updateStatus(uint16 row, uint16 col);
    void defectsChanged();

    void setIso(int cbIndex);

    void setWB();

    void resetAdjustments();
};

#endif // DCS_REMAP_H
