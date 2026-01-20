extends State
class_name DemoWalkState

func _ready():
	pass
	
func _process(_delta : float):
	pass

func _physics_process(_delta : float):
	pass
	
func _unhandled_input(event: InputEvent):
	pass	

func _on_enter_state() -> void:
	print("enter walk state")

func _on_exit_state() -> void:
	print("exit walk state")
