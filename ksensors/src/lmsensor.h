/***************************************************************************
                          lmsensor.h  -  description
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

#ifndef LMSENSOR_H
#define LMSENSOR_H

#include <qobject.h>
#include <kconfig.h>
#include <qstring.h>
#include <qcstring.h>

#include <sensors/sensors.h>
#include "sensor.h"


class LMSensorsList;

/**
  *@author Miguel Novas
  */

class LMSensor : public Sensor  {
  Q_OBJECT

  friend class LMSensorsChip;

public:

  LMSensor(SensorsList *parent=0);
	~LMSensor();

public slots:

  void updateValue();

protected:

  double calculateIdealValue();

#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
  bool init(const sensors_feature_data **data, int *nr1,int *nr2);
#else
  bool init(const sensors_feature **data, int *nr1,int *nr2);
#endif
  const sensors_chip_name *getChipName();

private:

   int        feature;
   SensorType type;
   QString    description;
   double     val;
   double     valPrevious;
   double     compensation;
   double     multiplicator;
   double     valMax;
   double     valMin;
   double     valIdeal;
   bool       monitorize;
   double readSensorValue();
};

#endif
