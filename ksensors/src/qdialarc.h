/***************************************************************************
                          qdialarc.h  -  description
                             -------------------
    begin                : Wed Aug 1 2001
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

#ifndef QDIALARC_H
#define QDIALARC_H

#include <qwidget.h>

/**
  *@author Miguel Novas
  */

class QDialArc : public QWidget  {
   Q_OBJECT
public: 
	QDialArc(QWidget *parent=0, const char *name=0);
	~QDialArc();

  void setValue            (double value);
  void setValueMin         (double value);
  void setValueMax         (double value);
  void setValueRanges      (double min,double max);
  void setValueLimitRanges (double min,double max);
  void setValueMinLimit    (double value, int percent= 15);
  void setValueMaxLimit    (double value, int percent= 15);
  void setValueMaxLimitPercent(int value);
  void setValueMinLimitPercent(int value);

  void setAngle        (int value);
  void setAngleLen     (int value);
  void setAngles       (int angle,int len);

  void setShowMarks (bool flag);

  void setColorMax(const QColor &color);
  void setColorMid(const QColor &color);
  void setColorMin(const QColor &color);
  void setColorRanges(const QColor &min,const QColor &mid, const QColor &max);

  void setArrowColor(const QColor &color);

  inline double getValue() { return val; }

protected:

  void resizeEvent( QResizeEvent *);
  void paintEvent ( QPaintEvent *);

private:

 double val;
 double valMin;
 double valMax;
 double valMaxLimit,valMinLimit;
 int    valMaxLimitPercent,valMinLimitPercent;
 int angleStart,angleLen;
 //
 int radius;
 int centerx,centery;
 bool fCalcParams;

 QColor arrowColor;
 QColor colorMin;
 QColor colorMid;
 QColor colorMax;
 bool fShowMarks;

 void calcParams();
 void paramsChanged();
 void drawMarks(QPainter *p,int l1,int l2);
 void drawArc(QPainter *p,int l1,int l2,const QColor &color);
 void drawArrow(QPainter *p, double value);
};

#endif
