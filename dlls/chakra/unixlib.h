#pragma once
#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "winternl.h"
#include "wine/unixlib.h"
#include "native/ChakraCore.h"
#include "native/ChakraCommon.h"

struct JsCreateRuntime_params {
    JsRuntimeAttributes attributes;
    JsThreadServiceCallback threadService;
    JsRuntimeHandle runtime;
};

struct JsCreateContext_params {
    JsRuntimeHandle runtime;
    JsContextRef *newContext;
};

struct JsSetCurrentContext_params {
    JsContextRef context; //note: a JsContextRef is typedefd to a void* in the APIs.
};

struct JsRunScript_params {
    const char *script;
    JsSourceContext sourceContext;
    const char *sourceUrl;
    JsValueRef *result;
};

struct JsAddRef_params {
    JsRef ref;
    unsigned int *count;
};

struct JsGetGlobalObject_params {
    JsValueRef globalObject;
};

struct JsCreateObject_params {
    JsValueRef *object;
};

struct JsCreateExternalObject_params {
    void *data;
    JsFinalizeCallback finalizeCallback;
    JsValueRef object;
};

struct JsGetPropertyIdFromName_params {
    const WCHAR *name;
    JsPropertyIdRef *propertyId;
};

struct JsSetProperty_params {
    JsValueRef object;
    JsPropertyIdRef propertyId;
    JsValueRef value;
    bool useStrictRules;
};

struct JsCreateFunction_params {
    JsNativeFunction nativeFunction;
    void *callbackState;
    JsValueRef *function;
};

struct JsRelease_params {
    JsRef ref;
    unsigned int *count;
};

struct JsPointerToString_params {
    const char *stringValue;
    size_t stringLength;
    JsValueRef *value;
};

struct JsIntToNumber_params {
    int intValue;
    JsValueRef *value;
};

struct JsNumberToInt_params {
    JsValueRef value;
    int *intValue;
};

struct JsNumberToDouble_params {
    JsValueRef  value;
    double *doubleValue;
};

struct JsDoubleToNumber_params {
    double doubleValue;
    JsValueRef  *value;
};

struct JsSetPromiseContinuationCallback_params {
    JsPromiseContinuationCallback promiseContinuationCallback;
    void *callbackState;
};

struct JsHasException_params {
    bool *hasException;
};

struct JsCreateArray_params {
    unsigned int length;
    JsValueRef *result;
};

struct JsSetIndexedProperty_params {
    JsValueRef object;
    JsValueRef index;
    JsValueRef value;
};

struct JsDisposeRuntime_params {
    JsRuntimeHandle runtime;
};

struct JsBoolToBoolean_params {
    bool value;
    JsValueRef *booleanValue;
};

struct JsBooleanToBool_params {
    JsValueRef value;
    bool *boolValue;
};

struct JsCallFunction_params {
    JsValueRef function;
    JsValueRef *arguments;
    unsigned short argumentCount; //word
    JsValueRef *result;
};

struct JsGetAndClearException_params {
    JsValueRef *exception;
};

struct JsGetProperty_params {
    JsValueRef object;
    JsPropertyIdRef propertyId;
    JsValueRef *value;
};

struct JsConvertValueToBoolean_params {
    JsValueRef value;
    JsValueRef *booleanValue;
};

struct JsConvertValueToNumber_params {
    JsValueRef value;
    JsValueRef *numberValue;
};

struct JsConvertValueToString_params {
    JsValueRef value;
    JsValueRef *stringValue;
};

struct JsCreateError_params {
    JsValueRef message;
    JsValueRef *error;
};

struct JsGetIndexedProperty_params {
    JsValueRef object;
    JsValueRef index;
    JsValueRef *result;
};

struct JsGetNullValue_params {
    JsValueRef *nullValue;
};

struct JsGetOwnPropertyNames_params {
    JsValueRef object;
    JsValueRef *propertyNames;
};

struct JsGetUndefinedValue_params {
    JsValueRef *value;
};

struct JsGetValueType_params {
    JsValueRef value;
    JsValueType *type;
};

struct JsHasIndexedProperty_params {
    JsValueRef object;
    JsValueRef index;
    bool *result;
};

struct JsHasProperty_params {
    JsValueRef object;
    JsPropertyIdRef propertyId;
    bool *hasProperty;
};

struct JsSetException_params {
    JsValueRef exception;
};

struct JsStringToPointer_params {
    JsValueRef value;
    const WCHAR **stringValue;
    size_t *stringLength;
};

enum chakra_funcs
{
    unix_JsCreateRuntime,
    unix_JsCreateContext,
    unix_JsSetCurrentContext,
    unix_JsRunScript,
    unix_JsAddRef,
    unix_JsGetGlobalObject,
    unix_JsCreateObject,
    unix_JsCreateExternalObject,
    unix_JsGetPropertyIdFromName,
    unix_JsSetProperty,
    unix_JsCreateFunction,
    unix_JsRelease,
    unix_JsPointerToString,
    unix_JsIntToNumber,
    unix_JsNumberToInt,
    unix_JsNumberToDouble,
    unix_JsDoubleToNumber,
    unix_JsSetPromiseContinuationCallback,
    unix_JsHasException,
    unix_JsCreateArray,
    unix_JsSetIndexedProperty,
    unix_JsDisposeRuntime,
    unix_JsBoolToBoolean,
    unix_JsBooleanToBool,
    unix_JsCallFunction,
    unix_JsGetAndClearException,
    unix_JsGetProperty,
    unix_JsConvertValueToBoolean,
    unix_JsConvertValueToNumber,
    unix_JsConvertValueToString,
    unix_JsCreateError,
    unix_JsGetIndexedProperty,
    unix_JsGetNullValue,
    unix_JsGetOwnPropertyNames,
    unix_JsGetUndefinedValue,
    unix_JsGetValueType,
    unix_JsHasIndexedProperty,
    unix_JsHasProperty,
    unix_JsSetException,
    unix_JsStringToPointer
};