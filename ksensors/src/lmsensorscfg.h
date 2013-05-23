/***************************************************************************
                          lmsensorscfg.h  -  description
                             -------------------
    begin                : Mon Aug 13 2001
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

#ifndef LMSENSORSCFG_H
#define LMSENSORSCFG_H

//#include <qobject.h>

#include "sensorslist.h"
#include "lmsensorscfgdesign.h"
#include "palettecfg.h"

/**
  *@author 
  */

class LMSensorsCfg : public LMSensorsCfgDesign  {
Q_OBJECT
public:
	LMSensorsCfg(SensorsList *lsensors,QWidget *parent=0, const char *name=0);
	~LMSensorsCfg();

protected slots:

  void slotAccept();

  void slotTestAlarm();
  void slotCurrentSensorChanged(int index);

  void slotMainTabPageChanged(QWidget *);
  void slotComboMinMaxSelected(int index);

public slots:
  void slotApplyChanges();

protected:

  void applySensorChanges();
  void applyPreferencesChanges();
  void applySensorAlarmConfig(Sensor *sensor);

  void readSensorInfo(int index);
  void readPreferencesInfo();
  void readSensorsList();

private:

  PaletteCfg *palPanelCfg;

  SensorsList *sensors;
  Sensor      *curSensor;
};

#endif
