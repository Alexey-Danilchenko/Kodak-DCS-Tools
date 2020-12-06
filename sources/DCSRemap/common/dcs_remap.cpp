/*
    dcs_remap.cpp - mainform class to deal with QT application

    Copyright 2013,2014,2020 Alexey Danilchenko
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

#define NOMINMAX

#include <QAbstractSlider>
#include <QByteArray>
#include <QColorDialog>
#include <QDesktopServices>
#include <QDoubleSpinBox>
#include <QDir>
#include <QFileDialog>
#include <QPalette>
#include <QProxyStyle>
#include <QSettings>
#include <QStyle>
#include <QScrollBar>
#include <QStyleFactory>
#include <QFileInfo>
#include <QString>
#include <QStringList>
#include <QUrl>

#include <libraw.h>

#include <string.h>
#include <math.h>

#include <algorithm>
#include <memory>

#include <tbb/tbb.h>

#include "dcs_remap.h"
#include "about.h"
#include "ifdata.h"
#include "defects.h"
#include "raw_image.h"

#define APP_VERSION " v1.2"

#define MAIN_TITLE APP_NAME APP_VERSION

#define STATE_SECTION "Saved State"

#define TAG_ImagerSerialN   2510

#define MAX_RAWS  7

#define RCF_COLS            3072
#define RCF_ROWS            4560
#define RCF_OVERCLOCK_COLS  24
#define RCF_CROP_COL_1      9
#define RCF_CROP_COL_2      27
#define RCF_CROP_ROW_1      34
#define RCF_CROP_ROW_2      10

#if defined( Q_OS_MACX )
#define BUNDLE_ID CFSTR("DCSRemap")
#if defined(_QT_STATIC_) && QT_VERSION >= 0x050000
#include <QtPlugin>
Q_IMPORT_PLUGIN (QCocoaIntegrationPlugin);
#endif
#endif

#if defined( Q_OS_WIN )
#if defined(_QT_STATIC_) && QT_VERSION >= 0x050000
#include <QtPlugin>
Q_IMPORT_PLUGIN (QWindowsIntegrationPlugin);
#endif
#endif

// --------------------------------------------------------
//    static data
// --------------------------------------------------------

// list of scale levels in percent
static uint16 zoomLevelList[] = {
    5, 10, 15, 20, 25, 30, 40, 50, 60, 75,
    100, 125, 150, 200, 300, 500, 700, 1000
};

static const uint16 zoomLevelListSize = sizeof(zoomLevelList) / sizeof(uint16);
static uint16 zoomLevelListFull = 0;

// --------------------------------------------------------
//    helper functions
// --------------------------------------------------------
static void initStaticData()
{
    static bool needInit = true;

    if (needInit)
    {
        for (int i=0; i<zoomLevelListSize; i++)
            if (zoomLevelList[i]==100)
            {
                zoomLevelListFull = i+1;
                break;
            }

        needInit = false;
    }
}

static double fitScale(uint16 imgWidth, uint16 imgHeight, QWidget &w)
{
    if (imgWidth==0 || imgHeight==0)
        return 1.0;

    double scale = (double)w.width()/imgWidth;
    double scaleH = (double)w.height()/imgHeight;

    if (scale > scaleH)
        scale = scaleH;

    // find the one with closes match
    int i=0;
    while (i<zoomLevelListSize && (scale*100) >= zoomLevelList[i])
        ++i;

    if (i>0)
        --i;

    return (double)zoomLevelList[i]/100;
}

static double getScrollBarRelPos(QScrollBar *scrl)
{
    if (!scrl->isVisible())
        return 0.5;
    return ((double)scrl->value() - scrl->minimum()) / (scrl->maximum() - scrl->minimum());
}

static void setScrollBarRelPos(QScrollBar *scrl, double relPos)
{
	scrl->setValue(roundToInt(relPos * (scrl->maximum() - scrl->minimum()) + scrl->minimum()));
}

static void setAdjustedScrollBarPos(QScrollBar *scrl, int value)
{
    if (value<0)
        value = scrl->maximum() + 1 - scrl->pageStep()/2;

    scrl->setValue(value);
}

inline double log2(double x) { return log(x)/log(2.0); }

inline uint16 blockSize(int index) { return uint16((index<<1)+4); }


// --------------------------------------------------------
//    DCSRemap class
// --------------------------------------------------------
DCSRemap::DCSRemap()
    : QMainWindow(), scale(1),
      lockModeChange(false), lockThresChange(false),
      unsavedChanges(false), overrideCursorSet(false),
      imagerFile(0), defects(0), rawIsoSpeed(0)
{
    language = QLocale::system().language();
    curRawPath = "./";

	// init statics
    initStaticData();

    ui.setupUi(this);
    ui.btnZoomFit->setEnabled(false);

    // load icon
    tickIcon.addFile(QStringLiteral(":/MainForm/images/tick_small.png"));
    tickEmptyIcon.addFile(QStringLiteral(":/MainForm/images/tick_small_empty.png"));

    // integrators
    expControls[C_ALL] = new SpinBoxSliderIntegrator(ui.expAllSpin, ui.expAll);
    expControls[C_RED] = new SpinBoxSliderIntegrator(ui.expRedSpin, ui.expRed);
    expControls[C_GREEN] = new SpinBoxSliderIntegrator(ui.expGreenSpin, ui.expGreen);
    expControls[C_BLUE] = new SpinBoxSliderIntegrator(ui.expBlueSpin, ui.expBlue);
    expControls[C_GREEN2] = new SpinBoxSliderIntegrator(ui.expGreen2Spin, ui.expGreen2);

    // buttons
    connect(ui.btnRussian, SIGNAL(clicked()), this, SLOT(setRussianLanguage()));
    connect(ui.btnEnglish, SIGNAL(clicked()), this, SLOT(setEnglishLanguage()));
    connect(ui.btnLoadRaws, SIGNAL(clicked()), this, SLOT(loadRaw()));
    connect(ui.btnLoadIF, SIGNAL(clicked()), this, SLOT(openImagerFile()));
    connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(saveImagerFile()));
    connect(ui.btnReset, SIGNAL(clicked()), this, SLOT(discardChanges()));
    connect(ui.btnRemoveDefects, SIGNAL(clicked()), this, SLOT(deleteShownDefects()));
    connect(ui.btnAutoRemap, SIGNAL(clicked()), this, SLOT(autoRemap()));
    connect(ui.btnZoom100, SIGNAL(clicked()), this, SLOT(zoomFull()));
    connect(ui.btnZoomFit, SIGNAL(clicked()), this, SLOT(zoomFit()));
    connect(ui.btnZoomIn, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui.btnZoomOut, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui.btnResetCorr, SIGNAL(clicked()), this, SLOT(resetAdjustments()));
    connect(ui.btnWB, SIGNAL(clicked()), this, SLOT(setWB()));
    connect(ui.btnDefColour, SIGNAL(clicked()), this, SLOT(changeDefColour()));
    connect(ui.btnDetectFromRaw, SIGNAL(clicked()), this, SLOT(calculateThresholds()));

    // comboboxes
    connect(ui.cboxZoomLevel, SIGNAL(currentIndexChanged(int)), this, SLOT(setZoomLevel(int)));
    connect(ui.cboxISO, SIGNAL(currentIndexChanged(int)), this, SLOT(setIso(int)));
    connect(ui.cbAdaptiveBlock, SIGNAL(currentIndexChanged(int)), this, SLOT(adjustAdaptiveBlockSize(int)));

    // spinboxes
    connect(ui.spinBlckRed, SIGNAL(valueChanged(int)), this, SLOT(adjustBlack(int)));
    connect(ui.spinBlckGreen, SIGNAL(valueChanged(int)), this, SLOT(adjustBlack(int)));
    connect(ui.spinBlckBlue, SIGNAL(valueChanged(int)), this, SLOT(adjustBlack(int)));
    connect(ui.spinBlckGreen2, SIGNAL(valueChanged(int)), this, SLOT(adjustBlack(int)));
    connect(ui.spbThrRed, SIGNAL(valueChanged(int)), this, SLOT(adjustThreshold(int)));
    connect(ui.spbThrGreen, SIGNAL(valueChanged(int)), this, SLOT(adjustThreshold(int)));
    connect(ui.spbThrBlue, SIGNAL(valueChanged(int)), this, SLOT(adjustThreshold(int)));
    connect(ui.spbThrGreen2, SIGNAL(valueChanged(int)), this, SLOT(adjustThreshold(int)));

    // exposure controls
    connect(expControls[C_ALL], SIGNAL(valueChanged(double)), this, SLOT(adjustExposure(double)));
    connect(expControls[C_RED], SIGNAL(valueChanged(double)), this, SLOT(adjustExposure(double)));
    connect(expControls[C_GREEN], SIGNAL(valueChanged(double)), this, SLOT(adjustExposure(double)));
    connect(expControls[C_BLUE], SIGNAL(valueChanged(double)), this, SLOT(adjustExposure(double)));
    connect(expControls[C_GREEN2], SIGNAL(valueChanged(double)), this, SLOT(adjustExposure(double)));

    // sliders
    connect(ui.sldrContrast, SIGNAL(valueChanged(int)), this, SLOT(adjustContrast(int)));
    connect(ui.sldrContrastPoint, SIGNAL(valueChanged(int)), this, SLOT(adjustContrastMidpoint(int)));

    // checkboxes
    connect(ui.checkGamma, SIGNAL(stateChanged(int)), this, SLOT(gammaChecked(int)));
    connect(ui.checkBlackZeroed, SIGNAL(stateChanged(int)), this, SLOT(blackLevelZeroed(int)));
    connect(ui.checkR, SIGNAL(stateChanged(int)), this, SLOT(redChecked(int)));
    connect(ui.checkG, SIGNAL(stateChanged(int)), this, SLOT(greenChecked(int)));
    connect(ui.checkB, SIGNAL(stateChanged(int)), this, SLOT(blueChecked(int)));
    connect(ui.checkG2, SIGNAL(stateChanged(int)), this, SLOT(green2Checked(int)));
    connect(ui.chkShowPreDefects, SIGNAL(stateChanged(int)), this, SLOT(showPreRemapChecked(int)));
    connect(ui.chkShowPoints, SIGNAL(stateChanged(int)), this, SLOT(showPointsChecked(int)));
    connect(ui.chkShowRows, SIGNAL(stateChanged(int)), this, SLOT(showRowsChecked(int)));
    connect(ui.chkShowCols, SIGNAL(stateChanged(int)), this, SLOT(showColsChecked(int)));
    connect(ui.chkAdaptiveRemap, SIGNAL(stateChanged(int)), this, SLOT(adaptiveRemapModeChecked(int)));

    // toggles
    connect(ui.radioRGB, SIGNAL(toggled(bool)), this, SLOT(rawRenderingChanged(bool)));
    connect(ui.radioComposite, SIGNAL(toggled(bool)), this, SLOT(rawRenderingChanged(bool)));
    connect(ui.radioCompGray, SIGNAL(toggled(bool)), this, SLOT(rawRenderingChanged(bool)));
    connect(ui.btnColMode, SIGNAL(toggled(bool)), this, SLOT(colDefectModeChecked(bool)));
    connect(ui.btnPointMode, SIGNAL(toggled(bool)), this, SLOT(pointDefectModeChecked(bool)));
    connect(ui.btnRowMode, SIGNAL(toggled(bool)), this, SLOT(rowDefectModeChecked(bool)));

    // actions
    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openImagerFile()));
    connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveImagerFile()));
    connect(ui.actionDiscard_changes, SIGNAL(triggered()), this, SLOT(discardChanges()));
    connect(ui.actionLoad_raw, SIGNAL(triggered()), this, SLOT(loadRaw()));
    connect(ui.actionAuto_remap, SIGNAL(triggered()), this, SLOT(autoRemap()));
    connect(ui.actionHelp_web, SIGNAL(triggered()), this, SLOT(help()));
    connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(close()));

    setWindowTitle(MAIN_TITLE);

    // raw image events
    connect(ui.rawImage, SIGNAL(imageCursorPosUpdated(uint16, uint16)),
            this,        SLOT(updateStatus(uint16, uint16)));
    connect(ui.rawImage, SIGNAL(defectsChanged()), this, SLOT(defectsChanged()));

    // init data
    init();

    ui.rawImage->setRawRenderingType(R_RGB);

    defectColour = QColor(255, 85, 0, 255);

    // read settings and position the window
    QSettings settings(APP_NAME, STATE_SECTION);
    QPoint pos = settings.value("Position").toPoint();
    QSize size = settings.value("Size").toSize();
    curRawPath = settings.value("Curent Raw Path").toString();
    curIFPath = settings.value("Curent IF Path").toString();
    defectColour = settings.value("Defect Colour", defectColour).value<QColor>();
    ui.cbAdaptiveBlock->setCurrentIndex(settings.value("Adaptive Block", 14).toInt());
    ui.chkAdaptiveRemap->setCheckState(Qt::CheckState(settings.value("Adaptive Remap", Qt::Unchecked).toInt()));

    int savedLanguage = settings.value("Language", language).toInt();

    if (savedLanguage != language)
    {
        language = savedLanguage;
        retranslate();
    }

    if (!pos.isNull())
        move(pos);

    if (!size.isEmpty())
        resize(size);

    if (settings.value("Maximized").toBool())
        setWindowState(windowState() | Qt::WindowMaximized);

    setIso(0);
	setZoomLevel(0);
    changeDefColour(&defectColour);

    updateWidgets();
}

DCSRemap::~DCSRemap()
{
    delete expControls[C_ALL];
    delete expControls[C_RED];
    delete expControls[C_GREEN];
    delete expControls[C_BLUE];
    delete expControls[C_GREEN2];

    delete defects;
    delete imagerFile;
}

bool DCSRemap::checkUnsavedAndSave()
{
    bool okToProceed = true;
    if (unsavedChanges && defects->hasDefects())
    {
        int dlgRes = showMessage(
                        tr("Warning"),
                        tr("The remap has been modified!"),
                        tr("Do you want to save your changes?"),
                        QMessageBox::Question,
                        QMessageBox::Save
                            | QMessageBox::Discard
                            | QMessageBox::Cancel);

        if (dlgRes == QMessageBox::Save)
            okToProceed = defects->saveToFile(*imagerFile) && imagerFile->save();
        else
            okToProceed = dlgRes==QMessageBox::Discard;

        if (okToProceed)
            unsavedChanges = false;
    }

    return okToProceed;
}

void DCSRemap::closeEvent(QCloseEvent *event)
{
    QSettings settings(APP_NAME, STATE_SECTION);

    if (!isMaximized())
    {
        settings.setValue("Position", pos());
        settings.setValue("Size", size());
    }

    settings.setValue("Curent Raw Path", curRawPath);
    settings.setValue("Curent IF Path", curIFPath);
    settings.setValue("Maximized", isMaximized());
    settings.setValue("Language", language);
    settings.setValue("Defect Colour", defectColour);
    settings.setValue("Adaptive Remap", ui.chkAdaptiveRemap->checkState());
    settings.setValue("Adaptive Block", ui.cbAdaptiveBlock->currentIndex());

    if (checkUnsavedAndSave())
        event->accept();
    else
        event->ignore();
}

void DCSRemap::retranslate()
{
    if (language == QLocale::Russian)
    {
        translator.load(QStringLiteral(":/MainForm/dcs_remap_ru.qm"));
        QApplication::installTranslator(&translator);
    }
    else
       QApplication::removeTranslator(&translator);

    ui.retranslateUi(this);
    ui.cboxZoomLevel->setItemText(0, tr("Fit to Window"));
    ui.rawImage->retranslate();
    updateRawStats();
    updateDefectStats();
    updateThresholdStats(C_ALL);
    updateWidgets();
    ui.cboxZoomLevel->updateGeometry();
}

void DCSRemap::setRussianLanguage()
{
    language = QLocale::Russian;
    retranslate();
}

void DCSRemap::setEnglishLanguage()
{
    language = QLocale::English;
    retranslate();
}

void DCSRemap::init()
{
    // init comboboxes for ISO and scale list
    ui.cboxZoomLevel->addItem(tr("Fit to Window"));
    QString numStr;
    for (int i=0; i<zoomLevelListSize; i++)
    {
        numStr.setNum(zoomLevelList[i]);
        ui.cboxZoomLevel->addItem(numStr);
    }
    numStr = "%1";
    for (int i=0; i<DCSDefects::ISO_COUNT; i++)
        ui.cboxISO->addItem(tickEmptyIcon, numStr.arg(DCSDefects::isoList[i]));

    numStr = "%1 x %1";
    for (int i=4; i<=MAX_ADAPTIVE_BLOCK; i+=2)
        ui.cbAdaptiveBlock->addItem(numStr.arg(i));

    ui.cboxZoomLevel->setMaxVisibleItems(10);
    ui.cboxISO->setMaxVisibleItems(10);
    ui.cbAdaptiveBlock->setMaxVisibleItems(20);

    for (int i=0; i<=Illuminants_length; i++)
        camWB[i][C_RED] = camWB[i][C_GREEN] = camWB[i][C_BLUE] = camWB[i][C_GREEN2] = 1;
    threshold[C_RED]=threshold[C_GREEN]=threshold[C_BLUE]=threshold[C_GREEN2]=0;
    thrStats[C_RED]=thrStats[C_GREEN]=thrStats[C_BLUE]=thrStats[C_GREEN2]=0;

    maxVal[C_RED] = maxVal[C_GREEN] = maxVal[C_BLUE] = maxVal[C_GREEN2] = 0;
    minVal[C_RED] = minVal[C_GREEN] = minVal[C_BLUE] = minVal[C_GREEN2] = 0;
    avgVal[C_RED] = avgVal[C_GREEN] = avgVal[C_BLUE] = avgVal[C_GREEN2] = 0;
}

int DCSRemap::showMessage(const QString& title,
                          const QString& msgText,
                          const QString& informativeText,
                          QMessageBox::Icon icon,
                          QMessageBox::StandardButtons buttons,
                          QMessageBox::StandardButton defButton)
{
    restoreOverrideCursor();

    QMessageBox msgBox(icon,
                       title,
                       msgText,
                       buttons);
    msgBox.setInformativeText(informativeText);
    msgBox.setDefaultButton(defButton);

    return msgBox.exec();
}

void DCSRemap::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    if (ui.cboxZoomLevel->currentIndex()==0)
    {
        scale = fitScale(ui.rawImage->getRawWidth(), ui.rawImage->getRawHeight(), *ui.rawImage);
        ui.rawImage->setScale(scale);
    }
}


void DCSRemap::updateWidgets()
{
    bool hasRaw = ui.rawImage->rawLoaded();
    bool hasDefects = ui.rawImage->hasDefects();

    QString title(MAIN_TITLE);

    if (hasRaw)
    {
        QFileInfo info(rawFileName);
        title.append("     DCR: ").append(info.fileName());
        if (rawIsoSpeed)
        {
            QString iso(" (ISO: %1)");
            title.append(iso.arg(rawIsoSpeed));
        }
    }
    if (hasDefects)
    {
        QFileInfo info(ifFileName);
        title.append("     IF: ").append(info.fileName());
        if (unsavedChanges)
            title.append(" * ");

        if (!imagerSerial.isEmpty())
            title.append(tr("     Imager serial: ")).append(imagerSerial);
    }

    setWindowTitle(title);

    bool isProback = ui.rawImage->getRawWidth() > 0 &&
                     ui.rawImage->getRawWidth() == ui.rawImage->getRawHeight();

    ui.tabDisplay->setEnabled(hasRaw);
    ui.tabRemap->setEnabled(hasDefects);

    ui.zoomBar->setEnabled(hasRaw || hasDefects);
    ui.btnColMode->setEnabled(hasDefects);
    ui.btnPointMode->setEnabled(hasDefects);
    // Proback does not support rows remap
    ui.btnRowMode->setEnabled(hasDefects && !isProback);
    ui.chkShowRows->setEnabled(hasDefects && !isProback);

    ui.btnSave->setEnabled(hasDefects);
    ui.btnReset->setEnabled(hasDefects);
    //ui.actionSave->setEnabled(hasDefects);
    //ui.actionDiscard_changes->setEnabled(hasDefects);

    if (hasDefects)
    {
        ui.grpRemapThr->setEnabled(hasRaw);
        ui.btnAutoRemap->setEnabled(hasRaw);
        ui.btnDetectFromRaw->setEnabled(hasRaw);
    }

    updateAutoRemap();
}

void DCSRemap::updateAutoRemap()
{
    uint32 matchedCount = thrStats[C_RED]+thrStats[C_GREEN]+thrStats[C_BLUE]+thrStats[C_GREEN2];
    ui.btnAutoRemap->setEnabled(matchedCount>0 && matchedCount<60000);
    //ui.actionAuto_remap->setEnabled(matchedCount>0 && matchedCount<20000);
}

// -------------------------------------------------------------------------
//   Event slots
// -------------------------------------------------------------------------

void DCSRemap::openImagerFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Load Kodak .IF imager file"),
                                                    curIFPath,
                                                    tr("Kodak imager files (*.IF)"));

    if (fileName != "")
    {
        QFileInfo info(fileName);
        curIFPath = info.absolutePath();

        auto newImagerFile = std::make_unique<DCSImagerFile>();
        auto newDefects = std::make_unique<DCSDefects>();

        if (!newImagerFile->readFromFile(fileName.toUtf8().data()))
        {
            showMessage(tr("Error"), tr("Error opening imager file\n%1!").arg(fileName));
        }
        else
        {
            if (!newDefects->loadFromFile(*newImagerFile))
            {
                showMessage(tr("Warning"),
                            tr("Imager file %1\ndoes not have any defects data!").arg(fileName),
                            "",
                            QMessageBox::Warning);
            }

            bool hasRaw = ui.rawImage->rawLoaded();
            bool isSwapped = newDefects->getMaxRows() > newDefects->getMaxCols();
            uint16 defWidth  = isSwapped ? newDefects->getMaxRows() : newDefects->getMaxCols();
            uint16 defHeight = isSwapped ? newDefects->getMaxCols() : newDefects->getMaxRows();
            bool loadDefects = checkUnsavedAndSave();

            if (loadDefects && hasRaw &&
                (defWidth != ui.rawImage->getRawWidth() ||
                 defHeight != ui.rawImage->getRawHeight()))
            {
                loadDefects = showMessage(
                                tr("Warning"),
                                tr("Imager file %1\nis not from the same type of\ncamera as currently loaded RAW file!").arg(fileName),
                                tr("Do you want to load imager file and discard the raw?"),
                                QMessageBox::Question,
                                QMessageBox::Yes | QMessageBox::No,
                                QMessageBox::Yes) == QMessageBox::Yes;

                if (loadDefects)
                    ui.rawImage->clearRawImage();
            }

            if (loadDefects)
            {
                delete defects;
                delete imagerFile;
                imagerFile = newImagerFile.release();
                defects = newDefects.release();
                imagerSerial = imagerFile->getStringTagValue(TAG_ImagerSerialN);

                // reset mode
                lockModeChange = true;
                ui.btnPointMode->setChecked(false);
                ui.btnColMode->setChecked(false);
                ui.btnRowMode->setChecked(false);
                lockModeChange = false;

                // recalculate fit
                if (ui.cboxZoomLevel->currentIndex()==0)
                {
                    scale = fitScale(defWidth, defHeight, *ui.rawImage);
                }

                ui.rawImage->setDefects(defects, scale);
                ifFileName = fileName;
                updateWidgets();
                updateDefectStats();
            }
        }
    }
}

bool DCSRemap::saveImagerFile()
{
    if (!defects)
        return true;

    if (!defects->hasDefects())
    {
        showMessage(tr("Error"),
                    tr("There are no remapped defects to save!"));

        return false;
    }

    bool success = defects->saveToFile(*imagerFile) && imagerFile->save();

    if (success)
    {
        unsavedChanges = false;

        // attempt to reload saved imager file
        std::unique_ptr<DCSImagerFile> newImagerFile(new DCSImagerFile);
        std::unique_ptr<DCSDefects> newDefects(new DCSDefects);

        if (newImagerFile->readFromFile(ifFileName.toUtf8().data()) &&
            newDefects->loadFromFile(*newImagerFile))
        {
            delete defects;
            delete imagerFile;
            imagerFile = newImagerFile.release();
            defects = newDefects.release();

            ui.rawImage->setDefects(defects, scale);

            // reset mode
            lockModeChange = true;
            ui.btnPointMode->setChecked(false);
            ui.btnColMode->setChecked(false);
            ui.btnRowMode->setChecked(false);
            lockModeChange = false;
        }
        else
            ui.rawImage->updateDefects();

        updateWidgets();
        updateDefectStats();
    }
    else
        showMessage(tr("Error"), tr("Error writing imager file %1!").arg(ifFileName));

    return success;
}

void DCSRemap::discardChanges()
{
    // reload
    unsavedChanges = false;
    defects->loadFromFile(*imagerFile);

    ui.rawImage->updateDefects();
    updateWidgets();
    updateDefectStats();
}

void DCSRemap::loadRaw()
{
    QStringList fileNames =
            QFileDialog::getOpenFileNames(this,
                                          tr("Load Kodak .DCR RAW file(s)"),
                                          curRawPath,
                                          tr("Kodak RAWs (*.dcr *.rcf)"));

    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

    // filter through and leave only files
    QStringList::iterator it = fileNames.begin();
    while (it != fileNames.end())
    {
        QFileInfo info(*it);

        if (!info.isFile())
            it = fileNames.erase(it);
        else
            ++it;
    }

    if (fileNames.size() > MAX_RAWS)
    {
        showMessage(tr("Error"), tr("Cannot load more than %1 RAW files!").arg(MAX_RAWS));
    }
    else if (fileNames.size() > 0)
    {
        // read the first raw
        QFileInfo info(fileNames.at(0));
		curRawPath = info.absolutePath();
        bool isRCF = false;

        LibRaw rawProc;
        QByteArray byteStr = fileNames.at(0).toUtf8();
        int ret = LIBRAW_SUCCESS;

        if ((ret = rawProc.open_file(byteStr.constData())) != LIBRAW_SUCCESS)
            showMessage(tr("Error"), tr("Error opening file\n%1!").arg(fileNames.at(0)));
        else
        {
            // check if we have the right format
            libraw_decoder_info_t decInf;
            rawProc.get_decoder_info(&decInf);

            if (!strstr(rawProc.imgdata.idata.make, "Kodak"))
            {
                ret = LIBRAW_FILE_UNSUPPORTED;
                showMessage(tr("Error"), tr("File %1\ndoes not seem to be Kodak .DCR file!").arg(fileNames.at(0)));
            }

            // RCF format checks
            if (ret == LIBRAW_SUCCESS &&
                info.suffix().compare("RCF", Qt::CaseInsensitive)==0)
            {
                isRCF = rawProc.imgdata.sizes.raw_width==RCF_COLS &&
                        rawProc.imgdata.sizes.raw_height==RCF_ROWS &&
                        rawProc.imgdata.idata.cdesc[rawProc.COLOR(0,0)] == 'G' &&
                        rawProc.imgdata.idata.cdesc[rawProc.COLOR(0,1)] == 'R' &&
                        rawProc.imgdata.idata.cdesc[rawProc.COLOR(1,0)] == 'B' &&
                        rawProc.imgdata.idata.cdesc[rawProc.COLOR(1,1)] == 'G';

                if (!isRCF)
                {
                    ret = LIBRAW_FILE_UNSUPPORTED;
                    showMessage(tr("Error"), tr("Only .RCF from SLR/n/c or 14n are supported!"));
                }
            }

            // check the bayer pattern
            if (ret == LIBRAW_SUCCESS && !isRCF &&
                (rawProc.imgdata.idata.cdesc[rawProc.COLOR(0,0)] != 'G' ||
                 rawProc.imgdata.idata.cdesc[rawProc.COLOR(0,1)] != 'R' ||
                 rawProc.imgdata.idata.cdesc[rawProc.COLOR(1,0)] != 'B' ||
                 rawProc.imgdata.idata.cdesc[rawProc.COLOR(1,1)] != 'G'))
            {
                // its not Bayer or does not have Kodak as a maker
                // or is not in
                //   G R
                //   B G
                // pattern
                ret = LIBRAW_FILE_UNSUPPORTED;
                showMessage(tr("Error"), tr("File %1\ndoes not seem to be Kodak .DCR file!").arg(fileNames.at(0)));
            }
            else if (ret == LIBRAW_SUCCESS && (ret = rawProc.unpack() ) != LIBRAW_SUCCESS)
            {
                showMessage(tr("Error"), tr("Error unpacking RAW data from file\n%1!").arg(fileNames.at(0)));
            }
        }

        // check if we have multiple files and load up a stack
        if (ret == LIBRAW_SUCCESS && fileNames.size() > 1)
            ret = loadRawStack(rawProc.imgdata.rawdata.raw_image,
                               rawProc.imgdata.sizes.raw_width,
                               rawProc.imgdata.sizes.raw_height,
                               fileNames);

        if (ret == LIBRAW_SUCCESS && isRCF)
            ret = loadRCF(rawProc.imgdata.rawdata.raw_image,
                          rawProc.imgdata.sizes.raw_width,
                          rawProc.imgdata.sizes.raw_height);

        bool hasDefects = ui.rawImage->hasDefects();
        if (ret == LIBRAW_SUCCESS && hasDefects &&
            (rawProc.imgdata.sizes.raw_width != ui.rawImage->getRawWidth() ||
             rawProc.imgdata.sizes.raw_height != ui.rawImage->getRawHeight()))
        {
            if (showMessage(tr("Warning"),
                            tr("RAW file %1\ndoes not match currently loaded imager file!").arg(fileNames.at(0)),
                            tr("Do you want to load RAW file and discard the imager file?"),
                            QMessageBox::Question,
                            QMessageBox::Yes | QMessageBox::No,
                            QMessageBox::Yes) == QMessageBox::No)
                ret = LIBRAW_UNSPECIFIED_ERROR;
            else if (checkUnsavedAndSave())
            {
                ui.rawImage->clearDefects();
                // reset mode
                lockModeChange = true;
                ui.btnPointMode->setChecked(false);
                ui.btnColMode->setChecked(false);
                ui.btnRowMode->setChecked(false);
                lockModeChange = false;
            }
            else
                ret = LIBRAW_UNSPECIFIED_ERROR;
        }

        // actually load the data into control
        if (ret == LIBRAW_SUCCESS)
        {
            // get WB
            float* wb = rawProc.imgdata.color.cam_mul;

            if (wb[0] <= 0)
                wb = rawProc.imgdata.color.pre_mul;

            camWB[DaylightIllum][C_RED]    = wb[rawProc.COLOR(0,1)];
            camWB[DaylightIllum][C_GREEN]  = wb[rawProc.COLOR(0,0)];
            camWB[DaylightIllum][C_BLUE]   = wb[rawProc.COLOR(1,0)];
            camWB[DaylightIllum][C_GREEN2] = wb[rawProc.COLOR(1,1)];

            if (camWB[DaylightIllum][C_GREEN2] <= 0)
                camWB[DaylightIllum][C_GREEN2] = camWB[DaylightIllum][C_GREEN];

            double maxGreen = std::max(camWB[DaylightIllum][C_GREEN], camWB[DaylightIllum][C_GREEN2]);
            if (maxGreen == 0.0)
                maxGreen = 1.0;

            // normalise camWB
            camWB[DaylightIllum][C_RED]    /= maxGreen;
            camWB[DaylightIllum][C_GREEN]  /= maxGreen;
            camWB[DaylightIllum][C_BLUE]   /= maxGreen;
            camWB[DaylightIllum][C_GREEN2] /= maxGreen;

            rawIsoSpeed = rawProc.imgdata.other.iso_speed;

            // recalculate fit
            if (ui.cboxZoomLevel->currentIndex()==0)
                scale = fitScale(rawProc.imgdata.sizes.raw_width,
                                 rawProc.imgdata.sizes.raw_height,
                                 *ui.rawImage);
            ui.rawImage->setRawImage(rawProc.imgdata.rawdata.raw_image,
                                     rawProc.imgdata.sizes.raw_width,
                                     rawProc.imgdata.sizes.raw_height,
                                     DCSDefects::isoCodeFromISO((uint16)rawIsoSpeed),
                                     scale);
            // update ISO selection
            int16 isoIndex = ui.rawImage->getIsoCode();
            if (isoIndex<DCSDefects::ISO_COUNT)
                ui.cboxISO->setCurrentIndex(isoIndex);

            // process raw data to gather stats
            processRawData();
        }

        rawFileName = fileNames.at(0);
        updateWidgets();

        rawProc.recycle();
    }

    QApplication::restoreOverrideCursor();
}

// The number of files in a stack passed here needs to be limited by MAX_RAWS
int DCSRemap::loadRawStack(uint16* data,
                           uint16 width,
                           uint16 height,
                           QStringList fileNames)
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

    LibRaw *rawProc = new LibRaw[fileNames.size()-1];
    int result = LIBRAW_SUCCESS;
    int rawCount = fileNames.size()>MAX_RAWS ? MAX_RAWS : fileNames.size();

    // attempt to go and open all raw files
    for (int i=1; result==LIBRAW_SUCCESS && i<rawCount; i++)
    {
        QByteArray byteStr = fileNames.at(i).toUtf8();
        if ((result = rawProc[i-1].open_file(byteStr.constData())) != LIBRAW_SUCCESS)
            showMessage(tr("Error"), tr("Error opening file\n%1!").arg(fileNames.at(i)));
        else
        {
            // check if we have the right format
            libraw_decoder_info_t decInf;
            rawProc[i-1].get_decoder_info(&decInf);
            if (!strstr(rawProc[i-1].imgdata.idata.make, "Kodak") ||
                rawProc[i-1].imgdata.idata.cdesc[rawProc[i-1].COLOR(0,0)] != 'G' ||
                rawProc[i-1].imgdata.idata.cdesc[rawProc[i-1].COLOR(0,1)] != 'R' ||
                rawProc[i-1].imgdata.idata.cdesc[rawProc[i-1].COLOR(1,0)] != 'B' ||
                rawProc[i-1].imgdata.idata.cdesc[rawProc[i-1].COLOR(1,1)] != 'G')
            {
                // its not Bayer or does not have Kodak as a maker
                // or is not in
                //   G R
                //   B G
                // pattern
                result = LIBRAW_FILE_UNSUPPORTED;
                showMessage(tr("Error"), tr("File %1\ndoes not seem to be Kodak .DCR raw!").arg(fileNames.at(i)));
            }
            else if ((result = rawProc[i-1].unpack() ) != LIBRAW_SUCCESS)
            {
                showMessage(tr("Error"), tr("Error unpacking RAW data from file %1!").arg(fileNames.at(i)));
            }
            else if (rawProc[i-1].imgdata.sizes.raw_width  != width ||
                     rawProc[i-1].imgdata.sizes.raw_height != height)
            {
                result = LIBRAW_FILE_UNSUPPORTED;
                showMessage(tr("Error"), tr("File %1\ndoes not have the same dimensions\nas the other selected files!").arg(fileNames.at(i)));
            }
        }
    }

    // loaded all the raws - calculate the median into first array
    if (result == LIBRAW_SUCCESS)
    {
        tbb::parallel_for(size_t(0), size_t(width*height),
        [&](size_t i)
        {
            uint16 stack[MAX_RAWS];
            stack[0] = data[i];
            for (int cnt=1; cnt<rawCount; cnt++)
                stack[cnt] = rawProc[cnt-1].imgdata.rawdata.raw_image[i];
            data[i] = calc_median(stack, rawCount);
        });
    }

	delete[] rawProc;

    QApplication::restoreOverrideCursor();

    return result;
}

int DCSRemap::loadRCF(uint16* data,
                      uint16& width,
                      uint16& height)
{
    int result = LIBRAW_SUCCESS;

    width  = RCF_ROWS - RCF_CROP_ROW_1 - RCF_CROP_ROW_2;
    height = RCF_COLS - RCF_OVERCLOCK_COLS - RCF_CROP_COL_1 - RCF_CROP_COL_2;

    int startRow = RCF_CROP_ROW_1;
    int maxRow = width + startRow;
    int startCol = RCF_CROP_COL_1;
    int maxCol = height + startCol;

    uint16* tmpData = new uint16[width*height];

    if (tmpData)
    {
        tbb::parallel_for(size_t(startRow), size_t(maxRow),
        [&](size_t row)
        {
            for (int col = startCol; col<maxCol; col++)
            {
                int newRow = col - startCol;
                int newCol = width - (row - startRow) - 1;
                tmpData[newRow*width+newCol] = data[row*RCF_COLS+col];
            }
        });
        memcpy(data, tmpData, sizeof(uint16)*width*height);
        delete[] tmpData;
    }
    else
        result = LIBRAW_UNSPECIFIED_ERROR;

    return result;
}

// walks through raw data and gets the stats
void DCSRemap::processRawData()
{
    uint16 rawWidth = ui.rawImage->getRawWidth();
    uint16 rawHeight = ui.rawImage->getRawHeight();
    int totalValuesPerChannel = (rawWidth * rawHeight)>>2;

    maxVal[C_RED] = maxVal[C_GREEN] = maxVal[C_BLUE] = maxVal[C_GREEN2] = 0;
    minVal[C_RED] = minVal[C_GREEN] = minVal[C_BLUE] = minVal[C_GREEN2] = 0xFFFF;
    avgVal[C_RED] = avgVal[C_GREEN] = avgVal[C_BLUE] = avgVal[C_GREEN2] = 0;

    for (int row=0; row<rawHeight; row++)
        for (int col=0; col<rawWidth; col++)
        {
            EChannel channel = ui.rawImage->getRawColor(row,col);
            uint16 val = ui.rawImage->getRawValue(row,col);
            if (maxVal[channel]<val)
                maxVal[channel] = val;
            if (minVal[channel]>val)
                minVal[channel] = val;
            avgVal[channel] += val;
        }

    avgVal[C_RED] /= totalValuesPerChannel;
    avgVal[C_GREEN] /= totalValuesPerChannel;
    avgVal[C_BLUE] /= totalValuesPerChannel;
    avgVal[C_GREEN2] /= totalValuesPerChannel;

    updateRawStats();

    // calculate thersholds
    calculateThresholds();
}

void DCSRemap::updateRawStats()
{
    QString fmtStr("%1");

    // populate UI controls
    ui.lblStatsMinR->setText(fmtStr.arg(minVal[C_RED]));
    ui.lblStatsMinG->setText(fmtStr.arg(minVal[C_GREEN]));
    ui.lblStatsMinB->setText(fmtStr.arg(minVal[C_BLUE]));
    ui.lblStatsMinG2->setText(fmtStr.arg(minVal[C_GREEN2]));
    ui.lblStatsMaxR->setText(fmtStr.arg(maxVal[C_RED]));
    ui.lblStatsMaxG->setText(fmtStr.arg(maxVal[C_GREEN]));
    ui.lblStatsMaxB->setText(fmtStr.arg(maxVal[C_BLUE]));
    ui.lblStatsMaxG2->setText(fmtStr.arg(maxVal[C_GREEN2]));
    ui.lblStatsAvgR->setText(fmtStr.arg(avgVal[C_RED],0,'f',2));
    ui.lblStatsAvgG->setText(fmtStr.arg(avgVal[C_GREEN],0,'f',2));
    ui.lblStatsAvgB->setText(fmtStr.arg(avgVal[C_BLUE],0,'f',2));
    ui.lblStatsAvgG2->setText(fmtStr.arg(avgVal[C_GREEN2],0,'f',2));
}

void DCSRemap::calculateThresholds()
{
    const double DARK_THRESHOLD = 10;
    const double LIGHT_THRESHOLD = 20;

    bool isDark = (avgVal[C_RED]-minVal[C_RED] +
                   avgVal[C_GREEN]-minVal[C_GREEN] +
                   avgVal[C_BLUE]-minVal[C_BLUE] +
                   avgVal[C_GREEN2]-minVal[C_GREEN2]) < DARK_THRESHOLD;
    bool isLight = (maxVal[C_RED]-avgVal[C_RED] +
                    maxVal[C_GREEN]-avgVal[C_GREEN] +
                    maxVal[C_BLUE]-avgVal[C_BLUE] +
                    maxVal[C_GREEN2]-avgVal[C_GREEN2]) < LIGHT_THRESHOLD;

    if (isDark || isLight)
    {
        if (isDark)
        {
            threshold[C_RED] = roundToInt((maxVal[C_RED]-avgVal[C_RED])/10);
            threshold[C_GREEN] = roundToInt((maxVal[C_GREEN]-avgVal[C_GREEN])/10);
            threshold[C_BLUE] = roundToInt((maxVal[C_BLUE]-avgVal[C_BLUE])/10);
            threshold[C_GREEN2] = roundToInt((maxVal[C_GREEN2]-avgVal[C_GREEN2])/10);
        }
        else if (isLight)
        {
            threshold[C_RED] = roundToInt((avgVal[C_RED]-minVal[C_RED])/2);
            threshold[C_GREEN] = roundToInt((avgVal[C_GREEN]-minVal[C_GREEN])/2);
            threshold[C_BLUE] = roundToInt((avgVal[C_BLUE]-minVal[C_BLUE])/2);
            threshold[C_GREEN2] = roundToInt((avgVal[C_GREEN2]-minVal[C_GREEN2])/2);
        }

    }
    else
        threshold[C_RED]=threshold[C_GREEN]=threshold[C_BLUE]=threshold[C_GREEN2]=0;

    lockThresChange = true;
    ui.spbThrRed->setValue(threshold[C_RED]);
    ui.spbThrGreen->setValue(threshold[C_GREEN]);
    ui.spbThrBlue->setValue(threshold[C_BLUE]);
    ui.spbThrGreen2->setValue(threshold[C_GREEN2]);
    lockThresChange = false;

    // update stats
    updateThresholdStats(C_ALL);
}

void DCSRemap::updateThresholdStats(EChannel channel)
{
    QString fmtStr("%1");

    uint16 rawWidth = ui.rawImage->getRawWidth();
    uint16 rawHeight = ui.rawImage->getRawHeight();

    if (!ui.rawImage->rawLoaded())
        return;

    if (ui.chkAdaptiveRemap->checkState()==Qt::Checked)
    {
        ui.rawImage->performAdaptiveAutoRemap(
                    threshold,
                    blockSize(ui.cbAdaptiveBlock->currentIndex()),
                    true,
                    channel,
                    thrStats);
    }
    else if (channel == C_ALL)
    {
        thrStats[C_RED]=thrStats[C_GREEN]=thrStats[C_BLUE]=thrStats[C_GREEN2]=0;
        for (int row=0; row<rawHeight; row++)
            for (int col=0; col<rawWidth; col++)
            {
                EChannel channel = ui.rawImage->getRawColor(row,col);
                if (threshold[channel]>0 &&
                    fabs(avgVal[channel]-ui.rawImage->getRawValue(row,col))>threshold[channel])
                    thrStats[channel]++;
            }
    }
    else
    {
        thrStats[channel] = 0;
        int rowStart = (channel==C_RED || channel==C_GREEN) ? 0 : 1;
        int colStart = (channel==C_BLUE || channel==C_GREEN) ? 0 : 1;

        for (int row=rowStart; row<rawHeight; row+=2)
            for (int col=colStart; col<rawWidth; col+=2)
            {
                if (threshold[channel]>0 &&
                    fabs(avgVal[channel]-ui.rawImage->getRawValue(row,col))>threshold[channel])
                    thrStats[channel]++;
            }
    }

    if (channel == C_ALL)
    {
        ui.lblStatsDefR->setText(fmtStr.arg(thrStats[C_RED]));
        ui.lblStatsDefG->setText(fmtStr.arg(thrStats[C_GREEN]));
        ui.lblStatsDefB->setText(fmtStr.arg(thrStats[C_BLUE]));
        ui.lblStatsDefG2->setText(fmtStr.arg(thrStats[C_GREEN2]));
    }
    else if (channel==C_RED)
        ui.lblStatsDefR->setText(fmtStr.arg(thrStats[C_RED]));
    else if (channel==C_GREEN)
        ui.lblStatsDefG->setText(fmtStr.arg(thrStats[C_GREEN]));
    else if (channel==C_BLUE)
        ui.lblStatsDefB->setText(fmtStr.arg(thrStats[C_BLUE]));
    else if (channel==C_GREEN2)
        ui.lblStatsDefG2->setText(fmtStr.arg(thrStats[C_GREEN2]));

    updateAutoRemap();
}

void DCSRemap::autoRemap()
{
    if (ui.chkAdaptiveRemap->checkState()==Qt::Checked)
    {
        if (ui.rawImage->performAdaptiveAutoRemap(
                        threshold,
                        blockSize(ui.cbAdaptiveBlock->currentIndex())))
        {
            unsavedChanges = true;
            updateWidgets();
            updateDefectStats();
        }
    }
    else if (ui.rawImage->performAvgAutoRemap(avgVal, threshold))
    {
        unsavedChanges = true;
        updateWidgets();
        updateDefectStats();
    }
}

void DCSRemap::deleteShownDefects()
{
    if (ui.chkShowPreDefects->checkState()!=Qt::Checked ||
        showMessage(tr("Warning"),
                    tr("This will remove all selected types of remapped\n"
                       "defects for currently loaded imager file!\n"
                       "You can always go back by pressing \"Reset\""
                       "\nif the file was not overriden by saving."),
                    tr("Are you sure you want to continue?"),
                    QMessageBox::Question,
                    QMessageBox::Yes | QMessageBox::No,
                    QMessageBox::Yes) == QMessageBox::Yes)
    {
        ui.rawImage->eraseEnabledDefects();
        unsavedChanges = true;
        updateWidgets();
        updateDefectStats();
    }
}

void DCSRemap::help()
{
    QDir dir(QApplication::applicationDirPath());

#ifdef Q_OS_MACX
    dir.cdUp();
#endif

    if (dir.cd("help"))
    {
        if (language == QLocale::Russian)
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir.filePath("help_ru.html")));
        else
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir.filePath("help_en.html")));
    }
}

void DCSRemap::about()
{
    About about(language);

    about.exec();
}

void DCSRemap::zoomFit()
{
    ui.cboxZoomLevel->setCurrentIndex(0);
}

void DCSRemap::zoomFull()
{
    ui.cboxZoomLevel->setCurrentIndex(zoomLevelListFull);
}

void DCSRemap::zoomIn()
{
    int i=0;
    while (i<zoomLevelListSize && scale*100 >= zoomLevelList[i])
        ++i;

    if (i<zoomLevelListSize)
    {
        ui.cboxZoomLevel->setCurrentIndex(i+1);
    }
}

void DCSRemap::zoomOut()
{
    int i=0;
    while (i<zoomLevelListSize && scale*100 >= zoomLevelList[i])
        ++i;

    if (--i>0)
    {
        ui.cboxZoomLevel->setCurrentIndex(i);
    }
}

void DCSRemap::setZoomLevel(int cbIndex)
{
    if (cbIndex >= 0)
    {
        double horValue=0, vertValue=0;
        bool resizable = true;

        if (cbIndex == zoomLevelListFull)
            ui.btnZoom100->setEnabled(false);
        else
            ui.btnZoom100->setEnabled(true);

        if (cbIndex == 1)
            ui.btnZoomOut->setEnabled(false);
        else
            ui.btnZoomOut->setEnabled(true);

        if (cbIndex+1 == ui.cboxZoomLevel->count())
            ui.btnZoomIn->setEnabled(false);
        else
            ui.btnZoomIn->setEnabled(true);

        QScrollBar *hBar = ui.rawScrollArea->horizontalScrollBar();
        QScrollBar *vBar = ui.rawScrollArea->verticalScrollBar();

        // disable updates
        ui.rawScrollArea->setUpdatesEnabled(false);

        // check the types of zoom
        if (cbIndex == 0)
        {
            ui.btnZoomFit->setEnabled(false);
	        ui.rawScrollArea->setWidgetResizable(true);
            scale = fitScale(ui.rawImage->getRawWidth(), ui.rawImage->getRawHeight(), *ui.rawImage);
        }
        else
        {
            ui.btnZoomFit->setEnabled(true);
            resizable = false;
            scale = (double)zoomLevelList[cbIndex-1]/100;

            horValue = getScrollBarRelPos(hBar);
            vertValue = getScrollBarRelPos(vBar);

            // setWidgetResizable() updates the scrollbars so it has to
            // be called after we read their values
			ui.rawScrollArea->setWidgetResizable(false);
        }

        ui.rawImage->setScale(scale);

        if (cbIndex != 0)
        {
            // the viewport may not updated yet - it is delayed to layout engine
            QSize max = ui.rawScrollArea->maximumViewportSize();
            QSize vSize = ui.rawScrollArea->viewport()->size();
            QSize wSize = ui.rawImage->sizeHint();

            if (max.width()==vSize.width() && wSize.width()>max.width())
            {
                vSize.rwidth() -= vBar->width();
                hBar->setRange(0, wSize.width() - vSize.width());
                hBar->setPageStep(vSize.width());
            }
            if (max.height()==vSize.height() && wSize.height()>max.height())
            {
                vSize.rheight() -= hBar->height();
                vBar->setRange(0, wSize.height() - vSize.height());
                vBar->setPageStep(vSize.height());
            }

            setScrollBarRelPos(hBar, horValue);
            setScrollBarRelPos(vBar, vertValue);
        }

        ui.rawScrollArea->setUpdatesEnabled(true);

    }
}

void DCSRemap::gammaChecked(int state)
{
    ui.rawImage->enableGammaCorrection(state==Qt::Checked);
}

void DCSRemap::blackLevelZeroed(int state)
{
    ui.rawImage->enableBlackLevelZeroed(state==Qt::Checked);
}

void DCSRemap::redChecked(int state)
{
    ui.rawImage->enableChannel(state==Qt::Checked, C_RED);
}

void DCSRemap::greenChecked(int state)
{
    ui.rawImage->enableChannel(state==Qt::Checked, C_GREEN);
}

void DCSRemap::blueChecked(int state)
{
    ui.rawImage->enableChannel(state==Qt::Checked, C_BLUE);
}

void DCSRemap::rawRenderingChanged(bool checked)
{
    if (checked)
    {
        if (ui.radioRGB->isChecked())
            ui.rawImage->setRawRenderingType(R_RGB);
        else if (ui.radioComposite->isChecked())
            ui.rawImage->setRawRenderingType(R_COMPOSITE_COLOUR);
        else if (ui.radioCompGray->isChecked())
            ui.rawImage->setRawRenderingType(R_COMPOSITE_GRAY);
    }
}

void DCSRemap::adjustContrastMidpoint(int value)
{
    double midpoint = (double)value/ui.sldrContrastPoint->maximum();
    if (midpoint==0.0)
        midpoint=0.01;
    if (midpoint==1.0)
        midpoint=0.99;
    ui.rawImage->setContrMidpoint(midpoint);
}

void DCSRemap::adjustContrast(int value)
{
    // make contrast rise nonlinear - slower initially and faster towards end
    ui.rawImage->setContrCorr(pow((double)value/ui.sldrContrast->maximum(), 1.41));
}

void DCSRemap::adjustExposure(double value)
{
    QObject *sender = QObject::sender();
    double factor = pow(2, value);

    if (sender==expControls[C_ALL])
        ui.rawImage->setExpCorr(factor, C_ALL);
    else if (sender==expControls[C_RED])
        ui.rawImage->setExpCorr(factor, C_RED);
    else if (sender==expControls[C_GREEN])
        ui.rawImage->setExpCorr(factor, C_GREEN);
    else if (sender==expControls[C_BLUE])
        ui.rawImage->setExpCorr(factor, C_BLUE);
    else if (sender==expControls[C_GREEN2])
        ui.rawImage->setExpCorr(factor, C_GREEN2);
}

void DCSRemap::adjustBlack(int value)
{
    QObject *sender = QObject::sender();

    if (sender==ui.spinBlckRed)
        ui.rawImage->setBlack(value, C_RED);
    else if (sender==ui.spinBlckGreen)
        ui.rawImage->setBlack(value, C_GREEN);
    else if (sender==ui.spinBlckBlue)
        ui.rawImage->setBlack(value, C_BLUE);
    else if (sender==ui.spinBlckGreen2)
        ui.rawImage->setBlack(value, C_GREEN2);
}

void DCSRemap::adjustThreshold(int value)
{
    if (lockThresChange)
        return;

    QObject *sender = QObject::sender();
    EChannel channel = C_ALL;
    if (sender==ui.spbThrRed)
        channel = C_RED;
    else if (sender==ui.spbThrGreen)
        channel = C_GREEN;
    else if (sender==ui.spbThrBlue)
        channel = C_BLUE;
    else if (sender==ui.spbThrGreen2)
        channel = C_GREEN2;

    if (channel!=C_ALL)
    {
        threshold[channel] = value;
        updateThresholdStats(channel);
    }
}

void DCSRemap::adaptiveRemapModeChecked(int state)
{
    ui.frmAdaptiveBlock->setEnabled(state==Qt::Checked);
    updateThresholdStats(C_ALL);
}

void DCSRemap::adjustAdaptiveBlockSize(int value)
{
    updateThresholdStats(C_ALL);
}

void DCSRemap::setWB()
{
    ui.rawImage->pauseUpdates(true);

    ui.expRedSpin->setValue(log(camWB[DaylightIllum][C_RED])/log(2.0));
    ui.expGreenSpin->setValue(log(camWB[DaylightIllum][C_GREEN])/log(2.0));
    ui.expBlueSpin->setValue(log(camWB[DaylightIllum][C_BLUE])/log(2.0));
    ui.expGreen2Spin->setValue(log(camWB[DaylightIllum][C_GREEN2])/log(2.0));

    ui.rawImage->setWB(camWB[DaylightIllum]);

    ui.rawImage->pauseUpdates(false);
}

void DCSRemap::resetAdjustments()
{
    ui.rawImage->pauseUpdates(true);

    ui.sldrContrast->setValue(0);
    ui.sldrContrastPoint->setValue(ui.sldrContrastPoint->maximum()/2);

    ui.expAll->setValue(0);
    ui.expRed->setValue(0);
    ui.expGreen->setValue(0);
    ui.expBlue->setValue(0);
    ui.expGreen2->setValue(0);

    ui.spinBlckRed->setValue(0);
    ui.spinBlckGreen->setValue(0);
    ui.spinBlckBlue->setValue(0);
    ui.spinBlckGreen2->setValue(0);

    ui.rawImage->resetAllCorrections();
    ui.rawImage->pauseUpdates(false);
}

void DCSRemap::updateDefectStats()
{
    QString fmtStr("%1");

    if (!ui.rawImage->hasDefects())
        return;

    ui.lblStPoints->setText(fmtStr.arg(ui.rawImage->getDefectPoints()));
    ui.lblStCols->setText(fmtStr.arg(ui.rawImage->getDefectCols()));
    ui.lblStRows->setText(fmtStr.arg(ui.rawImage->getDefectRows()));

    // update ISO labels
    for (int i=0; i<DCSDefects::ISO_COUNT; i++)
        if (ui.rawImage->hasDefectsForIso(i))
            ui.cboxISO->setItemIcon(i, tickIcon);
        else
            ui.cboxISO->setItemIcon(i, tickEmptyIcon);
}

void DCSRemap::updateStatus(uint16 row, uint16 col)
{
    QString fmtStr("%1");
    EChannel channel = ui.rawImage->getRawColor(row,col);
    uint16 value = ui.rawImage->getRawValue(row,col);
    ERawRendering curRendMode = ui.rawImage->getRawRenderingType();

    ui.lblStRow->setText(fmtStr.arg(row, -5));
    ui.lblStCol->setText(fmtStr.arg(col, -5));

    // pattern is
    //    G R
    //    B G
    switch (channel)
    {
        case C_RED:
            ui.lblStR->setText(fmtStr.arg(value, -5));
            if (curRendMode==R_RGB)
            {
                uint16 green = (ui.rawImage->getRawValue(row,col-1)+
                                ui.rawImage->getRawValue(row+1,col) + 1)>>1;

                ui.lblStG->setText(fmtStr.arg(green, -5));
                ui.lblStB->setText(fmtStr.arg(ui.rawImage->getRawValue(row+1,col-1), -5));
                ui.lblStG2->setText(fmtStr.arg(green, -5));
            }
            else
            {
                ui.lblStG->setText(fmtStr.arg(0, -5));
                ui.lblStB->setText(fmtStr.arg(0, -5));
                ui.lblStG2->setText(fmtStr.arg(0, -5));
            }
            break;
        case C_GREEN:
            if (curRendMode==R_RGB)
            {
                uint16 green = (value+ui.rawImage->getRawValue(row+1,col+1) + 1)>>1;
                ui.lblStR->setText(fmtStr.arg(ui.rawImage->getRawValue(row,col+1), -5));
                ui.lblStG->setText(fmtStr.arg(green, -5));
                ui.lblStB->setText(fmtStr.arg(ui.rawImage->getRawValue(row+1,col), -5));
                ui.lblStG2->setText(fmtStr.arg(green, -5));
            }
            else
            {
                ui.lblStR->setText(fmtStr.arg(0, -5));
                ui.lblStG->setText(fmtStr.arg(value, -5));
                ui.lblStB->setText(fmtStr.arg(0, -5));
                ui.lblStG2->setText(fmtStr.arg(0, -5));
            }
            break;
        case C_BLUE:
            ui.lblStB->setText(fmtStr.arg(value, -5));
            if (curRendMode==R_RGB)
            {
                uint16 green = (ui.rawImage->getRawValue(row-1,col)+
                                ui.rawImage->getRawValue(row,col+1) + 1)>>1;
                ui.lblStR->setText(fmtStr.arg(ui.rawImage->getRawValue(row-1,col+1), -5));
                ui.lblStG->setText(fmtStr.arg(green, -5));
                ui.lblStG2->setText(fmtStr.arg(green, -5));
            }
            else
            {
                ui.lblStR->setText(fmtStr.arg(0, -5));
                ui.lblStG->setText(fmtStr.arg(0, -5));
                ui.lblStG2->setText(fmtStr.arg(0, -5));
            }
            break;
        case C_GREEN2:
            if (curRendMode==R_RGB)
            {
                uint16 green = (value+ui.rawImage->getRawValue(row-1,col-1) + 1)>>1;
                ui.lblStR->setText(fmtStr.arg(ui.rawImage->getRawValue(row-1,col), -5));
                ui.lblStG->setText(fmtStr.arg(green, -5));
                ui.lblStB->setText(fmtStr.arg(ui.rawImage->getRawValue(row,col-1), -5));
                ui.lblStG2->setText(fmtStr.arg(green, -5));
            }
            else
            {
                ui.lblStR->setText(fmtStr.arg(0, -5));
                ui.lblStG->setText(fmtStr.arg(0, -5));
                ui.lblStB->setText(fmtStr.arg(0, -5));
                ui.lblStG2->setText(fmtStr.arg(value, -5));
            }
            break;
        case C_ALL:
            break;
    }
}

void DCSRemap::green2Checked(int state)
{
    ui.rawImage->enableChannel(state==Qt::Checked, C_GREEN2);
}

void DCSRemap::pointDefectModeChecked(bool checked)
{
    if (lockModeChange)
        return;

    if (checked)
    {
        // points remap on
        ui.rawImage->setDefectSettingMode(M_POINT);
        lockModeChange = true;
        ui.btnColMode->setChecked(false);
        ui.btnRowMode->setChecked(false);
        lockModeChange = false;

        if (ui.chkShowPoints->checkState()!=Qt::Checked)
            ui.chkShowPoints->setCheckState(Qt::Checked);
    }
    else
        ui.rawImage->setDefectSettingMode(M_NONE);
}

void DCSRemap::rowDefectModeChecked(bool checked)
{
    if (lockModeChange)
        return;

    if (checked)
    {
        // rows remap on
        ui.rawImage->setDefectSettingMode(M_ROW);
        lockModeChange = true;
        ui.btnColMode->setChecked(false);
        ui.btnPointMode->setChecked(false);
        lockModeChange = false;

        if (ui.chkShowRows->checkState()!=Qt::Checked)
            ui.chkShowRows->setCheckState(Qt::Checked);
    }
    else
        ui.rawImage->setDefectSettingMode(M_NONE);
}

void DCSRemap::colDefectModeChecked(bool checked)
{
    if (lockModeChange)
        return;

    if (checked)
    {
        // cols remap on
        ui.rawImage->setDefectSettingMode(M_COL);
        lockModeChange = true;
        ui.btnPointMode->setChecked(false);
        ui.btnRowMode->setChecked(false);
        lockModeChange = false;

        if (ui.chkShowCols->checkState()!=Qt::Checked)
            ui.chkShowCols->setCheckState(Qt::Checked);
    }
    else
        ui.rawImage->setDefectSettingMode(M_NONE);
}

void DCSRemap::changeDefColour(QColor* colour)
{
    if (!colour)
    {
        QColor tmpColour = QColorDialog::getColor(defectColour,
                                                  0,
                                                  tr("Choose colour for displaying defects"));

        if (tmpColour.isValid())
        {
            defectColour = tmpColour;
            colour = &defectColour;
        }
    }

    if (colour)
    {
        ui.rawImage->setDefectColour(*colour);

        QPalette palette = ui.btnDefColour->palette();

        palette.setColor(QPalette::Button, *colour);

        ui.btnDefColour->setPalette(palette);
    }
}

void DCSRemap::showPreRemapChecked(int state)
{
    ui.rawImage->enablePreRemap(state==Qt::Checked);
    updateDefectStats();
}

void DCSRemap::showPointsChecked(int state)
{
    ui.rawImage->enableDefPoints(state==Qt::Checked);

    if (state!=Qt::Checked && ui.btnPointMode->isChecked())
        ui.btnPointMode->setChecked(false);

    updateDefectStats();
}

void DCSRemap::showRowsChecked(int state)
{
    ui.rawImage->enableDefRows(state==Qt::Checked);

    if (state!=Qt::Checked && ui.btnRowMode->isChecked())
        ui.btnRowMode->setChecked(false);

    updateDefectStats();
}

void DCSRemap::showColsChecked(int state)
{
    ui.rawImage->enableDefCols(state==Qt::Checked);

    if (state!=Qt::Checked && ui.btnColMode->isChecked())
        ui.btnColMode->setChecked(false);

    updateDefectStats();
}

void DCSRemap::defectsChanged()
{
    if (!defects)
        return;
    updateDefectStats();
    unsavedChanges = true;
    updateWidgets();
}

void DCSRemap::setIso(int cbIndex)
{
    ui.rawImage->setIsoCode(cbIndex);
    updateDefectStats();
}

// -------------------------------------------------------------------------
//   Fusion proxy style to disable stupid QStyle::SH_ComboBox_Popup
// -------------------------------------------------------------------------
class DCSProxyStyle : public QProxyStyle
{
public:
    DCSProxyStyle(QStyle *style): QProxyStyle(style) {}

    int styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget, QStyleHintReturn *returnData) const
    {
        if (hint == QStyle::SH_ComboBox_Popup)
        {
            return 0;
        }
        return QProxyStyle::styleHint(hint, option, widget, returnData);
    }

    void polish (QWidget *w)
    {
#ifdef Q_OS_MACX
        QMenu* mn = qobject_cast<QMenu*>(w);
        if (!mn && !w->testAttribute(Qt::WA_MacNormalSize))
            w->setAttribute(Qt::WA_MacSmallSize);
#endif
    }
};

// -------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if QT_VERSION >= 0x050000
	app.setStyle(new DCSProxyStyle(QStyleFactory::create("fusion")));
#endif

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(83,83,83));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(63,63,63));
    palette.setColor(QPalette::AlternateBase, QColor(83,83,83));
    palette.setColor(QPalette::ToolTipBase, QColor(94,180,255));
    palette.setColor(QPalette::ToolTipText, Qt::black);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(83,83,83));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Highlight, QColor(51,153,255));
    palette.setColor(QPalette::HighlightedText, Qt::black);

    palette.setColor(QPalette::Disabled, QPalette::WindowText, Qt::gray);
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::gray);

    app.setPalette(palette);


    DCSRemap remapMain;
    remapMain.show();

    return app.exec();
}
