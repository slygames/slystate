#include "state_machine.h"

void StateMachine::_bind_methods() {

#if 0
    // setters and getters
    ClassDB::bind_method(D_METHOD("set_states", "p_states"), &StateMachine::set_states);
	ClassDB::bind_method(D_METHOD("get_states"), &StateMachine::get_states);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "states", PROPERTY_HINT_ARRAY_TYPE, "NodePath"), "set_states", "get_states");
    //ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "states", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":State"), "set_states", "get_states" );
#endif

    ClassDB::bind_method(D_METHOD("set_state", "p_state"), &StateMachine::set_state);
	ClassDB::bind_method(D_METHOD("get_state"), &StateMachine::get_state);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "state", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":State"), "set_state", "get_state");
}

void StateMachine::_ready() {
    set_process_mode(PROCESS_MODE_PAUSABLE);
}

void StateMachine::_initialize() {
    
}

