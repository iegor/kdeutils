/***************************************************************************
                          LMSensors.h  -  description
                             -------------------
    begin                : Mon Aug 6 2001
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

#ifndef LMSENSORS_H
#define LMSENSORS_H

#include <qobject.h>
#include <qobjectlist.h>
#include <kconfig.h>
#include <qstringlist.h>

#include <sensors/sensors.h>

#include "lmsensorschip.h"
#include "hdsensorslist.h"
#include "i8ksensorslist.h"
/**
  *@author Michael
  */

class LMSensors : public QObject
{
Q_OBJECT

  friend class LMSensor;

public:

	LMSensors(QObject *parent=0, const char *name=0);
	~LMSensors();

  void setMonitorized(bool enable);
  QObjectList   *getSensorsChips()                { return (QObjectList *)children(); };
  SensorsList   *getSensorsChip(int index)        { return children() ? (SensorsList *)((QObjectList *)children())->at(index) : 0; }
  SensorsList   *getSensorsChip(const char *name) { return (SensorsList *)child(name); }
  int count() 									                  { return children() ? children()->count() : 0; }
  Sensor *getSensor(const char *name);

  void emitConfigChanged(const char *name=0)        { emit configChanged(name); }

signals:

  void valueChanged(Sensor *);
  void configChanged(const char *name);

private:

  bool initSensors();
  void createLMSensors();
  void createHDSensors();
  void createI8KSensors();
  void childEvent ( QChildEvent *e );

#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
  static int existSensor(const sensors_chip_name *chip_name,const char *sensor_name);
#endif
};

#endif
