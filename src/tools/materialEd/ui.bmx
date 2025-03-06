Incbin "toolbar.png"

Const MENU_NEW = 101
Const MENU_OPEN = 102
Const MENU_SAVE = 103
Const MENU_SAVEAS = 104
Const MENU_EXIT = 105
Const MENU_OPTIONS = 201
Const MENU_INVMOUSE = 202
Const MENU_VIEWTOOLBAR = 301
Const MENU_INDEX = 401
Const MENU_ABOUT = 402

Const TOOLBAR_NEW =		0
Const TOOLBAR_OPEN =		1
Const TOOLBAR_SAVE =		2
Const TOOLBAR_OPTIONS =	4
Const TOOLBAR_INDEX =		6
Const TOOLBAR_ABOUT =		7

Type Ui
	Global win:TGadget
	Global invMouseMenu:TGadget
	Global viewToolbarMenu:TGadget
	Global toolbar:TGadget
	Global leftPanel:TGadget
	Global matLabel:TGadget
	Global listBox:TGadget
	Global timer:TTimer
	Global toolbarHeight

	Function Init()
		'Create window
		win = CreateWindow("", 0, 0, ClientWidth(Desktop()), ClientHeight(Desktop()), Null, WINDOW_TITLEBAR | WINDOW_RESIZABLE | WINDOW_MENU | WINDOW_STATUS | WINDOW_CLIENTCOORDS | WINDOW_HIDDEN)

		'Create menu
		Local parent:TGadget = CreateMenu("File", 0, WindowMenu(win))
			CreateMenu("New Material", MENU_NEW, parent, KEY_N, MODIFIER_CONTROL)
			CreateMenu("Open Material", MENU_OPEN, parent, KEY_O, MODIFIER_CONTROL)
			Local mnu:TGadget = CreateMenu("Save Material", MENU_SAVE, parent, KEY_S, MODIFIER_CONTROL); If DEMO = 1 Then DisableMenu mnu
			mnu = CreateMenu("Save Material As...", MENU_SAVEAS, parent, KEY_S, MODIFIER_CONTROL | MODIFIER_SHIFT); If DEMO = 1 Then DisableMenu mnu
			CreateMenu("", 0, parent)
			CreateMenu("Exit", MENU_EXIT, parent)
		parent = CreateMenu("Edit", 0, WindowMenu(win))
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
		SetToolBarTips toolbar, ["New", "Open", "Save", "", "Options", "", "Index", "About"]
		If Settings.viewToolBar Then toolbarHeight = GadgetY(toolbar) + GadgetHeight(toolbar) Else toolbarHeight = 0; HideGadget toolbar

		'Create rendering area
		leftPanel = CreatePanel(0, toolbarHeight, ClientWidth(win) - 250, ClientHeight(win) - toolbarHeight, win, PANEL_BORDER | PANEL_ACTIVE)
		SetGadgetLayout leftPanel, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED

		'Create list box
		matLabel = CreateLabel("Material Settings:", ClientWidth(win) - 246, toolbarHeight + 4, 242, 20, win)
		SetGadgetLayout matLabel, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		listBox = CreateListBox(ClientWidth(win) - 246, toolbarHeight + 24, 244, ClientHeight(win) - toolbarHeight - 24, win)
		SetGadgetLayout listBox, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_ALIGNED

		'Create timer
		timer = CreateTimer(60)
		
		'Resize and show window
		'SetGadgetShape win, ClientWidth(Desktop())/2 - 320, ClientHeight(Desktop())/2 - 240, 640, 480
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
						SetStatusText win, "Material created"
					Case MENU_OPEN
						Local file$ = RequestFile$("Open material", "Material Files:mat", False, Settings.path$ + Settings.mat_path$ + Scene.file$)
						If file$ <> "" And FileType(file$) = FILETYPE_FILE
							Scene.Load(Replace$(file$, "\", "/"))
						End If
						SetStatusText win, "Material loaded"
					Case MENU_SAVE
						If Scene.file$ = "" Then
							EmitEvent CreateEvent(EVENT_MENUACTION, Null, MENU_SAVEAS)
						Else
							Scene.Save(Scene.file$)
						End If
						SetStatusText win, "Material saved"
					Case MENU_SAVEAS
						Local file$ = RequestFile$("Save material", "Material Files:mat", True, Settings.path$ + Settings.mat_path$ + Scene.file$)
						If file$ <> ""
							If ExtractExt(file$) = "" Then file$ :+ ".mat"
							Scene.Save(Replace$(file$, "\", "/"))
						End If
						SetStatusText win, "Material saved"
					Case MENU_EXIT
						PostEvent CreateEvent(EVENT_APPTERMINATE)
					Case MENU_OPTIONS
						RequestOptions RequestMaterialOptions
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
						SetGadgetShape matLabel, GadgetX(matLabel), toolbarHeight + 4, GadgetWidth(matLabel), 20
						SetGadgetShape listBox, GadgetX(listBox), toolbarHeight + 24, GadgetWidth(listBox), ClientHeight(win) - toolbarHeight - 24
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
							Case TOOLBAR_OPTIONS
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_OPTIONS)
							Case TOOLBAR_INDEX
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_INDEX)
							Case TOOLBAR_ABOUT
								PostEvent CreateEvent(EVENT_MENUACTION, Null, MENU_ABOUT)
						End Select
					Case listBox
						Select EventData()
							Case MAT_NAME
								Local name$ = RequestInput("Name:", Material.Name$, win)
								If name$ <> "" Then Material.Name$ = name$
							Case MAT_TYPE
								Material.Type_ = RequestMaterialType()
							Case MAT_FLAGS
								Material.Flags = RequestMaterialFlags()
							Case MAT_TEX0
								Local file$ = RequestFile$("Texture file", "Texture Files:bmp,png,jpg,tga,pcx,psd", False, Settings.path$)
								If file$ <> "" And FileType(file$) = FILETYPE_FILE Then Material.Tex$[0] = Replace$(Replace$(file$, "\", "/"), Settings.path$, "")
								If file$ = "" Then Material.Tex$[0] = ""
							Case MAT_TEX1
								Local file$ = RequestFile$("Texture file", "Texture Files:bmp,png,jpg,tga,pcx,psd", False, Settings.path$)
								If file$ <> "" And FileType(file$) = FILETYPE_FILE Then Material.Tex$[1] = Replace$(Replace$(file$, "\", "/"), Settings.path$, "")
								If file$ = "" Then Material.Tex$[1] = ""
							Case MAT_AMBIENT
								If RequestColor(csGetRed(Material.Ambient), csGetGreen(Material.Ambient), csGetBlue(Material.Ambient)) Then Material.Ambient = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255)
							Case MAT_DIFFUSE
								If RequestColor(csGetRed(Material.Diffuse), csGetGreen(Material.Diffuse), csGetBlue(Material.Diffuse)) Then Material.Diffuse = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255)
							Case MAT_EMISSIVE
								If RequestColor(csGetRed(Material.Emissive), csGetGreen(Material.Emissive), csGetBlue(Material.Emissive)) Then Material.Emissive = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255)
							Case MAT_SPECULAR
								If RequestColor(csGetRed(Material.Specular), csGetGreen(Material.Specular), csGetBlue(Material.Specular)) Then Material.Specular = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255)
							Case MAT_SHININESS
								Local shininess$ = RequestInput$("Shininess:", Material.Shininess#, win)
								If shininess$ <> "" Then Material.Shininess# = shininess$.ToFloat()
							Case MAT_PARAM
								Local param$ = RequestInput$("Param:", Material.Param#, win)
								If param$ <> "" Then Material.Param# = param$.ToFloat()
						End Select
						Material.Update
				End Select
		End Select
	End Function
	
	Function Finish()
		FreeGadget win
		win = Null
	End Function
	
	Function UpdateListBox()
		ClearGadgetItems listBox
		AddGadgetItem listBox, "Name: " + Material.Name$
		Select Material.Type_
			Case CSMT_MODULATE
				AddGadgetItem listBox, "Type: Modulate"
			Case CSMT_MODULATE2X
				AddGadgetItem listBox, "Type: Modulate 2X"
			Case CSMT_MODULATE4X
				AddGadgetItem listBox, "Type: Modulate 4X"
			Case CSMT_DETAIL
				AddGadgetItem listBox, "Type: Detail Mapped"
			Case CSMT_ADD
				AddGadgetItem listBox, "Type: Add"
			Case CSMT_VERTEX_ALPHA
				AddGadgetItem listBox, "Type: Vertex Alpha"
			Case CSMT_ALPHA
				AddGadgetItem listBox, "Type: Alpha"
			Case CSMT_MASKED
				AddGadgetItem listBox, "Type: Masked"
			Case CSMT_REFLECTION
				AddGadgetItem listBox, "Type: Reflection"
			Case CSMT_REFLECTION_ALPHA
				AddGadgetItem listBox, "Type: Reflection Alpha"
			Case CSMT_NORMAL
				AddGadgetItem listBox, "Type: Normal Mapped"
			Case CSMT_PARALLAX
				AddGadgetItem listBox, "Type: Parallax Mapped"
		End Select
		Local flags$ = "Flags: "
		If Material.Flags = 0 Then flags$ = "Flags: None"
		If (Material.Flags & CSMF_FULLBRIGHT) = CSMF_FULLBRIGHT Then flags$ = flags$ + "Fullbright, "
		If (Material.Flags & CSMF_FLATSHADING) = CSMF_FLATSHADING Then flags$ = flags$ + "Flat-shaded, "
		If (Material.Flags & CSMF_FOG) = CSMF_FOG Then flags$ = flags$ + "Fog, "
		If (Material.Flags & CSMF_NOCULL) = CSMF_NOCULL Then flags$ = flags$ + "No cull, "
		If (Material.Flags & CSMF_WIREFRAME) = CSMF_WIREFRAME Then flags$ = flags$ + "Wireframe, "
		If (Material.Flags & CSMF_NOZDEPTH) = CSMF_NOZDEPTH Then flags$ = flags$ + "No Z-Depth, "
		If (Material.Flags & CSMF_NOZWRITE) = CSMF_NOZWRITE Then flags$ = flags$ + "No Z-Write, "
		If (Material.Flags & CSMF_ANISOTROPIC) = CSMF_ANISOTROPIC Then flags$ = flags$ + "Anisotropic, "
		If Material.Flags <> 0 Then flags$ = Left$(flags$, Len(flags$) - 2)
		AddGadgetItem listBox, flags$
		AddGadgetItem listBox, "Texture 0: " + Material.Tex$[0]
		AddGadgetItem listBox, "Texture 1: " + Material.Tex$[1]
		AddGadgetItem listBox, "Ambient (R G B): " + csGetRed(Material.Ambient) + " " + csGetGreen(Material.Ambient) + " " + csGetBlue(Material.Ambient)
		AddGadgetItem listBox, "Diffuse (R G B): " + csGetRed(Material.Diffuse) + " " + csGetGreen(Material.Diffuse) + " " + csGetBlue(Material.Diffuse)
		AddGadgetItem listBox, "Emissive (R G B): " + csGetRed(Material.Emissive) + " " + csGetGreen(Material.Emissive) + " " + csGetBlue(Material.Emissive)
		AddGadgetItem listBox, "Specular (R G B): " + csGetRed(Material.Specular) + " " + csGetGreen(Material.Specular) + " " + csGetBlue(Material.Specular)
		AddGadgetItem listBox, "Shininess: " + Material.Shininess#
		AddGadgetItem listBox, "Param: " + Material.Param#
	End Function
End Type