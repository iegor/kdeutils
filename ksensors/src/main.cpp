/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : dom ago 19 02:10:35 EDT 2001
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

#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>

#include <kuniqueapp.h>
#include "ksensorssplash.h"
#include "lmsensorsdock.h"

static const char *description =
	I18N_NOOP("KSensors - A nice lmsensors frontend for KDE");
// INSERT A DESCRIPTION FOR YOUR APPLICATION HERE
	
	
static KCmdLineOptions options[] =
{
  { "nodock", I18N_NOOP("Don't dock in KDE system tray."), 0 },
  { "splash", I18N_NOOP("Show splash screen."), 0 },
  { 0, 0, 0 }
  // INSERT YOUR COMMANDLINE OPTIONS HERE
};


int main(int argc, char *argv[])
{

  KAboutData aboutData( "ksensors", I18N_NOOP("KSensors"),
    VERSION, description, KAboutData::License_GPL,
    "(c) 2001, Miguel Novas", 0, 0, "michaell@teleline.es");
  aboutData.addAuthor("Miguel Novas",0, "michaell@teleline.es");

  KCmdLineArgs::init( argc, argv, &aboutData );
  KCmdLineArgs::addCmdLineOptions( options );
  KUniqueApplication::addCmdLineOptions();

  KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
  bool noDock= !args->isSet("dock");
  bool showSplash=  args->isSet("splash");
  args->clear();

  if(!KUniqueApplication::start())  return 0;
  KUniqueApplication a;

  KConfig *cfg= kapp->config();
  cfg->setGroup("General");
  if( cfg->readEntry("Version")!=aboutData.version() ) {
    cfg->writeEntry("Version",aboutData.version());
    showSplash= true;
  }

  if(showSplash)  (void)new KSensorsSplash();

  LMSensorsDock *ksensors= new LMSensorsDock(noDock);
  QObject::connect( ksensors, SIGNAL(destroyed()), kapp, SLOT(quit()) );
  QObject::connect( kapp, SIGNAL(saveYourself()), ksensors, SLOT(saveConfig()) );

  return a.exec();
}
