extends CharacterBody2D
class_name DemoPlayer

@onready var demo_state_machine: DemoStateMachine = $DemoStateMachine
@onready var demo_animation_player: AnimationPlayer = $AnimationPlayer

enum Facing {
	UP,
	DOWN,
	LEFT,
	RIGHT,
}

var facing : Facing = Facing.DOWN

var direction : Vector2

func _unhandled_input(event: InputEvent):
	# get direction from Inputs
	direction = Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")
	 
	# Check if moving diagonally (length > 1) and normalize to limit speed (otherwise diagonal movement is faster than horizontal)
	if direction.length() > 1:
		direction = direction.normalized() # Makes vector length 1, capping speed
		
	if abs(direction.y) > abs(direction.x):
		facing = Facing.UP if direction.y > 0 else Facing.DOWN
	else:
		facing = Facing.LEFT if direction.x > 0 else Facing.RIGHT

	print("Facing ", Facing.keys()[facing])

func update_animation(anim_name : StringName):

	demo_animation_player.play(anim_name)
