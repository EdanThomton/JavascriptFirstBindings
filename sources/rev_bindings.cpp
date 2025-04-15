#include <node.h>
#include <node_object_wrap.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

using namespace v8;

#define OBJECT_SET(object, name, value) object->Set(context, String::NewFromUtf8(isolate, name).ToLocalChecked(), value)
#define ARRAY_SET(array, index, value) array->Set(context, index, value)

void throw_type_err(Isolate* isolate, const char* err) {
    isolate->ThrowException(
        Exception::TypeError(
            String::NewFromUtf8(isolate, err).ToLocalChecked()
        )
    );
}
void throw_range_err(Isolate* isolate, const char* err) {
    isolate->ThrowException(
        Exception::RangeError(
            String::NewFromUtf8(isolate, err).ToLocalChecked()
        )
    );
}
class _binding_SparkBase : public node::ObjectWrap {

    protected:
        rev::spark::SparkBase* spark_base_ptr = NULL;

    public:
        rev::spark::SparkBase* get_spark_base() {
            return spark_base_ptr;
        };

};
class _binding_SparkBaseConfig : public node::ObjectWrap {
    private:
        rev::spark::SparkBaseConfig* config;

        explicit _binding_SparkBaseConfig(rev::spark::SparkBaseConfig* config) {
            this->config = config;
        }
        ~_binding_SparkBaseConfig() {
            delete config;
        }

        static void New(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() > 0) {
                throw_type_err(isolate, "SparkBaseConfig does not take arguments!");
            }

            rev::spark::SparkBaseConfig* config = new rev::spark::SparkBaseConfig();
            _binding_SparkBaseConfig* obj = new _binding_SparkBaseConfig(config);
            obj->Wrap(args.This());

            args.GetReturnValue().Set(args.This());
        }

        static void set_idle_mode(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkBaseConfig::set_idle_mode requires one argument!");
            }
            if(!args[0]->IsBoolean()) {
                throw_type_err(isolate, "SparkBaseConfig::set_idle_mode requires the first argument to be a boolean!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            bool arg0 = args[0].As<Boolean>()->Value();

            if(arg0) {
                config = &config->SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake);
            } else {
                config = &config->SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kCoast);
            }

            args.GetReturnValue().Set(args.This());
        }
        static void inverted(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkBaseConfig::inverted requires one argument!");
            }
            if(!args[0]->IsBoolean()) {
                throw_type_err(isolate, "SparkBaseConfig::inverted requires the first argument to be a boolean!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            bool arg0 = args[0].As<Boolean>()->Value();

            config = &config->Inverted(arg0);

            args.GetReturnValue().Set(args.This());
        }
        static void smart_current_limit(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() < 1) {
                throw_type_err(isolate, "SparkBaseConfig::smart_current_limit requires at least one argument!");
            }
            if(!args[0]->IsInt32()) {
                throw_type_err(isolate, "SparkBaseConfig::smart_current_limit requires the first argument to be an Int32!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            int32_t arg0 = args[0].As<Int32>()->Value();
            int32_t arg1 = args[1]->IsInt32() ? args[1].As<Int32>()->Value() : 0;
            int32_t arg2 = args[2]->IsInt32() ? args[2].As<Int32>()->Value() : 20000;

            config = &config->SmartCurrentLimit(arg0, arg1, arg2);

            args.GetReturnValue().Set(args.This());
        }
        static void secondary_current_limit(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() < 1) {
                throw_type_err(isolate, "SparkBaseConfig::secondary_current_limit requires at least one argument!");
            }
            if(!args[0]->IsNumber()) {
                throw_type_err(isolate, "SparkBaseConfig::secondary_current_limit requires the first argument to be a Number!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            double arg0 = args[0].As<Number>()->Value();
            int32_t arg1 = args[1]->IsInt32() ? args[1].As<Int32>()->Value() : 0;

            config = &config->SecondaryCurrentLimit(arg0, arg1);

            args.GetReturnValue().Set(args.This());
        }
        static void open_loop_ramp_rate(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkBaseConfig::open_loop_ramp_rate requires one argument!");
            }
            if(!args[0]->IsNumber()) {
                throw_type_err(isolate, "SparkBaseConfig::open_loop_ramp_rate requires the first argument to be a Number!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            double arg0 = args[0].As<Number>()->Value();

            config = &config->OpenLoopRampRate(arg0);

            args.GetReturnValue().Set(args.This());
        }
        static void closed_loop_ramp_rate(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkBaseConfig::closed_loo_ramp_rate requires one argument!");
            }
            if(!args[0]->IsNumber()) {
                throw_type_err(isolate, "SparkBaseConfig::closed_loo_ramp_rate requires the first argument to be a Number!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            double arg0 = args[0].As<Number>()->Value();

            config = &config->ClosedLoopRampRate(arg0);

            args.GetReturnValue().Set(args.This());
        }
        static void voltage_compensation(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkBaseConfig::voltage_compensation requires one argument!");
            }
            if(!args[0]->IsNumber()) {
                throw_type_err(isolate, "SparkBaseConfig::voltage_compensation requires the first argument to be a Number!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;
            double arg0 = args[0].As<Number>()->Value();

            config = &config->VoltageCompensation(arg0);

            args.GetReturnValue().Set(args.This());
        }
        static void disable_voltage_compensation(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 0) {
                throw_type_err(isolate, "SparkBaseConfig::disable_voltage_compensation does not take arguments!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;

            config = &config->DisableVoltageCompensation();

            args.GetReturnValue().Set(args.This());
        }
        static void follow(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() < 1) {
                throw_type_err(isolate, "SparkBaseConfig::follow requires at least one argument!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;

            bool arg1 = args[1]->IsBoolean() ? args[1].As<Boolean>()->Value() : false;
            if(!args[0]->IsInt32()) {
                int arg0 = args[0].As<Int32>()->Value();

                config = &config->Follow(arg0, arg1);
            } else {
                // wtf is this cursed piece of code
                // rev why'd you make me do this :(
                _binding_SparkBase* obj = node::ObjectWrap::Unwrap<_binding_SparkBase>(
                    args[0]->ToObject(context).ToLocalChecked()
                );
                rev::spark::SparkBase* arg0 = obj->get_spark_base();

                config = &config->Follow(*arg0, arg1);
            }

            args.GetReturnValue().Set(args.This());
        }
        static void disable_follower_mode(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 0) {
                throw_type_err(isolate, "SparkBaseConfig::disable_follower_mode does not take arguments!");
            }

            _binding_SparkBaseConfig* this_obj = ObjectWrap::Unwrap<_binding_SparkBaseConfig>(args.This());
            rev::spark::SparkBaseConfig* config = this_obj->config;

            config = &config->DisableFollowerMode();

            args.GetReturnValue().Set(args.This());
        }

    public:
        static void Init(Local<Object> exports) {
            Isolate* isolate = exports->GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            Local<ObjectTemplate> addon_data_tpl = ObjectTemplate::New(isolate);
            addon_data_tpl->SetInternalFieldCount(1);
            Local<Object> addon_data = addon_data_tpl->NewInstance(context).ToLocalChecked();

            Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New, addon_data);
            tpl->SetClassName(String::NewFromUtf8(isolate, "SparkConfig").ToLocalChecked());
            tpl->InstanceTemplate()->SetInternalFieldCount(10);

            NODE_SET_PROTOTYPE_METHOD(tpl, "set_idle_mode", set_idle_mode);
            NODE_SET_PROTOTYPE_METHOD(tpl, "inverted", inverted);
            NODE_SET_PROTOTYPE_METHOD(tpl, "smart_current_limit", smart_current_limit);
            NODE_SET_PROTOTYPE_METHOD(tpl, "secondary_current_limit", secondary_current_limit);
            NODE_SET_PROTOTYPE_METHOD(tpl, "open_loop_ramp_rate", open_loop_ramp_rate);
            NODE_SET_PROTOTYPE_METHOD(tpl, "closed_loop_ramp_rate", closed_loop_ramp_rate);
            NODE_SET_PROTOTYPE_METHOD(tpl, "voltage_compensation", voltage_compensation);
            NODE_SET_PROTOTYPE_METHOD(tpl, "disable_voltage_compensation", disable_voltage_compensation);
            NODE_SET_PROTOTYPE_METHOD(tpl, "follow", follow);
            NODE_SET_PROTOTYPE_METHOD(tpl, "disable_follower_mode", disable_follower_mode);
        }

        rev::spark::SparkBaseConfig* get_config() {
            return config;
        }
};
class _binding_SparkMax : public _binding_SparkBase {

    private:
        rev::spark::SparkMax* spark_max;

        explicit _binding_SparkMax(rev::spark::SparkMax* spark_max) {
            this->spark_max = spark_max;
            this->spark_base_ptr = spark_max;
        }
        ~_binding_SparkMax() {
            delete spark_max;
        };

        static void New(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();
            
            if(args.IsConstructCall()) {

                if(args.Length() != 2) {
                    throw_type_err(isolate, "SparkMax requires two arguments!");
                }
                if(!args[0]->IsInt32()) {
                    throw_type_err(isolate, "SparkMax requires the first argument to be an Int32!");
                }
                if(!args[1]->IsBoolean()) {
                    throw_type_err(isolate, "SparkMax requires the second argument to be a boolean!");
                }
                int32_t arg0 = args[0].As<Int32>()->Value();
                bool arg1 = args[1].As<Boolean>()->Value();

                rev::spark::SparkLowLevel::MotorType m_type;
                if(arg1) { m_type = rev::spark::SparkLowLevel::MotorType::kBrushed;   }
                else     { m_type = rev::spark::SparkLowLevel::MotorType::kBrushless; }

                rev::spark::SparkMax* spark_max = new rev::spark::SparkMax(arg0, m_type);
                _binding_SparkMax* obj = new _binding_SparkMax(spark_max);
                obj->Wrap(args.This());

                args.GetReturnValue().Set(args.This());
            } else {
                throw_type_err(isolate, "Class constructor SparkMax cannot be invoked with 'new'");
            }
        }

        static void configure(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 3) {
                throw_type_err(isolate, "SparkMax::configure requires three arguments!");
            }
            if(!args[1]->IsBoolean()) {
                throw_type_err(isolate, "SparkMax::configure requires the second argument to be a boolean!");
            }
            if(!args[1]->IsBoolean()) {
                throw_type_err(isolate, "SparkMax::configure requires the third argument to be a boolean!");
            }

            _binding_SparkMax* this_obj = ObjectWrap::Unwrap<_binding_SparkMax>(args.This());
            rev::spark::SparkMax* spark_max = this_obj->spark_max;

            // get config
            _binding_SparkBaseConfig* arg0 = 
                node::ObjectWrap::Unwrap<_binding_SparkBaseConfig>(
                    args[0]->ToObject(context).ToLocalChecked()
                );
            rev::spark::SparkBaseConfig* cfg = arg0->get_config();

            bool arg1 = args[1].As<Boolean>()->Value();
            bool arg2 = args[2].As<Boolean>()->Value();

            rev::spark::SparkBase::ResetMode reset_mode;
            if(arg1) {
                reset_mode = rev::spark::SparkBase::ResetMode::kNoResetSafeParameters;
            } else {
                reset_mode = rev::spark::SparkBase::ResetMode::kResetSafeParameters;
            }

            rev::spark::SparkBase::PersistMode persist_mode;
            if(arg2) {
                persist_mode = rev::spark::SparkBase::PersistMode::kNoPersistParameters;
            } else {
                persist_mode = rev::spark::SparkBase::PersistMode::kPersistParameters;
            }

            spark_max->Configure(*cfg, reset_mode, persist_mode);
        }

        // TODOs
        static void get_alternate_encoder(const FunctionCallbackInfo<Value>& args) {}
        static void get_absolute_encoder(const FunctionCallbackInfo<Value>& args) {}
        static void get_forward_limit_switch(const FunctionCallbackInfo<Value>& args) {}
        static void get_reverse_limit_switch(const FunctionCallbackInfo<Value>& args) {}

        static void set(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkMax::set requires one argument!");
            }
            if(!args[0]->IsNumber()) {
                throw_type_err(isolate, "SparkMax::set requires the first argument to be a number!");
            }

            _binding_SparkMax* this_obj = ObjectWrap::Unwrap<_binding_SparkMax>(args.This());
            rev::spark::SparkMax* spark_max = this_obj->spark_max;

            double arg0 = args[0].As<Number>()->Value();

            spark_max->Set(arg0);
        }
        static void set_voltage(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 1) {
                throw_type_err(isolate, "SparkMax::set_voltage requires one argument!");
            }
            if(!args[0]->IsNumber()) {
                throw_type_err(isolate, "SparkMax::set_voltage requires the first argument to be a number!");
            }

            _binding_SparkMax* this_obj = ObjectWrap::Unwrap<_binding_SparkMax>(args.This());
            rev::spark::SparkMax* spark_max = this_obj->spark_max;

            units::volt_t arg0 = units::volt_t(args[0].As<Number>()->Value());

            spark_max->SetVoltage(arg0);
        }
        static void get(const FunctionCallbackInfo<Value>& args) {
            Isolate* isolate = args.GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            if(args.Length() != 0) {
                throw_type_err(isolate, "SparkMax::get does not take arguments!");
            }

            _binding_SparkMax* this_obj = ObjectWrap::Unwrap<_binding_SparkMax>(args.This());
            rev::spark::SparkMax* spark_max = this_obj->spark_max;

            double val = spark_max->Get();
            Local<Number> result = Number::New(isolate, val);

            args.GetReturnValue().Set(result);
        }
        static void set_inverted(const FunctionCallbackInfo<Value>& args) {}
        static void get_inverted(const FunctionCallbackInfo<Value>& args) {}
        static void disable(const FunctionCallbackInfo<Value>& args) {}
        static void stop_motor(const FunctionCallbackInfo<Value>& args) {}
        // TODO: maybe configure_async
        static void get_encoder(const FunctionCallbackInfo<Value>& args) {}
        static void get_analog(const FunctionCallbackInfo<Value>& args) {}
        static void get_closed_loop_controller(const FunctionCallbackInfo<Value>& args) {}
        static void resume_follower_mode(const FunctionCallbackInfo<Value>& args) {}
        static void resume_follower_mode_async(const FunctionCallbackInfo<Value>& args) {}
        static void pause_follower_mode(const FunctionCallbackInfo<Value>& args) {}
        static void pause_follower_mode_async(const FunctionCallbackInfo<Value>& args) {}
        static void is_follower(const FunctionCallbackInfo<Value>& args) {}
        static void has_active_fault(const FunctionCallbackInfo<Value>& args) {}
        static void has_sticky_fault(const FunctionCallbackInfo<Value>& args) {}
        static void has_active_warning(const FunctionCallbackInfo<Value>& args) {}
        static void has_sticky_warning(const FunctionCallbackInfo<Value>& args) {}
        static void get_faults(const FunctionCallbackInfo<Value>& args) {}
        static void get_sticky_faults(const FunctionCallbackInfo<Value>& args) {}
        static void get_warnings(const FunctionCallbackInfo<Value>& args) {}
        static void get_sticky_warnings(const FunctionCallbackInfo<Value>& args) {}
        static void get_bus_voltage(const FunctionCallbackInfo<Value>& args) {}
        static void get_applied_output(const FunctionCallbackInfo<Value>& args) {}
        static void get_output_current(const FunctionCallbackInfo<Value>& args) {}
        static void get_motor_temperature(const FunctionCallbackInfo<Value>& args) {}
        static void clear_faults(const FunctionCallbackInfo<Value>& args) {}
        

    public:
        static void Init(Local<Object> exports) {

            Isolate* isolate = exports->GetIsolate();
            Local<Context> context = isolate->GetCurrentContext();

            Local<ObjectTemplate> addon_data_tpl = ObjectTemplate::New(isolate);
            addon_data_tpl->SetInternalFieldCount(1);
            Local<Object> addon_data = addon_data_tpl->NewInstance(context).ToLocalChecked();

            Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New, addon_data);
            tpl->SetClassName(String::NewFromUtf8(isolate, "SparkMax").ToLocalChecked());
            tpl->InstanceTemplate()->SetInternalFieldCount(10);

            NODE_SET_PROTOTYPE_METHOD(tpl, "configure", configure);
            NODE_SET_PROTOTYPE_METHOD(tpl, "set", set);
            NODE_SET_PROTOTYPE_METHOD(tpl, "set_voltage", set_voltage);
            NODE_SET_PROTOTYPE_METHOD(tpl, "get", get);

        }

};