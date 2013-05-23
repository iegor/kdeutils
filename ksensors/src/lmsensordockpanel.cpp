/***************************************************************************
                    lmsensordockpanel.cpp  -  description
                             -------------------
    begin                : Tue Sep 18 2001
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


#include <qpixmap.h>

#include <kstddirs.h>
#include <klocale.h>
#include <kconfig.h>
#include <kiconloader.h>

#include "lmsensordockpanel.h"

LMSensorDockPanel::LMSensorDockPanel(Sensor *newSensor, const char *name) : KSystemTray( 0, name )
{
 strValue   = "";
 if(newSensor) {
    sensor= newSensor;
    updateConfig();
    connect( newSensor, SIGNAL(valueChanged(double)) , this, SLOT(setValue(double)) );
    connect( newSensor, SIGNAL(configChanged())      , this, SLOT(updateConfig()) );
    setPixmap(0);	
 } else {
    sensor= 0;
    setPixmap(BarIcon("ksensorsdocked"));
 }
}

LMSensorDockPanel::~LMSensorDockPanel()
{
}

void LMSensorDockPanel::setValue(double value)
{
 if(sensor) {
   switch(sensor->getType()) {
    case Sensor::lmTemp:
      strValue.sprintf("%2.0f",value);
      break;
    case Sensor::lmFan:
      strValue.sprintf("%1.1f",value/1000);
      break;
    case Sensor::lmVoltage:
      strValue.sprintf("%2.1f",value);
      break;
   }
   update();
 }
}


void LMSensorDockPanel::updateConfig()
{
 colorAlarm = readColorAlarm (name());
 colorNormal= readColorNormal(name());
 setValue(sensor->getValue());
}

void LMSensorDockPanel::paintEvent ( QPaintEvent *e )
{
 if(sensor) {
   int w= width();
   int h= height();
   QPainter painter(this);
   QColor color= sensor->getAlarm() ? colorAlarm : colorNormal;
   QColor colorShadow= color.dark(200);
   painter.setPen(color);
   painter.drawLine(2, 2  , w-2,2  );
   painter.drawLine(2, h-3, w-2,h-3);
   painter.setPen(colorShadow);
   painter.drawLine(3, 3  , w-3,3  );
   painter.drawLine(3, h-4, w-3,h-4);
   if(sensor->getType()==Sensor::lmTemp) {
     QLcd::draw(&painter,4,6,w-6, h-12,strValue.latin1(),QLcd::drawShadow,&color,&colorShadow);
   } else {
     QLcd::draw(&painter,1,7,w-1, h-14,strValue.latin1(),QLcd::drawNumber|QLcd::alignCenter|QLcd::drawShadow,&color,&colorShadow);
   }
 } else {
   KSystemTray::paintEvent(e);
 }
}

void LMSensorDockPanel::mousePressEvent ( QMouseEvent *e )
{
 emit mouseEvent(e);
}

void LMSensorDockPanel::mouseReleaseEvent ( QMouseEvent *e )
{
 emit mouseEvent(e);
}


//*****************************************************************+

void LMSensorDockPanel::writeColorAlarm(const char *name, const QColor &color)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("colorAlarm",color);
}

void LMSensorDockPanel::writeColorNormal(const char *name,const QColor &color)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("colorNormal",color);
}

QColor LMSensorDockPanel::readColorAlarm(const char *name)
{
 KGlobal::config()->setGroup(name);
 return KGlobal::config()->readColorEntry("colorAlarm" , &red  );
}

QColor LMSensorDockPanel::readColorNormal(const char *name)
{
  KGlobal::config()->setGroup(name);
  return KGlobal::config()->readColorEntry("colorNormal", &darkGreen);
}

void LMSensorDockPanel::writeShowInDock(const char *name, bool fShow)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("showInDock",fShow);
}

bool LMSensorDockPanel::readShowInDock(const char *name)
{
 KGlobal::config()->setGroup(name);
 return KGlobal::config()->readBoolEntry("showInDock", false);
}

