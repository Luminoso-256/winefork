/* WinRT Windows.Foundation.PropertySet Implementation
 *
 * Written by Weather
 *
 * This is an implementation of Microsoft's OneCoreUAP binaries.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef PROPERTY_SET_INTERNAL_H
#define PROPERTY_SET_INTERNAL_H

#include "../../../private.h"
#include "wine/debug.h"

extern struct IPropertySetVtbl property_set_vtbl;

struct property_set_statics
{
    IActivationFactory IActivationFactory_iface;
    IPropertySet IPropertySet_iface;
    LONG ref;
};

struct buffer *impl_from_IPropertySet( IPropertySet *iface );

#endif