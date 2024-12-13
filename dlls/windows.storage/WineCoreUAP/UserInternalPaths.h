/* WinRT Windows.Storage.UserDataPaths Implementation
 *
 * Written by Weather
 *
 * This is a reverse engineered implementation of Microsoft's OneCoreUAP binaries.
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

#ifndef USER_INTERNAL_PATHS_H
#define USER_INTERNAL_PATHS_H

#include <appx.h>
#include <windows.h>

#include "../private.h"
#include "wine/debug.h"

struct user_data_paths_statics
{
    IActivationFactory IActivationFactory_iface;
    IUserDataPathsStatics IUserDataPathsStatics_iface;
    LONG ref;
};

HRESULT WINAPI user_data_paths_GetKnownFolder( IUserDataPaths *iface, const char * FOLDERID, HSTRING *value );

#endif