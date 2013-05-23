/***************************************************************************
                          lmsensorpanel.h  -  description
                             -------------------
    begin                : Sat Aug 11 2001
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

#ifndef LMSENSORPANEL_H
#define LMSENSORPANEL_H

#include <qstring.h>

#include "panel.h"
#include "sensor.h"
#include "qdialarc.h"
#include "qlcdstring.h"


/**
  *@author 
  */

class LMSensorPanel : public Panel  {
   Q_OBJECT
public: 

	LMSensorPanel(Sensor *newSensor, QWidget *parent=0, const char *name=0);
	~LMSensorPanel();

public slots:

  void setValue(double value);
  void updateConfig();

protected:

  void resizeEvent ( QResizeEvent * );

  void createTitleWidget();
  void createGraphicWidget();
  void createValueWidget();

  void timerEvent( QTimerEvent * );
  void paletteChange(const QPalette &oldPalette);

private:

  Sensor     *sensor;
  QDialArc   *arc;
  QLCDString *lcdDes;
  QLCDString *lcdVal;
  QString    valMask;
  bool       alarm;
};

#endif
