/***************************************************************************
                          lmsensorsalarms.h  -  description
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

#ifndef LMSENSORSALARMS_H
#define LMSENSORSALARMS_H

#include <qobject.h>
#include <qstring.h>
#include "lmsensors.h"

/**
  *@author Miguel Novas
  */

class LMSensorsAlarms : public QObject  {
Q_OBJECT
public:

  enum Actions { acNothing, acSound, acCommand };

	LMSensorsAlarms(LMSensors *sensors, QObject *parent=0, const char *name=0);
	~LMSensorsAlarms();

  static int     readAlarm(const char *name);
  static QString readAlarmSound(const char *name);
  static void    writeAlarm(const char *name, int alarm);
  static QString readAlarmCommand(const char *name);
  static void    writeAlarmCommand(const char *name, const QString &cmd);
  static void    writeAlarmSound(const char *name, const QString &cmd);

  static void    runSensorCommand(const char *name,const char *value, const char *cmd);
  static void    playSound(const char *sound);
public slots:

  void setValueChanged(Sensor *);

private:

  int     sensorCount;
  QString soundPlay;

  static void runCommand(const char *str);

  void timerEvent( QTimerEvent * );
};

#endif
