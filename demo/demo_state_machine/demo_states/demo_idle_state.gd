extends State
class_name DemoIdleState

@onready var animation_player: AnimationPlayer = $"../../AnimationPlayer"

func _ready():
	pass
	
func _process(_delta : float):
	pass

func _physics_process(_delta : float):
	pass
	
func _unhandled_input(event: InputEvent):
	pass	

func _on_enter_state() -> void:
	print("enter idle state")

func _on_exit_state() -> void:
	print("exit idle state")
