/***************************************************************************
                          procinfo.h  -  description
                             -------------------
    begin                : Wed Jan 9 2002
    copyright            : (C) 2002 by Miguel Novas
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


int  getMemInfo(int *RamTotal,int *RamUsed,int *SwapTotal, int *SwapUsed);
bool getCpuTime(int *user,int *nice,int *system,int *idle);
int  getUpTime();
int getI8KInfo(double *cpuTemp,  double *leftFan, double *rightFan);
int getAcpiTemperature(double *cpuTemp);
