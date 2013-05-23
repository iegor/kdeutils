#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './lmsensorscfgdesign.ui'
**
** Created: mer aoû 18 23:39:03 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "lmsensorscfgdesign.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <kcolorbutton.h>
#include <qframe.h>
#include <qradiobutton.h>
#include <qlistbox.h>
#include <qbuttongroup.h>
#include <qspinbox.h>
#include <qslider.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a LMSensorsCfgDesign as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
LMSensorsCfgDesign::LMSensorsCfgDesign( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "LMSensorsCfgDesign" );
    setMinimumSize( QSize( 0, 340 ) );
    LMSensorsCfgDesignLayout = new QGridLayout( this, 1, 1, 8, 4, "LMSensorsCfgDesignLayout"); 

    MainTab = new QTabWidget( this, "MainTab" );
    MainTab->setMinimumSize( QSize( 422, 295 ) );

    tab = new QWidget( MainTab, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    SensorsTab = new QTabWidget( tab, "SensorsTab" );
    SensorsTab->setMinimumSize( QSize( 272, 276 ) );
    SensorsTab->setTabShape( QTabWidget::Rounded );
    SensorsTab->setMargin( 0 );

    tab_2 = new QWidget( SensorsTab, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    GroupBoxDes = new QGroupBox( tab_2, "GroupBoxDes" );
    GroupBoxDes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)1, 0, 0, GroupBoxDes->sizePolicy().hasHeightForWidth() ) );
    GroupBoxDes->setColumnLayout(0, Qt::Vertical );
    GroupBoxDes->layout()->setSpacing( 6 );
    GroupBoxDes->layout()->setMargin( 11 );
    GroupBoxDesLayout = new QGridLayout( GroupBoxDes->layout() );
    GroupBoxDesLayout->setAlignment( Qt::AlignTop );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    pixmapSensor = new QLabel( GroupBoxDes, "pixmapSensor" );
    pixmapSensor->setScaledContents( TRUE );
    layout5->addWidget( pixmapSensor );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    TextLabel2_2 = new QLabel( GroupBoxDes, "TextLabel2_2" );
    layout4->addWidget( TextLabel2_2 );

    editDescription = new QLineEdit( GroupBoxDes, "editDescription" );
    layout4->addWidget( editDescription );
    layout5->addLayout( layout4 );

    GroupBoxDesLayout->addLayout( layout5, 0, 0 );

    tabLayout_2->addWidget( GroupBoxDes, 0, 0 );

    GroupBox2_2_2 = new QGroupBox( tab_2, "GroupBox2_2_2" );
    GroupBox2_2_2->setFrameShape( QGroupBox::Box );
    GroupBox2_2_2->setFrameShadow( QGroupBox::Sunken );
    GroupBox2_2_2->setColumnLayout(0, Qt::Vertical );
    GroupBox2_2_2->layout()->setSpacing( 6 );
    GroupBox2_2_2->layout()->setMargin( 11 );
    GroupBox2_2_2Layout = new QGridLayout( GroupBox2_2_2->layout() );
    GroupBox2_2_2Layout->setAlignment( Qt::AlignTop );

    editValue = new QLineEdit( GroupBox2_2_2, "editValue" );
    editValue->setEnabled( FALSE );
    editValue->setAlignment( int( QLineEdit::AlignLeft ) );
    editValue->setEdited( TRUE );

    GroupBox2_2_2Layout->addWidget( editValue, 1, 0 );

    TextLabel3_2_2_3_2_2_2 = new QLabel( GroupBox2_2_2, "TextLabel3_2_2_3_2_2_2" );

    GroupBox2_2_2Layout->addWidget( TextLabel3_2_2_3_2_2_2, 0, 0 );

    TextLabel3_2_4_2_2_2 = new QLabel( GroupBox2_2_2, "TextLabel3_2_4_2_2_2" );
    TextLabel3_2_4_2_2_2->setScaledContents( FALSE );

    GroupBox2_2_2Layout->addWidget( TextLabel3_2_4_2_2_2, 0, 1 );

    editMaxValue = new QComboBox( FALSE, GroupBox2_2_2, "editMaxValue" );
    editMaxValue->setEditable( TRUE );
    editMaxValue->setSizeLimit( 12 );

    GroupBox2_2_2Layout->addWidget( editMaxValue, 1, 1 );

    TextLabel1_2_3_2_2 = new QLabel( GroupBox2_2_2, "TextLabel1_2_3_2_2" );

    GroupBox2_2_2Layout->addWidget( TextLabel1_2_3_2_2, 0, 2 );

    editMul = new QLineEdit( GroupBox2_2_2, "editMul" );

    GroupBox2_2_2Layout->addWidget( editMul, 1, 2 );

    TextLabel3_2 = new QLabel( GroupBox2_2_2, "TextLabel3_2" );

    GroupBox2_2_2Layout->addWidget( TextLabel3_2, 3, 0 );

    TextLabel3_2_3_2_2_2_2 = new QLabel( GroupBox2_2_2, "TextLabel3_2_3_2_2_2_2" );

    GroupBox2_2_2Layout->addWidget( TextLabel3_2_3_2_2_2_2, 3, 1 );

    TextLabel1_3_3_2 = new QLabel( GroupBox2_2_2, "TextLabel1_3_3_2" );

    GroupBox2_2_2Layout->addWidget( TextLabel1_3_3_2, 3, 2 );

    editIdealValue = new QLineEdit( GroupBox2_2_2, "editIdealValue" );
    editIdealValue->setAlignment( int( QLineEdit::AlignLeft ) );

    GroupBox2_2_2Layout->addWidget( editIdealValue, 4, 0 );

    editMinValue = new QComboBox( FALSE, GroupBox2_2_2, "editMinValue" );
    editMinValue->setEditable( TRUE );
    editMinValue->setSizeLimit( 12 );

    GroupBox2_2_2Layout->addWidget( editMinValue, 4, 1 );

    editSum = new QLineEdit( GroupBox2_2_2, "editSum" );

    GroupBox2_2_2Layout->addWidget( editSum, 4, 2 );
    spacer12 = new QSpacerItem( 21, 21, QSizePolicy::Minimum, QSizePolicy::Expanding );
    GroupBox2_2_2Layout->addItem( spacer12, 5, 1 );
    spacer10 = new QSpacerItem( 20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed );
    GroupBox2_2_2Layout->addItem( spacer10, 2, 1 );

    tabLayout_2->addWidget( GroupBox2_2_2, 1, 0 );
    SensorsTab->insertTab( tab_2, QString("") );

    tab_3 = new QWidget( SensorsTab, "tab_3" );
    tabLayout_3 = new QVBoxLayout( tab_3, 11, 6, "tabLayout_3"); 

    GroupBox13 = new QGroupBox( tab_3, "GroupBox13" );
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
    tabLayout_3->addWidget( GroupBox13 );

    boxPanelPalette = new QGroupBox( tab_3, "boxPanelPalette" );
    boxPanelPalette->setMinimumSize( QSize( 0, 90 ) );
    tabLayout_3->addWidget( boxPanelPalette );
    Spacer4_2 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_3->addItem( Spacer4_2 );
    SensorsTab->insertTab( tab_3, QString("") );

    tab_4 = new QWidget( SensorsTab, "tab_4" );
    tabLayout_4 = new QGridLayout( tab_4, 1, 1, 11, 6, "tabLayout_4"); 

    GroupBox14 = new QGroupBox( tab_4, "GroupBox14" );
    GroupBox14->setMinimumSize( QSize( 0, 50 ) );
    GroupBox14->setMaximumSize( QSize( 32767, 50 ) );
    GroupBox14->setColumnLayout(0, Qt::Vertical );
    GroupBox14->layout()->setSpacing( 6 );
    GroupBox14->layout()->setMargin( 11 );
    GroupBox14Layout = new QGridLayout( GroupBox14->layout() );
    GroupBox14Layout->setAlignment( Qt::AlignTop );

    checkShowInDock = new QCheckBox( GroupBox14, "checkShowInDock" );
    checkShowInDock->setCursor( QCursor( 0 ) );

    GroupBox14Layout->addWidget( checkShowInDock, 0, 0 );

    tabLayout_4->addWidget( GroupBox14, 0, 0 );
    Spacer3_2 = new QSpacerItem( 20, 120, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_4->addItem( Spacer3_2, 2, 0 );

    GroupBoxColorDock = new QGroupBox( tab_4, "GroupBoxColorDock" );
    GroupBoxColorDock->setEnabled( TRUE );
    GroupBoxColorDock->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, GroupBoxColorDock->sizePolicy().hasHeightForWidth() ) );
    GroupBoxColorDock->setFrameShape( QGroupBox::Box );
    GroupBoxColorDock->setColumnLayout(0, Qt::Vertical );
    GroupBoxColorDock->layout()->setSpacing( 6 );
    GroupBoxColorDock->layout()->setMargin( 11 );
    GroupBoxColorDockLayout = new QGridLayout( GroupBoxColorDock->layout() );
    GroupBoxColorDockLayout->setAlignment( Qt::AlignTop );

    TextLabel1_2_2_2_2 = new QLabel( GroupBoxColorDock, "TextLabel1_2_2_2_2" );
    TextLabel1_2_2_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );

    GroupBoxColorDockLayout->addWidget( TextLabel1_2_2_2_2, 1, 0 );

    colorAlarm = new KColorButton( GroupBoxColorDock, "colorAlarm" );
    colorAlarm->setEnabled( TRUE );
    colorAlarm->setToggleButton( FALSE );
    colorAlarm->setColor( QColor( 255, 85, 0 ) );

    GroupBoxColorDockLayout->addWidget( colorAlarm, 1, 1 );

    colorNormal = new KColorButton( GroupBoxColorDock, "colorNormal" );
    colorNormal->setEnabled( TRUE );
    colorNormal->setAcceptDrops( TRUE );
    colorNormal->setToggleButton( FALSE );
    colorNormal->setOn( FALSE );
    colorNormal->setColor( QColor( 0, 0, 255 ) );

    GroupBoxColorDockLayout->addWidget( colorNormal, 0, 1 );
    spacer5 = new QSpacerItem( 41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GroupBoxColorDockLayout->addItem( spacer5, 0, 2 );
    spacer6 = new QSpacerItem( 41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GroupBoxColorDockLayout->addItem( spacer6, 1, 2 );

    TextLabel1_4_2_2 = new QLabel( GroupBoxColorDock, "TextLabel1_4_2_2" );
    TextLabel1_4_2_2->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignLeft ) );

    GroupBoxColorDockLayout->addWidget( TextLabel1_4_2_2, 0, 0 );

    tabLayout_4->addWidget( GroupBoxColorDock, 1, 0 );
    SensorsTab->insertTab( tab_4, QString("") );

    tab_5 = new QWidget( SensorsTab, "tab_5" );
    tabLayout_5 = new QVBoxLayout( tab_5, 11, 6, "tabLayout_5"); 

    TextLabel1_3_2_2_2_2 = new QLabel( tab_5, "TextLabel1_3_2_2_2_2" );
    tabLayout_5->addWidget( TextLabel1_3_2_2_2_2 );

    Frame11_2_2_2 = new QFrame( tab_5, "Frame11_2_2_2" );
    Frame11_2_2_2->setFrameShape( QFrame::HLine );
    Frame11_2_2_2->setFrameShadow( QFrame::Sunken );
    tabLayout_5->addWidget( Frame11_2_2_2 );

    layout9 = new QGridLayout( 0, 1, 1, 0, 6, "layout9"); 

    CheckAllSensors = new QCheckBox( tab_5, "CheckAllSensors" );
    CheckAllSensors->setAutoResize( TRUE );

    layout9->addWidget( CheckAllSensors, 6, 0 );
    spacer9 = new QSpacerItem( 20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout9->addItem( spacer9, 7, 0 );

    radioAlarm1 = new QRadioButton( tab_5, "radioAlarm1" );
    radioAlarm1->setCursor( QCursor( 0 ) );
    radioAlarm1->setChecked( TRUE );

    layout9->addWidget( radioAlarm1, 4, 0 );

    buttonTest = new QPushButton( tab_5, "buttonTest" );
    buttonTest->setEnabled( FALSE );

    layout9->addWidget( buttonTest, 5, 1 );

    radioAlarm2 = new QRadioButton( tab_5, "radioAlarm2" );
    radioAlarm2->setCursor( QCursor( 0 ) );
    radioAlarm2->setChecked( FALSE );

    layout9->addWidget( radioAlarm2, 2, 0 );

    radioAlarm3 = new QRadioButton( tab_5, "radioAlarm3" );
    radioAlarm3->setCursor( QCursor( 0 ) );

    layout9->addWidget( radioAlarm3, 0, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 
    spacer7 = new QSpacerItem( 31, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout6->addItem( spacer7 );

    editLaunch = new QLineEdit( tab_5, "editLaunch" );
    editLaunch->setEnabled( FALSE );
    layout6->addWidget( editLaunch );

    layout9->addLayout( layout6, 1, 0 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 
    spacer8 = new QSpacerItem( 31, 21, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout7->addItem( spacer8 );

    editPlay = new QLineEdit( tab_5, "editPlay" );
    editPlay->setEnabled( FALSE );
    layout7->addWidget( editPlay );

    layout9->addLayout( layout7, 3, 0 );
    tabLayout_5->addLayout( layout9 );
    SensorsTab->insertTab( tab_5, QString("") );

    tabLayout->addWidget( SensorsTab, 0, 1 );

    listSensors = new QListBox( tab, "listSensors" );
    listSensors->setMinimumSize( QSize( 120, 0 ) );
    listSensors->setMaximumSize( QSize( 120, 32767 ) );
    listSensors->setFrameShape( QListBox::StyledPanel );
    listSensors->setFrameShadow( QListBox::Sunken );
    listSensors->setLineWidth( 2 );
    listSensors->setColumnMode( QListBox::FixedNumber );

    tabLayout->addWidget( listSensors, 0, 0 );
    MainTab->insertTab( tab, QString("") );

    tab_6 = new QWidget( MainTab, "tab_6" );
    tabLayout_6 = new QGridLayout( tab_6, 1, 1, 11, 6, "tabLayout_6"); 

    ButtonGroup5 = new QButtonGroup( tab_6, "ButtonGroup5" );
    ButtonGroup5->setColumnLayout(0, Qt::Vertical );
    ButtonGroup5->layout()->setSpacing( 6 );
    ButtonGroup5->layout()->setMargin( 11 );
    ButtonGroup5Layout = new QGridLayout( ButtonGroup5->layout() );
    ButtonGroup5Layout->setAlignment( Qt::AlignTop );

    RadioF = new QRadioButton( ButtonGroup5, "RadioF" );
    RadioF->setMinimumSize( QSize( 0, 0 ) );

    ButtonGroup5Layout->addWidget( RadioF, 1, 0 );

    RadioC = new QRadioButton( ButtonGroup5, "RadioC" );
    RadioC->setChecked( TRUE );

    ButtonGroup5Layout->addWidget( RadioC, 0, 0 );

    RadioK = new QRadioButton( ButtonGroup5, "RadioK" );

    ButtonGroup5Layout->addWidget( RadioK, 2, 0 );

    tabLayout_6->addWidget( ButtonGroup5, 0, 0 );
    spacer12_2 = new QSpacerItem( 5, 5, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_6->addItem( spacer12_2, 2, 0 );

    groupBox79 = new QGroupBox( tab_6, "groupBox79" );
    groupBox79->setColumnLayout(0, Qt::Vertical );
    groupBox79->layout()->setSpacing( 6 );
    groupBox79->layout()->setMargin( 18 );
    groupBox79Layout = new QGridLayout( groupBox79->layout() );
    groupBox79Layout->setAlignment( Qt::AlignTop );

    SpinUpdateTime = new QSpinBox( groupBox79, "SpinUpdateTime" );
    SpinUpdateTime->setMinValue( 1 );
    SpinUpdateTime->setValue( 5 );

    groupBox79Layout->addWidget( SpinUpdateTime, 0, 0 );

    SliderUpdateTime = new QSlider( groupBox79, "SliderUpdateTime" );
    SliderUpdateTime->setMaxValue( 60 );
    SliderUpdateTime->setValue( 5 );
    SliderUpdateTime->setOrientation( QSlider::Horizontal );
    SliderUpdateTime->setTickmarks( QSlider::Below );
    SliderUpdateTime->setTickInterval( 1 );

    groupBox79Layout->addWidget( SliderUpdateTime, 0, 1 );

    tabLayout_6->addWidget( groupBox79, 1, 0 );
    MainTab->insertTab( tab_6, QString("") );

    LMSensorsCfgDesignLayout->addWidget( MainTab, 0, 0 );
    languageChange();
    resize( QSize(438, 344).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( radioAlarm3, SIGNAL( toggled(bool) ), editLaunch, SLOT( setEnabled(bool) ) );
    connect( radioAlarm2, SIGNAL( toggled(bool) ), editPlay, SLOT( setEnabled(bool) ) );
    connect( radioAlarm1, SIGNAL( toggled(bool) ), buttonTest, SLOT( setDisabled(bool) ) );
    connect( SliderUpdateTime, SIGNAL( valueChanged(int) ), SpinUpdateTime, SLOT( setValue(int) ) );
    connect( SpinUpdateTime, SIGNAL( valueChanged(int) ), SliderUpdateTime, SLOT( setValue(int) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
LMSensorsCfgDesign::~LMSensorsCfgDesign()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void LMSensorsCfgDesign::languageChange()
{
    setCaption( tr2i18n( "LMSensorsCfgDesign" ) );
    GroupBoxDes->setTitle( QString::null );
    TextLabel2_2->setText( tr2i18n( "Description" ) );
    editDescription->setText( QString::null );
    GroupBox2_2_2->setTitle( tr2i18n( "Values" ) );
    editValue->setText( QString::null );
    TextLabel3_2_2_3_2_2_2->setText( tr2i18n( "Current" ) );
    TextLabel3_2_4_2_2_2->setText( tr2i18n( "Maximum" ) );
    editMaxValue->clear();
    editMaxValue->insertItem( tr2i18n( "+1%" ) );
    editMaxValue->insertItem( tr2i18n( "+2%" ) );
    editMaxValue->insertItem( tr2i18n( "+3%" ) );
    editMaxValue->insertItem( tr2i18n( "+4%" ) );
    editMaxValue->insertItem( tr2i18n( "+5%" ) );
    editMaxValue->insertItem( tr2i18n( "+10%" ) );
    editMaxValue->insertItem( tr2i18n( "+15%" ) );
    editMaxValue->insertItem( tr2i18n( "+20%" ) );
    editMaxValue->insertItem( tr2i18n( "+30%" ) );
    editMaxValue->insertItem( tr2i18n( "+40%" ) );
    editMaxValue->insertItem( tr2i18n( "+50%" ) );
    TextLabel1_2_3_2_2->setText( tr2i18n( "Multiplier" ) );
    TextLabel3_2->setText( tr2i18n( "Ideal" ) );
    TextLabel3_2_3_2_2_2_2->setText( tr2i18n( "Minimum" ) );
    TextLabel1_3_3_2->setText( tr2i18n( "Addition" ) );
    editIdealValue->setText( QString::null );
    editMinValue->clear();
    editMinValue->insertItem( tr2i18n( "-1%" ) );
    editMinValue->insertItem( tr2i18n( "-2%" ) );
    editMinValue->insertItem( tr2i18n( "-3%" ) );
    editMinValue->insertItem( tr2i18n( "-4%" ) );
    editMinValue->insertItem( tr2i18n( "-5%" ) );
    editMinValue->insertItem( tr2i18n( "-10%" ) );
    editMinValue->insertItem( tr2i18n( "-15%" ) );
    editMinValue->insertItem( tr2i18n( "-20%" ) );
    editMinValue->insertItem( tr2i18n( "-30%" ) );
    editMinValue->insertItem( tr2i18n( "-40%" ) );
    editMinValue->insertItem( tr2i18n( "-50%" ) );
    SensorsTab->changeTab( tab_2, tr2i18n( "General" ) );
    GroupBox13->setTitle( QString::null );
    checkShow->setText( tr2i18n( "Visible" ) );
    boxPanelPalette->setTitle( tr2i18n( "Colors" ) );
    SensorsTab->changeTab( tab_3, tr2i18n( "Panel" ) );
    GroupBox14->setTitle( QString::null );
    checkShowInDock->setText( tr2i18n( "Visible" ) );
    GroupBoxColorDock->setTitle( tr2i18n( "Colors" ) );
    TextLabel1_2_2_2_2->setText( tr2i18n( "Alarm" ) );
    colorAlarm->setText( QString::null );
    colorNormal->setText( QString::null );
    TextLabel1_4_2_2->setText( tr2i18n( "Normal" ) );
    SensorsTab->changeTab( tab_4, tr2i18n( "Dock" ) );
    TextLabel1_3_2_2_2_2->setText( tr2i18n( "On reach alarm value:" ) );
    CheckAllSensors->setText( tr2i18n( "Apply to all sensors" ) );
    radioAlarm1->setText( tr2i18n( "Do nothing" ) );
    buttonTest->setText( tr2i18n( "Test" ) );
    radioAlarm2->setText( tr2i18n( "Play alarm sound" ) );
    radioAlarm3->setText( tr2i18n( "Run command" ) );
    SensorsTab->changeTab( tab_5, tr2i18n( "Alarms" ) );
    MainTab->changeTab( tab, tr2i18n( "Sensors" ) );
    ButtonGroup5->setTitle( tr2i18n( "Temperatures scale" ) );
    RadioF->setText( tr2i18n( "Fahrenheit" ) );
    RadioC->setText( tr2i18n( "Celsius" ) );
    RadioK->setText( tr2i18n( "Kelvin" ) );
    groupBox79->setTitle( tr2i18n( "Update interval" ) );
    SpinUpdateTime->setSuffix( tr2i18n( "s" ) );
    MainTab->changeTab( tab_6, tr2i18n( "Preferences" ) );
}

#include "lmsensorscfgdesign.moc"
