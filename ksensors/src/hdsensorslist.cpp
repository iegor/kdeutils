/***************************************************************************
                          hdsensorslist.cpp  -  description
                             -------------------
    begin                : vie abr 26 2002
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

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <qstringlist.h>
#include <klocale.h>
#include <qregexp.h>

#include "sensor.h"
#include "hdsensorslist.h"


HDSensorsList::HDSensorsList(QObject *parent, const char * name): SensorsList(parent,name)
{
 process= 0;

 setDescription( QString(i18n("Hard Disks")) );

 setClass(Sensor::hdSensor);

 readConfig();

 if(!isHddTempInstalled()) return;

 QStringList disks;
 if(!getDisks(disks)) return;

 for(QStringList::Iterator it = disks.begin(); it != disks.end(); ++it ) {
   ProcessExec proc;
   proc << "hddtemp" << "-q";
   proc << *it;
   if(proc.runAndWait()) {
     double value;
     QString str;
     if(getDiskInfo(proc.getStdoutData(),str,value)) {
       Sensor *sensor= new Sensor(this);
       sensor->setType(Sensor::lmTemp);
       sensor->setName(*it);
       sensor->setDescription(str);
       sensor->setValueMax  (40   , Sensor::dgCelsius);
       sensor->setValueMin  ( 0   , Sensor::dgCelsius);
       sensor->setValueIdeal(value, Sensor::dgCelsius);
       sensor->setValue     (value, Sensor::dgCelsius);
       sensor->readConfig();
     }
   }
 }
}

HDSensorsList::~HDSensorsList()
{
 delete process;
}

//*************

void HDSensorsList::updateSensors()
{
 if(process) return;

 QObjectList *list= (QObjectList *)children();
 if(!list) return;

 QStringList params;
 for(Sensor *obj= (Sensor *)list->first(); obj!=0; obj= (Sensor *)list->next())
  if(obj->monitorized())
     params << obj->name();

 if(params.count()>0) {
   process= new ProcessExec;
   *process << "hddtemp" << "-q" << params;
   connect( process, SIGNAL(processExited(KProcess *)), this, SLOT(slotProcessExited(KProcess *)) );
   process->run();
 }
}

void HDSensorsList::slotProcessExited(KProcess *)
{
 QObjectList *list= (QObjectList *)children();

 if (!list) return;

 if (process->outputErrors())
   qWarning("HddTemp Error:\n%s", process->getStdoutData().ascii());

 QStringList buf = QStringList::split(QChar('\n'), process->getStdoutData());
 for(QStringList::Iterator it = buf.begin(); it != buf.end(); ++it ) {
   for(Sensor *obj= (Sensor *)list->first(); obj!=0; obj= (Sensor *)list->next()) {
     QRegExp rx(QString(obj->name()) + QString(":\\s+.+:\\s+(\\d+).*C"));
     if (rx.search((*it)) > -1)
       obj->setValue(rx.cap(1).toDouble(), Sensor::dgCelsius); 
   }
 }
 delete process;
 process= 0;
}

// ***************  Static methods


bool HDSensorsList::getDiskInfo(const QString buf, QString &name, double &value)
{
 QRegExp rx(":\\s+(.+):\\s+(\\d+).*C");

 if (rx.search(buf) > -1) {
   bool ok;
   name = rx.cap(1);
   value = rx.cap(2).toDouble(&ok);
   if (ok)
     return true;
   else
     return false;
 }
 else 
   return false;
}


bool HDSensorsList::isHddTempInstalled()
{
 ProcessExec proc;

 proc << "hddtemp" << "-v" ;
 if(proc.runAndWait()) {
   if(proc.getStdoutData().contains("ERROR")==0) return true;
   qWarning("HddTemp Error:\n%s", proc.getStdoutData().ascii());
 }
 return false;
}

bool HDSensorsList::getDisks(QStringList &disks )
{
  DIR *dir;

  /* Get a listing of the hard drives looking under sysfs first then falling back to /proc/ide */
  if((dir = opendir ("/sys/block")) == NULL)
    if ((dir = opendir ("/proc/ide")) == NULL)
      return false;
  QString str;
  struct dirent *ptr;
  while((ptr= readdir(dir))) {
    if((ptr->d_name[0]=='h' || ptr->d_name[0]=='s') && ptr->d_name[1]=='d') {
       str.sprintf("/dev/%s",ptr->d_name);
       disks << str;
    }
  }
  closedir(dir);
  return true;
}

// ***************

