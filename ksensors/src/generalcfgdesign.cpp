#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './generalcfgdesign.ui'
**
** Created: mer aoû 18 23:39:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "generalcfgdesign.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a GeneralCfgDesign as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
GeneralCfgDesign::GeneralCfgDesign( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "GeneralCfgDesign" );
    GeneralCfgDesignLayout = new QGridLayout( this, 1, 1, 8, 6, "GeneralCfgDesignLayout"); 

    ButtonGroup5 = new QButtonGroup( this, "ButtonGroup5" );
    ButtonGroup5->setColumnLayout(0, Qt::Vertical );
    ButtonGroup5->layout()->setSpacing( 6 );
    ButtonGroup5->layout()->setMargin( 11 );
    ButtonGroup5Layout = new QGridLayout( ButtonGroup5->layout() );
    ButtonGroup5Layout->setAlignment( Qt::AlignTop );

    Radio64 = new QRadioButton( ButtonGroup5, "Radio64" );
    Radio64->setChecked( TRUE );

    ButtonGroup5Layout->addWidget( Radio64, 0, 0 );

    Radio56 = new QRadioButton( ButtonGroup5, "Radio56" );

    ButtonGroup5Layout->addWidget( Radio56, 0, 1 );

    Radio48 = new QRadioButton( ButtonGroup5, "Radio48" );

    ButtonGroup5Layout->addWidget( Radio48, 0, 2 );

    GeneralCfgDesignLayout->addWidget( ButtonGroup5, 0, 0 );

    boxGeneralPalette = new QGroupBox( this, "boxGeneralPalette" );
    boxGeneralPalette->setMinimumSize( QSize( 0, 65 ) );

    GeneralCfgDesignLayout->addWidget( boxGeneralPalette, 1, 0 );

    GroupBox2 = new QGroupBox( this, "GroupBox2" );
    GroupBox2->setColumnLayout(0, Qt::Vertical );
    GroupBox2->layout()->setSpacing( 6 );
    GroupBox2->layout()->setMargin( 11 );
    GroupBox2Layout = new QVBoxLayout( GroupBox2->layout() );
    GroupBox2Layout->setAlignment( Qt::AlignTop );

    CheckBoxAutoStart = new QCheckBox( GroupBox2, "CheckBoxAutoStart" );
    GroupBox2Layout->addWidget( CheckBoxAutoStart );

    GeneralCfgDesignLayout->addWidget( GroupBox2, 2, 0 );
    Spacer28 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    GeneralCfgDesignLayout->addItem( Spacer28, 3, 0 );
    languageChange();
    resize( QSize(343, 239).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
GeneralCfgDesign::~GeneralCfgDesign()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void GeneralCfgDesign::languageChange()
{
    setCaption( tr2i18n( "GeneralCfg" ) );
    ButtonGroup5->setTitle( tr2i18n( "Panels size" ) );
    Radio64->setText( tr2i18n( "64 x 64" ) );
    Radio56->setText( tr2i18n( "56 x 56" ) );
    Radio48->setText( tr2i18n( "48 x 48" ) );
    boxGeneralPalette->setTitle( tr2i18n( "Colors" ) );
    GroupBox2->setTitle( tr2i18n( "Startup" ) );
    CheckBoxAutoStart->setText( tr2i18n( "Autostart KSensors on KDE startup" ) );
}

#include "generalcfgdesign.moc"
