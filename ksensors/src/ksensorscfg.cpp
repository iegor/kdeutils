/***************************************************************************
                          ksensorscfg.cpp  -  description
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

#include "ksensorscfg.h"

#include <qvariant.h>
#include <qframe.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include <kiconloader.h>
#include <klocale.h>
#include <kaboutdata.h>
#include <kdialogbase.h>

#include <kuniqueapp.h>
#include "lmsensors.h"
#include "sensorslist.h"
#include "generalcfg.h"
#include "systemcfg.h"
#include "lmsensorscfg.h"
#include "aboutcfgdesign.h"

#define Icon(x) KGlobal::instance()->iconLoader()->loadIcon( x, KIcon::NoGroup, KIcon::SizeMedium )

KSensorsCfg::KSensorsCfg(LMSensors *lsensors, const char *name)
: KDialogBase(IconList, name, Apply|Close, Close )
{
   sensors= lsensors;

   //resize( 558, 370 );
   setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
   setCaption( i18n("KSensors Configuration") );

   QFrame *page;
   QVBoxLayout *lay;
   
   page = addPage( i18n("Global settings"), i18n("Global settings"), Icon("earth.png") );
   m_generalcfg = new GeneralCfg(sensors, page);
   lay = new QVBoxLayout( page );
   lay->addWidget(m_generalcfg);
   connect(this, SIGNAL(applyClicked()), m_generalcfg, SLOT(slotApplyChanges()) );  

   QObjectList *list= sensors->getSensorsChips();
   if(list) {
     for(SensorsList *chip= (SensorsList *)list->first(); chip!=0; chip= (SensorsList *)list->next())
     {
       if(chip->getClass()==Sensor::lmSensor)
       {
	       page = addPage( chip->getDescription()+QString(i18n(" sensors")), chip->getDescription()+QString(i18n(" sensors")), Icon("motherboard.png") );
	       cfgWidget = new LMSensorsCfg(chip, page);
	       lay = new QVBoxLayout( page );
	       lay->addWidget(cfgWidget);
	       connect(this, SIGNAL(applyClicked()), cfgWidget, SLOT(slotApplyChanges()) );
       }
       else
       {
	       page = addPage( chip->getDescription(), chip->getDescription(), Icon("harddisk.png") );
	       cfgWidget = new LMSensorsCfg(chip, page);
	       lay = new QVBoxLayout( page );
	       lay->addWidget(cfgWidget);
	       connect(this, SIGNAL(applyClicked()), cfgWidget, SLOT(slotApplyChanges()) );
       }
     }
   }

   page = addPage( i18n( "System Information" ), i18n( "System Information" ), Icon("computers.png") );
   m_systemcfg = new SystemCfg(sensors, page);
   lay = new QVBoxLayout( page );
   lay->addWidget(m_systemcfg);
   connect(this, SIGNAL(applyClicked()), m_systemcfg, SLOT(slotApplyChanges()) );

   adjustSize();
}

KSensorsCfg::~KSensorsCfg()
{
}


