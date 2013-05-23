/***************************************************************************
                          lmsensorswidget.h  -  description
                             -------------------
    begin                : Mon Aug 6 2001
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

#ifndef LMSENSORSWIDGET_H
#define LMSENSORSWIDGET_H

#include <qwidget.h>
#include <qpixmap.h>

#include "lmsensors.h"
#include "lmsensorpanel.h"
#include "infopanels.h"

/**
  *@author Miguel Novas
  */

class LMSensorsWidget : public QWidget  {
   Q_OBJECT
public:

	LMSensorsWidget(LMSensors *lsensors,QWidget *parent=0, const char *name=0);
	~LMSensorsWidget();

  static bool cfgReadPalette(QPalette &pal,const char *name=0, bool returnDefault= false);
  static void cfgWritePalette(const QPalette &pal,const char *name=0);
  static void cfgUnsetPalette(const char *name=0);
  static void getDefaultPalette(QPalette &pal);
  static void cfgWritePanelSize(int newSize);
  static int  cfgReadPanelSize();

protected slots:

   void slotConfigChanged(const char *name);

signals:

   void rightMouseClicked(QMouseEvent *);

private:

  LMSensors  *sensors;
  InfoPanels *infoPanels;
  QWidget    *childDraging;
  int         panelsSize;
	QPoint			origMousePt;

  void loadPalette(Panel *panel=0);
  void loadDisplayConfig(Panel *display);
  void saveDisplayConfig(Panel *display);
  void mouseReleaseEvent ( QMouseEvent *m );
  void mouseMoveEvent ( QMouseEvent *m );

  void createSensorPanels();
  void findUnusedPosition(int *px,int *py);
  void startDragChild(QMouseEvent *m, QWidget *w);
  void endDragChild();
  void resizePanels(int newSize);
  void loadGeneralOptions();

private slots:

  void childEvent(QChildEvent *);
  void childEventReceived(QEvent *);

};

#endif
