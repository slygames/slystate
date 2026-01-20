extends CharacterBody2D
class_name DemoPlayer

@onready var demo_state_machine: DemoStateMachine = $DemoStateMachine

var direction : Vector2

func _unhandled_input(event: InputEvent):

	# get direction from Inputs
	direction = Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")
	 
	# Check if moving diagonally (length > 1) and normalize to limit speed (otherwise diagonal movement is faster than horizontal)
	if direction.length() > 1:
		direction = direction.normalized() # Makes vector length 1, capping speed


	#if Input.is_action_just_pressed("ui_left"):
		#print("LEFT")
	#elif Input.is_action_just_pressed("ui_right"):
		#print("RIGHT")
	#elif Input.is_action_just_pressed("ui_up"):
		#print("UP")
	#elif Input.is_action_just_pressed("ui_down"):
		#print("DOWN")
