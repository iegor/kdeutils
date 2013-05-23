#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './systemcfgdesign.ui'
**
** Created: mer aoû 18 23:39:06 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "systemcfgdesign.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlistbox.h>
#include <qframe.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qspinbox.h>
#include <qslider.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SystemCfgDesign as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SystemCfgDesign::SystemCfgDesign( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SystemCfgDesign" );
    SystemCfgDesignLayout = new QGridLayout( this, 1, 1, 8, 4, "SystemCfgDesignLayout"); 

    TabWidget = new QTabWidget( this, "TabWidget" );

    tab = new QWidget( TabWidget, "tab" );
    tabLayout = new QHBoxLayout( tab, 8, 8, "tabLayout"); 

    listSensors = new QListBox( tab, "listSensors" );
    listSensors->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, listSensors->sizePolicy().hasHeightForWidth() ) );
    listSensors->setMinimumSize( QSize( 160, 0 ) );
    listSensors->setMaximumSize( QSize( 160, 32767 ) );
    listSensors->setFrameShape( QListBox::StyledPanel );
    listSensors->setFrameShadow( QListBox::Sunken );
    listSensors->setLineWidth( 2 );
    listSensors->setColumnMode( QListBox::FixedNumber );
    tabLayout->addWidget( listSensors );

    framePanelCfg = new QFrame( tab, "framePanelCfg" );
    framePanelCfg->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, framePanelCfg->sizePolicy().hasHeightForWidth() ) );
    framePanelCfg->setFrameShape( QFrame::NoFrame );
    framePanelCfg->setFrameShadow( QFrame::Raised );
    framePanelCfgLayout = new QVBoxLayout( framePanelCfg, 0, 4, "framePanelCfgLayout"); 

    GroupBox13 = new QGroupBox( framePanelCfg, "GroupBox13" );
    GroupBox13->setMinimumSize( QSize( 0, 50 ) );
    GroupBox13->setMaximumSize( QSize( 32767, 50 ) );
    GroupBox13->setColumnLayout(0, Qt::Vertical );
    GroupBox13->layout()->setSpacing( 6 );
    GroupBox13->layout()->setMargin( 11 );
    GroupBox13Layout = new QGridLayout( GroupBox13->layout() );
    GroupBox13Layout->setAlignment( Qt::AlignTop );

    checkShow = new QCheckBox( GroupBox13, "checkShow" );
    checkShow->setCursor( QCursor( 0 ) );

    GroupBox13Layout->addWidget( checkShow, 0, 0 );
    framePanelCfgLayout->addWidget( GroupBox13 );

    boxPanelPalette = new QGroupBox( framePanelCfg, "boxPanelPalette" );
    boxPanelPalette->setMinimumSize( QSize( 0, 90 ) );
    framePanelCfgLayout->addWidget( boxPanelPalette );
    Spacer4_2 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    framePanelCfgLayout->addItem( Spacer4_2 );
    tabLayout->addWidget( framePanelCfg );
    TabWidget->insertTab( tab, QString("") );

    tab_2 = new QWidget( TabWidget, "tab_2" );
    tabLayout_2 = new QVBoxLayout( tab_2, 11, 6, "tabLayout_2"); 

    GroupBox7 = new QGroupBox( tab_2, "GroupBox7" );
    GroupBox7->setMinimumSize( QSize( 0, 0 ) );
    GroupBox7->setColumnLayout(0, Qt::Vertical );
    GroupBox7->layout()->setSpacing( 12 );
    GroupBox7->layout()->setMargin( 12 );
    GroupBox7Layout = new QHBoxLayout( GroupBox7->layout() );
    GroupBox7Layout->setAlignment( Qt::AlignTop );

    SpinUpdateTime = new QSpinBox( GroupBox7, "SpinUpdateTime" );
    SpinUpdateTime->setMinValue( 1 );
    SpinUpdateTime->setValue( 5 );
    GroupBox7Layout->addWidget( SpinUpdateTime );

    SliderUpdateTime = new QSlider( GroupBox7, "SliderUpdateTime" );
    SliderUpdateTime->setMaxValue( 60 );
    SliderUpdateTime->setValue( 5 );
    SliderUpdateTime->setOrientation( QSlider::Horizontal );
    SliderUpdateTime->setTickmarks( QSlider::Right );
    SliderUpdateTime->setTickInterval( 1 );
    GroupBox7Layout->addWidget( SliderUpdateTime );
    tabLayout_2->addWidget( GroupBox7 );
    Spacer18 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_2->addItem( Spacer18 );
    TabWidget->insertTab( tab_2, QString("") );

    SystemCfgDesignLayout->addWidget( TabWidget, 0, 0 );
    languageChange();
    resize( QSize(334, 240).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( SliderUpdateTime, SIGNAL( valueChanged(int) ), SpinUpdateTime, SLOT( setValue(int) ) );
    connect( SpinUpdateTime, SIGNAL( valueChanged(int) ), SliderUpdateTime, SLOT( setValue(int) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SystemCfgDesign::~SystemCfgDesign()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SystemCfgDesign::languageChange()
{
    setCaption( tr2i18n( "SystemCfgDesign" ) );
    GroupBox13->setTitle( QString::null );
    checkShow->setText( tr2i18n( "Visible" ) );
    boxPanelPalette->setTitle( tr2i18n( "Colors" ) );
    TabWidget->changeTab( tab, tr2i18n( "System Panels" ) );
    GroupBox7->setTitle( tr2i18n( "Update interval" ) );
    SpinUpdateTime->setSuffix( tr2i18n( "s" ) );
    TabWidget->changeTab( tab_2, tr2i18n( "Preferences" ) );
}

#include "systemcfgdesign.moc"
