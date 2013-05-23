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

#ifndef CPUTIMEPANEL_H
#define CPUTIMEPANEL_H

#include <qpainter.h>

#include <panel.h>
#include "qlcdstring.h"
#include "qbarmeter.h"

/**
  *@author Miguel Novas
  */

class CpuTimePanel : public Panel  {
public: 
	CpuTimePanel(QWidget *parent=0, const char *name=0);
	~CpuTimePanel();

protected:

  int old_user,old_nice,old_system,old_idle;
  QLCDString *lcd1,*lcd2,*lcd3,*lcd4;
  QBarMeter *barMeter;

  void updateInfo();
  void drawContents(QPainter *p);
  void resizeEvent ( QResizeEvent *e );
};

#endif
