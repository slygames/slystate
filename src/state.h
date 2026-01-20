#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class State : public Node {
	GDCLASS(State, Node)

protected:
	static void _bind_methods();

public:
	State() = default;
    ~State() override = default;

    /*
    void operator=(const State& other) {
        if (this != &other) {
            set_state(other);
        }
        //return *this;
    }*/

     #if 0
    //State::State(const State& other) {}
    // event handlers (these are not Node event handler overrides but StateMachine extends Node and calls these for its active state and they're exposed as virtual functions in gdscript)
    #endif
    
    // todo: overload = operator so assigning to state variable in state_machine class calls the set_state() function from the overloaded = operator

    // event handlers
    virtual void _ready() override;
	virtual void _process(double p_delta) override;
	virtual void _physics_process(double p_delta) override;
	virtual void _unhandled_input(const Ref<InputEvent> &p_event) override;

    // event handlers which get triggered when the state is enabled or disabled
    virtual void on_enter_state();
    virtual void on_exit_state();

    GDVIRTUAL0(_on_enter_state);
    GDVIRTUAL0(_on_exit_state);
};
