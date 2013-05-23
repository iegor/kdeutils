/***************************************************************************
                          ksensorscfg.h  -  description
                             -------------------
    begin                : mié may 8 2002
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

#ifndef KSENSORSCFG_H
#define KSENSORSCFG_H

#include <qwidget.h>
#include <kdialogbase.h>

//class QVBoxLayout;
//class QHBoxLayout;
//class QGridLayout;
//class QFrame;
//class QIconView;
//class QIconViewItem;
class KDialogBase;
class GeneralCfg;
class LMSensorsCfg;
class SystemCfg;

class LMSensors;

/**
  *@author Miguel Novas
  */

class KSensorsCfg : public KDialogBase 
{
Q_OBJECT
public:
	KSensorsCfg(LMSensors *lsensors, const char *name=0);
	~KSensorsCfg();

/*protected slots:

  void slotSelectionChanged();
*/
private:

   LMSensors    *sensors;
   GeneralCfg   *m_generalcfg;
   LMSensorsCfg *m_lmsensorscfg;
   SystemCfg    *m_systemcfg;

   QWidget     *cfgWidget;

   /*
   QIconView   *IconView;
   QWidget     *cfgWidget;
   QHBoxLayout *FormLayout;*/
};

#endif
