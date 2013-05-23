/***************************************************************************
                          palettecfg.h  -  description
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

#ifndef PALETTECFG_H
#define PALETTECFG_H

#include <palettecfgdesign.h>

#include <kconfig.h>

/**
  *@author Miguel Novas
  */

class PaletteCfg : public PaletteCfgDesign  {
Q_OBJECT
public:
  PaletteCfg(QWidget *parent=0, const char *name=0);
	~PaletteCfg();

  void readPalette(const char *name);
  void savePalette();

protected slots:

  void slotComboSelected(int index);
  void slotColorChanged(const QColor &newColor);
  void slotPaletteDefault();

private:

  bool palDefault;
  const char *groupName;

  void setPanelPalette(const QPalette &pal, bool updateColorButton=false);
};

#endif
