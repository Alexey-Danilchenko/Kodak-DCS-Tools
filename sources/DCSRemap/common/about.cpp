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


About::About(QWidget *parent): QDialog(parent)
{
    ui.setupUi(this);
}

About::~About()
{
}

void About::mousePressEvent(QMouseEvent* e)
{
    QWidget* child = childAt(e->position());

    if (child == ui.ReflectionLabel)
    {
        QDesktopServices::openUrl(QUrl("http://www.webdesignerdepot.com/2010/07/200-exclusive-free-icons-reflection/"));
    }
    else if (child == ui.qtLabel)
    {
        QDesktopServices::openUrl(QUrl("http://qt-project.org/"));
    }
    else if (child == ui.libRawLabel)
    {
        QDesktopServices::openUrl(QUrl("http://www.libraw.org/"));
    }
    else
	    done(0);
}
