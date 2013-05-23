/*  ksim - a system monitor for kde
 *
 *  Copyright (C) 2001 - 2004  Robbie Ward <linuxphreak@gmx.co.uk>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef FSYSTEMIFACE_H
#define FSYSTEMIFACE_H

#include <dcopobject.h>

class FsystemIface : virtual public DCOPObject
{
  K_DCOP
  k_dcop:
    virtual int totalFreeSpace() const = 0;
};

#endif // FSYSTEMIFACE_H
