/***************************************************************************
                          procinfo.c  -  description
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

#include "procinfo.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>


bool existsFile(const char *file)
{
struct stat buf;

 return (stat((const char *)file,&buf)==0);
}


int read_file(const char *name, char *buf, int max)
{
    int fd = open(name, O_RDONLY);
    if(fd >= 0) {
       int r = read(fd, buf, max);
       close(fd);
       return r;
    }
    return -1;
}


// ***** Dell i8k sensors info *****
//
//    $ cat /proc/i8k
//    1.0 A17 2J59L02 52 2 1 8040 6420 1 2
//
//The fields read from /proc/18k are:
//
//    1.0 A17 2J59L02 52 2 1 8040 6420 1 2
//    |   |   |       |  | | |    |    | |
//    |   |   |       |  | | |    |    | +------- 10. buttons status
//    |   |   |       |  | | |    |    +--------- 9.  ac status
//    |   |   |       |  | | |    +-------------- 8.  right fan rpm
//    |   |   |       |  | | +------------------- 7.  left fan rpm
//    |   |   |       |  | +--------------------- 6.  right fan status
//    |   |   |       |  +----------------------- 5.  left fan status
//    |   |   |       +-------------------------- 4.  CPU temperature (Celsius)
//    |   |   +---------------------------------- 3.  serial number
//    |   +-------------------------------------- 2.  BIOS version
//    +------------------------------------------ 1.  /proc/i8k format version

int getI8KInfo(double *cpuTemp,  double *leftFan, double *rightFan)
{
double version;
char buf[256];

 if(read_file("/proc/i8k", buf, sizeof(buf)) <= 0) return -1;
 if(sscanf(buf, "%lf %*s %*s %lf %*d %*d %lf %lf", &version, cpuTemp,leftFan,rightFan)!=4) return -2;
 if(version!=1.0) return -3;
 return 0;
}


// *************  Acpi temperature ************
// cat /proc/acpi/thermal_zone/THRM/temperature
// temperature:             61 C

int getAcpiTemperature(double *cpuTemp)
{
char buf[128];

    if(read_file("/proc/acpi/thermal_zone/THRM/temperature", buf, sizeof(buf))<= 0)  return -1;

    sscanf(buf, "temperature: %lf C", cpuTemp);

    return 0;
}


int getMemInfo(int *RamTotal,int *RamUsed,int *SwapTotal, int *SwapUsed)
{
char buf[4096];
int mem_free,mem_buffers,mem_cached;
char *p;

    // read memory info
    if(read_file("/proc/meminfo", buf, sizeof(buf)) <= 0) return -1;

    p = strstr(buf, "MemTotal:");
    if(p)  sscanf(p, "MemTotal: %d kB", RamTotal);
    else   *RamTotal= 0;

    p = strstr(buf, "MemFree:");
    if(p) sscanf(p, "MemFree: %d kB", &mem_free);
    else	mem_free= 0;

    p = strstr(buf, "Buffers:");
    if(p) sscanf(p, "Buffers: %d kB", &mem_buffers);
    else  mem_buffers= 0;

    p = strstr(buf, "Cached:");
    if(p) sscanf(p, "Cached: %d kB", &mem_cached);
    else mem_cached= 0;

    p = strstr(buf, "SwapTotal:");
    if(p) sscanf(p, "SwapTotal: %d kB", SwapTotal);
    else  *SwapTotal= 0;

    p = strstr(buf, "SwapFree:");
    if(p) sscanf(p, "SwapFree: %d kB", SwapUsed);
    else  *SwapUsed= 0;

   *SwapUsed= *SwapTotal - *SwapUsed;
   *RamUsed = *RamTotal - mem_free - mem_buffers - mem_cached;

   return 0;
}


bool getCpuTime(int *user,int *nice,int *system,int *idle)
{
char buf[512];

 if(read_file("/proc/stat", buf, sizeof(buf)) <= 0) return false;

 sscanf(buf, "cpu %u %u %u %u",user,nice,system,idle);

 return true;
}


int getUpTime()
{
char buf[256];

 if(read_file("/proc/uptime", buf, sizeof(buf)) < 0) return 0;
 float uptime;
 sscanf(buf, "%f", &uptime);
 return (int)uptime;
}

