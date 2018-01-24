struct TLensSetting
{
    uint32      focalLength;        // focal length in mm
    TRational   maxAperture;        // max lens aperture opening
    char        lensDataStr[16];    // lens data string in format: 150mm f/2.8
};

struct TManualLensConfig
{
    uint32          count;        // number of lenses configured (at least 1)
    TLensSetting    settings[21]; // array of lens data settings
};

TManualLensConfig lensSettingData =
{
    21,
    {
        { 0,    {0, 0},   "---"         },  // --- no lens
        { 24,   {40, 10}, "24mm  f/4"   },  // 24mm  f/4
        { 35,   {35, 10}, "35mm  f/3.5" },  // 35mm  f/3.5
        { 45,   {28, 10}, "45mm  f/2.8" },  // 45mm  f/2.8
        { 45,   {35, 10}, "45mm  f/3.5" },  // 45mm  f/3.5
        { 45,   {40, 10}, "45mm  f/4"   },  // 45mm  f/4
        { 50,   {40, 10}, "50mm  f/4"   },  // 50mm  f/4
        { 55,   {28, 10}, "55mm  f/2.8" },  // 55mm  f/2.8
        { 70,   {28, 10}, "70mm  f/2.8" },  // 70mm  f/2.8
        { 80,   {19, 10}, "80mm  f/1.9" },  // 80mm  f/1.9
        { 80,   {28, 10}, "80mm  f/2.8" },  // 80mm  f/2.8
        { 80,   {40, 10}, "80mm  f/4"   },  // 80mm  f/4
        { 110,  {28, 10}, "110mm f/2.8" },  // 110mm f/2.8
        { 120,  {40, 10}, "120mm f/4"   },  // 120mm f/4
        { 145,  {40, 10}, "145mm f/4"   },  // 145mm f/4
        { 150,  {28, 10}, "150mm f/2.8" },  // 150mm f/2.8
        { 150,  {40, 10}, "150mm f/4"   },  // 150mm f/4
        { 200,  {28, 10}, "200mm f/2.8" },  // 200mm f/2.8
        { 210,  {40, 10}, "210mm f/4"   },  // 210mm f/4
        { 300,  {28, 10}, "300mm f/2.8" },  // 300mm f/2.8
        { 500,  {45, 10}, "500mm f/4.5" }   // 500mm f/4.5
    }
};

// array of lens data strings for property
const char* cameraManualLensNames[21] =
{
    lensSettingData.settings[0].lensDataStr,
    lensSettingData.settings[1].lensDataStr,
    lensSettingData.settings[2].lensDataStr,
    lensSettingData.settings[3].lensDataStr,
    lensSettingData.settings[4].lensDataStr,
    lensSettingData.settings[5].lensDataStr,
    lensSettingData.settings[6].lensDataStr,
    lensSettingData.settings[7].lensDataStr,
    lensSettingData.settings[8].lensDataStr,
    lensSettingData.settings[9].lensDataStr,
    lensSettingData.settings[10].lensDataStr,
    lensSettingData.settings[11].lensDataStr,
    lensSettingData.settings[12].lensDataStr,
    lensSettingData.settings[13].lensDataStr,
    lensSettingData.settings[14].lensDataStr,
    lensSettingData.settings[15].lensDataStr,
    lensSettingData.settings[16].lensDataStr,
    lensSettingData.settings[17].lensDataStr,
    lensSettingData.settings[18].lensDataStr,
    lensSettingData.settings[19].lensDataStr,
    lensSettingData.settings[20].lensDataStr
};

uint32 cameraManualLensSetting = 0;   // 000124BC -> 2150

TProperty mamiyaProperties[1] =     // 00014460
{
    { "cameraManualLensSetting", "Manual Lens Data", &cameraManualLensSetting, "Camera Control", 
       LIST, 0x600502, 0, lensSettingData.count-1, 0, &cameraManualLensNames, 0, 0 }
    { "lensSettingData", "lensSettingData", &lensSettingData, 0, 
       BLOCK, 0x20, 0, 0, sizeof(lensSettingData), 0, 0, 0 }
}

const char* lensFileName = "LENS.TXT";

void cameraLensLoad()
{
    char* lensTxt = memoryReserveExt(2000, 0, 0);
    
    if (lensTxt)
    {
        memset(lensTxt, 0, 2000);
        
        if (folderFileLoad(lensFileName, lensTxt, 1999) != 0)
        {
            userDialog("Could not read LENS.TXT from the card!\n",
                       "OK", 0, 0, 0, 0, 0, 0, 0);
        }
        else if (!processLensSettings(lensTxt))
        {
            userDialog("No valid manual lens data is found!\n",
                       "OK", 0, 0, 0, 0, 0, 0, 0);
        }

        memoryRelease(lensTxt);
    }
    else
    {
        userDialog("Out of memory.\a\a",
                   "OK", 0, 0, 0, 0, 0, 0, 0);
    }
}

void cameraLensLoadResource()
{
    firmwareLoadTempResource(lensFileName);

    char* lensTxt = firmwareResourceAddress(lensFileName);
    uint32 lensFileSize = firmwareResourceSize(lensFileName);
    
    lensTxt[lensFileSize-1] = 0;

    if (!processLensSettings(lensTxt))
    {
        userDialog("No valid manual lens data is found!\n",
                   "OK", 0, 0, 0, 0, 0, 0, 0);
    }
    
    firmwareUnloadTempResource(lensFileName);
}

bool processLensSettings(char* lensTxt)
{
    bool loaded = false;
    TManualLensConfig *localLensSetting = 
        memoryReserveExt(sizeof(TManualLensConfig), 0, 0);

    if (localLensSetting)
    {
        // copy the first lens - no lens
        memset(localLensSetting, 0, sizeof(TManualLensConfig));
        memcpy(&localLensSetting->settings[0], 
                &lensSettingData.settings[0], sizeof(TLensSetting));
                
        int curLens = 1;    // 0 idx one is no lens "---"
        
        while (*lensTxt && curLens<=21)
        {
            char* lensStr = lensTxt;

            while (*lensTxt && *lensTxt!='\r' && *lensTxt!='\n')
                ++lensTxt;
            
            if (*lensTxt)
                *lensTxt++ = 0;
            
            // initialise the data
            uint32 fl = 0, apH = 0, apL = 0; 
            
            if (sscanf(lensStr, " %umm f/%u.%u ", &fl, &apH, &apL) == 3 ||
                sscanf(lensStr, " %umm f/%u ", &fl, &apH) == 2)
            {
                // add data if valid
                uint32 apVal = apH*10+apL;

                if (fl > 0 && fl <1000 && apVal > 0 && apVal <= 900)
                {
                    localLensSetting->settings[curLens].focalLength = fl;
                    localLensSetting->settings[curLens].maxAperture = {apVal, 10};
                    
                    char flStr[8];
                    sprintf(flStr, "%umm", fl);
                    if (apL)
                        sprintf(localLensSetting->settings[curLens].lensDataStr,
                                "%3umm f/%u.%u", flStr, apH, apL);
                    else
                        sprintf(localLensSetting->settings[curLens].lensDataStr,
                                "%6s f/%u", flStr, apH);
                                
                    ++curLens;
                }
            }
        }
        
        if (curLens > 1)
        {
            localLensSetting->count = curLens;
            memcpy(&lensSettingData, localLensSetting, sizeof(TManualLensConfig));
            
            // update properties
            propertySave(lensSettingData);
            cameraManualLensSetting = 0;
            propertyMaxSet(cameraManualLensSetting, lensSettingData.count-1);
            // may not need this
            // propertyListSet(cameraManualLensSetting, &cameraManualLensNames);
            loaded = true;
        }
        
        memoryRelease(localLensSetting);
    }
    else
    {
        userDialog("Out of memory.\a\a",
                   "OK", 0, 0, 0, 0, 0, 0, 0);
        loaded = true;
    }
        
    return loaded;
}