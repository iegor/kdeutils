/***************************************************************************
                          palettecfg.cpp  -  description
                             -------------------
    begin                : lun abr 15 2002
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

#include "palettecfg.h"
#include "lmsensorswidget.h"

#include <qlabel.h>
#include <qpalette.h>
#include <qcombobox.h>
#include <kcolorbutton.h>

PaletteCfg::PaletteCfg(QWidget *parent, const char *name): PaletteCfgDesign(parent,name)
{
 groupName= 0;
 slotComboSelected(0);
 connect( comboSelect,SIGNAL(activated(int)),this,SLOT(slotComboSelected(int)) );
 connect( buttonColor,SIGNAL(changed(const QColor &)),this,SLOT(slotColorChanged(const QColor &)) );
 connect( buttonDefaultPalette, SIGNAL(clicked()),this,SLOT(slotPaletteDefault()) );
}

PaletteCfg::~PaletteCfg()
{
}

void PaletteCfg::slotComboSelected(int index)
{
 QColorGroup colors= framePanel->palette().active();
 QColor color;
 switch(index) {
  case 0: color= colors.background(); break;
  case 1: color= colors.dark();       break;
  case 2: color= colors.text();       break;
  case 3: color= colors.foreground(); break;
 }
 buttonColor->blockSignals(true);
 buttonColor->setColor(color);
 buttonColor->blockSignals(false);
}

void PaletteCfg::slotColorChanged(const QColor &newColor)
{
 QPalette pal= framePanel->palette();
 switch(comboSelect->currentItem()) {
  case 0: pal.setColor(QColorGroup::Background,newColor);
          pal.setColor(QColorGroup::Light     ,newColor); break;
  case 1: pal.setColor(QColorGroup::Dark      ,newColor); break;
  case 2: pal.setColor(QColorGroup::Text      ,newColor); break;
  case 3: pal.setColor(QColorGroup::Foreground,newColor); break;
  default: return;
 }
 setPanelPalette(pal,false);
 palDefault= false;
}

void PaletteCfg::slotPaletteDefault()
{
 palDefault= true;
 QPalette pal;
 if(groupName) {
   LMSensorsWidget::cfgReadPalette(pal,"General",true);
 } else {
   LMSensorsWidget::getDefaultPalette(pal);
 }
 setPanelPalette(pal,true);
}

void PaletteCfg::setPanelPalette(const QPalette &pal, bool updateColorButton)
{
 labelTitle->unsetPalette();
 framePanel->setPalette(pal);
 labelTitle->setPaletteForegroundColor(pal.active().text());
 if(updateColorButton) slotComboSelected(comboSelect->currentItem());
}

void PaletteCfg::readPalette(const char *name)
{
 groupName= name;
 QPalette pal;
 palDefault= !LMSensorsWidget::cfgReadPalette(pal,name,false);
 if(palDefault) LMSensorsWidget::cfgReadPalette(pal,"General",true);
 setPanelPalette(pal,true);
}

void PaletteCfg::savePalette()
{
 if(palDefault) LMSensorsWidget::cfgUnsetPalette(groupName);
 else           LMSensorsWidget::cfgWritePalette(framePanel->palette(),groupName);
}


