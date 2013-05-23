/***************************************************************************
                          display.cpp  -  description
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

#include "panel.h"

#include <kglobal.h>

Panel::Panel(QWidget *parent, const char *name) : QFrame(parent,name)
{
 setFrameStyle(QFrame::Panel|QFrame::Raised);
 resize(64,64);
 installEventFilter(this);
}

Panel::~Panel(){
}


// Maybe another better solution to capture childs of child widgets events ???

bool Panel::eventFilter( QObject *o , QEvent *e)
{
 emit eventReceived(e);
 return false;
}


//*****************************************************************************

bool Panel::readShow(const char *name)
{
 KGlobal::config()->setGroup(name);
 return KGlobal::config()->readBoolEntry("show",false);
}

void Panel::writeShow(const char *name, bool fShow)
{
 KGlobal::config()->setGroup(name);
 KGlobal::config()->writeEntry("show",fShow);
}


//*****************************************************************************
