/***************************************************************************
                          lmsensorsdock.h  -  description
                             -------------------
    begin                : Sun Sep 23 2001
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

#ifndef LMSENSORSDOCK_H
#define LMSENSORSDOCK_H


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif


#include <qobject.h>
#include <qguardedptr.h>

#include <kconfig.h>
#include <kpopupmenu.h>
#include <kdialogbase.h>

#include "lmsensors.h"
#include "lmsensorpanel.h"
#include "lmsensorswidget.h"
#include "lmsensordockpanel.h"
#include "lmsensorsalarms.h"
#include "ksensorscfg.h"

/**
  *@author Miguel Novas
  */

class LMSensorsDock : public QObject 
{

	Q_OBJECT

public:
	LMSensorsDock(bool fNoDock=false, QObject *parent=0, const char *name=0);
	~LMSensorsDock();

public slots:
  void saveConfig();	
	
protected slots:

  void updateItemDock(const char *name);
  void mouseEventReceived(QMouseEvent *e);
  void minimizeRestoreWidget();
  void createConfigWidget();
  void updateMenu();
  void showAbout();
  void close();

private:

  bool noDock;

  int countSensors;

  LMSensors *sensors;
  QGuardedPtr<KSensorsCfg>     sensorsCfg;
  QGuardedPtr<LMSensorsWidget> sensorsWidget;
  QGuardedPtr<LMSensorsAlarms> sensorsAlarm;

  KPopupMenu *menu;

  void createMenu();
  void createWidgets();
  void createDockWidgets();
  void createDockSensor(Sensor *sensor);
  void deleteDockSensor(LMSensorDockPanel *sensor);
  void createShowWidget(int desktop=0);
  void createAlarmControl();
};

#endif
