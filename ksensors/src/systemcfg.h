/***************************************************************************
                          systemcfg.h  -  description
                             -------------------
    begin                : vie may 17 2002
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

#ifndef SYSTEMCFG_H
#define SYSTEMCFG_H

#include <systemcfgdesign.h>

#include <lmsensors.h>
#include <palettecfg.h>
/**
  *@author Miguel Novas
  */

class SystemCfg : public SystemCfgDesign  {
Q_OBJECT
public:
	SystemCfg(LMSensors *lsensors, QWidget *parent=0, const char *name=0);
	~SystemCfg();

protected slots:
  void slotCurrentSensorChanged(int index);
  void slotTabWidgetChanged(QWidget *);

  void readSensorInfo(int index);
  void readPreferencesInfo();
  void writeSensorInfo(int index);
  void writePreferencesInfo();

public slots:
  void slotApplyChanges();

  
private:

//  int indexCurSensor;
  LMSensors *sensors;
  PaletteCfg *palPanelCfg;
  const char *getPanelName(int index);
};

#endif
