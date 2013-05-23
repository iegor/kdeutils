/***************************************************************************
                          qdialarc.cpp  -  description
                             -------------------
    begin                : Wed Aug 1 2001
    copyright            : (C) 2001 by 
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "qdialarc.h"

#include <qpainter.h>
#include <math.h>
#include <stdlib.h>

#define qdegreesToRadians(n)  ((-(n))*M_PI*2/(360*16))

#define valToQDegrees(n)      (int)(((n)-valMin)*angleLen/(valMax-valMin)+angleStart+0.5)


QDialArc::QDialArc(QWidget *parent, const char *name ) : QWidget(parent,name)
{
 val            = 0;
 valMin         = 0;
 valMax         = 100;
 valMinLimit       = (valMax+valMin)/2;
 valMaxLimit       = (valMax+valMin)/2;
 valMinLimitPercent= 0;
 valMaxLimitPercent= 0;
 angleStart     = 0;
 angleLen       = 360*16;
 fShowMarks     = false;
 fCalcParams    = true;
 colorMin       = Qt::green;
 colorMax       = Qt::red;
 arrowColor     = foregroundColor();
}

QDialArc::~QDialArc(){
}

void QDialArc::setValue(double value)
{
 if(value>valMax) value= valMax;
 else if(value<valMin) value= valMin;
 if(val!=value) {
    QPainter p(this);
    p.setPen(backgroundColor());
    drawArrow(&p,val);
    val= value;
    p.setPen(arrowColor);
    drawArrow(&p,val);
 }
}


void QDialArc::setValueMin(double value)
{
 valMin= value;
 paramsChanged();
}


void QDialArc::setValueMax(double value)
{
 valMax= value;
 paramsChanged();
}


void QDialArc::setValueRanges(double min,double max)
{
 valMin= min;
 valMax= max;
 paramsChanged();
}


void QDialArc::setValueLimitRanges (double min,double max)
{
 valMinLimit= min;
 valMaxLimit= max;
 update();
}

void QDialArc::setAngle(int value)
{
 angleStart= value*16;
 paramsChanged();
}

void QDialArc::setAngleLen(int value)
{
 angleLen= value*16;
 paramsChanged();
}


void QDialArc::setAngles(int angle,int len)
{
 angleStart= angle*16;
 angleLen  = len*16;
 paramsChanged();
}

void QDialArc::setColorMin(const QColor &color)
{
 colorMin= color;
 update();
}

void QDialArc::setColorMid(const QColor &color)
{
 colorMid= color;
 update();
}


void QDialArc::setColorMax(const QColor &color)
{
 colorMax= color;
 update();
}

void QDialArc::setColorRanges(const QColor &min,const QColor &mid,const QColor &max)
{
 colorMin= min;
 colorMid= mid;
 colorMax= max;
 update();
}

void QDialArc::setValueMinLimit(double value, int percent)
{
 valMinLimit= value;
 valMinLimitPercent= percent;
 update();
}

void QDialArc::setValueMaxLimit(double value, int percent)
{
 valMaxLimit= value;
 valMaxLimitPercent= percent;
 update();
}

void QDialArc::setValueMinLimitPercent(int value)
{
 valMinLimitPercent=value;
 update();
}

void QDialArc::setValueMaxLimitPercent(int value)
{
 valMaxLimitPercent=value;
 update();
}


void QDialArc::setShowMarks (bool flag)
{
 fShowMarks= flag;
 update();
}

void QDialArc::setArrowColor(const QColor &color)
{
 arrowColor= color;
}


//*****************************************************************

void QDialArc::resizeEvent( QResizeEvent *)
{
 paramsChanged();
}

//*****************************************************************


void QDialArc::drawMarks(QPainter *p,int l1,int l2)
{
int a;
double r,co,se;

 if(l1>l2) { a= l1; l1= l2; l2= a; }   // swap(l1,l2)

 a= (l1 / (360*16/32)) * (360*16/32);

 while(a<l1) a+= 360*16/32;
 while(a<=l2) {
   r = qdegreesToRadians(a);
   co= cos(r);
   se= sin(r);
   p->drawLine((int)(centerx+ co*(radius-1-radius/10)+0.5),
               (int)(centery+ se*(radius-1-radius/10)+0.5),
               (int)(centerx+ co*(radius-1) +0.5),
               (int)(centery+ se*(radius-1) +0.5) );
   a+= 360*16/32;
 }
}


void QDialArc::drawArc(QPainter *p,int l1,int l2,const QColor &color)
{
 p->setPen(color);
 p->drawArc(centerx-radius,centery-radius,radius*2,radius*2, l1, l2-l1+1);
 if (fShowMarks) drawMarks(p,l1,l2);
}


void QDialArc::drawArrow(QPainter *p, double value)
{
double r= qdegreesToRadians(valToQDegrees(value));

 p->drawLine(centerx,
            centery,
            (int)(centerx+ cos(r)*(radius-1-radius/4) +0.5),
            (int)(centery+ sin(r)*(radius-1-radius/4) +0.5)
            );
}

void QDialArc::paintEvent ( QPaintEvent *)
{
int l0,l1,l2,l3,l4,l5;
QPainter p(this);

 if(fCalcParams) calcParams();

 l0= angleStart;
 l1= valToQDegrees(valMinLimit);
 l2= valToQDegrees(valMinLimit+(valMaxLimit-valMinLimit)*valMinLimitPercent/100);
 l3= valToQDegrees(valMaxLimit-(valMaxLimit-valMinLimit)*valMaxLimitPercent/100);
 l4= valToQDegrees(valMaxLimit);
 l5= angleStart+angleLen;

 drawArc(&p,l0,l1,colorMin);

 drawArc(&p,l1,l2, QColor( (colorMin.red()  +colorMid.red()  )/2,
                           (colorMin.green()+colorMid.green())/2,
                           (colorMin.blue() +colorMid.blue() )/2  ) );

 drawArc(&p,l2,l3,colorMid);

 drawArc(&p,l3,l4, QColor( (colorMax.red()  +colorMid.red()  )/2,
                           (colorMax.green()+colorMid.green())/2,
                           (colorMax.blue() +colorMid.blue() )/2  ) );
 drawArc(&p,l4,l5,colorMax);


 p.setPen(arrowColor);
 drawArrow(&p,val);
}


//*****************************************************************

struct POINT2D { double x,y; };

static void calcAngleMin(double a, POINT2D &m)
{
double x= cos(a);
double y= sin(a);

  if(x<m.x) m.x= x;
  if(y<m.y) m.y= y;
}

static void calcAngleMax(double a, POINT2D &m)
{
double x= cos(a);
double y= sin(a);

  if(x>m.x) m.x= x;
  if(y>m.y) m.y= y;
}


static bool angleIsInRange(int a,int a1,int len)
{
int a2=a1+len;

  if(len>0) {
     if(a2>360*16) return a>=a1 || a<=(a2-360*16);
     else          return a>=a1 && a<=a2;
  } else {
     if(a2<0)      return a<=a1 || a>=(360*16+a2);
     else          return a>=a2 && a<=a1;
  }
}


void QDialArc::calcParams()
{
double m,w,h;
POINT2D p1,p2,d,a;

 p1.x= p1.y= p2.x= p2.y=  0;
 //
 m= qdegreesToRadians(angleStart);
 calcAngleMin( m, p1);
 calcAngleMax( m, p2);
 m= qdegreesToRadians(angleStart+angleLen);
 calcAngleMin( m, p1);
 calcAngleMax( m, p2);
 //
 if(angleIsInRange(0     ,angleStart,angleLen)) calcAngleMax( 0       , p2);
 if(angleIsInRange(90*16 ,angleStart,angleLen)) calcAngleMin(-M_PI/2  , p1);
 if(angleIsInRange(180*16,angleStart,angleLen)) calcAngleMin(-M_PI    , p1);
 if(angleIsInRange(270*16,angleStart,angleLen)) calcAngleMax(-M_PI*3/2, p2);
 //
 d.x= p2.x - p1.x;
 d.y= p2.y - p1.y;
 //
 w= (double)width() -1;
 h= (double)height()-1;
 //
 if( d.x/d.y > w/h ) {
   m  = w / d.x;
   a.x= 0;
   a.y= (h - d.y * m)/2;
 } else {
   m  = h / d.y;
   a.x= (w - d.x * m)/2;
   a.y= 0;
 }
 radius =  (int) (m);
 centerx=  (int) ((-p1.x) *  m + a.x);
 centery=  (int) ((-p1.y) *  m + a.y);
 //
 fCalcParams= false;
}



void QDialArc::paramsChanged()
{
 fCalcParams= true;
 update();
}

//*****************************************************************
