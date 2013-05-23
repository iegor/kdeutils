# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = ksensors.h aboutcfgdesign.h \
	cpupanel.h cputimepanel.h generalcfgdesign.h generalcfg.h \
	hdsensorslist.h i8ksensorslist.h infopanels.h ksensorscfg.h \
	ksensors.h ksensorssplash.h lmsensordockpanel.h lmsensor.h \
	lmsensorpanel.h lmsensorsalarms.h lmsensorscfgdesign.h \
	lmsensorscfg.h lmsensorschip.h lmsensorsdock.h lmsensors.h \
	lmsensorswidget.h palettecfgdesign.h palettecfg.h panel.h \
	panelsgroup.h processexec.h procinfo.h qbarmeter.h \
	qdialarc.h qlcddraw.h qlcdstring.h rampanel.h sensor.h \
	sensorslist.h systemcfgdesign.h systemcfg.h uptimepanel.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/ksensors.pot


#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = ksensors

# the application source, library search path, and link libraries
ksensors_SOURCES = main.cpp ksensors.cpp aboutcfgdesign.ui \
		   cpupanel.cpp cputimepanel.cpp generalcfg.cpp \
		   generalcfgdesign.ui hdsensorslist.cpp i8ksensorslist.cpp \
		   infopanels.cpp ksensorscfg.cpp \
		   ksensorssplash.cpp lmsensor.cpp lmsensordockpanel.cpp \
		   lmsensorpanel.cpp lmsensorsalarms.cpp lmsensorscfg.cpp \
		   lmsensorscfgdesign.ui lmsensorschip.cpp lmsensors.cpp \
		   lmsensorsdock.cpp lmsensorswidget.cpp palettecfg.cpp \
		   palettecfgdesign.ui panel.cpp panelsgroup.cpp \
		   processexec.cpp procinfo.cpp qbarmeter.cpp \
		   qdialarc.cpp qlcdraw.cpp qlcdstring.cpp \
		   rampanel.cpp sensor.cpp sensorslist.cpp \
		   systemcfg.cpp systemcfgdesign.ui uptimepanel.cpp

ksensors_LDFLAGS = $(KDE_RPATH) $(all_libraries)
ksensors_LDADD = $(LIB_KDEUI) $(LIB_KDECORE) -lsensors -lm

# this is where the desktop file will go 
shelldesktopdir   = $(xdg_appsdir)
shelldesktop_DATA = ksensors.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/ksensors
shellrc_DATA = ksensorsui.rc

SUBDIRS = pics sounds

