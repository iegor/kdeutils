/***************************************************************************
                          hdsensorslist.h  -  description
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

#ifndef HDSENSORSLIST_H
#define HDSENSORSLIST_H

#include <sensorslist.h>

#include "sensor.h"
#include "processexec.h"

/**
  *@author Miguel Novas
  */

class HDSensorsList : public SensorsList  {
Q_OBJECT
public:
	HDSensorsList(QObject *parent, const char * name);
	~HDSensorsList();

public slots:

  void updateSensors();

protected slots:

  void slotProcessExited(KProcess *proc);

private:

  ProcessExec *process;

  static bool isHddTempInstalled();
  static bool getDisks(QStringList &disks);
  static bool getDiskInfo(const QString buf, QString &name, double &value);
};

#endif
