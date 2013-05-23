/***************************************************************************
                          lmsensorschip.cpp  -  description
                             -------------------
    begin                : Wed Feb 20 2002
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

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sensors/sensors.h>

#include "lmsensorschip.h"

//****************************************************************************
// Public methods
//****************************************************************************

LMSensorsChip::LMSensorsChip(const sensors_chip_name *chip, QObject *parent, const char * name)
                                  : SensorsList(parent,name)
{
 setClass(Sensor::lmSensor);
 chip_name= chip;
 setName( chip_name->prefix );
 setDescription( chip_name->prefix );
 readConfig();
 createSensors();
}

LMSensorsChip::~LMSensorsChip()
{
}

const sensors_chip_name *LMSensorsChip::getChipName()
{
 return chip_name;
}


void LMSensorsChip::createSensors()
{
 if(!chip_name) return;
 int nr1= 0;
 int nr2= 0;
#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
 const sensors_feature_data *data;
 data= sensors_get_all_features(*chip_name, &nr1, &nr2);
#else
 const sensors_feature *data;
 data= sensors_get_features(chip_name, &nr1);
#endif
 while(data) {
   LMSensor *sensor= new LMSensor(this);
   if( !sensor->init(&data,&nr1,&nr2) )
     delete sensor;
 }
}

void LMSensorsChip::updateSensors()
{
QObjectList *sensors= (QObjectList *)children();

 if(sensors)
   for(LMSensor *sensor= (LMSensor *)sensors->first(); sensor!=0; sensor= (LMSensor *)sensors->next())
     if(sensor->monitorized()) sensor->updateValue();
}

