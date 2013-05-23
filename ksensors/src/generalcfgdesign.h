/****************************************************************************
** Form interface generated from reading ui file './generalcfgdesign.ui'
**
** Created: mer aoû 18 23:39:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef GENERALCFGDESIGN_H
#define GENERALCFGDESIGN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QRadioButton;
class QGroupBox;
class QCheckBox;

class GeneralCfgDesign : public QWidget
{
    Q_OBJECT

public:
    GeneralCfgDesign( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~GeneralCfgDesign();

    QButtonGroup* ButtonGroup5;
    QRadioButton* Radio64;
    QRadioButton* Radio56;
    QRadioButton* Radio48;
    QGroupBox* boxGeneralPalette;
    QGroupBox* GroupBox2;
    QCheckBox* CheckBoxAutoStart;

protected:
    QGridLayout* GeneralCfgDesignLayout;
    QSpacerItem* Spacer28;
    QGridLayout* ButtonGroup5Layout;
    QVBoxLayout* GroupBox2Layout;

protected slots:
    virtual void languageChange();

};

#endif // GENERALCFGDESIGN_H
