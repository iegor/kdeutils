/***************************************************************************
                          lmsensorschip.h  -  description
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

#ifndef LMSENSORSCHIP_H
#define LMSENSORSCHIP_H

#include "lmsensor.h"
#include "sensorslist.h"

/**
  *@author Miguel Novas
  */

class LMSensorsChip : public SensorsList
{
Q_OBJECT

  friend class LMSensor;

public:

	LMSensorsChip(const sensors_chip_name *chip=0, QObject *parent=0, const char *name=0);
	~LMSensorsChip();

public slots:

 void updateSensors();

protected:

  const sensors_chip_name *getChipName();

private:

  const sensors_chip_name *chip_name;
  bool initSensorsChip();
  void createSensors();
};


#endif
