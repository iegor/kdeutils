/***************************************************************************
                          display.h  -  description
                             -------------------
    begin                : Sun Nov 11 2001
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

#ifndef PANEL_H
#define PANEL_H

#include <qframe.h>
#include <kconfig.h>
#include <qpalette.h>

/**
  *@author Miguel Novas
  */

class Panel : public QFrame  {
Q_OBJECT
public:

	Panel(QWidget *parent, const char *name);
	~Panel();

  inline const QColor &getColorTitle() { return colorGroup().text(); };
  inline const QColor &getColorValue() { return colorGroup().foreground(); };

  static bool readShow (const char *name);
  static void writeShow(const char *name, bool fShow);

public slots:

 virtual void updateInfo(){};

signals:

  void eventReceived(QEvent *);

private:

  bool eventFilter( QObject *o , QEvent *e);
};

#endif
