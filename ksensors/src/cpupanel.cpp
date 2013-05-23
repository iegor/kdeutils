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

#include "cpupanel.h"
#include "qlcddraw.h"

#include <qcolor.h>
#include <qpainter.h>
#include <qlcdnumber.h>

#include <string.h>

bool getCpuInfoValue(const char *name,QString &value)
{
char buffer[128];
char *ptr;
FILE *fp;
bool result;

 result= false;
 if( (fp= fopen("/proc/cpuinfo","r")) ) {
   while( fgets(buffer, 127, fp) ) {
     if(!strncmp(name,buffer,strlen(name))) {
        ptr= strchr(buffer,':');
        if(ptr) {
          value= (const char *)(ptr+2);
          value = value.stripWhiteSpace();
        }
        result= true;
        break;
     }
   }
  fclose(fp);
 }
 return result;
}

void  adjustString(QString &str,int maxlen)
{
int i= str.find('(');

 str.truncate(maxlen);
 if(i>=0) str.truncate(i);
 str= str.stripWhiteSpace();
}

CpuPanel::CpuPanel(QWidget *parent, const char *name) : Panel(parent,name)
{
 sCpu= "Unknown";
 getCpuInfoValue("model name",sCpu);
 adjustString(sCpu,16);

 sVendor= "Unknown";
 getCpuInfoValue("vendor_id",sVendor);
 adjustString(sVendor,16);

 sBogomips= "0";
 getCpuInfoValue("bogomips",sBogomips);
 sBogomips.sprintf("%.0f BMPS",sBogomips.toDouble());

 QString sSpeed= "0";
 getCpuInfoValue("cpu MHz",sSpeed);
 sSpeed.sprintf("%.0f",sSpeed.toDouble());
 speed= new QLCDNumber(this);
 speed->setGeometry(6,20,52,26);
 speed->setNumDigits(sSpeed.length());
 speed->setSegmentStyle(QLCDNumber::Filled);
 speed->setFrameShape(QFrame::NoFrame);
 speed->display(sSpeed);
 QPalette cg= speed->palette();
 cg.setColor( QColorGroup::Foreground, QColor( 255, 0, 0) );
 cg.setColor( QColorGroup::Light, QColor( 255, 0, 0) );
 cg.setColor( QColorGroup::Midlight, QColor( 231, 232, 246) );
 cg.setColor( QColorGroup::Dark, QColor( 104, 105, 118) );
 cg.setColor( QColorGroup::Mid, QColor( 139, 140, 158) );
 cg.setColor( QColorGroup::Background, palette().active().background() );
 speed->setPalette(cg);
 speed->installEventFilter(this);
}

CpuPanel::~CpuPanel()
{
}

void CpuPanel::updateInfo()
{
 getCpuInfoValue("bogomips",sBogomips);
 sBogomips.sprintf("%.0f BMPS",sBogomips.toDouble());

 getCpuInfoValue("cpu MHz",sSpeed);
 sSpeed.sprintf("%.0f",sSpeed.toDouble());
 speed->setNumDigits(sSpeed.length());
 speed->display(sSpeed);
 update();
}

void CpuPanel::drawContents(QPainter *p)
{
 int w= width();
 int h= height();

 int i2= (h * 4) / 5;
 int th= h-i2-h/11;

 QLcd::draw(p, 2,h/10,w-4,th,sCpu.latin1(),QLcd::alignJustify, &getColorTitle());
 QLcd::draw(p, 2,i2+1,w-4,th,sBogomips.latin1(),QLcd::alignCenter,&getColorTitle());
}

void CpuPanel::paletteChange( const QPalette &oldPalette)
{
QPalette cg= speed->palette();

 cg.setColor(QColorGroup::Background,palette().active().background());
 speed->setPalette(cg);
}


void CpuPanel::resizeEvent ( QResizeEvent *e )
{
 int w= width();
 int h= height();

 int mw= w/10;

 speed->setGeometry(mw,h/3,w-mw*2,(h*2)/5);
}
