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

#ifndef UPTIMEPANEL_H
#define UPTIMEPANEL_H

#include "panel.h"
#include "qlcdstring.h"

#include <qstring.h>

/**
  *@author Miguel Novas
  */

class UpTimePanel : public Panel  {
Q_OBJECT
public:
	UpTimePanel(QWidget *parent=0, const char *name=0);
	~UpTimePanel();

protected:

  void updateInfo();
  void drawContents ( QPainter *p );

private:

  QLCDString *lcd;
  void resizeEvent ( QResizeEvent *e );
};

#endif
