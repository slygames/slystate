#include "state.h"

void State::_bind_methods() {
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

void State::_on_enter_state() {
    set_process_mode(ProcessMode::PROCESS_MODE_INHERIT);
}

void State::_on_exit_state() {
    set_process_mode(ProcessMode::PROCESS_MODE_PAUSABLE);
}
