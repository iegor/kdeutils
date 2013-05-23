/***************************************************************************
                          lmsensorscfg.cpp  -  description
                             -------------------
    begin                : Mon Aug 13 2001
    copyright            : (C) 2001 by 
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "lmsensorscfg.h"

#include "lmsensorsalarms.h"
#include "lmsensorpanel.h"
#include "lmsensordockpanel.h"
#include "lmsensorswidget.h"

#include <qcolor.h>
#include <qlistbox.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
#include <qobjectlist.h>
#include <qtabwidget.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlayout.h>
#include <kcolorbutton.h>
#include <kiconloader.h>
#include <klocale.h>
#include <kaboutapplication.h>

LMSensorsCfg::LMSensorsCfg(SensorsList *lsensors,QWidget *parent, const char *name) : LMSensorsCfgDesign(parent,name,WDestructiveClose)
{
 sensors = lsensors;

 curSensor= 0;

 palPanelCfg= new PaletteCfg( boxPanelPalette );
 boxPanelPalette->setColumnLayout(0, Qt::Vertical );
 boxPanelPalette->layout()->setSpacing( 6 );
 boxPanelPalette->layout()->setMargin( 12 );
 QGridLayout *boxPanelPaletteLayout = new QGridLayout( boxPanelPalette->layout() );
 boxPanelPaletteLayout->setAlignment( Qt::AlignTop );
 boxPanelPaletteLayout->addWidget( palPanelCfg, 0, 0 );

 readSensorsList();

 connect( MainTab        ,SIGNAL(currentChanged(QWidget*)), this, SLOT(slotMainTabPageChanged(QWidget *)));
 connect( listSensors    ,SIGNAL(highlighted(int)),this,SLOT(slotCurrentSensorChanged(int)) );
 //connect( buttonApply    ,SIGNAL(clicked()),this,SLOT(slotApplyChanges()));
 connect( buttonTest     ,SIGNAL(clicked()),this,SLOT(slotTestAlarm()));
 connect( editMinValue   ,SIGNAL(activated(int)),this,SLOT(slotComboMinMaxSelected(int)));
 connect( editMaxValue   ,SIGNAL(activated(int)),this,SLOT(slotComboMinMaxSelected(int)));
}

LMSensorsCfg::~LMSensorsCfg()
{
}

void LMSensorsCfg::readSensorsList()
{
 QObjectList *list= sensors->getSensors();
 if(list) {
   listSensors->clear();
   QPixmap pm;
   for(LMSensor *sensor=(LMSensor*)list->first(); sensor!=0; sensor= (LMSensor*)list->next()) {
     switch(sensor->getType()) {
       case LMSensor::lmTemp   : pm= UserIcon("thermometer18x18.png"); break;
       case LMSensor::lmFan    : pm= UserIcon("cooler18x18.png");      break;
       case LMSensor::lmVoltage: pm= UserIcon("battery18x18.png");     break;
     }
     listSensors->insertItem(pm,sensor->getDescription());
   }
   listSensors->setCurrentItem(0);
 }
}


void LMSensorsCfg::readSensorInfo(int index)
{
 if(index<0) return;

 Sensor *oldSensor= curSensor;

 curSensor= sensors->getSensor(index);

 if(!curSensor) return;

 if( oldSensor==0 || curSensor->getType()!=oldSensor->getType() || curSensor->getClass()!=oldSensor->getClass() )
   switch(curSensor->getType()) {
     case LMSensor::lmTemp   : GroupBoxDes->setTitle(i18n("Temperature"));
                               pixmapSensor->setPixmap( UserIcon(
                                                                  curSensor->getClass()==Sensor::lmSensor ?
                                                                  "thermometer.png":"harddisk.png"
                                                                ) );
                               break;
     case LMSensor::lmFan    : GroupBoxDes->setTitle(i18n("Fan"));
                               pixmapSensor->setPixmap(UserIcon("cooler.png"));
                               break;
     case LMSensor::lmVoltage: GroupBoxDes->setTitle(i18n("Voltage"));
                               pixmapSensor->setPixmap(UserIcon("battery.png"));
                               break;
   }

 editDescription ->setText(curSensor->getDescription());

 QString str;

 const char *mask= curSensor->getType()==LMSensor::lmVoltage ? "%.2lf":"%.0lf";

 str.sprintf(curSensor->getPrintMask(true), curSensor->getValue());
 editValue->setText(str);

 str.sprintf(mask, curSensor->getValueIdeal());
 editIdealValue->setText(str);

 str.sprintf(mask, curSensor->getValueMin());
 editMinValue->setEditText(str);

 str.sprintf(mask, curSensor->getValueMax());
 editMaxValue->setEditText(str);

 editSum->setText(QString::number(curSensor->getCompensation()));
 editMul->setText(QString::number(curSensor->getMultiplicator()));

 //checkShowInDock->setEnabled( curSensor->getType()==LMSensor::lmTemp );
 //GroupBoxColorDock->setEnabled( curSensor->getType()==LMSensor::lmTemp );

 CheckAllSensors->setChecked(false);

 colorAlarm     ->setColor  ( LMSensorDockPanel::readColorAlarm(curSensor->name()) );
 colorNormal    ->setColor  ( LMSensorDockPanel::readColorNormal(curSensor->name()) );
 checkShow      ->setChecked( LMSensorPanel::readShow(curSensor->name()) );
 checkShowInDock->setChecked( checkShowInDock->isEnabled() && LMSensorDockPanel::readShowInDock(curSensor->name()) );

 editLaunch->setText( LMSensorsAlarms::readAlarmCommand(curSensor->name()) );
 editPlay  ->setText( LMSensorsAlarms::readAlarmSound  (curSensor->name()) );
 switch( LMSensorsAlarms::readAlarm(curSensor->name()) )
 {
   case LMSensorsAlarms::acNothing : radioAlarm1->setChecked(true); break;
   case LMSensorsAlarms::acSound   : radioAlarm2->setChecked(true); break;
   case LMSensorsAlarms::acCommand : radioAlarm3->setChecked(true); break;
 }
 palPanelCfg->readPalette(curSensor->name());

}


void LMSensorsCfg::readPreferencesInfo()
{
 switch(sensors->getTempScale()) {
  case LMSensor::dgCelsius   :  RadioC->setChecked(true); break;
  case LMSensor::dgFahrenheit:  RadioF->setChecked(true); break;
  case LMSensor::dgKelvin    :  RadioK->setChecked(true); break;
 }
 SpinUpdateTime->setValue(sensors->getUpdateInterval());
}


void LMSensorsCfg::applySensorChanges()
{
 if(!curSensor) return;

 const QString sName(curSensor->name());
 // Apply sensor configuration
 curSensor->setDescription(editDescription->text());
 curSensor->setCompensation(editSum->text().toDouble());
 curSensor->setMultiplicator(editMul->text().toDouble());
 curSensor->setValueIdeal(editIdealValue->text().toDouble());
 curSensor->setValueMax(editMaxValue->currentText().toDouble());
 curSensor->setValueMin(editMinValue->currentText().toDouble());
 curSensor->setMonitorized(
                            checkShow->isChecked()       ||
                            checkShowInDock->isChecked() ||
                            !radioAlarm1->isChecked()
                          );
 // Apply show in main window configuration
 LMSensorPanel::writeShow(sName,checkShow->isChecked() );
 // Apply dock configuration
 LMSensorDockPanel::writeShowInDock(sName,checkShowInDock->isChecked());
 LMSensorDockPanel::writeColorNormal(sName,colorNormal->color());
 LMSensorDockPanel::writeColorAlarm(sName,colorAlarm->color());
 //
 palPanelCfg->savePalette();
 //
 // Apply alarms configuration
 if( CheckAllSensors->isChecked() ) {
    QObjectList *list= sensors->getSensors();
    for(Sensor *sensor=(Sensor*)list->first(); sensor!=0; sensor= (Sensor*)list->next()) {
       applySensorAlarmConfig(sensor);
       sensor->writeConfig();
    }
 } else {
    applySensorAlarmConfig(curSensor);
    curSensor->writeConfig();
 }
 // This line must always be at the end of the method
 listSensors->changeItem( *listSensors->pixmap(listSensors->currentItem()),editDescription->text(), listSensors->currentItem() );
}


void LMSensorsCfg::applySensorAlarmConfig(Sensor *sensor)
{
 const char *name= sensor->name();
 LMSensorsAlarms::writeAlarmCommand(name,editLaunch->text());
 LMSensorsAlarms::writeAlarmSound  (name,editPlay  ->text());
 int code= LMSensorsAlarms::acNothing;
 if(radioAlarm1->isChecked()) code= LMSensorsAlarms::acNothing;
 else if(radioAlarm2->isChecked()) code= LMSensorsAlarms::acSound;
 else    if(radioAlarm3->isChecked()) code= LMSensorsAlarms::acCommand;
 LMSensorsAlarms::writeAlarm(name,code);
}


void LMSensorsCfg::applyPreferencesChanges()
{
 LMSensor::TempScale scale= LMSensor::dgCelsius;
 if(RadioK->isChecked()) scale= LMSensor::dgKelvin;
 else if(RadioF->isChecked()) scale= LMSensor::dgFahrenheit;
 sensors->setTempScale(scale);
 sensors->setUpdateInterval(SpinUpdateTime->value());
 sensors->writeConfig();
}


void LMSensorsCfg::slotCurrentSensorChanged(int index)
{
   readSensorInfo(index);
}

void LMSensorsCfg::slotApplyChanges()
{
  if (!isVisible())
	  return;

  switch(MainTab->currentPageIndex())
  {
    case 0: applySensorChanges();      break;
    case 1: applyPreferencesChanges(); break;
  }
}

void LMSensorsCfg::slotAccept()
{
 slotApplyChanges();
 close();
}

void LMSensorsCfg::slotTestAlarm()
{
  if( radioAlarm2->isChecked() ) {
    LMSensorsAlarms::playSound(editPlay->text());
  } else
  if( radioAlarm3->isChecked() ) {
    LMSensorsAlarms::runSensorCommand("TEST","100",editLaunch->text());
  }
}

void LMSensorsCfg::slotMainTabPageChanged(QWidget *)
{
  switch(MainTab->currentPageIndex())
  {
    case 0: readSensorInfo(listSensors->currentItem());  break;
    case 1: readPreferencesInfo();                       break;
  }
}

void LMSensorsCfg::slotComboMinMaxSelected(int index)
{
 QComboBox *combo  = (QComboBox*)sender();
 QString       str = combo->text(index);
 double     percent= str.left(str.length()-1).toDouble();
 double     value  = editIdealValue->text().toDouble();

 if(value<0) percent= -percent;
 value= value + value * percent / 100;

 const char *mask= curSensor->getType()==LMSensor::lmVoltage ? "%.2lf":"%.0lf";
 str.sprintf(mask,value);

 combo->setEditText(str);
}
