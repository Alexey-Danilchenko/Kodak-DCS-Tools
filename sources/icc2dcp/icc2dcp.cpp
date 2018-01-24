/*
    icc2dcp.cpp - Converts matrix .ICC to matrix .DCP

    Copyright 2015 Alexey Danilchenko
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <string>

#define CMS_DLL
#include <lcms2.h>

#include "dng_camera_profile.h"
#include "dng_file_stream.h"
#include "dng_image_writer.h"
#include "dng_matrix.h"

typedef unsigned char byte;

dng_matrix_3by3 matrix;
std::string cameraModel;
std::string copyright;
std::string description;

dng_vector_3 cameraWhite;

dng_vector_3 D50XYZ(cmsD50X, cmsD50Y, cmsD50Z);

dng_matrix_3by3 getAdaptationMatrix(const dng_vector_3 &whiteFrom,
						            const dng_vector_3 &whiteTo)
{
	
	// Use the linearized Bradford adaptation matrix.
	dng_matrix_3by3 Mb ( 0.8951,  0.2664, -0.1614,
		 		        -0.7502,  1.7135,  0.0367,
		  			     0.0389, -0.0685,  1.0296);
	
	dng_vector_3 w1 = Mb * whiteFrom;
	dng_vector_3 w2 = Mb * whiteTo;
	
	// Negative white coordinates are kind of meaningless.
	w1 [0] = Max_real64 (w1 [0], 0.0);
	w1 [1] = Max_real64 (w1 [1], 0.0);
	w1 [2] = Max_real64 (w1 [2], 0.0);
	
	w2 [0] = Max_real64 (w2 [0], 0.0);
	w2 [1] = Max_real64 (w2 [1], 0.0);
	w2 [2] = Max_real64 (w2 [2], 0.0);

	// Limit scaling to something reasonable.
	dng_matrix_3by3 A;
	
	A [0] [0] = Pin_real64 (0.1, w1 [0] > 0.0 ? w2 [0] / w1 [0] : 10.0, 10.0);
	A [1] [1] = Pin_real64 (0.1, w1 [1] > 0.0 ? w2 [1] / w1 [1] : 10.0, 10.0);
	A [2] [2] = Pin_real64 (0.1, w1 [2] > 0.0 ? w2 [2] / w1 [2] : 10.0, 10.0);
		
	dng_matrix_3by3 B = Invert (Mb) * A * Mb;
	
	return B;
}

bool processIcc(char* iccFileName)
{
    bool success = true;
    cmsHPROFILE hICC = cmsOpenProfileFromFile(iccFileName, "r");
    
    if (!hICC)
    {
        std::cerr << "Error reading \"" << iccFileName << "\" ICC profile!" << std::endl;
        return false;
    }

    if (!cmsIsMatrixShaper(hICC) || cmsGetDeviceClass(hICC) != cmsSigInputClass)
    {
        std::cerr << "The \"" << iccFileName << "\" is not a matrix shaper input profile!" << std::endl;
        success = false;
    }
    else
    {
        char buf[512];
        
        cmsGetProfileInfoASCII(hICC, cmsInfoDescription, "en", "US", buf, 512);
        description = buf;
        cmsGetProfileInfoASCII(hICC, cmsInfoCopyright, "en", "US", buf, 512);
        copyright = buf;
        copyright += " Converted by icc2dcp (c) Alexey Danilchenko";
        
        // read matrix
        cmsCIEXYZ *xyz = 0;

        xyz = (cmsCIEXYZ *)cmsReadTag(hICC, cmsSigRedColorantTag);
        if (xyz)
        {
            matrix[0][0] = xyz->X;
            matrix[1][0] = xyz->Y;
            matrix[2][0] = xyz->Z;
        }
        else
        {
            std::cerr << "Error reading red colourant from matrix profile!" << std::endl;
            success = false;
        }
        xyz = (cmsCIEXYZ *)cmsReadTag(hICC, cmsSigGreenColorantTag);
        if (xyz)
        {
            matrix[0][1] = xyz->X;
            matrix[1][1] = xyz->Y;
            matrix[2][1] = xyz->Z;
        }
        else
        {
            std::cerr << "Error reading green colourant from matrix profile!" << std::endl;
            success = false;
        }
        xyz = (cmsCIEXYZ *)cmsReadTag(hICC, cmsSigBlueColorantTag);
        if (xyz)
        {
            matrix[0][2] = xyz->X;
            matrix[1][2] = xyz->Y;
            matrix[2][2] = xyz->Z;
        }
        else
        {
            std::cerr << "Error reading blue colourant from matrix profile!" << std::endl;
            success = false;
        }
    }
    
    // adapt matrix to D50 XYZ
    if (success)
    {
        // get max white XYZ (whitepoint)
        dng_vector_3 maxRGB(1,1,1);
        dng_vector wp = matrix * maxRGB;

        // adaptation
        matrix = getAdaptationMatrix(wp, D50XYZ) * matrix;
    }
    
    cmsCloseProfile(hICC);
    
    return success;
}

void correctFileName(std::string &fileName)
{
    std::string::iterator iter = fileName.begin();
    while (iter != fileName.end())
    {
        if (*iter == ' ' || *iter == '\\' || *iter == '/')
            *iter = '_';
        ++iter;
    }
}


void createDCP(const char* profName, dng_tone_curve *curve=0, const char* curveName=0)
{
    std::string name = cameraModel;
    name += ' ';
    name += profName;
    if (curve && curveName)
    {
        name += ' ';
        name += curveName;
    }

    std::cout << "   Creating \"" << name << "\" DCP profile" << std::endl;

    // build colour matrix
    dng_matrix_3by3 cm = cameraWhite.AsDiagonal() * Invert(matrix);
    
    // populate the profile
    dng_camera_profile dcp;

    dcp.SetName(name.c_str());
    dcp.SetColorMatrix1(cm);
    dcp.SetForwardMatrix1(matrix);
    dcp.SetCalibrationIlluminant1(lsD65);
    dcp.SetUniqueCameraModelRestriction(cameraModel.c_str());
    dcp.SetCopyright(copyright.c_str());
    dcp.SetEmbedPolicy(pepNoRestrictions);
    if (curve)
        dcp.SetToneCurve(*curve);
    
    // write it to a file 
    std::string fName = name + ".DCP";
    correctFileName(fName);
    try
    {
        dng_file_stream fs(fName.c_str(), true);
        tiff_dng_extended_color_profile writer(dcp);
        writer.Put(fs);
		fs.Flush();
    }
    catch (...) 
    {
        std::cerr << "Error saving \"" << fName << "\" file!" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 7)
    {
        fprintf(stderr,"Converts input (camera) shaper .ICC profile to .DCP profile for Adobe ACR/Lightroom\n");
        fprintf(stderr,"Usage: %s <in file> <DCP profile description> <R> <G> <B> <DCP Camera Model>\n", argv[0]);
        fprintf(stderr,"    <in file>          - input .ICC file - should be shaper profile\n");
        fprintf(stderr,"    <DCP description>  - output profile description (will be used to build filename)\n");
        fprintf(stderr,"    <R>,<G>,<B>        - red, green and blue levels of camera white\n");
        fprintf(stderr,"    <DCP Camera Model> - string describing DCP camera model. For Kodaks examples are:\n");
        fprintf(stderr,"                              Kodak ProBack645\n");
        fprintf(stderr,"                              Kodak DCS Pro SLR/n\n");
        fprintf(stderr,"                              Kodak DCS Pro SLR/c\n");
        return 1;
    }
    
    char* icc_name = argv[1];
    char* dcr_prof_decr = argv[2];

    cameraModel = argv[6];

    cameraWhite[0] = atof(argv[3]);
    cameraWhite[1] = atof(argv[4]);
    cameraWhite[2] = atof(argv[5]);
    
    if (cameraWhite[0]<=0 || cameraWhite[1]<=0 || cameraWhite[2]<=0)
    {
        std::cerr << "Invalid white level specified!" << std::endl;
        return 1;
    }
    
    if (processIcc(icc_name))
    {
        // create single illuminant DCPs
        createDCP(dcr_prof_decr);
        
        // create linear curve profile
        dng_tone_curve linear;
        createDCP(dcr_prof_decr, &linear, "Linear");
    }

    return 0;
}
