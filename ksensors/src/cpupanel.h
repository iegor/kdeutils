/***************************************************************************
                          cpudisplay.h  -  description
                             -------------------
    begin                : Sun Nov 25 2001
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

#ifndef CPUPANEL_H
#define CPUPANEL_H

#include "panel.h"

#include <qlcdnumber.h>
#include "qlcdstring.h"

/**
  *@author Miguel Novas
  */

#include <stdio.h>

class CpuPanel : public Panel  {
Q_OBJECT
public:
	CpuPanel(QWidget *parent=0, const char *name=0);
	~CpuPanel();

protected:

  void drawContents ( QPainter *p );
  void paletteChange( const QPalette &oldPalette);

private:

  void updateInfo();

  QLCDNumber *speed;

  QString sCpu,sVendor,sSpeed,sBogomips;

  void resizeEvent ( QResizeEvent *e );
};

#endif
