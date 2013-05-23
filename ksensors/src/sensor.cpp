/***************************************************************************
                          sensor.cpp  -  description
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

#include <kglobal.h>

#include "sensor.h"
#include "sensorslist.h"



Sensor::Sensor(SensorsList *parent,const char *name): QObject(parent,name)
{
  description  = "";
  compensation = 0;
  multiplicator= 1;
  monitorize   = false;
}


Sensor::~Sensor(){
}

Sensor::SensorClass Sensor::getClass()
{
return ((SensorsList *)parent())->getClass();
}

QString Sensor::getPrintMask(bool addSufix)
{
 return getSensorPrintMask(type, addSufix, ((SensorsList*)parent())->getTempScale() );
}

const char *Sensor::getSensorPrintMask(int sensorType, bool addSufix, TempScale temp)
{
 if(addSufix) {
    switch(sensorType) {
      case Sensor::lmTemp:
         switch(temp) {
           case dgCelsius   : return "%.0lf C";
           case dgFahrenheit: return "%.0lf F";
           case dgKelvin    : return "%.0lf K";
         }
         break;
      case Sensor::lmFan:     return "%.0lf rpm";
      case Sensor::lmVoltage: return "%.2lfV";
    }
 }
 return sensorType==Sensor::lmVoltage ? ".2lf" : ".0lf";
}

bool Sensor::monitorized()
{
  return monitorize;
}

void Sensor::setMonitorized(bool enable)
{
 if( monitorize!=enable ) monitorize= enable;
}

void Sensor::setValueIdeal(double value, TempScale scale)
{
 valIdeal= toCelsius(value, scale);
}
	
void Sensor::setValueMax(double value, TempScale scale)
{
  valMax= toCelsius(value,scale);
}

void Sensor::setValueMin(double value, TempScale scale)
{
  valMin= toCelsius(value,scale);
}

void Sensor::setCompensation(double value, TempScale scale)
{
  compensation= toCelsiusDiff(value,scale);
}

void Sensor::setMultiplicator(double value)
{
 multiplicator= value;
}

void Sensor::setDescription(const QString &str)
{
 description= str;
}


void Sensor::setValue(double newVal, TempScale scale, bool ajust)
{
 newVal= toCelsius(newVal,scale);
 if (ajust) newVal= adjustValue(newVal);
 if(val!=newVal) {
   valPrevious= val;
   val        = newVal;
   emit valueChanged( celsiusTo(val) );
 }
}



void Sensor::writeConfig()
{
KConfig *ksConfig= KGlobal::config();

  if(ksConfig) {
    ksConfig->setGroup( QString(name()) );
    ksConfig->writeEntry("description"  ,description);
    ksConfig->writeEntry("valueIdeal"   ,valIdeal);
    ksConfig->writeEntry("valueMax"     ,valMax);
    ksConfig->writeEntry("valueMin"     ,valMin);
    ksConfig->writeEntry("compensation" ,compensation);
    ksConfig->writeEntry("multiplicator",multiplicator);
    ksConfig->writeEntry("monitorize"   ,monitorize);
    emit configChanged();
  }
}

void Sensor::readConfig()
{
KConfig *ksConfig= KGlobal::config();

  if(ksConfig) {
    ksConfig->setGroup( QString(name()) );
    valMax       = ksConfig->readDoubleNumEntry("valueMax"     ,valMax);
    valMin       = ksConfig->readDoubleNumEntry("valueMin"     ,valMin);
    compensation = ksConfig->readDoubleNumEntry("compensation" ,compensation);
    multiplicator= ksConfig->readDoubleNumEntry("multiplicator",multiplicator);
    description  = ksConfig->readEntry         ("description"  ,description);
    valIdeal     = ksConfig->readDoubleNumEntry("valueIdeal"   ,valIdeal);
    setMonitorized( ksConfig->readBoolEntry    ("monitorize"   ,monitorize) );
  }
}

double Sensor::toCelsius(double val, TempScale scale)
{
  if(type!=lmTemp) return val;
  switch( scale == dgDefault ? getTempScale(): scale ) {
   case dgCelsius   : return val;
   case dgFahrenheit: return  (5.0/9.0)*(val-32.0);
  }
  return  val - 273.16;  // Kelvin to Celsius
}

double Sensor::celsiusTo(double val, TempScale scale)
{
  if(type!=lmTemp) return val;
  switch( scale==dgDefault ? getTempScale() : scale ) {
   case dgCelsius   : return val;
   case dgFahrenheit: return  (9.0/5.0)*val+32.0;
  }
  return  val + 273.16;  // Celsius to Kelvin
}

double Sensor::toCelsiusDiff(double val, TempScale scale)
{
  if(scale==dgDefault) scale= getTempScale();
  if(type!=lmTemp || scale!=dgFahrenheit ) return val;
  return val*(5.0/9.0);
}

double Sensor::celsiusToDiff(double val, TempScale scale)
{
  if(scale==dgDefault) scale= getTempScale();
  if(type!=lmTemp || scale!=dgFahrenheit ) return val;
  return val*(9.0/5.0);
}

Sensor::TempScale Sensor::getTempScale()
{
 return ((SensorsList *)parent())->getTempScale();
}
