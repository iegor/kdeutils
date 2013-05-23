/****************************************************************************
** Form interface generated from reading ui file './palettecfgdesign.ui'
**
** Created: mer aoû 18 23:39:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PALETTECFGDESIGN_H
#define PALETTECFGDESIGN_H

#include <qvariant.h>
#include <qwidget.h>
#include <kcolorbutton.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QPushButton;
class QComboBox;
class KColorButton;

class PaletteCfgDesign : public QWidget
{
    Q_OBJECT

public:
    PaletteCfgDesign( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PaletteCfgDesign();

    QFrame* framePanel;
    QLabel* labelTitle;
    QLabel* labelValue;
    QPushButton* buttonDefaultPalette;
    QComboBox* comboSelect;
    KColorButton* buttonColor;

protected:
    QGridLayout* PaletteCfgDesignLayout;

protected slots:
    virtual void languageChange();

};

#endif // PALETTECFGDESIGN_H
