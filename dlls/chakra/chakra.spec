@ stub JsProjectWinRTNamespace
@ stub JsSetProjectionEnqueueCallback
@ stub CreateChakraEngine
@ stub DumpDiagInfo
@ stub JsDiscardBackgroundParse
@ stub JsInitializeJITServer
@ stub JsQueueBackgroundParse
@ stub MemProtectHeapAddRootSection
@ stub MemProtectHeapCollect
@ stub MemProtectHeapCreate
@ stub MemProtectHeapDestroy
@ stub MemProtectHeapDisableCollection
@ stub MemProtectHeapIsValidObject
@ stub MemProtectHeapMemSize
@ stub MemProtectHeapNotifyCurrentThreadDetach
@ stub MemProtectHeapProtectCurrentThread
@ stub MemProtectHeapRemoveRootSection
@ stub MemProtectHeapReportHeapSize
@ stub MemProtectHeapRootAlloc
@ stub MemProtectHeapRootAllocLeaf
@ stub MemProtectHeapRootRealloc
@ stub MemProtectHeapRootReallocLeaf
@ stub MemProtectHeapSynchronizeWithCollector
@ stub MemProtectHeapUnprotectCurrentThread
@ stub MemProtectHeapUnrootAndZero
@ stub RecyclerNativeHeapAddExternalMemoryUsage
@ stub RecyclerNativeHeapAllocLeaf
@ stub RecyclerNativeHeapAllocLeafFinalized
@ stub RecyclerNativeHeapAllocTraced
@ stub RecyclerNativeHeapAllocTracedFinalized
@ stub RecyclerNativeHeapCollectGarbageInThread
@ stub RecyclerNativeHeapCreateWeakReference
@ stub RecyclerNativeHeapGetRealAddressFromInterior
@ stub RecyclerNativeHeapGetStrongReference
@ stub RecyclerNativeHeapHasWeakReferenceCleanupOccurred
@ stub RecyclerNativeHeapRootAddRef
@ stub RecyclerNativeHeapRootRelease
@ stdcall -private DllCanUnloadNow()
@ stub DllGetClassObject
@ stub DllRegisterServer
@ stub DllUnregisterServer
@ stdcall JsAddRef(ptr ptr) CHAKRA_JsAddRef
@ stdcall JsBoolToBoolean(long ptr) CHAKRA_JsBoolToBoolean
@ stdcall JsBooleanToBool(ptr ptr) CHAKRA_JsBooleanToBool
@ stdcall JsCallFunction(ptr ptr long ptr) CHAKRA_JsCallFunction
@ stub JsCollectGarbage
@ stub JsConstructObject
@ stdcall JsConvertValueToBoolean(ptr ptr) CHAKRA_JsConvertValueToBoolean
@ stdcall JsConvertValueToNumber(ptr ptr) CHAKRA_JsConvertValueToNumber
@ stub JsConvertValueToObject
@ stdcall JsConvertValueToString(ptr ptr) CHAKRA_JsConvertValueToString
@ stdcall JsCreateArray(long ptr) CHAKRA_JsCreateArray
@ stub JsCreateArrayBuffer
@ stdcall JsCreateContext(ptr ptr) CHAKRA_JsCreateContext
@ stub JsCreateDataView
@ stdcall JsCreateError(ptr ptr) CHAKRA_JsCreateError
@ stub JsCreateExternalArrayBuffer
@ stdcall JsCreateExternalObject(ptr ptr ptr) CHAKRA_JsCreateExternalObject
@ stdcall JsCreateFunction(ptr ptr ptr) CHAKRA_JsCreateFunction
@ stub JsCreateNamedFunction
@ stdcall JsCreateObject(ptr) CHAKRA_JsCreateObject
@ stub JsCreateRangeError
@ stub JsCreateReferenceError
@ stdcall JsCreateRuntime(long ptr ptr) CHAKRA_JsCreateRuntime
@ stub JsCreateSymbol
@ stub JsCreateSyntaxError
@ stub JsCreateThreadService
@ stub JsCreateTypeError
@ stub JsCreateTypedArray
@ stub JsCreateURIError
@ stub JsDefineProperty
@ stub JsDeleteIndexedProperty
@ stub JsDeleteProperty
@ stub JsDisableRuntimeExecution
@ stdcall JsDisposeRuntime(ptr) CHAKRA_JsDisposeRuntime
@ stdcall JsDoubleToNumber(double ptr) CHAKRA_JsDoubleToNumber
@ stub JsEnableRuntimeExecution
@ stub JsEnumerateHeap
@ stub JsEquals
@ stdcall JsGetAndClearException(ptr) CHAKRA_JsGetAndClearException
@ stub JsGetArrayBufferStorage
@ stub JsGetContextData
@ stub JsGetContextOfObject
@ stub JsGetCurrentContext
@ stub JsGetDataViewStorage
@ stub JsGetExtensionAllowed
@ stub JsGetExternalData
@ stub JsGetFalseValue
@ stdcall JsGetGlobalObject(ptr) CHAKRA_JsGetGlobalObject
@ stub JsGetIndexedPropertiesExternalData
@ stdcall JsGetIndexedProperty(ptr ptr ptr) CHAKRA_JsGetIndexedProperty
@ stdcall JsGetNullValue(ptr) CHAKRA_JsGetNullValue
@ stub JsGetOwnPropertyDescriptor
@ stdcall JsGetOwnPropertyNames(ptr ptr) CHAKRA_JsGetOwnPropertyNames
@ stub JsGetOwnPropertySymbols
@ stdcall JsGetProperty(ptr ptr ptr) CHAKRA_JsGetProperty
@ stdcall JsGetPropertyIdFromName(ptr ptr) CHAKRA_JsGetPropertyIdFromName
@ stub JsGetPropertyIdFromSymbol
@ stub JsGetPropertyIdType
@ stub JsGetPropertyNameFromId
@ stub JsGetPrototype
@ stub JsGetRuntime
@ stub JsGetRuntimeMemoryLimit
@ stub JsGetRuntimeMemoryUsage
@ stub JsGetStringLength
@ stub JsGetSymbolFromPropertyId
@ stub JsGetTrueValue
@ stub JsGetTypedArrayInfo
@ stub JsGetTypedArrayStorage
@ stdcall JsGetUndefinedValue(ptr) CHAKRA_JsGetUndefinedValue
@ stdcall JsGetValueType(ptr ptr) CHAKRA_JsGetValueType
@ stdcall JsHasException(ptr) CHAKRA_JsHasException
@ stub JsHasExternalData
@ stub JsHasIndexedPropertiesExternalData
@ stdcall JsHasIndexedProperty(ptr ptr ptr) CHAKRA_JsHasIndexedProperty
@ stdcall JsHasProperty(ptr ptr ptr) CHAKRA_JsHasProperty
@ stub JsIdle
@ stub JsInspectableToObject
@ stub JsInstanceOf
@ stdcall JsIntToNumber(long ptr) CHAKRA_JsIntToNumber
@ stub JsIsEnumeratingHeap
@ stub JsIsRuntimeExecutionDisabled
@ stdcall JsNumberToDouble(ptr ptr) CHAKRA_JsNumberToDouble
@ stdcall JsNumberToInt(ptr ptr) CHAKRA_JsNumberToInt
@ stub JsObjectToInspectable
@ stub JsParseScript
@ stub JsParseScriptWithAttributes
@ stub JsParseSerializedScript
@ stub JsParseSerializedScriptWithCallback
@ stdcall JsPointerToString(ptr long ptr) CHAKRA_JsPointerToString
@ stub JsPreventExtension
@ stdcall JsRelease(ptr ptr) CHAKRA_JsRelease
@ stdcall JsRunScript(ptr ptr ptr ptr) CHAKRA_JsRunScript
@ stub JsRunSerializedScript
@ stub JsRunSerializedScriptWithCallback
@ stub JsSerializeScript
@ stub JsSetContextData
@ stdcall JsSetCurrentContext(ptr) CHAKRA_JsSetCurrentContext
@ stdcall JsSetException(ptr) CHAKRA_JsSetException
@ stub JsSetExternalData
@ stub JsSetIndexedPropertiesToExternalData
@ stdcall JsSetIndexedProperty(ptr ptr ptr) CHAKRA_JsSetIndexedProperty
@ stub JsSetObjectBeforeCollectCallback
@ stdcall JsSetPromiseContinuationCallback(ptr ptr) CHAKRA_JsSetPromiseContinuationCallback
@ stdcall JsSetProperty(ptr ptr ptr long) CHAKRA_JsSetProperty
@ stub JsSetPrototype
@ stub JsSetRuntimeBeforeCollectCallback
@ stub JsSetRuntimeMemoryAllocationCallback
@ stub JsSetRuntimeMemoryLimit
@ stdcall JsStartDebugging() CHAKRA_JsStartDebugging
@ stdcall JsStartProfiling(ptr long long) CHAKRA_JsStartProfiling
@ stub JsStopProfiling
@ stub JsStrictEquals
@ stdcall JsStringToPointer(ptr ptr ptr) CHAKRA_JsStringToPointer
@ stub JsValueToVariant
@ stub JsVarAddRef
@ stub JsVarRelease
@ stub JsVarToExtension
@ stub JsVarToScriptDirect
@ stub JsVariantToValue