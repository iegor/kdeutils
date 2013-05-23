/***************************************************************************
                          sensor.h  -  description
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

#ifndef SENSOR_H
#define SENSOR_H

#include <qobject.h>
#include <kconfig.h>
#include <qstring.h>
#include <qcstring.h>

/**
  *@author Miguel Novas
  */

//

class SensorsList;

class Sensor : public QObject  {
  Q_OBJECT

  friend class SensorsList;

public:

  enum SensorClass { lmSensor, hdSensor };

  enum TempScale { dgCelsius, dgFahrenheit, dgKelvin, dgDefault };

  enum SensorType { lmTemp, lmFan, lmVoltage };

  Sensor(SensorsList *parent=0, const char *name=0);
	~Sensor();

  inline void setType(SensorType newType)    { type= newType; };
  void   setValue(double newVal, TempScale scale= dgDefault, bool ajust=true);

  inline SensorType  getType()              { return type; };
  inline const QString &getDescription()    { return description;   };
  inline double getValue() 							    { return celsiusTo(val); };
  inline double getValuePrevious() 			    { return celsiusTo(valPrevious);   };
  inline double getValueIdeal()             { return celsiusTo(valIdeal);      };
  inline double getValueMax()               { return celsiusTo(valMax);        };
  inline double getValueMin()               { return celsiusTo(valMin);        };
  inline double getCompensation()           { return celsiusToDiff(compensation);  };
  inline double getMultiplicator()          { return multiplicator; };
  inline bool   getAlarm()                  { return (val<valMin || val>valMax); };
  inline bool   getAlarmPrevious()          { return (valPrevious<valMin || valPrevious>valMax); };
  inline bool   getMonitorize()						  { return monitorize;   };
  inline bool   isAlarmValue(double value)  { value= toCelsius(value); return (value<valMin || value>valMax); };

  bool monitorized();
  void setMonitorized  (bool enable);
  void setDescription  (const QString &str);
  void setValueIdeal   (double value, TempScale scale= dgDefault);
  void setValueMax     (double value, TempScale scale= dgDefault);
  void setValueMin     (double value, TempScale scale= dgDefault);
  void setCompensation (double value, TempScale scale= dgDefault);
  void setMultiplicator(double value);

  SensorClass getClass();
  TempScale getTempScale();
  double toCelsius(double val, TempScale scale= dgDefault);
  double celsiusTo(double val, TempScale scale= dgDefault);
  double toCelsiusDiff(double val, TempScale scale= dgDefault);
  double celsiusToDiff(double val, TempScale scale= dgDefault);

  QString getPrintMask(bool addSufix);

public slots:

  void readConfig();
  void writeConfig();

signals:

  void valueChanged(double);
  void configChanged();

private:

   SensorType  type;
   QString    description;
   double     val;
   double     valPrevious;
   double     compensation;
   double     multiplicator;
   double     valMax;
   double     valMin;
   double     valIdeal;
   bool       monitorize;

   inline double adjustValue(double value)      { return value * multiplicator + compensation; };
   const char *getSensorPrintMask(int sensorType, bool addSufix, TempScale temp);

};

#endif
