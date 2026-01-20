#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>

using namespace godot;

class State : public Node {
	GDCLASS(State, Node)

protected:
	static void _bind_methods();

public:
	State() = default;
    ~State() override = default;

    #if 0
    //State::State(const State& other) {}
    // event handlers (these are not Node event handler overrides but StateMachine extends Node and calls these for its active state and they're exposed as virtual functions in gdscript)
    #endif
    
    // event handlers
    virtual void _ready() override;
	virtual void _process(double p_delta) override;
	virtual void _physics_process(double p_delta) override;
	virtual void _unhandled_input(const Ref<InputEvent> &p_event) override;

    // event handlers which get triggered when the state is enabled or disabled
    virtual void _on_enter_state();
    virtual void _on_exit_state();
};
