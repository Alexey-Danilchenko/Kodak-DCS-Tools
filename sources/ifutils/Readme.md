This will dump and format known data for all "defect" tags in imager file:

    ifutils.exe -lpfd TEST.IF 0x906-0x908 > defects.txt
    
This will dump and format the defect conceal thresholds from firmware .IPF file 
(extracted from firmware by my BIN_WCX plugin).

    ifutils.exe -lpfd pro14nx.ipf 0xA0A > defectConcThres.txt
    ifutils.exe -lpfd pro14nc.ipf 0xA0A > defectConcThres.txt
    ifutils.exe -lpfd pb645.ipf 0xA0A > defectConcThres.txt