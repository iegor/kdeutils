/*
 * Copyright (C) 2003 noname <s@s.org>
 */

#include "ksensors.h"

#include <qlabel.h>

#include <kmainwindow.h>
#include <klocale.h>

ksensors::ksensors()
    : KMainWindow( 0, "ksensors" )
{
    // set the shell's ui resource file
    setXMLFile("ksensorsui.rc");

    new QLabel( "Hello World", this, "hello label" );
}

ksensors::~ksensors()
{
}

#include "ksensors.moc"
