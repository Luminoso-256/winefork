#include <stdio.h>
#include <sys/types.h>

#include "unixlib.h"
#include "wine/debug.h"
#include "windows.h"

WINE_DEFAULT_DEBUG_CHANNEL(chakra);

BOOL WINAPI DllMain( HINSTANCE hinst, DWORD reason, LPVOID reserved ){
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinst);
        return !__wine_init_unix_call();
    }
    return TRUE;
}

JsErrorCode WINAPI CHAKRA_JsCreateRuntime(JsRuntimeAttributes attributes, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime){
    struct JsCreateRuntime_params params = { attributes, threadService, runtime };
    WINE_UNIX_CALL(unix_JsCreateRuntime, &params);
}

JsErrorCode WINAPI CHAKRA_JsCreateContext(JsRuntimeHandle runtime, JsContextRef *newContext){
    struct JsCreateContext_params params = { runtime, newContext };
    WINE_UNIX_CALL(unix_JsCreateContext, &params);
}

JsErrorCode WINAPI CHAKRA_JsSetCurrentContext(JsContextRef context){
    struct JsSetCurrentContext_params params = {context};
    WINE_UNIX_CALL(unix_JsSetCurrentContext,&params);
}

char *convert_wchar_to_utf8(const WCHAR *wchar_str)
{
    // Get the required buffer size for UTF-8 string
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wchar_str, -1, NULL, 0, NULL, NULL);
    char *utf8_str = (char *)malloc(size_needed);
    int bytes_written = WideCharToMultiByte(CP_UTF8, 0, wchar_str, -1, utf8_str, size_needed, NULL, NULL);
    return utf8_str;
}

JsErrorCode WINAPI CHAKRA_JsRunScript(const WCHAR *script, JsSourceContext sourceContext, const WCHAR *sourceUrl, JsValueRef *result){
    struct JsRunScript_params params = {
        convert_wchar_to_utf8(script),
        sourceContext,
        convert_wchar_to_utf8(sourceUrl),
        result};
    WINE_UNIX_CALL(unix_JsRunScript,&params);
}

JsErrorCode WINAPI CHAKRA_JsAddRef(JsRef ref, unsigned int *count){
    struct JsAddRef_params params = {ref, count};
    WINE_UNIX_CALL(unix_JsAddRef,&params);
}

JsErrorCode WINAPI CHAKRA_JsStartDebugging(){
    FIXME("stub: JsStartDebugging is not starting anything :)\n");
    return JsNoError;
}

JsErrorCode WINAPI CHAKRA_JsStartProfiling(void* callback, UINT32 flagsEnum, int){
    FIXME("stub: JsStartProfiling is not starting anything :)\n");
    return JsNoError;
}

JsErrorCode WINAPI CHAKRA_JsGetGlobalObject(JsValueRef globalObject){
    struct JsGetGlobalObject_params params = {globalObject};
    WINE_UNIX_CALL(unix_JsGetGlobalObject,&params);
}

JsErrorCode WINAPI CHAKRA_JsCreateObject(JsValueRef *object){
    struct JsCreateObject_params params = {object};
    WINE_UNIX_CALL(unix_JsCreateObject,&params);
}

JsErrorCode WINAPI CHAKRA_JsCreateExternalObject(void *data, JsFinalizeCallback finalizeCallback, JsValueRef object){
    struct JsCreateExternalObject_params params = {data,finalizeCallback,object};
    WINE_UNIX_CALL(unix_JsCreateExternalObject,&params);
}

JsErrorCode WINAPI CHAKRA_JsGetPropertyIdFromName(const WCHAR *name, JsPropertyIdRef *propertyId){
    struct JsGetPropertyIdFromName_params params = {name,propertyId};
    WINE_UNIX_CALL(unix_JsGetPropertyIdFromName,&params);
}

JsErrorCode WINAPI CHAKRA_JsSetProperty(JsValueRef object, JsPropertyIdRef propertyId, JsValueRef value, bool useStrictRules){
    struct JsSetProperty_params params = {object,propertyId,value,useStrictRules};
    WINE_UNIX_CALL(unix_JsSetProperty,&params);
}

JsErrorCode WINAPI CHAKRA_JsCreateFunction(JsNativeFunction nativeFunction, void *callbackState, JsValueRef function){
    struct JsCreateFunction_params params = {nativeFunction,callbackState,function};
    WINE_UNIX_CALL(unix_JsCreateFunction,&params);
}

JsErrorCode WINAPI CHAKRA_JsRelease(JsRef ref, unsigned int *count){
    struct JsRelease_params params = {ref,count};
    WINE_UNIX_CALL(unix_JsRelease,&params);
}

JsErrorCode WINAPI CHAKRA_JsPointerToString(const WCHAR *stringValue, size_t stringLength, JsValueRef *value){
    struct JsPointerToString_params params = {convert_wchar_to_utf8(stringValue), stringLength, value};
    WINE_UNIX_CALL(unix_JsPointerToString,&params);
}

JsErrorCode WINAPI CHAKRA_JsIntToNumber(int intValue, JsValueRef *value){
    struct JsIntToNumber_params params = {intValue,value};
    WINE_UNIX_CALL(unix_JsIntToNumber,&params);
}

JsErrorCode WINAPI CHAKRA_JsNumberToInt(JsValueRef value, int *intValue){
    struct JsNumberToInt_params params = {value,intValue};
    WINE_UNIX_CALL(unix_JsNumberToInt,&params);
}

JsErrorCode WINAPI CHAKRA_JsNumberToDouble(JsValueRef value, double *doubleValue){
    struct JsNumberToDouble_params params = {value, doubleValue};
    WINE_UNIX_CALL(unix_JsNumberToDouble,&params);
}

JsErrorCode WINAPI CHAKRA_JsDoubleToNumber(double doubleValue, JsValueRef *value){
    struct JsDoubleToNumber_params params = {doubleValue, value};
    WINE_UNIX_CALL(unix_JsDoubleToNumber,&params);
}

JsErrorCode WINAPI CHAKRA_JsSetPromiseContinuationCallback(JsPromiseContinuationCallback promise, void *cbState){
    struct JsSetPromiseContinuationCallback_params params = {promise,cbState};
    WINE_UNIX_CALL(unix_JsSetPromiseContinuationCallback,&params);
}

JsErrorCode WINAPI CHAKRA_JsHasException(bool *hasException){
    struct JsHasException_params params = {hasException};
    WINE_UNIX_CALL(unix_JsHasException,&params);
}

JsErrorCode WINAPI CHAKRA_JsCreateArray(unsigned int length, JsValueRef *result){
    struct JsCreateArray_params params = {length, result};
    WINE_UNIX_CALL(unix_JsCreateArray,&params);
}

JsErrorCode WINAPI CHAKRA_JsSetIndexedProperty(JsValueRef object, JsValueRef index, JsValueRef value){
    struct JsSetIndexedProperty_params params = {object,index,value};
    WINE_UNIX_CALL(unix_JsSetIndexedProperty,&params);
}

JsErrorCode WINAPI CHAKRA_JsDisposeRuntime(JsRuntimeHandle runtime){
    struct JsDisposeRuntime_params p = {runtime};
    WINE_UNIX_CALL(unix_JsDisposeRuntime,&p);
}

JsErrorCode WINAPI CHAKRA_JsBoolToBoolean(bool value, JsValueRef *booleanValue){
    struct JsBoolToBoolean_params p = {value,booleanValue};
    WINE_UNIX_CALL(unix_JsBoolToBoolean,&p);
}

JsErrorCode WINAPI CHAKRA_JsBooleanToBool(JsValueRef value, bool *boolValue){
    struct JsBooleanToBool_params p = {value,boolValue};
    WINE_UNIX_CALL(unix_JsBooleanToBool,&p);
}

JsErrorCode WINAPI CHAKRA_JsCallFunction(JsValueRef f, JsValueRef *a, unsigned short ac, JsValueRef *result){
    struct JsCallFunction_params p = {f,a,ac,result};
    WINE_UNIX_CALL(unix_JsCallFunction,&p);
}

JsErrorCode WINAPI CHAKRA_JsGetAndClearException(JsValueRef *exception){
    struct JsGetAndClearException_params p = {exception};
    WINE_UNIX_CALL(unix_JsGetAndClearException,&p);
}

JsErrorCode WINAPI CHAKRA_JsGetProperty(JsValueRef object, JsPropertyIdRef propertyId, JsValueRef *value){
    struct JsGetProperty_params p = {object, propertyId, value};
    WINE_UNIX_CALL(unix_JsGetProperty,&p);
}

#define H(name) JsErrorCode WINAPI CHAKRA_##name
#define S(name,...) { struct name##_params p = {__VA_ARGS__}; WINE_UNIX_CALL(unix_##name,&p); }

H(JsConvertValueToBoolean) (JsValueRef value, JsValueRef *booleanValue) S(JsConvertValueToBoolean,value,booleanValue)
H(JsConvertValueToNumber) (JsValueRef value, JsValueRef *numberValue) S(JsConvertValueToNumber,value,numberValue)
H(JsConvertValueToString) (JsValueRef value, JsValueRef *stringValue) S(JsConvertValueToString,value,stringValue)
H(JsCreateError) (JsValueRef message, JsValueRef *error) S(JsCreateError,message,error)
H(JsGetIndexedProperty) (JsValueRef object, JsValueRef index, JsValueRef *result) S(JsSetIndexedProperty,object,index,result)
H(JsGetNullValue) (JsValueRef *nullValue) S(JsGetNullValue, nullValue)
H(JsGetOwnPropertyNames) (JsValueRef object, JsValueRef *propertyNames) S(JsGetOwnPropertyNames, object, propertyNames)
H(JsGetUndefinedValue) (JsValueRef *value) S(JsGetUndefinedValue, value)
H(JsGetValueType) (JsValueRef value, JsValueType *type) S(JsGetValueType, value, type)
H(JsHasIndexedProperty) (JsValueRef object, JsValueRef index, bool *result) S(JsHasIndexedProperty, object, index, result)
H(JsHasProperty) (JsValueRef object, JsPropertyIdRef propertyId, bool *hasProperty) S(JsHasProperty, object, propertyId, hasProperty)
H(JsSetException) (JsValueRef exception) S(JsSetException, exception)
H(JsStringToPointer) (JsValueRef value, const WCHAR **stringValue, size_t *stringLength) S(JsStringToPointer,value,stringValue,stringLength)