#if 0
#pragma makedep unix
#endif

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "unixlib.h"
#include "wine/debug.h"
#include <windows.h>

#define trace printf("Current function: %s\n", __func__);

static NTSTATUS chakra_JsCreateRuntime(void *args)
{
    trace
    struct JsCreateRuntime_params *params = args;
    return JsCreateRuntime(params->attributes, params->threadService, params->runtime);
}

static NTSTATUS chakra_JsCreateContext(void *args)
{
    trace
    struct JsCreateContext_params *params = args;
    JsErrorCode x = JsCreateContext(params->runtime, params->newContext);
    return x;
}

static NTSTATUS chakra_JsSetCurrentContext(void *args)
{
    trace
    struct JsSetCurrentContext_params *params = args;
    return JsSetCurrentContext(params->context);
}



static NTSTATUS chakra_JsRunScript(void *args)
{
    trace
    struct JsRunScript_params *params = args;
    // technically we should initialize a context for this but in practice this is already being called within a context.
    // as such we're safe to assume a ctx exists.
    // wprintf(L"%ls\n",params->script);
    JsValueRef script;
    JsValueRef sourceUrl;

    printf("getting script from %s\n",params->sourceUrl);
    if (JsCreateString(params->script,strlen(params->script),&script) != JsNoError)
        printf("Couldn't make JsString for Source String\n");
    if (JsCreateString(params->sourceUrl,strlen(params->sourceUrl),&sourceUrl) != JsNoError)
        printf("Couldn't make JsString for SourceUrl String\n");

    JsErrorCode runErr = JsRun(script, params->sourceContext, sourceUrl, JsParseScriptAttributeNone, params->result);
    if (runErr != JsNoError)
    {
        printf("jserr: %d from \n", runErr);
    }
    printf("Finished runScript\n");
    return runErr;
}

static NTSTATUS chakra_JsAddRef(void *args)
{
    trace
    struct JsAddRef_params *params = args;
    return JsAddRef(params->ref, params->count);
}

static NTSTATUS chakra_JsGetGlobalObject(void *args)
{
    trace
    struct JsGetGlobalObject_params *params = args;
    return JsGetGlobalObject(params->globalObject);
}

static NTSTATUS chakra_JsCreateObject(void *args)
{
    trace
    struct JsCreateObject_params *params = args;
    return JsCreateObject(params->object);
}

static NTSTATUS chakra_JsCreateExternalObject(void *args)
{
    trace
    struct JsCreateExternalObject_params *params = args;
    return JsCreateExternalObject(params->data, params->finalizeCallback, params->object);
}

static NTSTATUS chakra_JsGetPropertyIdFromName(void *args)
{
    trace
    struct JsGetPropertyIdFromName_params *params = args;
    return JsGetPropertyIdFromName(params->name, params->propertyId);
}

static NTSTATUS chakra_JsSetProperty(void *args)
{
    trace
    struct JsSetProperty_params *params = args;
    return JsSetProperty(params->object, params->propertyId, params->value, params->useStrictRules);
}

static NTSTATUS chakra_JsCreateFunction(void *args)
{
    trace
    struct JsCreateFunction_params *params = args;
    return JsCreateFunction(params->nativeFunction, params->callbackState, params->function);
}

static NTSTATUS chakra_JsRelease(void *args)
{
    trace
    struct JsRelease_params *params = args;
    return JsRelease(params->ref, params->count);
}

static NTSTATUS chakra_JsPointerToString(void *args)
{
    struct JsPointerToString_params *params = args;
    printf("Ptr2Str: %s\n",params->stringValue);
    return JsCreateString(params->stringValue, strlen(params->stringValue), params->value);
}

static NTSTATUS chakra_JsIntToNumber(void *args)
{
    trace
    struct JsIntToNumber_params *params = args;
    return JsIntToNumber(params->intValue, params->value);
}

static NTSTATUS chakra_JsNumberToInt(void *args)
{
    trace
    struct JsNumberToInt_params *params = args;
    return JsNumberToInt(params->value, params->intValue);
}

static NTSTATUS chakra_JsNumberToDouble(void *args)
{
    trace
    struct JsNumberToDouble_params *params = args;
    return JsNumberToDouble(params->value, params->doubleValue);
}

static NTSTATUS chakra_JsDoubleToNumber(void *args)
{
    trace
    struct JsDoubleToNumber_params *params = args;
    return JsDoubleToNumber(params->doubleValue, params->value);
}

static NTSTATUS chakra_JsSetPromiseContinuationCallback(void *args)
{
    trace
    struct JsSetPromiseContinuationCallback_params *params = args;
    return JsSetPromiseContinuationCallback(params->promiseContinuationCallback, params->callbackState);
}

static NTSTATUS chakra_JsHasException(void *args)
{
    trace
    struct JsHasException_params *params = args;
    return JsHasException(params->hasException);
}

static NTSTATUS chakra_JsCreateArray(void *args)
{
    trace
    struct JsCreateArray_params *params = args;
    return JsCreateArray(params->length, params->result);
}

static NTSTATUS chakra_JsSetIndexedProperty(void *args)
{
    trace
    struct JsSetIndexedProperty_params *params = args;
    return JsSetIndexedProperty(params->object, params->index, params->value);
}

static NTSTATUS chakra_JsStringToPointer(void *args)
{
    printf("String to pointer\n");
    struct JsStringToPointer_params *params = args;
    int len;
    JsGetStringLength(params->value,&len);
    WCHAR resbuf[len+1];
    size_t lenReal;
    JsErrorCode r = JsCopyStringUtf16(params->value,0,len+1,resbuf,&lenReal);
    if (r != JsNoError) printf("failed to copy string :(");
    *(params->stringValue) = (WCHAR*)resbuf;
    *(params->stringLength) = len;
    return r;
}

#define FUNC(name)                            \
    static NTSTATUS chakra_##name(void *args) \
    {                                         \
        printf("Current function: %s\n", __func__);\
        struct name##_params *params = args;

FUNC(JsDisposeRuntime)
return JsDisposeRuntime(params->runtime);
}

FUNC(JsBoolToBoolean)
return JsBoolToBoolean(params->value, params->booleanValue);
}

FUNC(JsBooleanToBool)
return JsBooleanToBool(params->value, params->boolValue);
}

FUNC(JsCallFunction)
return JsCallFunction(params->function, params->arguments, params->argumentCount, params->result);
}

FUNC(JsGetAndClearException)
return JsGetAndClearException(params->exception);
}

FUNC(JsGetProperty)
return JsGetProperty(params->object, params->propertyId, params->value);
}

FUNC(JsConvertValueToBoolean)
return JsConvertValueToBoolean(params->value, params->booleanValue);
}

FUNC(JsConvertValueToNumber)
return JsConvertValueToNumber(params->value, params->numberValue);
}

FUNC(JsConvertValueToString)
return JsConvertValueToString(params->value, params->stringValue);
}

FUNC(JsCreateError)
return JsCreateError(params->message, params->error);
}

FUNC(JsGetIndexedProperty)
return JsGetIndexedProperty(params->object, params->index, params->result);
}

FUNC(JsGetNullValue)
return JsGetNullValue(params->nullValue);
}

FUNC(JsGetOwnPropertyNames)
return JsGetOwnPropertyNames(params->object, params->propertyNames);
}

FUNC(JsGetUndefinedValue)
return JsGetUndefinedValue(params->value);
}

FUNC(JsGetValueType)
return JsGetValueType(params->value, params->type);
}

FUNC(JsHasIndexedProperty)
return JsHasIndexedProperty(params->object, params->index, params->result);
}

FUNC(JsHasProperty)
return JsHasProperty(params->object, params->propertyId, params->hasProperty);
}

FUNC(JsSetException)
return JsSetException(params->exception);
}

const unixlib_entry_t __wine_unix_call_funcs[] = {
    chakra_JsCreateRuntime,
    chakra_JsCreateContext,
    chakra_JsSetCurrentContext,
    chakra_JsRunScript,
    chakra_JsAddRef,
    chakra_JsGetGlobalObject,
    chakra_JsCreateObject,
    chakra_JsCreateExternalObject,
    chakra_JsGetPropertyIdFromName,
    chakra_JsSetProperty,
    chakra_JsCreateFunction,
    chakra_JsRelease,
    chakra_JsPointerToString,
    chakra_JsIntToNumber,
    chakra_JsNumberToInt,
    chakra_JsNumberToDouble,
    chakra_JsDoubleToNumber,
    chakra_JsSetPromiseContinuationCallback,
    chakra_JsHasException,
    chakra_JsCreateArray,
    chakra_JsSetIndexedProperty,
    chakra_JsDisposeRuntime,
    chakra_JsBoolToBoolean,
    chakra_JsBooleanToBool,
    chakra_JsCallFunction,
    chakra_JsGetAndClearException,
    chakra_JsGetProperty,
    chakra_JsConvertValueToBoolean,
    chakra_JsConvertValueToNumber,
    chakra_JsConvertValueToString,
    chakra_JsCreateError,
    chakra_JsGetIndexedProperty,
    chakra_JsGetNullValue,
    chakra_JsGetOwnPropertyNames,
    chakra_JsGetUndefinedValue,
    chakra_JsGetValueType,
    chakra_JsHasIndexedProperty,
    chakra_JsHasProperty,
    chakra_JsSetException,
    chakra_JsStringToPointer,
};