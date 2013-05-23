#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './aboutcfgdesign.ui'
**
** Created: mer aoû 18 23:39:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "aboutcfgdesign.h"

#include <qvariant.h>
#include <kcolorbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const img0_aboutcfgdesign[] = { 
"32 32 76 2",
"Qt c None",
".# c #000000",
".R c #292429",
".P c #292829",
".S c #292c29",
".T c #312c31",
".U c #313031",
".X c #313431",
".Y c #393439",
".2 c #393839",
".6 c #393c39",
".5 c #413c41",
"#a c #5a5d5a",
"#d c #625d62",
".7 c #626162",
".3 c #626562",
".8 c #6a656a",
".4 c #6a696a",
".9 c #736d73",
".Z c #737173",
".V c #737573",
".0 c #7b757b",
".W c #7b797b",
".L c #7b7d7b",
".M c #837d83",
".G c #838183",
".A c #838583",
".Q c #83858b",
".H c #8b858b",
".B c #8b898b",
".N c #8b8994",
".O c #8b8d8b",
".t c #8b8d94",
".I c #948d94",
".u c #949194",
".C c #94919c",
".x c #94959c",
".o c #9c959c",
".v c #9c999c",
".p c #9c99a4",
".q c #9c9da4",
".F c #a49da4",
".K c #a49dac",
".y c #a4a1a4",
".w c #a4a1ac",
".b c #bdf600",
".l c #c5d600",
".k c #c5d608",
".h c #c5da00",
".g c #c5de08",
".f c #c5ea00",
".c c #c5ee00",
".e c #c5f200",
".d c #c5f208",
".a c #c5f600",
".s c #cdba08",
".r c #cdbe08",
".m c #cdc608",
".n c #cdc610",
".j c #cdd608",
".i c #cdde08",
".z c #d5ae10",
".D c #d5d2d5",
".E c #d5d6d5",
".J c #ded6de",
"#i c #e64418",
"#j c #e64820",
"#g c #e64c18",
"#e c #e64c20",
"#b c #e65518",
"#c c #e65520",
"#. c #e65918",
"## c #e65d18",
".1 c #e66918",
"#h c #ee4820",
"#f c #ee4c20",
"QtQtQtQt.#.#.#.#.#.#.#.#.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.a.b.a.b.a.b.a.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.a.a.a.a.a.a.a.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.#.#.#.#.#.#.#.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.c.d.c.d.c.e.c.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.f.f.f.f.f.f.f.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.#.#.#.#.#.#.#.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.g.h.i.h.g.h.i.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.j.j.k.j.j.j.l.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.#.#.#.#.#.#.#.#Qt.#.#.#.#QtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.m.m.m.m.m.n.m.#.#.o.o.p.q.#.#QtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.r.r.r.s.r.#.#.t.u.u.o.v.q.q.w.#.#QtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.#.#.#.#.#.t.t.u.u.o.x.p.p.y.y.w.y.#.#QtQtQtQtQtQtQtQt",
"QtQtQtQt.#.z.#.#.A.B.B.t.t.C.D.E.v.q.q.w.F.w.q.w.#.#QtQtQtQtQtQt",
"QtQtQtQt.#.#.G.G.H.H.I.t.u.u.o.o.J.E.K.y.w.y.w.y.w.y.#.#QtQtQtQt",
"QtQt.#.#.L.G.M.G.A.B.B.I.D.E.u.o.x.q.D.J.q.w.F.w.q.w.F.w.#.#QtQt",
"Qt.#.G.G.G.G.G.G.H.H.N.O.u.u.J.E.p.p.F.F.J.E.w.y.w.y.w.y.w.y.#Qt",
"Qt.#.L.G.M.G.L.G.G.B.B.t.t.u.u.o.D.J.q.y.F.w.q.w.F.w.q.w.F.w.#Qt",
"Qt.#.P.P.G.G.G.G.H.Q.N.B.u.u.o.x.p.v.F.F.w.y.w.y.w.y.w.y.G.G.#Qt",
"Qt.#.R.P.P.S.M.G.G.H.B.t.O.u.u.o.x.p.p.w.q.w.F.w.q.w.M.G.L.G.#Qt",
"Qt.#.P.P.T.S.U.T.H.H.B.B.I.u.x.x.p.p.F.F.w.y.w.y.G.G.G.G.G.G.#Qt",
"QtQt.#.#.P.T.S.U.U.U.Q.t.O.u.u.o.x.p.v.F.F.w.V.W.W.G.L.G.#.#QtQt",
"QtQt.UQt.#.#.U.U.X.U.Y.Y.I.u.o.x.v.v.F.F.Z.Z.0.W.M.L.#.#Qt.#QtQt",
"QtQt.UQt.U.1.#.#.U.X.X.Y.X.2.u.o.x.p.3.4.4.Z.Z.0.#.#Qt.#Qt.#QtQt",
"QtQtQtQt.U.#.U.#.#.#.2.Y.2.2.5.6.7.7.8.4.9.9.#.UQt.UQt.#QtQtQtQt",
"QtQtQtQt.##..U##.U#..#.#.2.2.2.6#a.7.7.4.#.#Qt.UQt.UQtQtQtQtQtQt",
"QtQtQtQt.##b#c#b.U#b.U#b.#.#.5.6#d#d.#.#Qt.UQt.UQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.#.#.#.#.#.U.#.UQt.#.#.#.#Qt.UQt.UQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.##e#f#e#f#e#f#g.UQt.UQtQt.UQt.UQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.##h#i#j#i#h#i#j.#Qt.UQtQt.UQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQt.#.#.#.#.#.#.#.#.#QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt",
"QtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQtQt"};


/*
 *  Constructs a AboutCfgDesign as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
AboutCfgDesign::AboutCfgDesign( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl ),
      image0( (const char **) img0_aboutcfgdesign )
{
    if ( !name )
	setName( "AboutCfgDesign" );
    AboutCfgDesignLayout = new QVBoxLayout( this, 0, 0, "AboutCfgDesignLayout"); 

    Frame3 = new QFrame( this, "Frame3" );
    Frame3->setMinimumSize( QSize( 0, 47 ) );
    Frame3->setMaximumSize( QSize( 32767, 47 ) );
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
    cg.setColor( QColorGroup::Background, QColor( 222, 226, 246) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 222, 226, 246) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 222, 226, 246) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    Frame3->setPalette( pal );
    Frame3->setFrameShape( QFrame::NoFrame );
    Frame3->setFrameShadow( QFrame::Plain );

    PixmapLabel1 = new QLabel( Frame3, "PixmapLabel1" );
    PixmapLabel1->setGeometry( QRect( 10, 5, 38, 38 ) );
    PixmapLabel1->setPixmap( image0 );
    PixmapLabel1->setScaledContents( TRUE );

    TextLabel2 = new QLabel( Frame3, "TextLabel2" );
    TextLabel2->setGeometry( QRect( 61, 12, 326, 24 ) );
    QFont TextLabel2_font(  TextLabel2->font() );
    TextLabel2_font.setPointSize( 14 );
    TextLabel2_font.setBold( TRUE );
    TextLabel2->setFont( TextLabel2_font ); 
    AboutCfgDesignLayout->addWidget( Frame3 );

    Frame4 = new QFrame( this, "Frame4" );
    Frame4->setMinimumSize( QSize( 0, 22 ) );
    Frame4->setMaximumSize( QSize( 32767, 22 ) );
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
    cg.setColor( QColorGroup::Background, QColor( 97, 97, 97) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 97, 97, 97) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 97, 97, 97) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    Frame4->setPalette( pal );
    Frame4->setFrameShape( QFrame::NoFrame );
    Frame4->setFrameShadow( QFrame::Plain );

    TextLabel1 = new QLabel( Frame4, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 7, 2, 305, 16 ) );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 228, 228, 228) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 241, 241, 241) );
    cg.setColor( QColorGroup::Dark, QColor( 114, 114, 114) );
    cg.setColor( QColorGroup::Mid, QColor( 152, 152, 152) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 97, 97, 97) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 228, 228, 228) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 114, 114, 114) );
    cg.setColor( QColorGroup::Mid, QColor( 152, 152, 152) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 97, 97, 97) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 97, 97, 97) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    TextLabel1->setPalette( pal );
    AboutCfgDesignLayout->addWidget( Frame4 );

    Frame5 = new QFrame( this, "Frame5" );
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
    cg.setColor( QColorGroup::Background, QColor( 49, 121, 172) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 49, 121, 172) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 49, 121, 172) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    Frame5->setPalette( pal );
    Frame5->setFrameShape( QFrame::NoFrame );
    Frame5->setFrameShadow( QFrame::Plain );
    Frame5Layout = new QHBoxLayout( Frame5, 22, 6, "Frame5Layout"); 

    Frame6 = new QFrame( Frame5, "Frame6" );
    Frame6->setMinimumSize( QSize( 300, 200 ) );
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
    cg.setColor( QColorGroup::Background, QColor( 222, 226, 246) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 222, 226, 246) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
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
    cg.setColor( QColorGroup::Background, QColor( 222, 226, 246) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 95, 137) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    Frame6->setPalette( pal );
    Frame6->setFrameShape( QFrame::NoFrame );
    Frame6->setFrameShadow( QFrame::Plain );

    labelTitle = new QLabel( Frame6, "labelTitle" );
    labelTitle->setGeometry( QRect( 19, 19, 221, 16 ) );
    QFont labelTitle_font(  labelTitle->font() );
    labelTitle_font.setPointSize( 10 );
    labelTitle_font.setBold( TRUE );
    labelTitle->setFont( labelTitle_font ); 

    TextLabel3_2 = new QLabel( Frame6, "TextLabel3_2" );
    TextLabel3_2->setGeometry( QRect( 20, 49, 248, 147 ) );
    TextLabel3_2->setAlignment( int( QLabel::WordBreak | QLabel::AlignTop | QLabel::AlignLeft ) );
    Frame5Layout->addWidget( Frame6 );
    Spacer1 = new QSpacerItem( 61, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    Frame5Layout->addItem( Spacer1 );
    AboutCfgDesignLayout->addWidget( Frame5 );
    languageChange();
    resize( QSize(413, 353).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AboutCfgDesign::~AboutCfgDesign()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AboutCfgDesign::languageChange()
{
    setCaption( tr2i18n( "AboutCfgDesign" ) );
    TextLabel2->setText( tr2i18n( "KSensors configuration" ) );
    TextLabel1->setText( tr2i18n( "Monitoring your motherboard" ) );
    labelTitle->setText( tr2i18n( "KSensors" ) );
    TextLabel3_2->setText( tr2i18n( "Welcome to the KSensors configuration window. Click on the left to select a configuration option." ) );
}

#include "aboutcfgdesign.moc"
