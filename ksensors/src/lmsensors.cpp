/***************************************************************************
                          LMSensors.cpp  -  description
                             -------------------
    begin                : Mon Aug 6 2001
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

#include <stdio.h>

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#include <qstrlist.h>
#include <qobjectlist.h>

#include "lmsensors.h"

//****************************************************************************
// Public methods
//****************************************************************************

LMSensors::LMSensors(QObject *parent, const char * name)
                                  : QObject(parent,name)
{
 if(initSensors()) createLMSensors();
 createI8KSensors();
 createHDSensors();
}

LMSensors::~LMSensors()
{
 if(count()) sensors_cleanup();
}

bool LMSensors::initSensors()
{
#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
 FILE *fp=fopen("/etc/sensors.conf","r");
 if(!fp) {
   qWarning("KSensors error: /etc/sensors.conf not found !");
   return false;
 }
#else
 FILE *fp=NULL;
#endif
 int err= sensors_init(fp);
 if(err) {
   qWarning("KSensors error: sensors_init fail, error code %d",err);
   return false;
 }
#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
 fclose(fp);
#endif
 return true;
}

void LMSensors::createLMSensors()
{
 const sensors_chip_name *chip_name;
 int err= 0;
#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
 while( (chip_name= sensors_get_detected_chips(&err)) )
 {
   if( existSensor(chip_name,"temp")  ||
       existSensor(chip_name,"fan")   )
       {
          (void)new LMSensorsChip(chip_name,this);
       }
 }
#else
 while( (chip_name= sensors_get_detected_chips(NULL, &err)) )
          (void)new LMSensorsChip(chip_name,this);
#endif
}

void LMSensors::createHDSensors()
{
 HDSensorsList *disks= new HDSensorsList(this,"Disks");
 if(disks->count()==0) delete disks;
}

void LMSensors::createI8KSensors()
{
 if(I8KSensorsList::I8KAvailable())
   (void) new I8KSensorsList(this,"I8KSensors");
}


#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
int LMSensors::existSensor(const sensors_chip_name *chip_name,const char *sensor_name)
{
int nr1,nr2;
const sensors_feature_data *sensor_data;

 nr1=nr2= 0;
 while( (sensor_data= sensors_get_all_features(*chip_name, &nr1, &nr2)) )
 {
   if( strstr(sensor_data->name,sensor_name) )
     return sensor_data->number;
 }
 return 0;
}
#endif

void LMSensors::setMonitorized(bool enable)
{
 QObjectList *list= getSensorsChips();
 if(list)
   for(LMSensorsChip *sensor=(LMSensorsChip*)list->first(); sensor!=0; sensor= (LMSensorsChip *)list->next())
     sensor->setMonitorized(enable);
}


Sensor *LMSensors::getSensor(const char *name)
{
 int     index= count();
 Sensor *sensor= 0;
 while(--index>=0 && !sensor) {
    sensor= getSensorsChip(index)->getSensor(name);
 }
 return sensor;
}

void LMSensors::childEvent( QChildEvent *e )
{
 if(e->inserted()) {
    connect((SensorsList *)e->child(),SIGNAL(valueChanged(Sensor *)) ,this,SIGNAL(valueChanged(Sensor  *)));
    connect((SensorsList *)e->child(),SIGNAL(configChanged(const char *)),this,SIGNAL(configChanged(const char *)));
 }
}


/*********************************************************************************/
