Include "sceneEd/ui_dialogs.bb"
Include "sceneEd/ui_misc.bb"

Type ui_t
	Field win
	Field winTitle$
	Field leftPanel
	Field treeView
	Field timer
End Type

Const UI_FILEMENU_NEW = 101
Const UI_FILEMENU_OPEN = 102
Const UI_FILEMENU_SAVE = 103
Const UI_FILEMENU_SAVEAS = 104
Const UI_FILEMENU_EXIT = 105
Const UI_EDITMENU_ADDGROUP = 201
Const UI_EDITMENU_ADDBILLBOARD = 202
Const UI_EDITMENU_ADDBODY = 203
Const UI_EDITMENU_ADDLIGHT = 204
Const UI_EDITMENU_ADDMESH = 205
Const UI_EDITMENU_ADDPARTICLES = 206
Const UI_EDITMENU_ADDTERRAIN = 207
Const UI_EDITMENU_ADDWATER = 208
Const UI_EDITMENU_REPBILLBOARD = 209
Const UI_EDITMENU_REPMESH = 210
Const UI_EDITMENU_OPTIONS = 211

Function UiInit()
	;Create window
	app\ui\winTitle$ = "ColdSteel Scene Editor"
	app\ui\win = CreateWindow("", ClientWidth(Desktop())/2 - 320, ClientHeight(Desktop())/2 - 240, 640, 480, 0, 1+2+4+8+32)

	;Create menu
	parent = CreateMenu("File", 0, WindowMenu(app\ui\win))
		CreateMenu("New Scene", UI_FILEMENU_NEW, parent)
		CreateMenu("Open Scene", UI_FILEMENU_OPEN, parent)
		DisableMenu CreateMenu("Save Scene", UI_FILEMENU_SAVE, parent)
		CreateMenu("Save Scene As...", UI_FILEMENU_SAVEAS, parent)
		CreateMenu("", 0, parent)
		CreateMenu("Exit", UI_FILEMENU_EXIT, parent)
	parent = CreateMenu("Edit", 0, WindowMenu(app\ui\win))
		parent2 = CreateMenu("Add", 0, parent)
			CreateMenu("Group...", UI_EDITMENU_ADDGROUP, parent2)
			CreateMenu("Billboard...", UI_EDITMENU_ADDBILLBOARD, parent2)
			CreateMenu("Body...", UI_EDITMENU_ADDBODY, parent2)
			CreateMenu("Light...", UI_EDITMENU_ADDLIGHT, parent2)
			CreateMenu("Mesh...", UI_EDITMENU_ADDMESH, parent2)
			CreateMenu("Particles...", UI_EDITMENU_ADDPARTICLES, parent2)
			CreateMenu("Terrain...", UI_EDITMENU_ADDTERRAIN, parent2)
			CreateMenu("Water...", UI_EDITMENU_ADDWATER, parent2)
		parent2 = CreateMenu("Replicator", 0, parent)
			CreateMenu("Billboard...", UI_EDITMENU_REPBILLBOARD, parent2)
			CreateMenu("Mesh...", UI_EDITMENU_REPMESH, parent2)
		CreateMenu("", 0, parent)
		CreateMenu("Options", UI_EDITMENU_OPTIONS, parent)
	UpdateWindowMenu app\ui\win

	;Create rendering area
	app\ui\leftPanel = CreatePanel(0, 0, ClientWidth(app\ui\win) - 200, ClientHeight(app\ui\win), app\ui\win, 1)
	SetGadgetLayout app\ui\leftPanel, 1, 1, 1, 1

	;Create tree view
	SetGadgetLayout CreateLabel("Scene View:", ClientWidth(app\ui\win) - 196, 4, 192, 20, app\ui\win), 0, 1, 1, 0
	app\ui\treeView = CreateTreeView(ClientWidth(app\ui\win) - 196, 24, 192, ClientHeight(app\ui\win) - 52, app\ui\win)
	SetGadgetLayout app\ui\treeView, 0, 1, 1, 1
	
	;Create timer
	app\ui\timer = CreateTimer(60)
End Function

Function UiLoop()
	Select WaitEvent()
		Case $802	;Resize window
		Case $803	;Close window
			If EventSource() = app\ui\win Then UiClosePressed()
		Case $1001	;Menu event
			Select EventData()
				Case UI_EDITMENU_ADDMESH
					UiAddMeshDialog(0)
				Case UI_EDITMENU_OPTIONS
					dir$ = RequestDir$("Select working folder", app\path$)
					If dir$ <> "" Then app\path$ = dir$ + "\"
			End Select
	End Select
End Function

Function UiFinish()
	FreeGadget app\ui\win
End Function