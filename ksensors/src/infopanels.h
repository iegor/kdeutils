/***************************************************************************
                          infopanels.h  -  description
                             -------------------
    begin                : vie may 10 2002
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

#ifndef INFOPANELS_H
#define INFOPANELS_H

#include <qtimer.h>
#include <kglobal.h>

#include "panelsgroup.h"
#include "cpupanel.h"
#include "rampanel.h"
#include "cputimepanel.h"
#include "uptimepanel.h"


/**
  *@author Miguel Novas
  */

class InfoPanels : public PanelsGroup  {
Q_OBJECT

public:
  InfoPanels(QWidget *panelsWidget, QObject *parent=0, const char *name=0);
	~InfoPanels();

   static int  cfgReadUpdateInterval();
   static void cfgWriteUpdateInterval(int interval);

public slots:

   void configChanged(const char *name);

protected slots:

   void infoPanelDestroyed();

private:

   int        timerPanelCount;
   QTimer    *timer;
   QWidget   *widget;

   void readUpdateInterval();
   void timerConnect(Panel *display);
};

#endif
