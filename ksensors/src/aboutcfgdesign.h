/****************************************************************************
** Form interface generated from reading ui file './aboutcfgdesign.ui'
**
** Created: mer aoû 18 23:39:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ABOUTCFGDESIGN_H
#define ABOUTCFGDESIGN_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;

class AboutCfgDesign : public QWidget
{
    Q_OBJECT

public:
    AboutCfgDesign( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~AboutCfgDesign();

    QFrame* Frame3;
    QLabel* PixmapLabel1;
    QLabel* TextLabel2;
    QFrame* Frame4;
    QLabel* TextLabel1;
    QFrame* Frame5;
    QFrame* Frame6;
    QLabel* labelTitle;
    QLabel* TextLabel3_2;

protected:
    QVBoxLayout* AboutCfgDesignLayout;
    QHBoxLayout* Frame5Layout;
    QSpacerItem* Spacer1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // ABOUTCFGDESIGN_H
