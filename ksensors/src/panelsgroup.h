/***************************************************************************
                          panelsfactory.h  -  description
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

#ifndef PANELSGROUP_H
#define PANELSGROUP_H

#include <qobject.h>

#include <panel.h>
/**
  *@author Miguel Novas
  */

class PanelsGroup : public QObject  {
Q_OBJECT
public:

 PanelsGroup(QWidget *widget, QObject *parent=0, const char *name=0) {};
 	~PanelsGroup() {};


public slots:

  virtual void configChanged(const char *name)= 0;

};

#endif
