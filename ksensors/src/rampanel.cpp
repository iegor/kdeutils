/***************************************************************************
                          rampanel.cpp  -  description
                             -------------------
    begin                : Fri Jan 11 2002
    copyright            : (C) 2002 by Miguel Novas
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

#include "rampanel.h"

#include "procinfo.h"

RamPanel::RamPanel(QWidget *parent, const char *name, RamType type): Panel(parent,name)
{
 ramType= type;
 memTotal= -1;
 memUsed = -1;

 arc = new QDialArc(this);
 arc->installEventFilter(this);
 arc->setAngles(180,-180);
 arc->setGeometry( 6 , 64/4+9, 64-10, 64/2-8);
 arc->setColorRanges(red,red,QColor(0,200,150)); // QColor(0,200,0));

 lcd1= new QLCDString(this);
 lcd1->setGeometry(6, 8,54,11);
 lcd1->setShadow(true);
 lcd1->setForeColor(getColorValue());
 lcd1->setAlign(QLCDString::alignCenter);
 lcd1->installEventFilter(this);

 lcd2= new QLCDString(this);
 lcd2->setGeometry(4, 52,58,8);
 lcd2->setForeColor(getColorTitle());
 lcd2->setAlign(QLCDString::alignCenter);
 lcd2->installEventFilter(this);

 updateInfo();
}

RamPanel::~RamPanel(){
}


void RamPanel::updateInfo()
{
 int newMemTotal,newMemUsed,newSwapTotal,newSwapUsed;

 getMemInfo(&newMemTotal,&newMemUsed,&newSwapTotal,&newSwapUsed);

 if(ramType==memSWAP) {
    newMemTotal= newSwapTotal;
    newMemUsed = newSwapUsed;
 }

 newMemUsed /=1024;
 newMemTotal/=1024;

 if(memTotal!=newMemTotal) {
    arc->setValueRanges(0,newMemTotal);
    QString str;
    str.sprintf ( ramType==memSWAP ? "SWP %dM" : "RAM %dM", newMemTotal);
    lcd2->display(str);
    memTotal= newMemTotal;
 }

 if(memUsed!=newMemUsed)  {
    QString str;
    str.sprintf ("%dM" , newMemUsed );
    lcd1->display(str);
    arc->setValue(newMemUsed);
    arc->setValueLimitRanges(newMemUsed,newMemUsed);
    memUsed = newMemUsed;
 }

}


void RamPanel::paletteChange(const QPalette &oldPalette)
{
 lcd2->setForeColor(getColorTitle());
 lcd1->setForeColor(getColorValue());
 arc->setArrowColor(getColorValue());
}

void RamPanel::resizeEvent ( QResizeEvent *e )
{
 int w= width();
 int h= height();

 int i1= (h * 2) / 5;
 int i2= (h * 4) / 5;

 lcd1->setGeometry( 3 , h/8 , w -4  , h/4-h/16);
 arc ->setGeometry( 3 , i1  , w -6 , i2-i1-2  );
 lcd2->setGeometry( 3 , i2+1, w -6 , h-i2-h/11);
}
