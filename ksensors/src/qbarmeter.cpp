/***************************************************************************
                          qbarmeter.cpp  -  description
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

#include "qbarmeter.h"

QBarMeter::QBarMeter(QWidget *parent, const char *name): QWidget(parent,name)
{
 count    = 1;
 val[0]   = 0;
 valMax   = 100;
 color[0] = red;
 maxColor = green;
 useValMax= true;
 dir      = dirUp;
 steps    = 10;

}

QBarMeter::~QBarMeter()
{
}

void QBarMeter::setDirection(Direction newDir)
{
 dir= newDir;
 update();
}

void QBarMeter::useValueMax(bool flag)
{
 if(useValMax!=flag) {
   useValMax= flag;
   update();
 }
}

void QBarMeter::setValueMax(double newVal)
{
 if(valMax!=newVal) {
   valMax= newVal;
   update();
 }
}

void QBarMeter::setValueMaxColor(const QColor &newColor)
{
 maxColor= newColor;
 update();
}


void QBarMeter::setValue(double newVal)
{
 if(val[0]!=newVal) {
   val[0]= newVal;
   update();
 }
}

void QBarMeter::setValueColor(const QColor &newColor)
{
 color[0]= newColor;
 update();
}

void QBarMeter::setValue(int index, double newVal)
{
 if(val[index]!=newVal) {
   val[index]= newVal;
   update();
 }
}

void QBarMeter::setValueColor(int index, const QColor &newColor)
{
 if(color[index]!=newColor) {
   color[index]= newColor;
   update();
 }

}

void QBarMeter::setValueCount(int newCount)
{
 if(count!=newCount) {
   count= newCount;
   update();
 }
}

void QBarMeter::setSteps(int newSteps)
{
 steps= newSteps;
 update();
}

void QBarMeter::paintEvent( QPaintEvent *)
{
  int x,y,lx,ly,sx,sy;
  switch(dir) {
    case dirUp   : sx= 0;
                   sy= - height() / steps;
                   lx= width();
                   ly= - (sy * 3) / 4;
                   x = 0;
                   y = height() - ly;
                   break;								
    case dirDown : sx= 0;
                   sy= height() / steps;
                   lx= width();
                   ly= (sy * 3) / 4;
                   x = 0;
                   y = 0;
                   break;
    case dirLeft : sx= - width() / steps;
                   sy= 0;
                   lx= - (sx * 3) / 4;
                   ly= height();
                   x = width() - lx;
                   y = 0;
                   break;
    case dirRight: sx= width() / steps;
                   sy= 0;
                   lx= (sx * 3) / 4;
                   ly= height();
                   x = 0;
                   y = 0;
                   break;
    default:       return;
  }

  if(!useValMax) {
    maxColor= color[count-1];
    valMax= 0;
    for(int i=0; i<count; i++)
     valMax+= val[i];
  }

  int csteps= steps;
  QPainter p(this);

  for(int i= 0; i<count; i++) {
    int v= (int) ( ((double)steps * val[i]) / valMax +0.5);
    if(v==0 && csteps>0 && val[i]>0) v++;
    csteps-= v;
    while(v-->0) {
       p.fillRect(x,y,lx,ly,color[i]);
       x+= sx;
       y+= sy;
    }
  }

  if(csteps>0) {
     do {
         p.fillRect(x,y,lx,ly,maxColor);
         x+= sx;
         y+= sy;
     } while(--csteps>0);
  }

}




