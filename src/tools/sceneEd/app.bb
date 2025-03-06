Type app_t
	Field ui.ui_t
	Field scene.scene_t
	Field quit
	Field path$
End Type
Global app.app_t = New app_t
app\ui = New ui_t
app\scene = New scene_t

Function AppInit()
	csLibInit "", "", 0
	app\path$ = CurrentDir$()
	UiInit()
	SceneInit()
End Function

Function AppLoop()
	UiLoop()
	SceneLoop()
End Function

Function AppFinish()
	UiFinish()
	SceneFinish()
	csLibFinish
End Function