/***************************************************************************
                          lmsensorsdock.cpp  -  description
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

#include "lmsensorsdock.h"

#include <qobjectlist.h>
#include <klocale.h>
#include <kiconloader.h>
#include <kapp.h>
#include <kaboutapplication.h>

#include <kwin.h>
#include <netwm.h>

LMSensorsDock::LMSensorsDock(bool fNoDock, QObject *parent, const char *name): QObject(parent,name)
{
 noDock= fNoDock;
 
 sensors= new LMSensors;
 sensors->setMonitorized(true);

 connect(sensors,SIGNAL(configChanged(const char *)),this,SLOT(updateItemDock(const char *)));

 createAlarmControl();
 createWidgets();
 if(!noDock) createDockWidgets();
 createMenu();
}


LMSensorsDock::~LMSensorsDock()
{
 saveConfig();
 if(sensorsWidget) delete sensorsWidget;
 if(sensorsCfg) delete sensorsCfg;
 if(sensorsAlarm) delete sensorsAlarm;
 delete menu;
 if(sensors) delete sensors;
}


void LMSensorsDock::createMenu()
{
  menu= new KPopupMenu;
  menu->insertTitle(kapp->miniIcon(),"KSensors");
  menu->insertItem(SmallIcon("configure"),i18n("&Configure"), this, SLOT(createConfigWidget() ) ,0,101 );
  menu->insertSeparator();
  menu->insertItem(kapp->miniIcon()      ,i18n("&About KSensors"), this, SLOT(showAbout()          ) ,0,103 );
  menu->insertSeparator();
  if(!noDock) menu->insertItem(sensorsWidget ? i18n("&Minimize"):i18n("&Restore"), this, SLOT(minimizeRestoreWidget() ) ,0,100 );
  menu->insertItem(SmallIcon("exit"),i18n("&Exit"), this, SLOT(close()),0,102);
}

void LMSensorsDock::createWidgets()
{
 KGlobal::config()->setGroup("General");
 if(noDock) createShowWidget();
 else if(KGlobal::config()->readBoolEntry("showWidget",false)) {
    int desktop = KGlobal::config()->readNumEntry("desktop", 0);
    createShowWidget(desktop);
 }
}

void LMSensorsDock::saveConfig()
{
 KGlobal::config()->setGroup("General");
 KGlobal::config()->writeEntry("showWidget",(bool)sensorsWidget);
 if(sensorsWidget) {
   NETWinInfo wm_client(qt_xdisplay(), sensorsWidget->winId(), qt_xrootwin(), NET::WMDesktop);
   KGlobal::config()->writeEntry("desktop", wm_client.desktop());
 }   
}

void LMSensorsDock::createDockWidgets()
{
QObjectList *chips= sensors->getSensorsChips();

 countSensors= 0;
 if(chips)
    for(LMSensorsChip *chip= (LMSensorsChip *)chips->first(); chip!=0; chip= (LMSensorsChip *)chips->next()) {
        QObjectList *list= (QObjectList *)chip->getSensors();
        if(list) {
           for(LMSensor *sensor= (LMSensor *)list->first(); sensor!=0; sensor= (LMSensor *)list->next()) {
             if( LMSensorDockPanel::readShowInDock(sensor->name()) )
               createDockSensor(sensor);
          }
        }
    }
 if(countSensors==0) createDockSensor(0);
}

void LMSensorsDock::createAlarmControl()
{
 sensorsAlarm= new LMSensorsAlarms(sensors);
}


void LMSensorsDock::minimizeRestoreWidget()
{
 if(sensorsWidget)  delete sensorsWidget;
 else               createShowWidget();
 updateMenu();
}

void LMSensorsDock::updateMenu()
{
 if(noDock && !sensorsWidget)
   close();
 else
   menu->changeItem(100, sensorsWidget ? i18n("&Minimize") : i18n("&Restore"));
}

void LMSensorsDock::createShowWidget(int desktop)
{
 if(!sensorsWidget)  {
   sensorsWidget= new LMSensorsWidget(sensors);
   connect( sensorsWidget, SIGNAL(rightMouseClicked(QMouseEvent *)), this, SLOT(mouseEventReceived(QMouseEvent *)) );
   connect( sensorsWidget, SIGNAL(destroyed()), this, SLOT(updateMenu()) );
 }
 if ((desktop != 0) && (desktop <= KWin::numberOfDesktops())) KWin::setOnDesktop(sensorsWidget->winId(), desktop);
 sensorsWidget->show();
}


void LMSensorsDock::createConfigWidget()
{
 if(!sensorsCfg) {
   sensorsCfg= new KSensorsCfg(sensors);
 }
 sensorsCfg->show();
}


void LMSensorsDock::close()
{
 delete this;
}

void LMSensorsDock::mouseEventReceived(QMouseEvent *e)
{
 if(e->type()==QEvent::MouseButtonRelease) {
   if( e->button()==LeftButton  ) minimizeRestoreWidget();
   if( e->button()==RightButton ) menu->popup(e->globalPos());
 }
}

void LMSensorsDock::createDockSensor(Sensor *sensor)
{
  if(countSensors==0) {
    QObjectList *list= (QObjectList *)children();
    if(list)
      for(LMSensorDockPanel *sensor= (LMSensorDockPanel *)list->first(); sensor!=0; sensor= (LMSensorDockPanel *)list->next())
       delete sensor;
  }
  const char *name= sensor ?  sensor->name() : 0;
  LMSensorDockPanel *dock= new LMSensorDockPanel(sensor,name);
  connect( dock, SIGNAL(mouseEvent(QMouseEvent *)), this, SLOT(mouseEventReceived(QMouseEvent *)) );
  insertChild(dock);
  dock->show();
  if(name) countSensors++;
}

void LMSensorsDock::deleteDockSensor(LMSensorDockPanel *sensor)
{
 delete sensor;
 if(--countSensors==0) createDockSensor(0);
}

void LMSensorsDock::updateItemDock(const char *name)
{
 if(!name) return;

 Sensor *sensor= sensors->getSensor(name);

// if((bool)sensor && sensor->getType()==LMSensor::lmTemp) {
   bool   fShow= LMSensorDockPanel::readShowInDock(name);
   LMSensorDockPanel *dockSensor= (LMSensorDockPanel *)child(name);
   if( fShow!=(bool)dockSensor ) {
     if(dockSensor) deleteDockSensor(dockSensor);
     else           createDockSensor(sensor);
   } else {
     if(dockSensor!=0)
       dockSensor->updateConfig();
   }
// }
}


void LMSensorsDock::showAbout()
{
KAboutApplication *dialog;

  dialog= new KAboutApplication;
  dialog->exec();
  delete dialog;
}

