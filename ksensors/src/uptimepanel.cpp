/***************************************************************************
                          cpudisplay.cpp  -  description
                             -------------------
    begin                : Sun Nov 25 2001
    copyright            : (C) 2001 by Miguel Novas
    email                : michaell@teleline.es
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "uptimepanel.h"
#include "procinfo.h"
#include "qlcddraw.h"

#include <qcolor.h>
#include <qpainter.h>



UpTimePanel::UpTimePanel(QWidget *parent, const char *name) : Panel(parent,name)
{
 lcd= new QLCDString(this);
 lcd->setGeometry(6,25,52,15);
 lcd->setShadow(true);
 lcd->setForeColor(red);
 lcd->setShadowColor(darkRed);
 lcd->installEventFilter(this);
 updateInfo();
}

UpTimePanel::~UpTimePanel()
{
}

void UpTimePanel::updateInfo()
{
 int uptime= getUpTime();

 int hours  = uptime/ (60*60);
 int minutes= (uptime % (60*60)) / 60;

 QString str;
 str.sprintf("%02d:%02d",hours,minutes);
 lcd->display(str);
 update();
}

void UpTimePanel::drawContents(QPainter *p)
{
 int w= width();
 int h= height();

 int i2= (h * 4) / 5;
 int th= h-i2-h/11;

 QLcd::draw(p, 2,h/10,w-4,th,"hh:mm",QLcd::alignCenter, &getColorTitle());
 QLcd::draw(p, 2,i2+1,w-4,th,"Up Time",QLcd::alignCenter,&getColorTitle());
}

void UpTimePanel::resizeEvent ( QResizeEvent *e )
{
 int w= width();
 int h= height();

 int mw= w/10;

 lcd->setGeometry(mw,h/3,w-mw*2,(h*2)/5);
}
