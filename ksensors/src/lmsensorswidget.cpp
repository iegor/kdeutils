/***************************************************************************
                          lmsensorswidget.cpp  -  description
                             -------------------
    begin                : Mon Aug 6 2001
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

#include <qobject.h>
#include <qobjectlist.h>
#include <qpixmap.h>
#include <qtimer.h>

#include <kiconloader.h>
#include <kstddirs.h>

#include "lmsensorswidget.h"


/***************************************************************************
 *  Public methods                                                         *
 ***************************************************************************/

LMSensorsWidget::LMSensorsWidget(LMSensors *lsensors,QWidget *parent, const char *name )
                                :  QWidget(parent,name,
                                   WStyle_Customize    |
                                   WType_TopLevel      |
                                   WStyle_StaysOnTop   |
                                   WStyle_NormalBorder |
                                   WDestructiveClose     )
{
 panelsSize= 64;
 setMinimumSize(0,0);
 setSizeIncrement(64,64);
 setBaseSize(64,64);
 //
 sensors= lsensors;
 //
 childDraging = 0;
 //
 setCaption("KSensors");
 //
 loadPalette();
 //
 loadGeneralOptions();
 //
 setBackgroundPixmap( UserIcon("ksensorsbackground.png") );
 //
 KConfig *cfg= KGlobal::config();
 cfg->setGroup("ShowWidget");
 QRect rect(32,32,64*4,64*3);
 rect= cfg->readRectEntry ("geometry", &rect);
 move( rect.topLeft() );
 resize( rect.size() );
 //
 createSensorPanels();
 //
 infoPanels= new InfoPanels(this);
 //
 connect(sensors, SIGNAL(configChanged(const char *)), this, SLOT(slotConfigChanged(const char *)) );
}


LMSensorsWidget::~LMSensorsWidget()
{
 if(x()>=0 && y()>=0) {
   KConfig *cfg= KGlobal::config();
   cfg->setGroup("ShowWidget");
   //cfg->writeEntry("geometry" , geometry() );
   cfg->writeEntry( "geometry" , QRect(pos(), size()) );
 }
 delete infoPanels;
}

// ******************* Protected slots ******************************

void LMSensorsWidget::slotConfigChanged(const char *name)
{
 if(name) {
    Panel *panel= (Panel *)child(name);
    Sensor *sensor= sensors->getSensor(name);
    if(sensor) {
      if(Panel::readShow(name)!= (bool)panel ) {
         if(panel) { delete panel; }
         else      (void)new LMSensorPanel(sensor, this, sensor->name() );
      }
    } else infoPanels->configChanged(name);
    panel= (Panel *)child(name);
    if(panel) loadPalette(panel);
 } else {
    loadPalette();
    loadGeneralOptions();
 }
}


/***************************************************************************
 * Private methods                                                         *
 ***************************************************************************/

void LMSensorsWidget::childEvent(QChildEvent *e)
{
 if(e->inserted()) {
   loadDisplayConfig((Panel *)e->child());
 }
}

// ************* Draging panels and show menu ************************

void LMSensorsWidget::childEventReceived(QEvent *e)
{
QMouseEvent *m = (QMouseEvent*)e;

 switch(e->type()) {
  case QEvent::MouseButtonPress:

      if( m->button()==LeftButton ) startDragChild(m,(QWidget *)sender());
      break;

  case QEvent::MouseButtonRelease:

      if( m->button()==RightButton ) emit rightMouseClicked(m);
      break;
 }
}


void LMSensorsWidget::startDragChild(QMouseEvent *m, QWidget *w)
{
	if(childDraging==0)
	{
		childDraging= w;    
		grabMouse(sizeAllCursor);
		origMousePt = w->mapFromGlobal(m->globalPos());
		//w->move( m->globalPos()-mapToGlobal(QPoint(0,0))-origMousePt);
		w->raise();
		w->update();
	}
}

void LMSensorsWidget::endDragChild()
{
int x= childDraging->x();
int y= childDraging->y();

 if(x<0) x=0;
 if(y<0) y=0;
 releaseMouse();
 childDraging->move(
                     ((x+childDraging->width() /2) / panelsSize) * panelsSize ,
                     ((y+childDraging->height()/2) / panelsSize) * panelsSize
                   );
 saveDisplayConfig((Panel *)childDraging);
 childDraging= 0;
}

void LMSensorsWidget::mouseMoveEvent ( QMouseEvent *m )
{
	if(childDraging) 
	{ 
		childDraging->move(m->pos()-origMousePt);
		childDraging->update(); 
	}
}


void LMSensorsWidget::mouseReleaseEvent ( QMouseEvent *m )
{
 if(childDraging && m->button()==LeftButton)  endDragChild();
 else
   if(m->button()==RightButton) emit rightMouseClicked(m);
}

// ********************** Panels creation ************************

void LMSensorsWidget::findUnusedPosition(int *px,int *py)
{
bool found;
uint mx,my,x,y,a[32];
QObjectList *list= (QObjectList *)children();

 for(y=0; y<32; y++) a[y]= 0;
 mx= 0; my= 0;
 if(list)
   for(QWidget *obj= (QWidget *)list->first(); obj!=0; obj= (QWidget *)list->next())
     {
       y=obj->y()/panelsSize;
       x=obj->x()/panelsSize;
       if(x<32 && y<32) a[y]|=  (1 << x);
       if(x>mx) mx= x;
       if(y>my) my= y;
     }
 //
 for(x=0,y=0,found=false;y<=my && !found;) {
   found= ((a[y] & (1 << x))==0);
   if(!found)
     if(++x>mx) { x= 0; y++; }
 }

 if(!found) {
    x= (width()-1) / panelsSize;
    if(x>mx) { x= mx+1; y= 0;    }
    else     { x= 0;    y= my+1; }
 }
 //
 *px= x;
 *py= y;
}

void LMSensorsWidget::loadDisplayConfig(Panel *display)
{
 if(display==0) return;

 loadPalette(display);

 bool fNoCfg;
 QPoint p(-1,-1);
 KConfig *cfg= KGlobal::config();
 cfg->setGroup(display->name());
 p= cfg->readPointEntry("showPos", &p );
 fNoCfg= (p.x()<0 || p.y()<0);
 if(fNoCfg) findUnusedPosition(&p.rx(),&p.ry());
 display->move(p.x()*panelsSize,p.y()*panelsSize);
 display->resize(panelsSize,panelsSize);
 display->show();
 if(fNoCfg) {
    saveDisplayConfig(display);
    adjustSize();
 }
 display->installEventFilter(this);
 connect(display, SIGNAL(eventReceived(QEvent *)), this, SLOT(childEventReceived(QEvent *)) );
}


void LMSensorsWidget::saveDisplayConfig(Panel *display)
{
KConfig *cfg= KGlobal::config();

 cfg->setGroup(display->name());
 cfg->writeEntry("show",true);
 QPoint p= display->pos()/panelsSize;
 cfg->writeEntry("showPos",p);
}

void LMSensorsWidget::createSensorPanels()
{
 QObjectList *chips= sensors->getSensorsChips();
 if(chips)
    for(LMSensorsChip *chip= (LMSensorsChip *)chips->first(); chip!=0; chip= (LMSensorsChip *)chips->next()) {
       QObjectList *list= (QObjectList *)chip->getSensors();
       if(list) {
           for(LMSensor *sensor= (LMSensor *)list->first(); sensor!=0; sensor= (LMSensor *)list->next()) {
             if( Panel::readShow(sensor->name()) )
                (void) new LMSensorPanel(sensor, this, sensor->name() );
           }
       }
    }
}

void LMSensorsWidget::resizePanels(int newSize)
{
QObjectList *panels= (QObjectList *)children();

 if(panels)
   for(QWidget *panel= (QWidget *)panels->first(); panel!=0; panel= (QWidget *)panels->next()) {
     panel->move( (panel->x()/panelsSize)*newSize, (panel->y()/panelsSize)*newSize);
     panel->resize(newSize,newSize);
   }
 panelsSize= newSize;
 adjustSize();
}

int LMSensorsWidget::cfgReadPanelSize()
{
KConfig *cfg= KGlobal::config();
 cfg->setGroup( "ShowWidget" );
 return cfg->readNumEntry("PanelsSize",64);
}

void LMSensorsWidget::cfgWritePanelSize(int newSize)
{
KConfig *cfg= KGlobal::config();
 cfg->setGroup( "ShowWidget" );
 cfg->writeEntry("PanelsSize",newSize);
}


void LMSensorsWidget::loadGeneralOptions()
{
 int newSize= cfgReadPanelSize();
 if(panelsSize!=newSize) {
   setSizeIncrement(newSize,newSize);
   setBaseSize(newSize,newSize);
   resizePanels(newSize);
 }
}

// ************************+******** Palettes stuff ****************************

void LMSensorsWidget::loadPalette(Panel *panel)
{
  QPalette pal= palette();
  if(panel) {
    if(cfgReadPalette(pal,panel->name(),false))  panel->setPalette(pal);
    else                                         panel->unsetPalette();
  } else {
    cfgReadPalette(pal,0,true);
    setPalette(pal);
  }
}


void LMSensorsWidget::getDefaultPalette(QPalette &pal)
{
 pal.setColor(QColorGroup::Background, Qt::white );
 pal.setColor(QColorGroup::Light     , Qt::white );
 pal.setColor(QColorGroup::Dark,       Qt::black );
 pal.setColor(QColorGroup::Foreground, Qt::black );
 pal.setColor(QColorGroup::Text,       Qt::black );
}


bool LMSensorsWidget::cfgReadPalette(QPalette &pal,const char *name, bool returnDefault)
{
 KConfig *cfg= KGlobal::config();
 cfg->setGroup( name ? name : "General" );
 if (cfg->readBoolEntry("PaletteActive",false)) {
    pal.setColor(QColorGroup::Background, cfg->readColorEntry("ColorBackground",&Qt::white) );
    pal.setColor(QColorGroup::Light     , cfg->readColorEntry("ColorBackground",&Qt::white) );
    pal.setColor(QColorGroup::Dark,       cfg->readColorEntry("ColorShadow"    ,&Qt::black) );
    pal.setColor(QColorGroup::Foreground, cfg->readColorEntry("ColorValue"     ,&Qt::black) );
    pal.setColor(QColorGroup::Text,       cfg->readColorEntry("ColorTitle"     ,&Qt::black) );
    return true;
 } else {
    if(returnDefault) {
      getDefaultPalette(pal);
      return true;
    }
 }
 return false;
}

void LMSensorsWidget::cfgWritePalette(const QPalette &pal,const char *name)
{
 KConfig *cfg= KGlobal::config();
 QColorGroup colors= pal.active();
 cfg->setGroup( name ? name : "General" );
 cfg->writeEntry("PaletteActive",true);
 cfg->writeEntry("ColorBackground",colors.background() );
 cfg->writeEntry("ColorShadow"    ,colors.dark()       );
 cfg->writeEntry("ColorValue"     ,colors.foreground() );
 cfg->writeEntry("ColorTitle"     ,colors.text()       );
}

void LMSensorsWidget::cfgUnsetPalette(const char *name)
{
 KGlobal::config()->setGroup( name ? name : "General" );
 KGlobal::config()->writeEntry("PaletteActive",false);
}

// *********************************** End *************************************

