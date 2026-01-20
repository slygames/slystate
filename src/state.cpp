#include "state.h"
#include "util.h"

void State::_bind_methods() {

    ClassDB::bind_method(D_METHOD("on_enter_state"), &State::on_enter_state);
    ClassDB::bind_method(D_METHOD("on_exit_state"), &State::on_exit_state);
	GDVIRTUAL_BIND(_on_enter_state);
    GDVIRTUAL_BIND(_on_exit_state);

}

void State::_ready() {
    set_process_mode(PROCESS_MODE_DISABLED);
}

void State::_process(double p_delta) {
}

void State::_physics_process(double p_delta) {
}

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
