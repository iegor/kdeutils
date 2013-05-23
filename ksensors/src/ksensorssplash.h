/***************************************************************************
                          ksensorssplash.h  -  description
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

#ifndef KSENSORSSPLASH_H
#define KSENSORSSPLASH_H

#include <qwidget.h>
//#include <qwidget.h>


/**
  *@author Miguel Novas
  */

class KSensorsSplash : public QWidget  {
 Q_OBJECT
public:

  KSensorsSplash(QWidget *parent=0, const char *name=0 );
	~KSensorsSplash();

protected:

  void timerEvent( QTimerEvent * );
};

#endif
