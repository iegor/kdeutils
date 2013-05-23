/****************************************************************************
** Form interface generated from reading ui file './systemcfgdesign.ui'
**
** Created: mer aoû 18 23:39:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SYSTEMCFGDESIGN_H
#define SYSTEMCFGDESIGN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QListBox;
class QListBoxItem;
class QFrame;
class QGroupBox;
class QCheckBox;
class QSpinBox;
class QSlider;

class SystemCfgDesign : public QWidget
{
    Q_OBJECT

public:
    SystemCfgDesign( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SystemCfgDesign();

    QTabWidget* TabWidget;
    QWidget* tab;
    QListBox* listSensors;
    QFrame* framePanelCfg;
    QGroupBox* GroupBox13;
    QCheckBox* checkShow;
    QGroupBox* boxPanelPalette;
    QWidget* tab_2;
    QGroupBox* GroupBox7;
    QSpinBox* SpinUpdateTime;
    QSlider* SliderUpdateTime;

protected:
    QGridLayout* SystemCfgDesignLayout;
    QHBoxLayout* tabLayout;
    QVBoxLayout* framePanelCfgLayout;
    QSpacerItem* Spacer4_2;
    QGridLayout* GroupBox13Layout;
    QVBoxLayout* tabLayout_2;
    QSpacerItem* Spacer18;
    QHBoxLayout* GroupBox7Layout;

protected slots:
    virtual void languageChange();

};

#endif // SYSTEMCFGDESIGN_H
