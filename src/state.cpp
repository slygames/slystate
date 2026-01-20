#include "state.h"
#include "util.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>


void State::_bind_methods() {

    ClassDB::bind_method(D_METHOD("on_enter_state"), &State::on_enter_state);
    ClassDB::bind_method(D_METHOD("on_exit_state"), &State::on_exit_state);
	GDVIRTUAL_BIND(_on_enter_state);
    GDVIRTUAL_BIND(_on_exit_state);

    ClassDB::bind_method(D_METHOD("set_state_name", "p_state_name"), &State::set_state_name);
	ClassDB::bind_method(D_METHOD("get_state_name"), &State::get_state_name);
    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "state_name"), "set_state_name", "get_state_name");
}

void State::_notification(int p_what) {
    switch(p_what) {
        case NOTIFICATION_READY:
            set_process_mode(PROCESS_MODE_DISABLED);
            break;
     case NOTIFICATION_PROCESS:
            break;
     case NOTIFICATION_PHYSICS_PROCESS:
            break;
    }
}

/*
void State::_ready() {
    
}

void State::_process(double p_delta) {
}

void State::_physics_process(double p_delta) {
}
*/
void State::_unhandled_input(const Ref<InputEvent> &p_event) {
}

void State::on_enter_state() {
    set_process_mode(ProcessMode::PROCESS_MODE_INHERIT);
    if(GDVIRTUAL_CALL(_on_enter_state)) {
		print("_on_enter_state gdvirtual called");
	}

}

void State::on_exit_state() {
    set_process_mode(ProcessMode::PROCESS_MODE_PAUSABLE);
    if(GDVIRTUAL_CALL(_on_enter_state)) {
		print("_on_exit_state gdvirtual called");
	}
}
