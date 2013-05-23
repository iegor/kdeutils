/***************************************************************************
                          lmsensorsalarms.cpp  -  description
                             -------------------
    begin                : Wed Nov 14 2001
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


#include <stdlib.h>

#include <qstring.h>
#include <kglobal.h>
#include <kprocess.h>
#include <kaudioplayer.h>
#include "lmsensorsalarms.h"




LMSensorsAlarms::LMSensorsAlarms(LMSensors *sensors, QObject *parent, const char *name)
                                : QObject(parent,name)
{
 sensorCount= 0;
 soundPlay  = "";
 connect( sensors, SIGNAL(valueChanged(Sensor *)) , this, SLOT(setValueChanged(Sensor *)) );
}

LMSensorsAlarms::~LMSensorsAlarms()
{
}

//###########################################################################################


void LMSensorsAlarms::runSensorCommand(const char *name,const char *value, const char *cmd)
{
  setenv("SENSOR_NAME" , name , 1);
  setenv("SENSOR_VALUE", value, 1);
  runCommand( cmd );
}

void LMSensorsAlarms::runCommand(const char *str)
{
KShellProcess p;

 p << str;
 p.start(KShellProcess::DontCare);
 p.detach();
}

void LMSensorsAlarms::playSound(const char *sound)
{
  KAudioPlayer::play(sound);
}

//###########################################################################################

void LMSensorsAlarms::setValueChanged(Sensor *sensor)
{
 if(sensor->getAlarm()) {
    if(!sensor->getAlarmPrevious()) {
       switch ( readAlarm(sensor->name()) )
       {
        case acSound:

           sensorCount++;
           soundPlay= readAlarmSound(sensor->name());
           if(sensorCount==1) startTimer(3000);
           break;

        case acCommand:

           runSensorCommand(
                              (const char *)sensor->getDescription(),
                              (const char *)QString::number(sensor->getValue()),
                              (const char *)readAlarmCommand(sensor->name())
                            );
           break;
       }
    }
 } else {
    if(sensor->getAlarmPrevious()) {
       if( readAlarm(sensor->name())==acSound ) {
          if(--sensorCount==0)  killTimers();
       }
    }
 }
}

void LMSensorsAlarms::timerEvent( QTimerEvent * )
{
 KAudioPlayer::play(soundPlay);
}

//##########################################################################

int LMSensorsAlarms::readAlarm(const char *name)
{
 KGlobal::config()->setGroup(name);
 return KGlobal::config()->readNumEntry("Alarm",acNothing);
}

void LMSensorsAlarms::writeAlarm(const char *name, int alarm)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("Alarm",alarm);
}


QString LMSensorsAlarms::readAlarmCommand(const char *name)
{
 KGlobal::config()->setGroup(name);
 return KGlobal::config()->readEntry("AlarmCommand", "");
}


void LMSensorsAlarms::writeAlarmCommand(const char *name, const QString &cmd)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("AlarmCommand", cmd);
}


QString  LMSensorsAlarms::readAlarmSound(const char *name)
{
 KGlobal::config()->setGroup(name);
 return KGlobal::config()->readEntry("AlarmSound", "ksensors_alert.wav");
}


void  LMSensorsAlarms::writeAlarmSound(const char *name, const QString &cmd)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("AlarmSound", cmd);
}
