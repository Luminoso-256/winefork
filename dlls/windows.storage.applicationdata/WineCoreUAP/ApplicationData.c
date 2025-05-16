/* WinRT Windows.Storage.ApplicationData ApplicationData Implementation
 *
 * Copyright (C) 2023 Mohamad Al-Jaf
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

#include "ApplicationDataInternal.h"
#include "ApplicationDataContainerInternal.h"

_ENABLE_DEBUGGING_

DEFINE_ASYNC_COMPLETED_HANDLER( async_storage_folder_handler, IAsyncOperationCompletedHandler_StorageFolder, IAsyncOperation_StorageFolder )

static inline struct application_data_statics *impl_from_IActivationFactory( IActivationFactory *iface )
{
    return CONTAINING_RECORD( iface, struct application_data_statics, IActivationFactory_iface );
}

static HRESULT WINAPI factory_QueryInterface( IActivationFactory *iface, REFIID iid, void **out )
{
    struct application_data_statics *impl = impl_from_IActivationFactory( iface );

    TRACE( "iface %p, iid %s, out %p.\n", iface, debugstr_guid( iid ), out );

    if (IsEqualGUID( iid, &IID_IUnknown ) ||
        IsEqualGUID( iid, &IID_IInspectable ) ||
        IsEqualGUID( iid, &IID_IAgileObject ) ||
        IsEqualGUID( iid, &IID_IActivationFactory ))
    {
        *out = &impl->IActivationFactory_iface;
        IInspectable_AddRef( *out );
        return S_OK;
    }

    if (IsEqualGUID( iid, &IID_IApplicationDataStatics ))
    {
        *out = &impl->IApplicationDataStatics_iface;
        IInspectable_AddRef( *out );
        return S_OK;
    }

    FIXME( "%s not implemented, returning E_NOINTERFACE.\n", debugstr_guid( iid ) );
    *out = NULL;
    return E_NOINTERFACE;
}

static ULONG WINAPI factory_AddRef( IActivationFactory *iface )
{
    struct application_data_statics *impl = impl_from_IActivationFactory( iface );
    ULONG ref = InterlockedIncrement( &impl->ref );
    TRACE( "iface %p increasing refcount to %lu.\n", iface, ref );
    return ref;
}

static ULONG WINAPI factory_Release( IActivationFactory *iface )
{
    struct application_data_statics *impl = impl_from_IActivationFactory( iface );
    ULONG ref = InterlockedDecrement( &impl->ref );
    TRACE( "iface %p decreasing refcount to %lu.\n", iface, ref );
    return ref;
}

static HRESULT WINAPI factory_GetIids( IActivationFactory *iface, ULONG *iid_count, IID **iids )
{
    FIXME( "iface %p, iid_count %p, iids %p stub!\n", iface, iid_count, iids );
    return E_NOTIMPL;
}

static HRESULT WINAPI factory_GetRuntimeClassName( IActivationFactory *iface, HSTRING *class_name )
{
    FIXME( "iface %p, class_name %p stub!\n", iface, class_name );
    return E_NOTIMPL;
}

static HRESULT WINAPI factory_GetTrustLevel( IActivationFactory *iface, TrustLevel *trust_level )
{
    FIXME( "iface %p, trust_level %p stub!\n", iface, trust_level );
    return E_NOTIMPL;
}

static HRESULT WINAPI factory_ActivateInstance( IActivationFactory *iface, IInspectable **instance )
{
    FIXME( "iface %p, instance %p stub!\n", iface, instance );
    return E_NOTIMPL;
}

static const struct IActivationFactoryVtbl factory_vtbl =
{
    factory_QueryInterface,
    factory_AddRef,
    factory_Release,
    /* IInspectable methods */
    factory_GetIids,
    factory_GetRuntimeClassName,
    factory_GetTrustLevel,
    /* IActivationFactory methods */
    factory_ActivateInstance,
};

struct application_data *impl_from_IApplicationData( IApplicationData *iface )
{
    return CONTAINING_RECORD( iface, struct application_data, IApplicationData_iface );
}

static HRESULT WINAPI application_data_QueryInterface( IApplicationData *iface, REFIID iid, void **out )
{
    struct application_data *impl = impl_from_IApplicationData( iface );

    TRACE( "iface %p, iid %s, out %p.\n", iface, debugstr_guid( iid ), out );

    if (IsEqualGUID( iid, &IID_IUnknown ) ||
        IsEqualGUID( iid, &IID_IInspectable ) ||
        IsEqualGUID( iid, &IID_IAgileObject ) ||
        IsEqualGUID( iid, &IID_IApplicationData ))
    {
        *out = &impl->IApplicationData_iface;
        IInspectable_AddRef( *out );
        return S_OK;
    }

    FIXME( "%s not implemented, returning E_NOINTERFACE.\n", debugstr_guid( iid ) );
    *out = NULL;
    return E_NOINTERFACE;
}

static ULONG WINAPI application_data_AddRef( IApplicationData *iface )
{
    struct application_data *impl = impl_from_IApplicationData( iface );
    ULONG ref = InterlockedIncrement( &impl->ref );
    TRACE( "iface %p increasing refcount to %lu.\n", iface, ref );
    return ref;
}

static ULONG WINAPI application_data_Release( IApplicationData *iface )
{
    struct application_data *impl = impl_from_IApplicationData( iface );
    ULONG ref = InterlockedDecrement( &impl->ref );

    TRACE( "iface %p decreasing refcount to %lu.\n", iface, ref );

    if (!ref) free( impl );
    return ref;
}

static HRESULT WINAPI application_data_GetIids( IApplicationData *iface, ULONG *iid_count, IID **iids )
{
    FIXME( "iface %p, iid_count %p, iids %p stub!\n", iface, iid_count, iids );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_GetRuntimeClassName( IApplicationData *iface, HSTRING *class_name )
{
    FIXME( "iface %p, class_name %p stub!\n", iface, class_name );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_GetTrustLevel( IApplicationData *iface, TrustLevel *trust_level )
{
    FIXME( "iface %p, trust_level %p stub!\n", iface, trust_level );
    return E_NOTIMPL;
}

/**
 * COM Oriented, WinRT Implementation: winrt::Windows::Storage::ApplicationData
*/

static HRESULT WINAPI application_data_get_Version( IApplicationData *iface, UINT32 *value )
{
    struct application_data *impl = impl_from_IApplicationData( iface );
    *value = impl->Version;
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_SetVersionAsync( IApplicationData *iface, UINT32 version, IApplicationDataSetVersionHandler *handler,
                                                        IAsyncAction **operation )
{
    HRESULT hr;
    //Keep in mind, IApplicationDataSetVersionHandler is implemented by the client.
    struct application_data *impl = impl_from_IApplicationData( iface );
    struct set_version_options *set_version_options;
    struct set_version *versionRequest;

    if (!(set_version_options = calloc( 1, sizeof(*set_version_options) ))) return E_OUTOFMEMORY;

    versionRequest = impl_from_ISetVersionRequest( &set_version_options->request );

    versionRequest->ISetVersionRequest_iface.lpVtbl = &set_version_vtbl;
    versionRequest->ISetVersionDeferral_iface.lpVtbl = &set_version_deferral_vtbl;
    versionRequest->CurrentVersion = impl->Version;
    versionRequest->DesiredVersion = version;
    versionRequest->ref = 1;

    set_version_options->handler = handler;

    hr = async_action_create( (IUnknown *)iface, (IUnknown *)set_version_options, application_data_SetVersion, operation );
    TRACE( "created IAsyncAction %p.\n", *operation );

    return hr;
}

static HRESULT WINAPI application_data_ClearAllAsync( IApplicationData *iface, IAsyncAction **operation )
{
    FIXME( "iface %p, operation %p stub!\n", iface, operation );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_ClearAsync( IApplicationData *iface, ApplicationDataLocality locality, IAsyncAction **operation )
{
    FIXME( "iface %p, %d locality, operation %p stub!\n", iface, locality, operation );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_get_LocalSettings( IApplicationData *iface, IApplicationDataContainer **value )
{
    struct application_data *impl = impl_from_IApplicationData( iface );
    TRACE( "iface %p, value %p\n", iface, value );
    return application_data_AssignAndTrackContainer( impl->appDataPath, L"ApplicationData\\LocalState", value );
}

static HRESULT WINAPI application_data_get_RoamingSettings( IApplicationData *iface, IApplicationDataContainer **value )
{
    //Client should use Azure App Service instead.
    TRACE( "iface %p, value %p client should use Azure App Service!\n", iface, value );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_get_LocalFolder( IApplicationData *iface, IStorageFolder **value )
{ 
    IActivationFactory *storageActivationFactory;
    IActivationFactory *appdataPathsActivationFactory;
    IStorageFolderStatics *storageFolderStatics;
    IAsyncOperation_StorageFolder *operation;
    IAppDataPathsStatics *appDataStatics;
    IAppDataPaths *appData;

    HRESULT hr;
    HSTRING classIds;
    HSTRING path;
    DWORD res;

    WindowsCreateString( L"Windows.Storage.StorageFolder", wcslen( L"Windows.Storage.StorageFolder" ), &classIds );
    hr = RoGetActivationFactory( classIds, &IID_IActivationFactory, (void **)&storageActivationFactory );
    if ( FAILED( hr ) ) return hr;

    WindowsCreateString( L"Windows.Storage.AppDataPaths", wcslen( L"Windows.Storage.AppDataPaths" ), &classIds );
    hr = RoGetActivationFactory( classIds, &IID_IActivationFactory, (void **)&appdataPathsActivationFactory );
    if ( FAILED( hr ) ) return hr;

    hr = IActivationFactory_QueryInterface( storageActivationFactory, &IID_IStorageFolderStatics, (void **)&storageFolderStatics );
    if ( FAILED( hr ) ) return hr;

    hr = IActivationFactory_QueryInterface( appdataPathsActivationFactory, &IID_IAppDataPathsStatics, (void **)&appDataStatics );
    if ( FAILED( hr ) ) return hr;

    hr = IAppDataPathsStatics_GetDefault( appDataStatics, &appData );
    if ( FAILED( hr ) ) return hr;

    IAppDataPaths_get_LocalAppData( appData, &path );

    hr = IStorageFolderStatics_GetFolderFromPathAsync( storageFolderStatics, path, &operation );
    if ( FAILED( hr ) ) return hr;

    res = await_IAsyncOperation_StorageFolder( operation, INFINITE );
    if ( res ) return E_ABORT;

    hr = IAsyncOperation_StorageFolder_GetResults( operation, value );
    
    return hr;
}

static HRESULT WINAPI application_data_get_RoamingFolder( IApplicationData *iface, IStorageFolder **value )
{
    IActivationFactory *storageActivationFactory;
    IActivationFactory *appdataPathsActivationFactory;
    IStorageFolderStatics *storageFolderStatics;
    IAsyncOperation_StorageFolder *operation;
    IAppDataPathsStatics *appDataStatics;
    IAppDataPaths *appData;

    HRESULT hr;
    HSTRING classIds;
    HSTRING path;
    DWORD res;

    WindowsCreateString( L"Windows.Storage.StorageFolder", wcslen( L"Windows.Storage.StorageFolder" ), &classIds );
    hr = RoGetActivationFactory( classIds, &IID_IActivationFactory, (void **)&storageActivationFactory );
    if ( FAILED( hr ) ) return hr;

    WindowsCreateString( L"Windows.Storage.AppDataPaths", wcslen( L"Windows.Storage.AppDataPaths" ), &classIds );
    hr = RoGetActivationFactory( classIds, &IID_IActivationFactory, (void **)&appdataPathsActivationFactory );
    if ( FAILED( hr ) ) return hr;

    hr = IActivationFactory_QueryInterface( storageActivationFactory, &IID_IStorageFolderStatics, (void **)&storageFolderStatics );
    if ( FAILED( hr ) ) return hr;

    hr = IActivationFactory_QueryInterface( appdataPathsActivationFactory, &IID_IAppDataPathsStatics, (void **)&appDataStatics );
    if ( FAILED( hr ) ) return hr;

    hr = IAppDataPathsStatics_GetDefault( appDataStatics, &appData );
    if ( FAILED( hr ) ) return hr;

    IAppDataPaths_get_RoamingAppData( appData, &path );

    hr = IStorageFolderStatics_GetFolderFromPathAsync( storageFolderStatics, path, &operation );
    if ( FAILED( hr ) ) return hr;

    res = await_IAsyncOperation_StorageFolder( operation, INFINITE );
    if ( res ) return E_ABORT;

    hr = IAsyncOperation_StorageFolder_GetResults( operation, value );
    
    return hr;
}

static HRESULT WINAPI application_data_get_TemporaryFolder( IApplicationData *iface, IStorageFolder **value )
{
    IActivationFactory *storageActivationFactory;
    IStorageFolderStatics *storageFolderStatics;
    IAsyncOperation_StorageFolder *operation;

    HRESULT hr;
    HSTRING windowsStorageFolderClassId;
    HSTRING path;
    WCHAR pathStr[MAX_PATH];
    DWORD attributes;
    DWORD res;

    struct application_data *impl = impl_from_IApplicationData( iface );

    wcscpy( pathStr, WindowsGetStringRawBuffer(impl->appDataPath, NULL) );
    PathAppendW( pathStr, L"TempState" );

    attributes = GetFileAttributesW( pathStr );
    if ( attributes == INVALID_FILE_ATTRIBUTES ) {
        if ( !CreateDirectoryW( pathStr, NULL ) ) {
            return E_UNEXPECTED;
        }
    }

    WindowsCreateString( pathStr, wcslen( pathStr ), &path );

    WindowsCreateString( L"Windows.Storage.StorageFolder", wcslen( L"Windows.Storage.StorageFolder" ), &windowsStorageFolderClassId );
    hr = RoGetActivationFactory( windowsStorageFolderClassId, &IID_IActivationFactory, (void **)&storageActivationFactory );
    if ( FAILED( hr ) ) return hr;

    hr = IActivationFactory_QueryInterface( storageActivationFactory, &IID_IStorageFolderStatics, (void **)&storageFolderStatics );
    if ( FAILED( hr ) ) return hr;

    hr = IStorageFolderStatics_GetFolderFromPathAsync( storageFolderStatics, path, &operation );
    if ( FAILED( hr ) ) return hr;

    res = await_IAsyncOperation_StorageFolder( operation, INFINITE );
    if ( res ) return E_ABORT;

    hr = IAsyncOperation_StorageFolder_GetResults( operation, value );
    
    return hr;
}

static HRESULT WINAPI application_data_add_DataChanged( IApplicationData *iface, ITypedEventHandler_ApplicationData_IInspectable *handler,
                                                        EventRegistrationToken *token )
{
    FIXME( "iface %p, handler %p, token %p stub!\n", iface, handler, token );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_remove_DataChanged( IApplicationData *iface, EventRegistrationToken token )
{
    FIXME( "iface %p, token %#I64x stub!\n", iface, token.value );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_SignalDataChanged( IApplicationData *iface )
{
    FIXME( "iface %p stub!\n", iface );
    return E_NOTIMPL;
}

static HRESULT WINAPI application_data_get_RoamingStorageQuota( IApplicationData *iface, UINT64 *value )
{
    FIXME( "iface %p, value %p stub!\n", iface, value );
    return E_NOTIMPL;
}

const struct IApplicationDataVtbl application_data_vtbl =
{
    application_data_QueryInterface,
    application_data_AddRef,
    application_data_Release,
    /* IInspectable methods */
    application_data_GetIids,
    application_data_GetRuntimeClassName,
    application_data_GetTrustLevel,
    /* IApplicationData methods */
    application_data_get_Version,
    application_data_SetVersionAsync,
    application_data_ClearAllAsync,
    application_data_ClearAsync,
    application_data_get_LocalSettings,
    application_data_get_RoamingSettings,
    application_data_get_LocalFolder,
    application_data_get_RoamingFolder,
    application_data_get_TemporaryFolder,
    application_data_add_DataChanged,
    application_data_remove_DataChanged,
    application_data_SignalDataChanged,
    application_data_get_RoamingStorageQuota,
};

DEFINE_IINSPECTABLE( application_data_statics, IApplicationDataStatics, struct application_data_statics, IActivationFactory_iface )

static HRESULT WINAPI application_data_statics_get_Current( IApplicationDataStatics *iface, IApplicationData **value )
{
    TRACE( "iface %p, value %p\n", iface, value );
    return application_data_Init( value );
}

static const struct IApplicationDataStaticsVtbl application_data_statics_vtbl =
{
    application_data_statics_QueryInterface,
    application_data_statics_AddRef,
    application_data_statics_Release,
    /* IInspectable methods */
    application_data_statics_GetIids,
    application_data_statics_GetRuntimeClassName,
    application_data_statics_GetTrustLevel,
    /* IApplicationDataStatics methods */
    application_data_statics_get_Current,
};

static struct application_data_statics application_data_statics =
{
    {&factory_vtbl},
    {&application_data_statics_vtbl},
    1,
};

IActivationFactory *application_data_factory = &application_data_statics.IActivationFactory_iface;
