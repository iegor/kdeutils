/***************************************************************************
                          lmsensordisplay.cpp  -  description
                             -------------------
    begin                : Sat Aug 11 2001
    copyright            : (C) 2001 by 
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "lmsensorpanel.h"

LMSensorPanel::LMSensorPanel(Sensor *newSensor, QWidget *parent, const char *name ) : Panel(parent,name)
{
 alarm= false;
 //
 sensor= newSensor;
 //
 createTitleWidget();
 createGraphicWidget();
 createValueWidget();
 //
 updateConfig();
 //
 connect( sensor, SIGNAL(valueChanged(double)) , this, SLOT(setValue(double)) );
 connect( sensor, SIGNAL(configChanged())      , this, SLOT(updateConfig()) );
 //
}

LMSensorPanel::~LMSensorPanel()
{
}

void LMSensorPanel::updateConfig()
{
 switch(sensor->getType())
 {
   case Sensor::lmTemp:
     if(arc) {
       arc->setValueRanges(sensor->celsiusTo(0),sensor->celsiusTo(100));
       arc->setValueMinLimit( sensor->getValueMin(),0);
       arc->setValueMaxLimit( sensor->getValueMax(),15);
       arc->setColorRanges(red,green,red);
     }
     switch( sensor->getTempScale() )
     {
      case Sensor::dgKelvin: valMask= "%.0fK"; break;
      default              : valMask= "%.0f^"; break;
     }
     break;

   case Sensor::lmFan :
     if(arc) {
       arc->setValueRanges(0,10000);
       arc->setValueMinLimit( sensor->getValueMin(),15);
       arc->setValueMaxLimit( sensor->getValueMax(),0);
       arc->setColorRanges(red,green,green);
     }
     valMask= "%.0f RPM";
     break;

   case Sensor::lmVoltage :
     if(arc) {
       double min= sensor->getValueMin();
       double max= sensor->getValueMax();
       arc->setValueRanges( min - (max-min)/3, max + (max-min)/3 );
       arc->setValueMinLimit( min,10);
       arc->setValueMaxLimit( max,10);
       arc->setColorRanges(blue,QColor(0,200,150),blue);
       arc->setArrowColor(darkBlue);
     }
     valMask= "%.2fv";
     break;

 }
 setValue(sensor->getValue());
 arc->update();
 lcdVal->update();
 lcdDes->display(sensor->getDescription());
}


void LMSensorPanel::setValue(double value)
{
QString str;

 str.sprintf(valMask.latin1(),value);
 lcdVal->display(str);
 arc->setValue(value);
 //
 bool newAlarm= sensor->getAlarm();
 if(newAlarm!=alarm) {
   alarm= newAlarm;
   if(newAlarm) {
     startTimer(500);
     lcdVal->setForeColor(red);
   } else {
     killTimers();
     lcdVal->setForeColor(black);
     if(lcdVal->isHidden()) lcdVal->show();
   }
 }
}

//**********************************************************************


void LMSensorPanel::createTitleWidget()
{
 lcdDes = new QLCDString(this);
 lcdDes->setNumberDisplay(true);
 lcdDes->installEventFilter(this);
}


void LMSensorPanel::createGraphicWidget()
{
 arc = new QDialArc(this);
 arc->installEventFilter(this);
 arc->setAngles(180,-180);
}


void LMSensorPanel::createValueWidget()
{
 lcdVal = new QLCDString(this);
 lcdVal->installEventFilter(this);
 lcdVal->setShadow(true);
 lcdVal->setNumberDisplay(sensor->getType()==Sensor::lmVoltage);
}


void LMSensorPanel::resizeEvent ( QResizeEvent *e )
{
 int w= width();
 int h= height();

 int i1= (h * 2) / 5;
 int i2= (h * 4) / 5;

 if(sensor->getType()==Sensor::lmVoltage)  lcdVal->setGeometry( 3 , h/8 , w -4  , h/5-h/32);
 else                                      lcdVal->setGeometry( 3 , h/8 , w -4  , h/4-h/16);
 arc->setGeometry   ( 3 , i1  , w -6 , i2-i1-2);
 lcdDes->setGeometry( 3 , i2+1, w -6 , h -i2-h/11);
}

void LMSensorPanel::timerEvent( QTimerEvent * )
{
  if(lcdVal->isVisible()) lcdVal->hide();
  else	 			 		    	  lcdVal->show();
  repaint();
}


void LMSensorPanel::paletteChange(const QPalette &oldPalette)
{
 lcdDes->setForeColor(getColorTitle());
 lcdVal->setForeColor(getColorValue());
 lcdVal->setShadowColor(getColorValue());
 arc->setArrowColor(getColorValue());
}
