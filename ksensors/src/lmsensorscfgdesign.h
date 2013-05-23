/****************************************************************************
** Form interface generated from reading ui file './lmsensorscfgdesign.ui'
**
** Created: mer aoû 18 23:39:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef LMSENSORSCFGDESIGN_H
#define LMSENSORSCFGDESIGN_H

#include <qvariant.h>
#include <qwidget.h>
#include <kcolorbutton.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QGroupBox;
class QLabel;
class QLineEdit;
class QComboBox;
class QCheckBox;
class KColorButton;
class QFrame;
class QRadioButton;
class QPushButton;
class QListBox;
class QListBoxItem;
class QButtonGroup;
class QSpinBox;
class QSlider;

class LMSensorsCfgDesign : public QWidget
{
    Q_OBJECT

public:
    LMSensorsCfgDesign( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~LMSensorsCfgDesign();

    QTabWidget* MainTab;
    QWidget* tab;
    QTabWidget* SensorsTab;
    QWidget* tab_2;
    QGroupBox* GroupBoxDes;
    QLabel* pixmapSensor;
    QLabel* TextLabel2_2;
    QLineEdit* editDescription;
    QGroupBox* GroupBox2_2_2;
    QLineEdit* editValue;
    QLabel* TextLabel3_2_2_3_2_2_2;
    QLabel* TextLabel3_2_4_2_2_2;
    QComboBox* editMaxValue;
    QLabel* TextLabel1_2_3_2_2;
    QLineEdit* editMul;
    QLabel* TextLabel3_2;
    QLabel* TextLabel3_2_3_2_2_2_2;
    QLabel* TextLabel1_3_3_2;
    QLineEdit* editIdealValue;
    QComboBox* editMinValue;
    QLineEdit* editSum;
    QWidget* tab_3;
    QGroupBox* GroupBox13;
    QCheckBox* checkShow;
    QGroupBox* boxPanelPalette;
    QWidget* tab_4;
    QGroupBox* GroupBox14;
    QCheckBox* checkShowInDock;
    QGroupBox* GroupBoxColorDock;
    QLabel* TextLabel1_2_2_2_2;
    KColorButton* colorAlarm;
    KColorButton* colorNormal;
    QLabel* TextLabel1_4_2_2;
    QWidget* tab_5;
    QLabel* TextLabel1_3_2_2_2_2;
    QFrame* Frame11_2_2_2;
    QCheckBox* CheckAllSensors;
    QRadioButton* radioAlarm1;
    QPushButton* buttonTest;
    QRadioButton* radioAlarm2;
    QRadioButton* radioAlarm3;
    QLineEdit* editLaunch;
    QLineEdit* editPlay;
    QListBox* listSensors;
    QWidget* tab_6;
    QButtonGroup* ButtonGroup5;
    QRadioButton* RadioF;
    QRadioButton* RadioC;
    QRadioButton* RadioK;
    QGroupBox* groupBox79;
    QSpinBox* SpinUpdateTime;
    QSlider* SliderUpdateTime;

protected:
    QGridLayout* LMSensorsCfgDesignLayout;
    QGridLayout* tabLayout;
    QGridLayout* tabLayout_2;
    QGridLayout* GroupBoxDesLayout;
    QHBoxLayout* layout5;
    QVBoxLayout* layout4;
    QGridLayout* GroupBox2_2_2Layout;
    QSpacerItem* spacer12;
    QSpacerItem* spacer10;
    QVBoxLayout* tabLayout_3;
    QSpacerItem* Spacer4_2;
    QGridLayout* GroupBox13Layout;
    QGridLayout* tabLayout_4;
    QSpacerItem* Spacer3_2;
    QGridLayout* GroupBox14Layout;
    QGridLayout* GroupBoxColorDockLayout;
    QSpacerItem* spacer5;
    QSpacerItem* spacer6;
    QVBoxLayout* tabLayout_5;
    QGridLayout* layout9;
    QSpacerItem* spacer9;
    QHBoxLayout* layout6;
    QSpacerItem* spacer7;
    QHBoxLayout* layout7;
    QSpacerItem* spacer8;
    QGridLayout* tabLayout_6;
    QSpacerItem* spacer12_2;
    QGridLayout* ButtonGroup5Layout;
    QGridLayout* groupBox79Layout;

protected slots:
    virtual void languageChange();

};

#endif // LMSENSORSCFGDESIGN_H
