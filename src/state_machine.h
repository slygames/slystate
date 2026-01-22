#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/typed_dictionary.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include "state.h"

using namespace godot;

class StateMachine : public Node {
	GDCLASS(StateMachine, Node)

	State* state = nullptr;	// currently active state
	State* state_prev = nullptr; // cached previous state //todo: maybe useful or remove if not useful

	TypedDictionary<StringName, NodePath> states;

protected:
	static void _bind_methods();
	void _notification(int p_what);

public:
	StateMachine() = default;
	~StateMachine() override = default;

	virtual void _initialize();

	// setters and getters
	State* get_state() const { return state; }
	void set_state(State* p_state);


	/*
	// event handlers
    //virtual void _ready() override;
	virtual void _process(double p_delta) override;
	virtual void _physics_process(double p_delta) override;
	virtual void _unhandled_input(const Ref<InputEvent> &p_event) override;

	TypedArray<NodePath> get_states() const { return states; }
	void set_states(TypedArray<NodePath> p_states) { states = p_states; }
	*/
};


