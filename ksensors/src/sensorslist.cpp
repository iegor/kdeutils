/***************************************************************************
                          sensorslist.cpp  -  description
                             -------------------
    begin                : mié abr 24 2002
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

#include "sensorslist.h"

#include <kglobal.h>

SensorsList::SensorsList(QObject *parent, const char * name)
                                  : QObject(parent,name)
{
 tempScale= Sensor::dgCelsius;
 updateInterval= 5000;
}

SensorsList::~SensorsList()
{
}


void SensorsList::setMonitorized(bool enable)
{
 if(monitorized!=enable) {
   monitorized= enable;
   if(enable) startTimer( updateInterval );
   else       killTimers();
 }
}

void SensorsList::setUpdateInterval(int seconds)
{
 seconds= seconds*1000;
 if(updateInterval!=seconds) {
    updateInterval= seconds;
    if(monitorized) {
       setMonitorized(false);
       setMonitorized(true);
    }
 }
}

void SensorsList::setTempScale(Sensor::TempScale scale)
{
 if(tempScale!=scale) {
     tempScale= scale;
     QObjectList *list= getSensors();
     if(list)
       for(Sensor *sensor=(Sensor*)list->first(); sensor!=0; sensor= (Sensor*)list->next())
         if(sensor->getType()==Sensor::lmTemp)
           emit sensor->configChanged();
 }
}


void SensorsList::readConfig()
{
 KConfig *ksConfig= KGlobal::config();
 ksConfig->setGroup( name() );
 setUpdateInterval(ksConfig->readNumEntry("UpdateInterval",5));
 QString str= ksConfig->readEntry("Scale" ,"C");
 Sensor::TempScale tempScale;
 if(str=="F") tempScale= Sensor::dgFahrenheit;
 else if(str=="K") tempScale= Sensor::dgKelvin;
      else             tempScale= Sensor::dgCelsius;
 setTempScale(tempScale);
}


void SensorsList::writeConfig()
{
 KConfig *ksConfig= KGlobal::config();
 ksConfig->setGroup( name() );
 ksConfig->writeEntry("UpdateInterval",updateInterval/1000);
 QString str;
 switch(tempScale) {
  case Sensor::dgCelsius   : str='C'; break;
  case Sensor::dgKelvin    : str='K'; break;
  case Sensor::dgFahrenheit: str='F'; break;
 }
 ksConfig->writeEntry("Scale" ,str);
}


//****************************************************************************
// Protected methods
//****************************************************************************

void SensorsList::timerEvent( QTimerEvent * )
{
 updateSensors();
}

//***************

void SensorsList::childEvent ( QChildEvent *e )
{
 if(e->inserted()) {
    connect((Sensor *)e->child(),SIGNAL(configChanged()),this,SLOT(slotConfigChanged()));
    connect((Sensor *)e->child(),SIGNAL(valueChanged(double)) ,this,SLOT(slotValueChanged()));
 }
}

//****************************************************************************
// Protected slots
//****************************************************************************


void SensorsList::slotConfigChanged()
{
 emit configChanged( sender()->name() );
}

void SensorsList::slotValueChanged()
{
 emit valueChanged( (Sensor *)sender() );
}


/*********************************************************************************/
