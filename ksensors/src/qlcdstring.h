/***************************************************************************
                          qlcdstring.h  -  description
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

#ifndef QLCDSTRING_H
#define QLCDSTRING_H

#include <qframe.h>
#include <qpainter.h>
#include <qcolor.h>
#include <qstring.h>

#include "qlcddraw.h"

/**
  *@author Miguel Novas
  */

#include <qpalette.h>

class QLCDString : public QWidget  {
Q_OBJECT
public:

  enum Align {
                alignLeft   = 0x0000,
                alignCenter = 0x0001,
                alignRight  = 0x0002,
                alignJustify= 0x0003
             };

  QLCDString( QWidget *parent=0, const char *name=0 );
	~QLCDString();

  void display( const QString &str );

  void setShadow(bool enable);
  bool getShadow() { return (bool)(options & QLcd::drawShadow); };

  void setAlign(Align newAlign);

  void setForeColor(const QColor &fore);
  void setShadowColor(const QColor &sha);

  void setNumberDisplay(bool enable);

  const QColor& foreColor();
  const QColor& shadowColor();

protected:

 void resizeEvent( QResizeEvent *);
 void paintEvent ( QPaintEvent *);

private:

  QString   digitStr;
  int       options;

  QColor forColor,shaColor;
};

#endif
