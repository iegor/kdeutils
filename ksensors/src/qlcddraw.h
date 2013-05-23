/***************************************************************************
                          lcddraw.h  -  description
                             -------------------
    begin                : Tue Nov 27 2001
    copyright            : (C) 2001 by Miguel Novas
    email                : michaell@teleline.es
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#ifndef QLCDDRAW_H
#define QLCDDRAW_H

#include <qpainter.h>
#include <qcolor.h>


class QLcd {

public:

  enum Options {
                 alignLeft   = 0x0000,
                 alignCenter = 0x0001,
                 alignRight  = 0x0002,
                 alignJustify= 0x0003,

                 drawShadow  = 0x0008,

                 drawNumber  = 0x0010,

                 alignMask   = 0x0007
               };


  static int  draw(QPainter *painter,
                   int x, int y,
                   int w, int h,
                   const char *str,
                   int   options=0,
                   const QColor *color=0,
                   const QColor *colorShadow=0);

  static void draw(QPainter *p,int x,int y,int w,int h, char c);

  static inline int charWidth(int height) { return (height * 3) / 4; };
  static inline int strWidth(const char *str,int height) { return strlen(str)*charWidth(height); };

private:

  static const uint asciiSegments[128];
  static const int segmentsCoords[32][8];

  static void drawSegment(QPainter *p,const int *c, int x, int y, int w, int h);

};

#endif
