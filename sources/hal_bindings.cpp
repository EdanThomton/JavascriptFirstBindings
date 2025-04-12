#include <node.h>
#include <hal/HAL.h>

using namespace v8;

#define OBJECT_SET(object, name, value) object->Set(context, String::NewFromUtf8(isolate, name).ToLocalChecked(), value)
#define ARRAY_SET(array, index, value) array->Set(context, index, value)

/* BINDINGS FOR DriverStation.h */
void _binding_HAL_GetControlWord(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetControlWord does not take arguments!").ToLocalChecked()
            )
        );
    }

    HAL_ControlWord word;
    HAL_GetControlWord(&word);

    Local<Object> result = Object::New(isolate);
    OBJECT_SET(result, "enabled", Boolean::New(isolate, word.enabled));
    OBJECT_SET(result, "autonomous", Boolean::New(isolate, word.autonomous));
    OBJECT_SET(result, "test", Boolean::New(isolate, word.test));
    OBJECT_SET(result, "eStop", Boolean::New(isolate, word.eStop));
    OBJECT_SET(result, "fmsAttached", Boolean::New(isolate, word.fmsAttached));
    OBJECT_SET(result, "dsAttached", Boolean::New(isolate, word.dsAttached));
    OBJECT_SET(result, "control_reserved", Int32::New(isolate, word.control_reserved));
    args.GetReturnValue().Set(result);
}
void _binding_HAL_GetJoystickAxes(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    if(args.Length() != 1) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetJoystickAxes requires one argument!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetJoystickAxes requires the first argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();

    HAL_JoystickAxes axes;
    HAL_GetJoystickAxes(arg0, &axes);

    Local<Array> result_axes = Array::New(isolate, HAL_kMaxJoystickAxes);
    Local<Array> result_raw  = Array::New(isolate, HAL_kMaxJoystickAxes);

    for(int i = 0; i < HAL_kMaxJoystickAxes; i++) {
        ARRAY_SET(result_axes, i, Number::New(isolate, axes.axes[i]));
        ARRAY_SET(result_raw, i, Integer::New(isolate, axes.raw[i]));
    }

    Local<Object> result = Object::New(isolate);
    OBJECT_SET(result, "count", Integer::New(isolate, axes.count));
    OBJECT_SET(result, "axes", result_axes);
    OBJECT_SET(result, "raw", result_raw);

    args.GetReturnValue().Set(result);
}
void _binding_HAL_GetJoystickPOVs(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    if(args.Length() != 1) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetJoystickPOVs requires one argument!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetJoystickPOVs requires the first argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();

    HAL_JoystickPOVs povs;
    HAL_GetJoystickPOVs(arg0, &povs);

    Local<Array> result_povs = Array::New(isolate, HAL_kMaxJoystickAxes);

    for(int i = 0; i < HAL_kMaxJoystickAxes; i++) {
        ARRAY_SET(result_povs, i, Integer::New(isolate, povs.povs[i]));
    }

    Local<Object> result = Object::New(isolate);
    OBJECT_SET(result, "count", Integer::New(isolate, povs.count));
    OBJECT_SET(result, "povs", result_povs);

    args.GetReturnValue().Set(result);
}
void _binding_HAL_GetJoystickButtons(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    if(args.Length() != 1) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetJoystickButtons requires one argument!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_GetJoystickButtons requires the first argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();

    HAL_JoystickButtons buttons;
    HAL_GetJoystickButtons(arg0, &buttons);

    Local<Object> result = Object::New(isolate);
    OBJECT_SET(result, "count", Integer::New(isolate, buttons.count));
    OBJECT_SET(result, "buttons", Integer::New(isolate, buttons.buttons));

    args.GetReturnValue().Set(result);
}
void _binding_HAL_RefreshDSData(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_RefreshDSData does not take arguments!").ToLocalChecked()
            )
        );
    }

    int32_t updated = HAL_RefreshDSData();

    Local<Boolean> result = Boolean::New(isolate, updated != 0);
    args.GetReturnValue().Set(result);
}
void _binding_HAL_ProvideNewDataEventHandle(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if(args.Length() != 1) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ProvideNewDataEventHandle requires one argument!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ProvideNewDataEventHandle requires the argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();

    HAL_ProvideNewDataEventHandle(arg0);
}
void _binding_HAL_RemoveNewDataEventHandle(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if(args.Length() != 1) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_RemoveNewDataEventHandle requires one argument!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_RemoveNewDataEventHandle requires the argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();

    HAL_RemoveNewDataEventHandle(arg0);
}
void _binding_HAL_ObserveUserProgramStarting(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ObserveUserProgramStarting does not take arguments!").ToLocalChecked()
            )
        );
    }
    HAL_ObserveUserProgramStarting();
}
void _binding_HAL_ObserveUserProgramDisabled(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ObserveUserProgramDisabled does not take arguments!").ToLocalChecked()
            )
        );
    }
    HAL_ObserveUserProgramDisabled();
}
void _binding_HAL_ObserveUserProgramAutonomous(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ObserveUserProgramAutonomous does not take arguments!").ToLocalChecked()
            )
        );
    }
    HAL_ObserveUserProgramAutonomous();
}
void _binding_HAL_ObserveUserProgramTeleop(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ObserveUserProgramTeleop does not take arguments!").ToLocalChecked()
            )
        );
    }
    HAL_ObserveUserProgramTeleop();
}
void _binding_HAL_ObserveUserProgramTest(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() != 0) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_ObserveUserProgramTest does not take arguments!").ToLocalChecked()
            )
        );
    }
    HAL_ObserveUserProgramTest();
}
/* END OF DriverStation.h */

/**
 * Node.JS binding for the HAL_Initialze function
 *
 * @author Edan Thomton
 * @date 4/8/2025
 */
void _binding_HAL_Initialize(const FunctionCallbackInfo<Value>& args) {
    // v8 isolate
    Isolate* isolate = args.GetIsolate();

    // check that there are exactly two arguments, if not throw a TypeError
    if(args.Length() != 2) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_Initialize requires two arguments!").ToLocalChecked()
            )
        );
    }
    // check that the first argument is an Int32, if not throw a TypeError
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_Initialize requires the first argument to be an Int32!").ToLocalChecked()
            )
        );
    }
    // check that the second argument is an Int32, if not throw a TypeError
    if(!args[1]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "HAL_Initialize requires the second argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    // get argument values as integers
    int32_t arg0 = args[0].As<Int32>()->Value();
    int32_t arg1 = args[1].As<Int32>()->Value();

    // run HAL_Initialze
    int32_t hal_result = HAL_Initialize(arg0, arg1);

    // store result as a boolean, TRUE if success, FALSE if failure
    Local<Boolean> result = Boolean::New(isolate, hal_result != 0);

    // return result
    args.GetReturnValue().Set(result);
}
void _binding_WPI_CreateEvent(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // check that there are exactly two arguments, if not throw a TypeError
    if(args.Length() != 2) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_CreateEvent requires two arguments!").ToLocalChecked()
            )
        );
    }
    // check that the first argument is an Int32, if not throw a TypeError
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_CreateEvent requires the first argument to be an Int32!").ToLocalChecked()
            )
        );
    }
    // check that the second argument is an Int32, if not throw a TypeError
    if(!args[1]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_CreateEvent requires the second argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();
    int32_t arg1 = args[1].As<Int32>()->Value();

    int32_t handle = WPI_CreateEvent(arg0, arg1);

    Local<Integer> result = Integer::New(isolate, handle);
    args.GetReturnValue().Set(result);
}
void _binding_WPI_DestroyEvent(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if(args.Length() != 1) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_DestroyEvent requires one argument!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_DestroyEvent requires the first argument to be an Int32!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();

    WPI_DestroyEvent(arg0);
}
void _binding_WPI_WaitForObjectTimeout(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    if(args.Length() != 2) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_WaitForObjectTimeout requires two arguments!").ToLocalChecked()
            )
        );
    }
    if(!args[0]->IsInt32()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_WaitForObjectTimeout requires the first argument to be a Int32!").ToLocalChecked()
            )
        );
    }
    if(!args[1]->IsNumber()) {
        isolate->ThrowException(
            Exception::TypeError(
                String::NewFromUtf8(isolate, "WPI_WaitForObjectTimeout requires the second argument to be a number!").ToLocalChecked()
            )
        );
    }

    int32_t arg0 = args[0].As<Int32>()->Value();
    double arg1 = args[1].As<Number>()->Value();

    int32_t timed_out = 0;
    int32_t signaled = WPI_WaitForObjectTimeout(arg0, arg1, &timed_out);

    Local<Object> result = Object::New(isolate);
    OBJECT_SET(result, "signaled", Boolean::New(isolate, signaled != 0));
    OBJECT_SET(result, "timed_out", Boolean::New(isolate, timed_out != 0));
    args.GetReturnValue().Set(result);
}

/**
 * Initialize bindings
 */
void Initialize(Local<Object> exports) {
    /* EXPORTS::DriverStation.h */
    NODE_SET_METHOD(exports, "HAL_GetControlWord", _binding_HAL_GetControlWord);
    NODE_SET_METHOD(exports, "HAL_GetJoystickAxes", _binding_HAL_GetJoystickAxes);
    NODE_SET_METHOD(exports, "HAL_GetJoystickPOVs", _binding_HAL_GetJoystickPOVs);
    NODE_SET_METHOD(exports, "HAL_GetJoystickButtons", _binding_HAL_GetJoystickButtons);
    NODE_SET_METHOD(exports, "HAL_RefreshDSData", _binding_HAL_RefreshDSData);
    NODE_SET_METHOD(exports, "HAL_ProvideNewDataEventHandle", _binding_HAL_ProvideNewDataEventHandle);
    NODE_SET_METHOD(exports, "HAL_RemoveNewDataEventHandle", _binding_HAL_RemoveNewDataEventHandle);
    NODE_SET_METHOD(exports, "HAL_ObserveUserProgramStarting", _binding_HAL_ObserveUserProgramStarting);
    NODE_SET_METHOD(exports, "HAL_ObserveUserProgramDisabled", _binding_HAL_ObserveUserProgramDisabled);
    NODE_SET_METHOD(exports, "HAL_ObserveUserProgramAutonomous", _binding_HAL_ObserveUserProgramAutonomous);
    NODE_SET_METHOD(exports, "HAL_ObserveUserProgramTeleop", _binding_HAL_ObserveUserProgramTeleop);
    NODE_SET_METHOD(exports, "HAL_ObserveUserProgramTest", _binding_HAL_ObserveUserProgramTest);

    /* EXPORTS::HALBase.h */
    NODE_SET_METHOD(exports, "HAL_Initialize", _binding_HAL_Initialize);

    /* EXPORTS::WPIutils */
    NODE_SET_METHOD(exports, "WPI_CreateEvent", _binding_WPI_CreateEvent);
    NODE_SET_METHOD(exports, "WPI_DestroyEvent", _binding_WPI_DestroyEvent);
    NODE_SET_METHOD(exports, "WPI_WaitForObjectTimeout", _binding_WPI_WaitForObjectTimeout);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)