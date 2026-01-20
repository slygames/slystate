extends CharacterBody2D
class_name DemoPlayer

@onready var example_state_machine: DemoStateMachine = $ExampleStateMachine

func _unhandled_input(event: InputEvent):
	var direction : Vector2 = Input.get_vector("ui_down", "ui_up", "ui_right", "ui_left");
	if direction.length() > 1:
		direction.normalized()

	#if Input.is_action_just_pressed("ui_left"):
		#print("LEFT")
	#elif Input.is_action_just_pressed("ui_right"):
		#print("RIGHT")
	#elif Input.is_action_just_pressed("ui_up"):
		#print("UP")
	#elif Input.is_action_just_pressed("ui_down"):
		#print("DOWN")
