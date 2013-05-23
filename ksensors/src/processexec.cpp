/***************************************************************************
                          processexec.cpp  -  description
                             -------------------
    begin                : sáb abr 27 2002
    copyright            : (C) 2002 by asdf
    email                : dsf
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <string.h>
#include "processexec.h"

ProcessExec::ProcessExec(): KProcess()
{
 clearData();
 connect( this, SIGNAL(receivedStdout(KProcess *, char *, int)),this, SLOT(slotReceivedStdout(KProcess *, char *, int)) );
 connect( this, SIGNAL(receivedStderr(KProcess *, char *, int)),this, SLOT(slotReceivedStderr(KProcess *, char *, int)) );
}

ProcessExec::~ProcessExec(){
}

bool ProcessExec::run()
{
 clearData();
 return start( NotifyOnExit, Communication(Stdout | Stderr )); // | NoRead));
}

bool ProcessExec::runAndWait()
{
 clearData();
 return start(Block,Communication(Stdout | Stderr));
}

void ProcessExec::slotReceivedStdout(KProcess *proc, char *buf, int len)
{
  buffer = QString(buf);
}

void ProcessExec::slotReceivedStderr(KProcess *proc, char *buf, int len)
{
 fErrors= true;
 slotReceivedStdout(proc,buf,len);
}

