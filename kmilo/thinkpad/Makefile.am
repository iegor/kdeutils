#    This file is part of the KDE project
#    Copyright (C) 2003 George Staikos <staikos@kde.org>

#    This library is free software; you can redistribute it and/or
#    modify it under the terms of the GNU Library General Public
#    License as published by the Free Software Foundation; either
#    version 2 of the License, or (at your option) any later version.

#    This library is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    Library General Public License for more details.

#    You should have received a copy of the GNU Library General Public License
#    along with this library; see the file COPYING.LIB.  If not, write to
#    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
#    Boston, MA 02110-1301, USA.

SUBDIRS = . kcmthinkpad

INCLUDES=-I$(srcdir)/../kmilod $(all_includes)

kde_module_LTLIBRARIES = kmilo_thinkpad.la

kmilo_thinkpad_la_LDFLAGS = -module $(KDE_PLUGIN) $(all_libraries)
kmilo_thinkpad_la_LIBADD = ../kmilod/libkmilo.la $(LIB_KIO)
kmilo_thinkpad_la_SOURCES = thinkpad.cpp
METASOURCES = AUTO

noinst_HEADERS = thinkpad.h

services_DATA = kmilo_thinkpad.desktop
servicesdir = $(kde_servicesdir)/kmilo

messages:
	$(XGETTEXT) $(kmilo_thinkpad_la_SOURCES) -o $(podir)/kmilo_thinkpad.pot
