/***************************************************************************
                          i8ksensorslist.h  -  description
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

#ifndef I8KSENSORSLIST_H
#define I8KSENSORSLIST_H

#include <sensorslist.h>

/**
  *@author Miguel Novas
  */

class I8KSensorsList : public SensorsList  {
Q_OBJECT
public:

  I8KSensorsList(QObject *parent, const char * name);
  ~I8KSensorsList();


  static bool I8KAvailable();

public slots:

  void updateSensors();

private:

  bool i8kAvail;
  bool acpiAvail;

  Sensor *cpuTempAcpi;
  Sensor *cpuTemp;
  Sensor *leftFan;
  Sensor *rightFan;

  static int AcpiAvailable();
  static int I8KOnlyAvailable();
};

#endif
