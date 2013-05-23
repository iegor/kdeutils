/***************************************************************************
                          ksensorssplash.cpp  -  description
                             -------------------
    begin                : sáb abr 20 2002
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

#include "ksensorssplash.h"

#include <kapp.h>
#include <kstandarddirs.h>

KSensorsSplash::KSensorsSplash(QWidget *parent, const char *name ) :
    QWidget(parent,name, WStyle_NoBorder | WStyle_Customize | WDestructiveClose | WStyle_StaysOnTop )
{
   QPixmap pm;
   pm.load( locate("appdata", "pics/ksensorssplash.png") );
   setBackgroundPixmap(pm);
   setGeometry( QApplication::desktop()->width ()/2-pm.width()/2,
                QApplication::desktop()->height()/2-pm.height()/2,
                pm.width(),pm.height()
               );
   show();
   startTimer( 4000 );
}

KSensorsSplash::~KSensorsSplash(){
}

void KSensorsSplash::timerEvent( QTimerEvent * )
{
 close();
}
