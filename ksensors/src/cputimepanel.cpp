/***************************************************************************
                          rampanel.cpp  -  description
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

#include "cputimepanel.h"

#include "procinfo.h"

CpuTimePanel::CpuTimePanel(QWidget *parent, const char *name): Panel(parent,name)
{
 lcd1= new QLCDString(this);
 lcd1->setGeometry(16,38,46,8);
 lcd1->setForeColor(red);
 lcd1->setAlign(QLCDString::alignLeft);
 lcd1->setNumberDisplay(true);
 lcd1->installEventFilter(this);

 QColor color2( 200, 0, 0);

 lcd2= new QLCDString(this);
 lcd2->setGeometry(16,28,46,8);
 lcd2->setForeColor(color2);
 lcd2->setAlign(QLCDString::alignLeft);
 lcd2->setNumberDisplay(true);
 lcd2->installEventFilter(this);

 QColor color3( 128,32,0 );

 lcd3= new QLCDString(this);
 lcd3->setGeometry(16,18,46,8);
 lcd3->setForeColor(color3);
 lcd3->setAlign(QLCDString::alignLeft);
 lcd3->setNumberDisplay(true);
 lcd3->installEventFilter(this);

 lcd4= new QLCDString(this);
 lcd4->setGeometry(16,8,46,8);
 lcd4->setForeColor(darkGreen);
 lcd4->setAlign(QLCDString::alignLeft);
 lcd4->setNumberDisplay(true);
 lcd4->installEventFilter(this);

 barMeter= new QBarMeter(this);
 barMeter->setGeometry(6,6,6,40);
 barMeter->setDirection(QBarMeter::dirUp);
 barMeter->setSteps(20);
 barMeter->useValueMax(false);
 barMeter->setValueColor( 0, red );
 barMeter->setValueColor( 1, color2 );
 barMeter->setValueColor( 2, color3 );
 barMeter->setValueColor( 3, QColor(0,220,0) );
 barMeter->setValueCount(4);
 barMeter->installEventFilter(this);

 getCpuTime(&old_user,&old_nice,&old_system,&old_idle);
 updateInfo();
}

CpuTimePanel::~CpuTimePanel(){
}

void CpuTimePanel::drawContents(QPainter *p)
{
 int w= width();
 int h= height();
 int i2= (h * 4) / 5;
 int th= h-i2-h/11;
 QLcd::draw(p, 2,i2+1,w-4,th, "CPU STATE",QLcd::alignCenter,&getColorTitle());
}


void CpuTimePanel::updateInfo()
{
 int user,nice,system,idle;

 getCpuTime(&user,&nice,&system,&idle);

 int puser  = user   - old_user;
 int pnice  = nice   - old_nice;
 int psystem= system - old_system;
 int pidle  = idle   - old_idle;

 int ptotal=  puser+pnice+psystem+pidle;

 if (ptotal==0) ptotal=1;

 QString str;
 str.sprintf ("USER%5.1f" , (float)puser  /ptotal * 100 );
 lcd1->display(str);
 str.sprintf ("NICE%5.1f" , (float)pnice  /ptotal * 100 );
 lcd2->display(str);
 str.sprintf ("SYS %5.1f" , (float)psystem/ptotal * 100 );
 lcd3->display(str);
 str.sprintf ("IDLE%5.1f" , (float)pidle  /ptotal * 100 );
 lcd4->display(str);

 barMeter->setValue(0,(double)puser);
 barMeter->setValue(1,(double)pnice);
 barMeter->setValue(2,(double)psystem);
 barMeter->setValue(3,(double)pidle);

 old_user  = user;
 old_nice  = nice;
 old_system= system;
 old_idle  = idle;
}

void CpuTimePanel::resizeEvent ( QResizeEvent *e )
{
  int w= width();
  int h= height();

  int lw= (w*10)/14;
  int lh= h/8;
  int sh= (h*10)/64;
  int i= h/8;
  int i0= i-1;
  lcd4    ->setGeometry(w/4 ,i ,lw,lh);
  i+= sh;
  lcd3    ->setGeometry(w/4 ,i ,lw,lh);
  i+= sh;
  lcd2    ->setGeometry(w/4 ,i ,lw,lh);
  i+= sh;
  lcd1    ->setGeometry(w/4 ,i ,lw,lh);

  int bl= i+lh-i0;
  barMeter->setGeometry(w/10,i0,w/10,bl);
  barMeter->setSteps(bl/2);
}
