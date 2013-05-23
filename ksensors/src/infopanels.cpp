/***************************************************************************
                          infopanels.cpp  -  description
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

#include "infopanels.h"



InfoPanels::InfoPanels(QWidget *panelsWidget, QObject *parent, const char *name): PanelsGroup(widget,parent,name)
{
 widget= panelsWidget;
 timerPanelCount=0;
 timer = new QTimer(this);
 configChanged("proc.CPUINFO");
 configChanged("proc.RAMINFO");
 configChanged("proc.SWAPINFO");
 configChanged("proc.CPULOAD");
 configChanged("proc.UPTIME");
}

InfoPanels::~InfoPanels(){
}

void InfoPanels::configChanged(const char *name)
{
  if(!strcmp(name,"proc")) readUpdateInterval();
  else {
     Panel *panel= (Panel *)widget->child(name);
     if( Panel::readShow(name)!= (bool)panel ) {
       if(panel) delete panel;
       else {
          if(!strcmp(name,"proc.CPUINFO" )) panel= new CpuPanel(widget,name);
          else
          if(!strcmp(name,"proc.RAMINFO" )) panel= new RamPanel(widget,name,RamPanel::memRAM);
          else
          if(!strcmp(name,"proc.SWAPINFO")) panel= new RamPanel(widget,name,RamPanel::memSWAP);
          else
          if(!strcmp(name,"proc.CPULOAD" )) panel= new CpuTimePanel(widget,name);
          else
          if(!strcmp(name,"proc.UPTIME"  )) panel= new UpTimePanel(widget,name);
          if(panel) timerConnect(panel);
       }
     }
  }
}

void InfoPanels::timerConnect(Panel *display)
{
 if(timerPanelCount==0) timer->start( cfgReadUpdateInterval()*1000 );
 connect( timer  , SIGNAL(timeout()  ), display, SLOT(updateInfo()) );
 connect( display, SIGNAL(destroyed()), this   , SLOT(infoPanelDestroyed()) );
 timerPanelCount++;
}

void InfoPanels::infoPanelDestroyed()
{
 if(--timerPanelCount<=0) timer->stop();
}

void InfoPanels::cfgWriteUpdateInterval(int interval)
{
 KGlobal::config()->setGroup("ShowWidget");
 KGlobal::config()->writeEntry("UpdateInterval" , interval );
}

int InfoPanels::cfgReadUpdateInterval()
{
 KGlobal::config()->setGroup("ShowWidget");
 return KGlobal::config()->readNumEntry("UpdateInterval" , 5 );
}

void InfoPanels::readUpdateInterval()
{
 timer->changeInterval(cfgReadUpdateInterval()*1000);
}

// ******************* Public static methods **********************

