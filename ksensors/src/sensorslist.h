/***************************************************************************
                          sensorslist.h  -  description
                             -------------------
    begin                : mié abr 24 2002
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

#ifndef SENSORSLIST_H
#define SENSORSLIST_H

#include <qobject.h>
#include <qobjectlist.h>
#include <kconfig.h>
#include <qstringlist.h>

#include <sensor.h>

/**
  *@author Miguel Novas
  */

class SensorsList : public QObject  {
Q_OBJECT

  friend class Sensor;

public:

	SensorsList(QObject *parent=0, const char *name=0);
	~SensorsList();

  void setMonitorized(bool enable);

  const QString &getDescription()        { return description; };
  QObjectList *getSensors()              { return (QObjectList *)children(); };
  Sensor *getSensor(int index)           { return children() ? (Sensor *)((QObjectList *)children())->at(index) : 0; }
  Sensor *getSensor(const char *name)    { return (Sensor *)child(name); }
  int count() 									         { return children() ? children()->count() : 0; }

  void setTempScale(Sensor::TempScale scale);
  Sensor::TempScale getTempScale()       { return tempScale; }

  void setUpdateInterval(int seconds);
  int  getUpdateInterval()               {  return updateInterval/1000; }

  Sensor::SensorClass getClass()         { return clas; };

public slots:

  virtual void updateSensors()= 0;
  virtual void readConfig();
  virtual void writeConfig();

signals:

  void valueChanged(Sensor *);
  void configChanged(const char *name);

protected slots:

  void slotConfigChanged();
  void slotValueChanged();

protected:

  void setDescription(const QString &name) { description= name; };
  void setClass(Sensor::SensorClass newClass) { clas= newClass; }
  void childEvent ( QChildEvent *e );

private:

  QString description;
  Sensor::SensorClass clas;
  bool monitorized;
  int  updateInterval;
  KConfig *ksConfig;
  Sensor::TempScale tempScale;

  void timerEvent( QTimerEvent * );
};

#endif
