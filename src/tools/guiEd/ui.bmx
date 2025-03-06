Incbin "toolbar.png"

Const MENU_NEW = 101
Const MENU_OPEN = 102
Const MENU_SAVE = 103
Const MENU_SAVEAS = 104
Const MENU_EXIT = 105
Const MENU_ADDBUTTON = 201
Const MENU_ADDCHECKBOX = 202
Const MENU_ADDCOMBOBOX = 203
Const MENU_ADDCONTEXTMENU = 204
Const MENU_ADDEDITBOX = 205
Const MENU_ADDGROUP = 206
Const MENU_ADDLISTBOX = 207
Const MENU_ADDMENU = 208
Const MENU_ADDSCROLLBAR = 209
Const MENU_ADDTABBER = 210
Const MENU_ADDTEXT = 211
Const MENU_ADDTEXTURE = 212
Const MENU_ADDTOOLBAR = 213
Const MENU_ADDWINDOW = 214
Const MENU_SELECT = 219
Const MENU_OPTIONS = 221
Const MENU_VIEWTOOLBAR = 301
Const MENU_INDEX = 401
Const MENU_ABOUT = 402
Const MENU_INVMOUSE = 0	'Needed because common.bmx refers to it

Const TOOLBAR_NEW =			0
Const TOOLBAR_OPEN =			1
Const TOOLBAR_SAVE =			2
Const TOOLBAR_ADDBUTTON =		4
Const TOOLBAR_ADDCHECKBOX =		5
Const TOOLBAR_ADDCOMBOBOX =		6
Const TOOLBAR_ADDCONTEXTMENU =	7
Const TOOLBAR_ADDEDITBOX =		8
Const TOOLBAR_ADDGROUP =		9
Const TOOLBAR_ADDLISTBOX =		10
Const TOOLBAR_ADDMENU =		11
Const TOOLBAR_ADDSCROLLBAR =	12
Const TOOLBAR_ADDTABBER =		13
Const TOOLBAR_ADDTEXT =		14
Const TOOLBAR_ADDTEXTURE =		15
Const TOOLBAR_ADDTOOLBAR =		16
Const TOOLBAR_ADDWINDOW =		17
Const TOOLBAR_SELECT =			19
Const TOOLBAR_OPTIONS =		21
Const TOOLBAR_INDEX =			23
Const TOOLBAR_ABOUT =			24
Global TOOLBARTIPS$[] = ["New", "Open", "Save", "", "Add Button", "Add Check Box", "Add Combo Box", "Add Context Menu", "Add Edit Box", "Add Group", "Add List Box", "Add Menu", "Add Scroll Bar", "Add Tabber", "Add Text", "Add Texture", "Add Tool Bar", "Add Window", "", "Select Gadget", "", "Options", "", "Index", "About"]

'Edit mode (tells what you are currently doing in the workspace)
Const EDIT_ADDBUTTON = 1
Const EDIT_ADDWINDOW = 10

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
	
	'Global mx, my		'Mouse position relative to workspace area
	'Global inarea		'Tells if the mouse is in the workspace area
	Global editmode	'Current edit mode
	
	Function Init()
		'Load iconstrip
		iconstrip = LoadIconStrip("incbin::toolbar.png")

		'Create window
		win = CreateWindow("", 0, 0, ClientWidth(Desktop()), ClientHeight(Desktop()), Null, WINDOW_TITLEBAR | WINDOW_RESIZABLE | WINDOW_MENU | WINDOW_STATUS | WINDOW_CLIENTCOORDS | WINDOW_HIDDEN)
		SetMinWindowSize win, 910, 594

		'Create menu
		Local parent:TGadget = CreateMenu("File", 0, WindowMenu(win))
			CreateMenu("New Gui", MENU_NEW, parent, KEY_N, MODIFIER_CONTROL)
			CreateMenu("Open Gui", MENU_OPEN, parent, KEY_O, MODIFIER_CONTROL)
			CreateMenu("Save Gui", MENU_SAVE, parent, KEY_S, MODIFIER_CONTROL)
			CreateMenu("Save Gui As...", MENU_SAVEAS, parent, KEY_S, MODIFIER_CONTROL | MODIFIER_SHIFT)
			CreateMenu("", 0, parent)
			CreateMenu("Exit", MENU_EXIT, parent)
		parent = CreateMenu("Edit", 0, WindowMenu(win))
			Local parent2:TGadget = CreateMenu("Add", 0, parent)
				CreateMenu("Button...", MENU_ADDBUTTON, parent2)
				CreateMenu("Check Box...", MENU_ADDCHECKBOX, parent2)
				CreateMenu("Combo Box...", MENU_ADDCOMBOBOX, parent2)
				CreateMenu("Context Menu...", MENU_ADDCONTEXTMENU, parent2)
				CreateMenu("Edit Box...", MENU_ADDEDITBOX, parent2)
				CreateMenu("Menu...", MENU_ADDMENU, parent2)
				CreateMenu("Scroll Bar...", MENU_ADDSCROLLBAR, parent2)
				CreateMenu("Tabber...", MENU_ADDTABBER, parent2)
				CreateMenu("Text...", MENU_ADDTEXT, parent2)
				CreateMenu("Texture...", MENU_ADDTEXTURE, parent2)
				CreateMenu("Tool Bar...", MENU_ADDTOOLBAR, parent2)
				CreateMenu("Window...", MENU_ADDWINDOW, parent2)
			CreateMenu("Options...", MENU_OPTIONS, parent)
		parent = CreateMenu("View", 0, WindowMenu(win))
			viewToolbarMenu = CreateMenu("Toolbar", MENU_VIEWTOOLBAR, parent)
			If Settings.viewToolbar Then CheckMenu viewToolbarMenu
		parent = CreateMenu("Help", 0, WindowMenu(win))
			CreateMenu("Index", MENU_INDEX, parent, KEY_F1)
			CreateMenu("About...", MENU_ABOUT, parent)
		UpdateWindowMenu win
		
		'Create toolbar
		toolbar = CreateToolBar("incbin::toolbar.png", 0, 0, 0, 0, win)
		SetToolBarTips toolbar, TOOLBARTIPS$
		If Settings.viewToolBar Then toolbarHeight = GadgetY(toolbar) + GadgetHeight(toolbar) Else toolbarHeight = 0; HideGadget toolbar

		'Create rendering area
		'leftPanel = CreatePanel(0, toolbarHeight, ClientWidth(win) - 250, ClientHeight(win) - toolbarHeight, win, PANEL_BORDER | PANEL_ACTIVE)
		'SetGadgetLayout leftPanel, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED
		leftPanel = CreatePanel(0, toolbarHeight, 640, 480, win, PANEL_BORDER | PANEL_ACTIVE)
		SetGadgetLayout leftPanel, EDGE_ALIGNED, EDGE_CENTERED, EDGE_ALIGNED, EDGE_CENTERED

		'Create TreeView
		label = CreateLabel("Gui Hierarchy:", ClientWidth(win) - 246, toolbarHeight + 4, 242, 20, win)
		SetGadgetLayout label, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		treeView = CreateTreeView(ClientWidth(win) - 246, toolbarHeight + 24, 244, ClientHeight(win) - toolbarHeight - 24, win)
		SetGadgetLayout treeView, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED
		SetGadgetIconStrip treeView, iconstrip

		'Create timer
		timer = CreateTimer(60)
		
		'Resize and show window
		'SetGadgetShape win, ClientWidth(Desktop())/2 - 320, ClientHeight(Desktop())/2 - 240, 640, 480
		SetStatusText win, "Ready"
		ShowGadget win
	End Function
	
	Function Loop()
		Select EventID()
			Case EVENT_MENUACTION
				Select EventData()
					Case MENU_NEW
						Scene.Reset()
						SetStatusText win, "New Gui"
					Case MENU_OPEN
					Case MENU_SAVE
					Case MENU_SAVEAS
					Case MENU_EXIT
						PostEvent CreateEvent(EVENT_APPTERMINATE)
					Case MENU_ADDBUTTON
						SetEditMode(EDIT_ADDBUTTON)
					Case MENU_ADDCHECKBOX
					Case MENU_ADDCOMBOBOX
					Case MENU_ADDCONTEXTMENU
					Case MENU_ADDEDITBOX
					Case MENU_ADDGROUP
					Case MENU_ADDLISTBOX
					Case MENU_ADDMENU
					Case MENU_ADDSCROLLBAR
					Case MENU_ADDTABBER
					Case MENU_ADDTEXT
					Case MENU_ADDTEXTURE
					Case MENU_ADDTOOLBAR
					Case MENU_ADDWINDOW
						SetEditMode(EDIT_ADDWINDOW)
					Case MENU_SELECT
					Case MENU_OPTIONS
						RequestOptions 'RequestMaterialOptions
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
						'SetGadgetShape leftPanel, GadgetX(leftPanel), toolbarHeight, GadgetWidth(leftPanel), ClientHeight(win) - toolbarHeight
						SetGadgetShape label, GadgetX(label), toolbarHeight + 4, GadgetWidth(label), 20
						SetGadgetShape treeView, GadgetX(treeView), toolbarHeight + 24, GadgetWidth(treeView), ClientHeight(win) - toolbarHeight - 24
						UpdateWindowMenu win
					Case MENU_ABOUT
						Notify ABOUT$
				End Select
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then PostEvent CreateEvent(EVENT_APPTERMINATE)
			'Case EVENT_MOUSEMOVE
			'	mx = EventX()
			'	my = EventY()
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
							Case TOOLBAR_ADDBUTTON
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDBUTTON)
							Case TOOLBAR_ADDCHECKBOX
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDCHECKBOX)
							Case TOOLBAR_ADDCOMBOBOX
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDCOMBOBOX)
							Case TOOLBAR_ADDCONTEXTMENU
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDCONTEXTMENU)
							Case TOOLBAR_ADDEDITBOX
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDEDITBOX)
							Case TOOLBAR_ADDGROUP
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDGROUP)
							Case TOOLBAR_ADDLISTBOX
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDLISTBOX)
							Case TOOLBAR_ADDMENU
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDMENU)
							Case TOOLBAR_ADDSCROLLBAR
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDSCROLLBAR)
							Case TOOLBAR_ADDTABBER
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDTABBER)
							Case TOOLBAR_ADDTEXT
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDTEXT)
							Case TOOLBAR_ADDTEXTURE
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDTEXTURE)
							Case TOOLBAR_ADDTOOLBAR
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDTOOLBAR)
							Case TOOLBAR_ADDWINDOW
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ADDWINDOW)
							Case TOOLBAR_SELECT
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_SELECT)
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

	Function AddTreeViewNodes(gadget, parent:TGadget)
		Local icon = -1
		Select csGadgetType(gadget)
			Case CSGT_BUTTON
				icon = TOOLBAR_ADDBUTTON
			Case CSGT_CHECKBOX
				icon = TOOLBAR_ADDCHECKBOX
			Case CSGT_COMBOBOX
				icon = TOOLBAR_ADDCOMBOBOX
			Case CSGT_EDITBOX
				icon = TOOLBAR_ADDEDITBOX
			Case CSGT_GROUP
				icon = TOOLBAR_ADDGROUP
			Case CSGT_LISTBOX
				icon = TOOLBAR_ADDLISTBOX
			Case CSGT_MENU
				icon = TOOLBAR_ADDMENU
			Case CSGT_SCROLLBAR
				icon = TOOLBAR_ADDSCROLLBAR
			Case CSGT_TABBER
				icon = TOOLBAR_ADDTABBER
			Case CSGT_TEXT
				icon = TOOLBAR_ADDTEXT
			Case CSGT_TEXTURE
				icon = TOOLBAR_ADDTEXTURE
			Case CSGT_TOOLBAR
				icon = TOOLBAR_ADDTOOLBAR
			Case CSGT_WINDOW
				icon = TOOLBAR_ADDWINDOW
		End Select
		parent = AddTreeViewNode(csGadgetGetText$(gadget), parent, icon)
		For Local i = 1 To csGadgetChildren(gadget)
			AddTreeViewNodes csGadgetChild(gadget, i), parent
		Next
		ExpandTreeViewNode parent
	End Function
	
	Function SetEditMode(mode)
		editmode = mode
		Select mode
			Case EDIT_ADDBUTTON
				SetStatusText win, "Add Button"
			Case EDIT_ADDWINDOW
				SetStatusText win, "Add Window"
		End Select
	End Function
	
	Rem
	Function CheckInArea()
		If mx => GadgetX(workspace) And mx <= (GadgetX(workspace) + GadgetWidth(workspace)) And my => GadgetY(workspace) And my <= (GadgetY(workspace) + GadgetHeight(workspace))
			inarea = True
		Else
			inarea = False
		End If
	End Function
	End Rem
End Type