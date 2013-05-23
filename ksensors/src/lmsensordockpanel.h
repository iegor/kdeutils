/***************************************************************************
                          lmsensordockpanel.h  -  description
                             -------------------
    begin                : Tue Sep 18 2001
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

#ifndef LMSENSORDOCKPANEL_H
#define LMSENSORDOCKPANEL_H


#include <ksystemtray.h>
#include <kpopupmenu.h>
#include <qcolor.h>

#include "qlcddraw.h"

#include "sensor.h"


/**
  *@author Miguel Novas
  */

class LMSensorDockPanel : public KSystemTray  {
Q_OBJECT
public:
	LMSensorDockPanel(Sensor *newSensor=0, const char *name=0);
	~LMSensorDockPanel();

  static void   writeColorAlarm (const char *name, const QColor &color);
  static void   writeColorNormal(const char *name, const QColor &color);
  static void   writeShowInDock (const char *name, bool fShow);

  static QColor readColorAlarm (const char *name);
  static QColor readColorNormal(const char *name);
  static bool   readShowInDock (const char *name);

public slots:

  void setValue(double value);
  void updateConfig();

signals:

  void mouseEvent(QMouseEvent *e);

protected:

  void paintEvent ( QPaintEvent * );
  void mousePressEvent ( QMouseEvent * );
  void mouseReleaseEvent ( QMouseEvent * );

private:

  Sensor *sensor;
  QString  strValue;
  QColor colorNormal,colorAlarm;

};

#endif
