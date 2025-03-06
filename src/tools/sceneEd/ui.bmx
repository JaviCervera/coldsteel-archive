Incbin "toolbar.png"

Const MENU_NEW = 101
Const MENU_OPEN = 102
Const MENU_SAVE = 103
Const MENU_SAVEAS = 104
Const MENU_EXIT = 105
Const MENU_ADDBILLBOARD = 201
Const MENU_ADDBODY = 202
Const MENU_ADDEMITTER = 203
Const MENU_ADDGROUP = 204
Const MENU_ADDLIGHT = 205
Const MENU_ADDMESH = 206
Const MENU_ADDPATH = 207
Const MENU_ADDTERRAIN = 208
Const MENU_ADDTRIGGER = 209
Const MENU_ADDWATER = 210
Const MENU_REPBILLBOARD = 211
Const MENU_REPMESH = 212
Const MENU_OPTIONS = 221
Const MENU_INVMOUSE = 222
Const MENU_VIEWTOOLBAR = 301
Const MENU_INDEX = 401
Const MENU_ABOUT = 402

Const TOOLBAR_NEW =		0
Const TOOLBAR_OPEN =		1
Const TOOLBAR_SAVE =		2
Const TOOLBAR_BILLBOARD =	4
Const TOOLBAR_BODY =		5
Const TOOLBAR_EMITTER =	6
Const TOOLBAR_GROUP =		7
Const TOOLBAR_LIGHT =		8
Const TOOLBAR_MESH =		9
Const TOOLBAR_PATH =		10
Const TOOLBAR_TERRAIN =	11
Const TOOLBAR_TRIGGER =	12
Const TOOLBAR_WATER =		13
Const TOOLBAR_OPTIONS =	15
Const TOOLBAR_INDEX =		17
Const TOOLBAR_ABOUT =		18

Type Ui
	Global win:TGadget
	Global invMouseMenu:TGadget
	Global viewToolbarMenu:TGadget
	Global toolbar:TGadget
	Global leftPanel:TGadget
	Global label:TGadget
	Global treeView:TGadget
	Global timer:TTimer
	Global iconstrip:TIconStrip
	Global toolbarHeight
	
	Function Init()
		'Load iconstrip
		iconstrip = LoadIconStrip("incbin::toolbar.png")

		'Create window
		win = CreateWindow("", 0, 0, ClientWidth(Desktop()), ClientHeight(Desktop()), Null, WINDOW_TITLEBAR | WINDOW_RESIZABLE | WINDOW_MENU | WINDOW_STATUS | WINDOW_CLIENTCOORDS | WINDOW_HIDDEN)

		'Create menu
		Local parent:TGadget = CreateMenu("File", 0, WindowMenu(win))
			CreateMenu("New Scene", MENU_NEW, parent, KEY_N, MODIFIER_CONTROL)
			CreateMenu("Open Scene", MENU_OPEN, parent, KEY_O, MODIFIER_CONTROL)
			CreateMenu("Save Scene", MENU_SAVE, parent, KEY_S, MODIFIER_CONTROL)
			CreateMenu("Save Scene As...", MENU_SAVEAS, parent, KEY_S, MODIFIER_CONTROL | MODIFIER_SHIFT)
			CreateMenu("", 0, parent)
			CreateMenu("Exit", MENU_EXIT, parent)
		parent = CreateMenu("Edit", 0, WindowMenu(win))
			Local parent2:TGadget = CreateMenu("Add", 0, parent)
				CreateMenu("Billboard...", MENU_ADDBILLBOARD, parent2)
				CreateMenu("Body...", MENU_ADDBODY, parent2)
				CreateMenu("Emitter...", MENU_ADDEMITTER, parent2)
				CreateMenu("Group...", MENU_ADDGROUP, parent2)
				CreateMenu("Light...", MENU_ADDLIGHT, parent2)
				CreateMenu("Mesh...", MENU_ADDMESH, parent2)
				CreateMenu("Path...", MENU_ADDPATH, parent2)
				CreateMenu("Terrain...", MENU_ADDTERRAIN, parent2)
				CreateMenu("Trigger...", MENU_ADDTRIGGER, parent2)
				CreateMenu("Water...", MENU_ADDWATER, parent2)
			parent2 = CreateMenu("Replicator", 0, parent)
				CreateMenu("Billboard...", MENU_REPBILLBOARD, parent2)
				CreateMenu("Mesh...", MENU_REPMESH, parent2)
			CreateMenu("Options...", MENU_OPTIONS, parent)
			invMouseMenu = CreateMenu("Invert Mouse", MENU_INVMOUSE, parent, KEY_I, MODIFIER_CONTROL)
				If Settings.invMouse Then CheckMenu invMouseMenu
		parent = CreateMenu("View", 0, WindowMenu(win))
			viewToolbarMenu = CreateMenu("Toolbar", MENU_VIEWTOOLBAR, parent)
			If Settings.viewToolbar Then CheckMenu viewToolbarMenu
		parent = CreateMenu("Help", 0, WindowMenu(win))
			CreateMenu("Index", MENU_INDEX, parent, KEY_F1)
			CreateMenu("About...", MENU_ABOUT, parent)
		UpdateWindowMenu win
		
		'Create toolbar
		toolbar = CreateToolBar("incbin::toolbar.png", 0, 0, 0, 0, win)
		SetToolBarTips toolbar, ["New", "Open", "Save", "", "Add Billboard", "Add Body", "Add Emitter", "Add Group", "Add Light", "Add Mesh", "Add Path", "Add Terrain", "Add Trigger", "Add Water", "", "Options", "", "Index", "About"]
		If Settings.viewToolBar Then toolbarHeight = GadgetY(toolbar) + GadgetHeight(toolbar) Else toolbarHeight = 0; HideGadget toolbar

		'Create rendering area
		leftPanel = CreatePanel(0, toolbarHeight, ClientWidth(win) - 250, ClientHeight(win) - toolbarHeight, win, PANEL_BORDER | PANEL_ACTIVE)
		SetGadgetLayout leftPanel, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED

		'Create TreeView
		label = CreateLabel("Scene View:", ClientWidth(win) - 246, toolbarHeight + 4, 242, 20, win)
		SetGadgetLayout label, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		treeView = CreateTreeView(ClientWidth(win) - 246, toolbarHeight + 24, 244, ClientHeight(win) - toolbarHeight - 24, win)
		SetGadgetLayout treeView, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED
		SetGadgetIconStrip treeView, iconstrip

		'Create timer
		timer = CreateTimer(60)
		
		'Resize and show window
		SetGadgetShape win, ClientWidth(Desktop())/2 - 320, ClientHeight(Desktop())/2 - 240, 640, 480
		SetStatusText win, "Ready"
		ShowGadget win
	End Function
	
	Function Loop()
		Select EventID()
			Case EVENT_MOUSEDOWN
				If EventData() = 2 Then Scene.freeLook = Not Scene.freeLook
				If Scene.freeLook Then SetPointer POINTER_CROSS Else SetPointer POINTER_DEFAULT
			Case EVENT_MOUSEWHEEL
				Settings.zoom = Settings.zoom - EventData()
				If Settings.zoom < 0 Then Settings.zoom = 0
			Case EVENT_MENUACTION
				Select EventData()
					Case MENU_NEW
						Scene.Reset()
						SetStatusText win, "Scene created"
					Case MENU_OPEN
					Case MENU_SAVE
					Case MENU_SAVEAS
					Case MENU_EXIT
						PostEvent CreateEvent(EVENT_APPTERMINATE)
					Case MENU_ADDBILLBOARD
					Case MENU_ADDBODY
					Case MENU_ADDEMITTER
					Case MENU_ADDGROUP
					Case MENU_ADDLIGHT
					Case MENU_ADDMESH
						RequestMesh
					Case MENU_ADDPATH
					Case MENU_ADDTERRAIN
					Case MENU_ADDTRIGGER
					Case MENU_ADDWATER
					Case MENU_REPBILLBOARD
					Case MENU_REPMESH
					Case MENU_OPTIONS
						RequestOptions 'RequestMaterialOptions
					Case MENU_INVMOUSE
						Settings.invMouse = Not Settings.invMouse
						If Settings.invMouse
							CheckMenu invMouseMenu
							SetStatusText win, "Mouse Y inverted"
						Else
							SetStatusText win, "Mouse Y not inverted"
							UncheckMenu invMouseMenu
						End If
						UpdateWindowMenu win
					Case MENU_VIEWTOOLBAR
						Settings.viewToolbar = Not Settings.viewToolbar
						If Settings.viewToolbar
							CheckMenu viewToolbarMenu
							ShowGadget toolbar
							toolbarHeight = GadgetY(toolbar) + GadgetHeight(toolbar)
							SetStatusText win, "Toolbar visible"
						Else
							UncheckMenu viewToolbarMenu
							HideGadget toolbar
							toolbarHeight = 0
							SetStatusText win, "Toolbar hidden"
						End If
						SetGadgetShape leftPanel, GadgetX(leftPanel), toolbarHeight, GadgetWidth(leftPanel), ClientHeight(win) - toolbarHeight
						SetGadgetShape label, GadgetX(label), toolbarHeight + 4, GadgetWidth(label), 20
						SetGadgetShape treeView, GadgetX(treeView), toolbarHeight + 24, GadgetWidth(treeView), ClientHeight(win) - toolbarHeight - 24
						UpdateWindowMenu win
					Case MENU_ABOUT
						Notify ABOUT$
				End Select
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then PostEvent CreateEvent(EVENT_APPTERMINATE)
			Case EVENT_GADGETACTION
				Select EventSource()
					Case toolbar
						Select EventData()
							Case TOOLBAR_NEW
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_NEW)
							Case TOOLBAR_OPEN
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_OPEN)
							Case TOOLBAR_SAVE
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_SAVE)
							Case TOOLBAR_BILLBOARD
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDBILLBOARD)
							Case TOOLBAR_BODY
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDBODY)
							Case TOOLBAR_EMITTER
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDEMITTER)
							Case TOOLBAR_GROUP
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDGROUP)
							Case TOOLBAR_LIGHT
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDLIGHT)
							Case TOOLBAR_MESH
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDMESH)
							Case TOOLBAR_PATH
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDPATH)
							Case TOOLBAR_TERRAIN
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDTERRAIN)
							Case TOOLBAR_TRIGGER
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDTRIGGER)
							Case TOOLBAR_WATER
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDWATER)
							Case TOOLBAR_OPTIONS
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_OPTIONS)
							Case TOOLBAR_INDEX
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_INDEX)
							Case TOOLBAR_ABOUT
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ABOUT)
						End Select
				End Select
		End Select
	End Function
	
	Function Finish()
	
	End Function
	
	Function UpdateTreeView()
		FreeGadget treeView
		treeView = CreateTreeView(ClientWidth(win) - 246, toolbarHeight + 24, 244, ClientHeight(win) - toolbarHeight - 24, win)
		SetGadgetLayout treeView, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED
		SetGadgetIconStrip treeView, iconstrip
		AddTreeViewNodes Scene.root, TreeViewRoot(treeView)
	End Function
	
	Function AddTreeViewNodes(node, parent:TGadget)
		Local icon = -1
		Select csNodeType(node)
			Case CSNT_EMPTY
				icon = TOOLBAR_GROUP
			Case CSNT_BILLBOARD
				icon = TOOLBAR_BILLBOARD
			Case CSNT_BODY
				icon = TOOLBAR_BODY
			Case CSNT_EMITTER
				icon = TOOLBAR_EMITTER
			Case CSNT_LIGHT
				icon = TOOLBAR_LIGHT
			Case CSNT_MESH
				icon = TOOLBAR_MESH
			Case CSNT_MESH_OCTREE
				icon = TOOLBAR_MESH
			Case CSNT_TERRAIN
				icon = TOOLBAR_TERRAIN
			Case CSNT_WATER
				icon = TOOLBAR_WATER
		End Select
		parent = AddTreeViewNode(csNodeGetName$(node), parent, icon)
		For Local i = 1 To csNodeChildren(node)
			AddTreeViewNodes csNodeChild(node, i), parent
		Next
	End Function

	Function AddGroups(node, gadget:TGadget, hideNonGroups = False)
		'Add current node
		If hideNonGroups = True And csNodeType(node) = CSNT_EMPTY
			AddGadgetItem gadget, csNodeGetName$(node)
		Else If hideNonGroups = False
			AddGadgetItem gadget, csNodeGetName$(node)
		End If

		'Add child nodes
		For Local i = 1 To csNodeChildren(node)
			AddGroups csNodeChild(node, i), gadget, hideNonGroups
		Next
End Function
End Type