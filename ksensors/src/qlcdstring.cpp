/***************************************************************************
                          qlcdstring.cpp  -  description
                             -------------------
    begin                : Sat Jul 21 2001
    copyright            : (C) 2001 by Michael
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


#include "qlcdstring.h"

#include <qpalette.h>


QLCDString::QLCDString( QWidget *parent, const char *name ): QWidget( parent, name )
{
 digitStr= "";
 options= QLcd::alignCenter;

 QColorGroup g= colorGroup();
 forColor= g.foreground();
 shaColor= g.shadow();
}


QLCDString::~QLCDString(){
}

void QLCDString::display( const QString &str )
{
  digitStr= str;
  update();
}


void QLCDString::setAlign(Align newAlign)
{
 if( (options & QLcd::alignMask)!=newAlign ) {
   options= (options & ~QLcd::alignMask ) | newAlign;
   update();
 }
}

const QColor& QLCDString::foreColor()
{
 return forColor;
}

const QColor& QLCDString::shadowColor()
{
 return shaColor;
}


void QLCDString::setForeColor(const QColor &fore)
{
  forColor= fore;
  update();
}

void QLCDString::setShadowColor(const QColor &sha)
{
 shaColor= sha;
 update();
}


void QLCDString::resizeEvent ( QResizeEvent *)
{
 update();
}


void QLCDString::setShadow(bool enable)
{
 if( (bool)(options & QLcd::drawShadow) != enable ) {
   options^= QLcd::drawShadow;
   update();
 }
}


void QLCDString::setNumberDisplay(bool enable)
{
 if( (bool)(options & QLcd::drawNumber) != enable ) {
   options^= QLcd::drawNumber;
   update();
 }
}


void QLCDString::paintEvent( QPaintEvent *e )
{
QPainter p(this);

 QLcd::draw(&p,0,0,width(),height(),digitStr.latin1(),options,&forColor,&shaColor);
}








