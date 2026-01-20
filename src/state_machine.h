#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include "state.h"

using namespace godot;

class StateMachine : public Node {
	GDCLASS(StateMachine, Node)

	#if 0
	TypedArray<NodePath> states;	// all states
	#endif

	State* state;	// currently active state
	State* state_prev; // cached previous state //todo: maybe useful or remove if not useful

protected:
	static void _bind_methods();

public:
	StateMachine() = default;
	~StateMachine() override = default;

	virtual void _initialize();

	// event handlers
    virtual void _ready() override;
	/*
	virtual void _process(double p_delta) override;
	virtual void _physics_process(double p_delta) override;
	virtual void _unhandled_input(const Ref<InputEvent> &p_event) override;
	*/

	State* get_state() const { return state; }
	void set_state(State* p_state) { 
		state_prev = state;
		state = p_state; 
		if(state_prev!=nullptr) state_prev->_on_exit_state();
		if(state!=nullptr) state->_on_enter_state();
	}
#if 0
	TypedArray<NodePath> get_states() const { return states; }
	void set_states(TypedArray<NodePath> p_states) { states = p_states; }
#endif
};
