/***************************************************************************
                          generalcfg.cpp  -  description
                             -------------------
    begin                : mar may 14 2002
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

#include "generalcfg.h"

#include <qgroupbox.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qcheckbox.h>

#include "lmsensorswidget.h"
#include "lmsensorsdock.h"

GeneralCfg::GeneralCfg(LMSensors *lsensors, QWidget *parent, const char *name) : GeneralCfgDesign(parent,name)
{
 sensors= lsensors;

 palPanelCfg= new PaletteCfg( boxGeneralPalette );
 boxGeneralPalette->setColumnLayout(0, Qt::Vertical );
 boxGeneralPalette->layout()->setSpacing( 6 );
 boxGeneralPalette->layout()->setMargin( 12 );
 QGridLayout *boxGeneralPaletteLayout = new QGridLayout( boxGeneralPalette->layout() );
 boxGeneralPaletteLayout->setAlignment( Qt::AlignTop );
 boxGeneralPaletteLayout->addWidget( palPanelCfg, 0, 0 );

 palPanelCfg->readPalette(0);

 int panelSize= LMSensorsWidget::cfgReadPanelSize();
 switch(panelSize) {
   case 64: Radio64->setChecked(true); break;
   case 56: Radio56->setChecked(true); break;
   case 48: Radio48->setChecked(true); break;
 }

 KConfig *cfg= KGlobal::config();
 cfg->setGroup( "General" );
 CheckBoxAutoStart->setChecked(cfg->readBoolEntry("AutoStart",true));
 //connect( buttonApply ,SIGNAL(clicked()),this, SLOT(slotApplyChanges()));
}

GeneralCfg::~GeneralCfg(){
}


void GeneralCfg::slotApplyChanges()
{
  if (!isVisible())
	return;

  palPanelCfg->savePalette();
  //
  int panelSize= 64;
  if(Radio56->isChecked()) panelSize= 56;
  else if(Radio48->isChecked()) panelSize= 48;
  LMSensorsWidget::cfgWritePanelSize(panelSize);

  KConfig *cfg= KGlobal::config();
  cfg->setGroup( "General" );
  cfg->writeEntry("AutoStart", CheckBoxAutoStart->isChecked());
  
  //
  sensors->emitConfigChanged();
}
