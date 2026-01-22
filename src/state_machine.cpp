#include "state_machine.h"
#include "util.h"


void StateMachine::_bind_methods() {

    ClassDB::bind_method(D_METHOD("set_state", "p_state"), &StateMachine::set_state);
	ClassDB::bind_method(D_METHOD("get_state"), &StateMachine::get_state);

    ClassDB::bind_method(D_METHOD("get_state_name"), &StateMachine::get_state_name);

    /*
    // setters and getters
    ClassDB::bind_method(D_METHOD("set_states", "p_states"), &StateMachine::set_states);
	ClassDB::bind_method(D_METHOD("get_states"), &StateMachine::get_states);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "states", PROPERTY_HINT_ARRAY_TYPE, "NodePath"), "set_states", "get_states");
    //ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "states", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":State"), "set_states", "get_states" );

    //ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "state", PROPERTY_HINT_NODE_TYPE, "State"), "set_state", "get_state");
    //ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "state", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_NODE_TYPE) + ":State"), "set_state", "get_state");
    */

}

void StateMachine::_notification(int p_what) {
	switch(p_what) {
		case NOTIFICATION_READY:
        case NOTIFICATION_CHILD_ORDER_CHANGED:
            set_process_mode(PROCESS_MODE_PAUSABLE);
            //print("state machine _ready");
            _initialize();
            break;
    }
}

void StateMachine::_initialize() {
    // get states from statemachine child nodes (the array will be populated in the scene tree order, so the top state is the default states[0])
    for(int i=0; i<get_children().size();i++) {
        if(State* new_state = cast_to<State>(get_children()[i])) {
            if(new_state->is_inside_tree()) {
                states[new_state->get_name()] = new_state->get_path(); // if(new_state->is_inside_tree()) else NodePath()
                // set default state to first state
                if(i==0) {
                    set_state(new_state);
                }
                //print("Registered state ", new_state->get_name(), " : ", states[new_state->get_name()] );
            }
        }
    }
}

/* Use this instead of state= because it  triggers the state exit and enter events*/
void StateMachine::set_state(State *p_state) {
    state_prev = state;
    state = p_state; 
    if(state_prev !=nullptr) state_prev->on_exit_state();
    if(state!=nullptr) state->on_enter_state();
}
