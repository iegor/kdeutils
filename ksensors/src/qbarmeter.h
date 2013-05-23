/***************************************************************************
                          qbarmeter.h  -  description
                             -------------------
    begin                : Mon Dec 3 2001
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

#ifndef QBARMETER_H
#define QBARMETER_H

#include <qpainter.h>
#include <qwidget.h>
#include <qcolor.h>

/**
  *@author Miguel Novas
  */

class QBarMeter: public QWidget {
Q_OBJECT
public:

   enum Direction { dirLeft, dirRight ,dirUp, dirDown };

   QBarMeter(QWidget *parent=0, const char *name=0);
   ~QBarMeter();

   void setDirection(Direction dir);
   void setValueMax(double newVal);
   void setValue(double newVal);
   void setValueColor(const QColor &newColor);
   void setValueMaxColor(const QColor &newColor);
   void setSteps(int newSteps);

   void setValue(int index, double newVal);
   void setValueColor(int index, const QColor &newColor);
   void setValueCount(int count);
   void useValueMax(bool flag);

protected:

   double val[8];
   QColor color[8];
   bool   useValMax;
   double valMax;
   QColor maxColor;
   int count;
   int steps;
   Direction dir;
   void paintEvent( QPaintEvent *);
};

#endif
