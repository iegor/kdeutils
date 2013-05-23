/***************************************************************************
                          i8ksensorslist.cpp  -  description
                             -------------------
    begin                : jue jun 20 2002
    copyright            : (C) 2002 by Miguel Novas
    email                : migueln@users.sourceforge.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <klocale.h>

#include "i8ksensorslist.h"

#include "procinfo.h"




I8KSensorsList::I8KSensorsList(QObject *parent, const char *name): SensorsList(parent,name)
{
  setDescription(QString(i18n("MainBoard")) );

  setClass(Sensor::lmSensor);

  readConfig();

  if ( (i8kAvail = (I8KOnlyAvailable()==0)) )
  {
	cpuTemp= new Sensor(this);
	cpuTemp->setType(Sensor::lmTemp);
	cpuTemp->setName("cputemp");
	cpuTemp->setDescription("CPU Temp");
	cpuTemp->setValueMax  (40 , Sensor::dgCelsius);
	cpuTemp->setValueMin  ( 0 , Sensor::dgCelsius);
	cpuTemp->setValueIdeal(30 , Sensor::dgCelsius);
	cpuTemp->setValue     (30 , Sensor::dgCelsius);
	cpuTemp->readConfig();

	leftFan= new Sensor(this);
	leftFan->setType(Sensor::lmFan);
	leftFan->setName("fan1");
	leftFan->setDescription("Left Fan");
	leftFan->setValueMax  (10000);
	leftFan->setValueMin  (    0);
	leftFan->setValueIdeal( 4500);
	leftFan->setValue     ( 4500);
	leftFan->readConfig();

	rightFan= new Sensor(this);
	rightFan->setType(Sensor::lmFan);
	rightFan->setName("fan2");
	rightFan->setDescription("Right Fan");
	rightFan->setValueMax  (10000);
	rightFan->setValueMin  (    0);
	rightFan->setValueIdeal( 4500);
	rightFan->setValue     ( 4500);
	rightFan->readConfig();
  }

  if ( (acpiAvail=(AcpiAvailable()==0)) )
  {
	cpuTempAcpi= new Sensor(this);
	cpuTempAcpi->setType(Sensor::lmTemp);
	cpuTempAcpi->setName("cputemp");
	cpuTempAcpi->setDescription("CPU Temp");
	cpuTempAcpi->setValueMax  (40 , Sensor::dgCelsius);
	cpuTempAcpi->setValueMin  ( 0 , Sensor::dgCelsius);
	cpuTempAcpi->setValueIdeal(30 , Sensor::dgCelsius);
	cpuTempAcpi->setValue     (30 , Sensor::dgCelsius);
	cpuTempAcpi->readConfig();
  }

  updateSensors();
}

I8KSensorsList::~I8KSensorsList(){
}


void I8KSensorsList::updateSensors()
{
double t,f1,f2;

  if(i8kAvail && !getI8KInfo(&t,&f1,&f2)) {
    cpuTemp->setValue(t,Sensor::dgCelsius);
    leftFan->setValue(f1);
    rightFan->setValue(f2);
  }
  if(acpiAvail && !getAcpiTemperature(&t)) {
    cpuTempAcpi->setValue(t,Sensor::dgCelsius);
  }
}


int I8KSensorsList::AcpiAvailable()
{
 double t;
 return  getAcpiTemperature(&t);
}

int I8KSensorsList::I8KOnlyAvailable()
{
double d1,d2,d3;

  return getI8KInfo(&d1,&d2,&d3);
}

bool I8KSensorsList::I8KAvailable()
{
int result;

 switch(result= I8KOnlyAvailable()) {
  case -2: qWarning("I18K Warning: /proc/i8k format not valid or not supported. Inform the author."); break;
  case -3: qWarning("I18K Warning: Only format version 1.0 is supported. Inform the author.");         break;
 }

 return (result==0 ||  AcpiAvailable()==0);
}



