/***************************************************************************
                          lcddraw.cpp  -  description
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

#include "qlcddraw.h"


const uint QLcd::asciiSegments[128]=
  {
   0x00000000, // 0
   0x00000000, // 1 // From 1-31 maybe for future use (to draw symbols)
   0x00000000, // 2
   0x00000000, // 3
   0x00000000, // 4
   0x00000000, // 5
   0x00000000, // 6
   0x00000000, // 7
   0x00000000, // 8
   0x00000000, // 9
   0x00000000, // 10
   0x00000000, // 11
   0x00000000, // 12
   0x00000000, // 13
   0x00000000, // 14
   0x00000000, // 15
   0x00000000, // 16
   0x00000000, // 17
   0x00000000, // 18
   0x00000000, // 19
   0x00000000, // 20
   0x00000000, // 21
   0x00000000, // 22
   0x00000000, // 23
   0x00000000, // 24
   0x00000000, // 25
   0x00000000, // 26
   0x00000000, // 27
   0x00000000, // 28
   0x00000000, // 29
   0x00000000, // 30
   0x00000000, // 31
   0x00000000, // 32
   0x21C00000, // 33  !
   0x00400800, // 34  "
   0x01BC3618, // 35  #
   0x03C03CF3, // 36  $
   0x18028000, // 37  %
   0x00440801, // 38  &
   0x00400000, // 39  '
   0x03C00042, // 40  (
   0x03C00081, // 41  )
   0x03C3C000, // 42  *
   0x01803000, // 43  +
   0x00010000, // 44  ,
   0x00003000, // 45  -
   0x20000000, // 46  .
   0x00028000, // 47  /
   0x00000FFF, // 48  0
   0x0000003C, // 49  1
   0x000033CF, // 50  2
   0x000030FF, // 51  3
   0x00003C3C, // 52  4
   0x00003CF3, // 53  5
   0x00003FF3, // 54  6
   0x0000003F, // 55  7
   0x00003FFF, // 56  8
   0x00003CFF, // 57  9
   0x18000000, // 58  :
   0x18000000, // 59  ;
   0x00028000, // 60  <
   0x003C0000, // 61  =
   0x00024000, // 62  >
   0x2100200F, // 63  ?
   0x00882FCF, // 64  @
   0x00003F3F, // 65  A
   0x00003FFF, // 66  B
   0x00000FC3, // 67  C
   0x00000FFF, // 68  D
   0x00003FC3, // 69  E
   0x00001F03, // 70  F
   0x00002FF3, // 71  G
   0x00003F3C, // 72  H
   0x03C00000, // 73  I
   0x000001FC, // 74  J
   0x40000F00, // 75  K Especial segment bit 30 to draw <
   0x00000FC0, // 76  L
   0x0000CF3C, // 77  M
   0x00014F3C, // 78  N
   0x00000FFF, // 79  O
   0x00003F0F, // 80  P
   0x00010FFF, // 81  Q
   0x00013F0F, // 82  R
   0x00003CF3, // 83  S
   0x03C00003, // 84  T
   0x00000FFC, // 85  U
   0x80000000, // 86  V Especial segment bit 31 to draw this letter
   0x00030F3C, // 87  W
   0x0003C000, // 88  X
   0x0300C000, // 89  Y
   0x000280C3, // 90  Z
   0x03C00042, // 91  [
   0x00014000, // 92
   0x03C00081, // 93  ]
   0x00003C0F, // 94  ^
   0x000000C0, // 95  _
   0x00004000, // 96  `
   0x00003F3F, // 97  A
   0x00003FFF, // 98  B
   0x00000FC3, // 99  C
   0x00000FFF, //100  D
   0x00003FC3, //101  E
   0x00001F03, //102  F
   0x00002FF3, //103  G
   0x00003F3C, //104  H
   0x03C00000, //105  I
   0x000001FC, //106  J
   0x40000F00, //107  K Especial segment bit 30 to draw <
   0x00000FC0, //108  L
   0x0000CF3C, //109  M
   0x00014F3C, //110  N
   0x00000FFF, //111  O
   0x00003F0F, //112  P
   0x00010FFF, //113  Q
   0x00013F0F, //114  R
   0x00003CF3, //115  S
   0x03C00003, //116  T
   0x00000FFC, //117  U
   0x80000000, //118  V  Especial segment bit 31 to draw this letter
   0x00030F3C, //119  W
   0x0003C000, //120  X
   0x0300C000, //121  Y
   0x000280C3, //122  Z
   0x03C00042, //123  {
   0x03C00000, //124  |
   0x03C00081, //125  }
   0x00000003, //126  ~
   0x003C0518  //127
  };


const int QLcd::segmentsCoords[32][8]=
  {
   { 0,0, 1,0, -1 },  // 00
   { 1,0, 2,0, -1 },
   { 2,0, 2,1, -1 },
   { 2,1, 2,2, -1 },
   { 2,2, 2,3, -1 },
   { 2,3, 2,4, -1 },
   { 2,4, 1,4, -1 },
   { 1,4, 0,4, -1 },
   { 0,4, 0,3, -1 },
   { 0,3, 0,2, -1 },
   { 0,2, 0,1, -1 },
   { 0,1, 0,0, -1 },
   { 0,2, 1,2, -1 },
   { 1,2, 2,2, -1 },
   { 0,0, 1,2, -1 },
   { 2,0, 1,2, -1 },
   { 2,4, 1,2, -1 },  // 16
   { 0,4, 1,2, -1 },
   { 0,1, 1,1, -1 },
   { 1,1, 2,1, -1 },
   { 0,3, 1,3, -1 },
   { 1,3, 2,3, -1 },
   { 1,0, 1,1, -1 },
   { 1,1, 1,2, -1 },
   { 1,2, 1,3, -1 },
   { 1,3, 1,4, -1 },
   { 1,0, 1,0, -1 },
   { 1,1, 1,1, -1 },
   { 1,3, 1,3, -1 },
   { 2,4, 2,4, -1 },
   { 2,0, 0,2, 2,4, -1 }, // 30  ->  <
   { 0,0, 1,4, 2,0, -1 }  // 31  ->  V
  };



void QLcd::drawSegment(QPainter *p,const int *c, int x, int y, int w, int h)
{
 h--;
 p->moveTo( x+(c[0]*w)/2 , y+(c[1]*h)/4 );
 c+= 2;
 do {
     p->lineTo( x+(c[0]*w)/2 , y+(c[1]*h)/4 );
     c+= 2;
 } while(*c>=0);
}


void QLcd::draw(QPainter *p,int x,int y,int w,int h, char c)
{
uint mask= asciiSegments[(uint)c&0x007F];

  if (mask) {
    int i= 0;
    do {
         if(mask&1) drawSegment(p, segmentsCoords[i & 0x001F], x,y,w,h);
         mask>>= 1;
         i++;
    } while(mask);
  }
}



int QLcd::draw(QPainter *painter,int x, int y, int w, int h,const char *str, int options, const QColor *color, const QColor *colorShadow)
{
 int len= strlen(str)<<1;

 bool point= false;
 if(options & drawNumber)
   for(const char *ptr=str; *ptr!=0; ptr++)
     if(*ptr=='.') { point= true; len--; break; }

 int cww= charWidth(h);
 int tww= cww*len;

 if((options & alignMask)==alignJustify || tww>(w<<1)) {
   cww= (w<<1)/len;
   tww= cww*len;
 }

 len>>= 1;
 tww>>= 1;

 int sep= (cww+4)/4;
 if(options & drawShadow) {
   h--;
   if(sep<=2) sep= 3;
 }

 int cw= cww - sep;

 switch( options & alignMask ) {
  case alignLeft  : break;
  case alignRight : x+=  w - tww;      break;
  default         : x+= (w - tww) / 2; break;
 }

 if(options & drawShadow) {
   if(colorShadow) painter->setPen( *colorShadow );
   int px = x+1;
   int py = y+1;
   const char *ptr= str;
   while(*ptr) {
    draw(painter,px,py,cw,h,*ptr++);
    px+= (point && *ptr=='.') ? cww/2 : cww;
   }
 }

 if(color) painter->setPen( *color );
 while(*str) {
   draw(painter,x,y,cw,h,*str++);
   x+= (point && *str=='.') ? cww/2 : cww;
 }

 return x;
}



