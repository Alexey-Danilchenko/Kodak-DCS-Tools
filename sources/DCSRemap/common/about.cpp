/*
    about.h - QT class for About window

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
#include "about.h"

#include <QDesktopServices>
#include <QMouseEvent>
#include <QUrl>
#include <QSettings>

#include "ifdata.h"

// private rand and decode functions

static uint16 seed_ = 0;

inline void randInit(uint16 seed) 
{
    seed_ = seed;
}

inline byte getRand(void) 
{
    const uint16 a = 23719;
	const uint16 c = 18947;
	
	seed_= (a*seed_ + c) & 0xFFFF;

    return seed_ & 0x7F;
}

void decodeStr(byte* str, uint16 seed, int len)
{
	randInit(seed);
	for (int i = 0; i < len; i++)
    {
		*str = *str ^ (getRand()+i);
        
        str++;
	}
    *str = 0;
}

About::About(int language, QWidget *parent): QDialog(parent)
{
    this->language = language;
    ui.setupUi(this);
    
    connect(ui.btnDonate, SIGNAL(clicked()), this, SLOT(donate()));
}

About::~About()
{
}

void About::donate()
{
    char url[200] = "\x72\xe\x0\x14\x3d\x74\x7\x17\xf5\x55\x2b\x22\x46\x17\x69\x10"
                    "\xb\x26\x6a\x57\x71\x73\x57\xeb\x35\x1b\x1\x3e\xef\x28\x4f\x47"
                    "\x5f\xf8\xe7\xe7\x1c\x51\x2b\x35\xc6\x7f\x23\x5f\x7b\xee\x53"
                    "\xec\xe3\x9\xf\x72\x56\x51\xeb\xdc\x17\xf6\x13\x1e\xd3\x12"
                    "\xf4\x3f\x34\xe5\xdd\xc0\xb3\xd6\x3d\x22\x88\x5b\xa4\x4\x41"
                    "\xe1\x18\xee\x99\xbc";
                    
    decodeStr((byte*)url, 17, 82);
    QDesktopServices::openUrl(QUrl(url));
}

void About::mousePressEvent(QMouseEvent* e) 
{
    QWidget* child = childAt(e->x(), e->y());

    if (child == ui.CopyrightLabel || child == ui.mainLabel)
    {
        if (language == QLocale::Russian)
            QDesktopServices::openUrl(QUrl("http://wowcamera.info/viewtopic.php?f=18&t=283"));
        else
            QDesktopServices::openUrl(QUrl("http://dalex-257.livejournal.com/"));
    }
    else if (child == ui.ReflectionLabel) 
    {
        QDesktopServices::openUrl(QUrl("http://www.webdesignerdepot.com/2010/07/200-exclusive-free-icons-reflection/"));
    }
    else if (child == ui.qtLabel)
    {
        QDesktopServices::openUrl(QUrl("http://qt-project.org/"));
    }
    else if (child == ui.libRawLabel)
    {
        if (language == QLocale::Russian)
            QDesktopServices::openUrl(QUrl("http://www.libraw.su/"));
        else
            QDesktopServices::openUrl(QUrl("http://www.libraw.org/"));
    }
    else
	    done(0);
}
