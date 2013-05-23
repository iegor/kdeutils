/***************************************************************************
                          processexec.h  -  description
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

#ifndef PROCESSEXEC_H
#define PROCESSEXEC_H

#include <unistd.h>
#include <kprocess.h>

/**
  *@author asdf
  */

class ProcessExec : public KProcess  {
Q_OBJECT
public:
	ProcessExec();
	~ProcessExec();

  bool run();
  bool runAndWait();
  bool outputErrors()				{ return fErrors; };

  inline QString getStdoutData()		{ return buffer; };
  inline unsigned int getStdoutDataLen()	{ return buffer.length(); }
  inline void clearData()			{ buffer.truncate(0); fErrors= false; };

protected slots:

 void slotReceivedStdout(KProcess *proc, char *buf, int len);
 void slotReceivedStderr(KProcess *proc, char *buf, int len);

private:

  static const int bufMax= 1023;
  QString buffer;
  bool fErrors;
};

#endif
