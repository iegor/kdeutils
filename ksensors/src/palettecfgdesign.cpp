#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './palettecfgdesign.ui'
**
** Created: mer aoû 18 23:39:05 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "palettecfgdesign.h"

#include <qvariant.h>
#include <qframe.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <kcolorbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a PaletteCfgDesign as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PaletteCfgDesign::PaletteCfgDesign( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PaletteCfgDesign" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, sizePolicy().hasHeightForWidth() ) );
    PaletteCfgDesignLayout = new QGridLayout( this, 1, 1, 0, 6, "PaletteCfgDesignLayout"); 

    framePanel = new QFrame( this, "framePanel" );
    framePanel->setMinimumSize( QSize( 64, 64 ) );
    framePanel->setMaximumSize( QSize( 64, 64 ) );
    QPalette pal;
    QColorGroup cg;
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 228, 228, 228) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 241, 241, 241) );
    cg.setColor( QColorGroup::Dark, QColor( 114, 114, 114) );
    cg.setColor( QColorGroup::Mid, QColor( 152, 152, 152) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 228, 228, 228) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 114, 114, 114) );
    cg.setColor( QColorGroup::Mid, QColor( 152, 152, 152) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 228, 228, 228) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 114, 114, 114) );
    cg.setColor( QColorGroup::Mid, QColor( 152, 152, 152) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setDisabled( cg );
    framePanel->setPalette( pal );
    framePanel->setFrameShape( QFrame::Panel );
    framePanel->setFrameShadow( QFrame::Raised );

    labelTitle = new QLabel( framePanel, "labelTitle" );
    labelTitle->setGeometry( QRect( 8, 40, 50, 20 ) );
    QFont labelTitle_font(  labelTitle->font() );
    labelTitle_font.setPointSize( 7 );
    labelTitle->setFont( labelTitle_font ); 
    labelTitle->setAlignment( int( QLabel::AlignCenter ) );

    labelValue = new QLabel( framePanel, "labelValue" );
    labelValue->setGeometry( QRect( 7, 16, 50, 20 ) );
    labelValue->setAlignment( int( QLabel::AlignCenter ) );

    PaletteCfgDesignLayout->addMultiCellWidget( framePanel, 0, 1, 0, 0 );

    buttonDefaultPalette = new QPushButton( this, "buttonDefaultPalette" );
    buttonDefaultPalette->setMinimumSize( QSize( 0, 22 ) );

    PaletteCfgDesignLayout->addMultiCellWidget( buttonDefaultPalette, 1, 1, 1, 2 );

    comboSelect = new QComboBox( FALSE, this, "comboSelect" );
    comboSelect->setMinimumSize( QSize( 0, 22 ) );

    PaletteCfgDesignLayout->addWidget( comboSelect, 0, 1 );

    buttonColor = new KColorButton( this, "buttonColor" );
    buttonColor->setMinimumSize( QSize( 0, 22 ) );

    PaletteCfgDesignLayout->addWidget( buttonColor, 0, 2 );
    languageChange();
    resize( QSize(287, 74).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PaletteCfgDesign::~PaletteCfgDesign()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PaletteCfgDesign::languageChange()
{
    setCaption( tr2i18n( "PaletteCfg" ) );
    labelTitle->setText( tr2i18n( "Title" ) );
    labelValue->setText( tr2i18n( "+3.5V" ) );
    buttonDefaultPalette->setText( tr2i18n( "Default colors" ) );
    comboSelect->clear();
    comboSelect->insertItem( tr2i18n( "Background" ) );
    comboSelect->insertItem( tr2i18n( "Border" ) );
    comboSelect->insertItem( tr2i18n( "Title" ) );
    comboSelect->insertItem( tr2i18n( "Value" ) );
    buttonColor->setText( QString::null );
}

#include "palettecfgdesign.moc"
