/***************************************************************************
                          rampanel.h  -  description
                             -------------------
    begin                : Fri Jan 11 2002
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

#ifndef RAMPANEL_H
#define RAMPANEL_H

#include <panel.h>
#include <qdialarc.h>
#include <qlcdstring.h>

/**
  *@author Miguel Novas
  */

class RamPanel : public Panel  {
public:

  enum RamType { memRAM, memSWAP };

	RamPanel(QWidget *parent=0, const char *name=0, RamType type= memRAM);
	~RamPanel();

protected:

  RamType ramType;
  int memTotal,memUsed;
  QDialArc *arc;
  QLCDString *lcd1,*lcd2;
  void updateInfo();
  void paletteChange(const QPalette &oldPalette);
  void resizeEvent ( QResizeEvent *e );
};

#endif
