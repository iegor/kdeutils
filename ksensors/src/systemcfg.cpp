/***************************************************************************
                          systemcfg.cpp  -  description
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

#include <qlistbox.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtabwidget.h>
#include <klocale.h>
#include "systemcfg.h"

#include "infopanels.h"


SystemCfg::SystemCfg(LMSensors *lsensors, QWidget *parent, const char *name): SystemCfgDesign(parent,name)
{
 sensors= lsensors;

 palPanelCfg= new PaletteCfg( boxPanelPalette );
 boxPanelPalette->setColumnLayout(0, Qt::Vertical );
 boxPanelPalette->layout()->setSpacing( 6 );
 boxPanelPalette->layout()->setMargin( 12 );
 QGridLayout *boxPanelPaletteLayout = new QGridLayout( boxPanelPalette->layout() );
 boxPanelPaletteLayout->setAlignment( Qt::AlignTop );
 boxPanelPaletteLayout->addWidget( palPanelCfg, 0, 0 );

 connect( TabWidget  ,SIGNAL(currentChanged(QWidget*)), this, SLOT(slotTabWidgetChanged(QWidget *)));
 //connect( buttonApply ,SIGNAL(clicked()),this, SLOT(slotApplyChanges()));

 listSensors->clear();
 listSensors->insertItem( i18n("CPU Speed"));
 listSensors->insertItem( i18n("CPU State"));
 listSensors->insertItem( i18n("RAM Used"));
 listSensors->insertItem( i18n("SWAP Used"));
 listSensors->insertItem( i18n("Up Time"));
 listSensors->setCurrentItem(0);
 readSensorInfo(0);

 connect( listSensors,SIGNAL(highlighted(int)),this,SLOT(slotCurrentSensorChanged(int)) );
}

SystemCfg::~SystemCfg(){
}

void SystemCfg::slotTabWidgetChanged(QWidget *)
{
   switch(TabWidget->currentPageIndex())
  {
    case 0: readSensorInfo(listSensors->currentItem());  break;
    case 1: readPreferencesInfo();                       break;
  }
}

const char *SystemCfg::getPanelName(int index)
{
 switch(index) {
   case 0:  return "proc.CPUINFO";
   case 1:  return "proc.CPULOAD";
   case 2:  return "proc.RAMINFO";
   case 3:  return "proc.SWAPINFO";
   case 4:  return "proc.UPTIME";
 }
 return 0;
}

void SystemCfg::slotCurrentSensorChanged(int index)
{
 readSensorInfo(index);
}

void SystemCfg::readSensorInfo(int index)
{
const char *panelName= getPanelName(index);

 checkShow->setChecked( Panel::readShow(panelName) );
 palPanelCfg->readPalette(panelName);
}

void SystemCfg::readPreferencesInfo()
{
 SpinUpdateTime->setValue(InfoPanels::cfgReadUpdateInterval());
}


void SystemCfg::writeSensorInfo(int index)
{
const char *panelName= getPanelName(index);

 Panel::writeShow(panelName,checkShow->isChecked());
 palPanelCfg->savePalette();
 sensors->emitConfigChanged(panelName);
}

void SystemCfg::writePreferencesInfo()
{
 InfoPanels::cfgWriteUpdateInterval(SpinUpdateTime->value());
 sensors->emitConfigChanged("proc");
}

void SystemCfg::slotApplyChanges()
{
  if (!isVisible())
	  return;
  switch(TabWidget->currentPageIndex())
  {
    case 0: writeSensorInfo(listSensors->currentItem()); break;
    case 1: writePreferencesInfo();          break;
  }
}

