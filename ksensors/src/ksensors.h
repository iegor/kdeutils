/*
 * Copyright (C) 2003 noname <s@s.org>
 */

#ifndef _KSENSORS_H_
#define _KSENSORS_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kmainwindow.h>

/**
 * @short Application Main Window
 * @author noname <s@s.org>
 * @version 0.1
 */
class ksensors : public KMainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    ksensors();

    /**
     * Default Destructor
     */
    virtual ~ksensors();
};

#endif // _KSENSORS_H_
