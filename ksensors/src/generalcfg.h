/***************************************************************************
                          generalcfg.h  -  description
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

#ifndef GENERALCFG_H
#define GENERALCFG_H

#include "lmsensors.h"
#include "generalcfgdesign.h"
#include "palettecfg.h"

/**
  *@author Miguel Novas
  */

class GeneralCfg : public GeneralCfgDesign  {
Q_OBJECT
public:
	GeneralCfg(LMSensors *lsensors, QWidget *parent=0, const char *name=0);
	~GeneralCfg();

public slots:

  void slotApplyChanges();

private:
  PaletteCfg *palPanelCfg;
  LMSensors *sensors;
};

#endif
