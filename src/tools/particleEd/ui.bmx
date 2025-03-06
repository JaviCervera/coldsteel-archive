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
	Global partLabel:TGadget
	Global partListbox:TGadget
	Global fAffLabel:TGadget
	Global fAffListbox:TGadget
	Global fAffAddButton:TGadget
	Global fAffRemoveButton:TGadget
	Global gAffLabel:TGadget
	Global gAffListBox:TGadget
	Global gAffAddButton:TGadget
	Global gAffRemoveButton:TGadget
	Global timer:TTimer
	Global toolbarHeight
	
	Function Init()
		'Create window
		win = CreateWindow("", 0, 0, ClientWidth(Desktop()), ClientHeight(Desktop()), Null, WINDOW_TITLEBAR | WINDOW_RESIZABLE | WINDOW_MENU | WINDOW_STATUS | WINDOW_CLIENTCOORDS | WINDOW_HIDDEN)

		'Create menu
		Local parent:TGadget = CreateMenu("File", 0, WindowMenu(win))
			CreateMenu("New Particle", MENU_NEW, parent, KEY_N, MODIFIER_CONTROL)
			CreateMenu("Open Particle", MENU_OPEN, parent, KEY_O, MODIFIER_CONTROL)
			Local mnu:TGadget = CreateMenu("Save Particle", MENU_SAVE, parent, KEY_S, MODIFIER_CONTROL); If DEMO = 1 Then DisableMenu mnu
			mnu = CreateMenu("Save Particle As...", MENU_SAVEAS, parent, KEY_S, MODIFIER_CONTROL | MODIFIER_SHIFT); If DEMO = 1 Then DisableMenu mnu
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

		'Create particle data list box
		partLabel = CreateLabel("Particle Data:", ClientWidth(win) - 246, toolbarHeight + 4, 242, 20, win)
		SetGadgetLayout partLabel, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		partListbox = CreateListBox(ClientWidth(win) - 246, toolbarHeight + 24, 244, 160, win)
		SetGadgetLayout partListbox, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		
		'Create fade out affectors list box
		fAffLabel = CreateLabel("Fade-Out Affectors (A R G B, Time):", ClientWidth(win) - 246, toolbarHeight + 188, 242, 20, win)
		SetGadgetLayout fAffLabel, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		fAffListBox = CreateListBox(ClientWidth(win) - 246, toolbarHeight + 208, 244, 60, win)
		SetGadgetLayout fAffListbox, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		fAffAddButton = CreateButton("Add", ClientWidth(win) - 246, toolbarHeight + 270, 121, 20, win)
		SetGadgetLayout fAffAddButton, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		fAffRemoveButton = CreateButton("Remove", ClientWidth(win) - 125, toolbarHeight + 270, 121, 20, win)
		SetGadgetLayout fAffRemoveButton, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED

		'Create fade otu affectors list box
		gAffLabel = CreateLabel("Gravity Affectors (X Y Z, Time):", ClientWidth(win) - 246, toolbarHeight + 294, 242, 20, win)
		SetGadgetLayout gAffLabel, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		gAffListBox = CreateListBox(ClientWidth(win) - 246, toolbarHeight + 314, 244, 60, win)
		SetGadgetLayout gAffListbox, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		gAffAddButton = CreateButton("Add", ClientWidth(win) - 246, toolbarHeight + 376, 121, 20, win)
		SetGadgetLayout gAffAddButton, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED
		gAffRemoveButton = CreateButton("Remove", ClientWidth(win) - 125, toolbarHeight + 376, 121, 20, win)
		SetGadgetLayout gAffRemoveButton, EDGE_CENTERED, EDGE_ALIGNED, EDGE_ALIGNED, EDGE_CENTERED


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
						SetStatusText win, "Particles created"
					Case MENU_OPEN
						Local file$ = RequestFile$("Open particles", "Particles Files:par", False, Settings.path$ + Settings.part_path$ + Scene.file$)
						If file$ <> "" And FileType(file$) = FILETYPE_FILE
							Scene.Load(Replace$(file$, "\", "/"))
						End If
						SetStatusText win, "Particles loaded"
					Case MENU_SAVE
						If Scene.file$ = "" Then
							EmitEvent CreateEvent(EVENT_MENUACTION, Null, MENU_SAVEAS)
						Else
							Scene.Save(Scene.file$)
						End If
						SetStatusText win, "Particles saved"
					Case MENU_SAVEAS
						Local file$ = RequestFile$("Save particles", "Particles Files:par", True, Settings.path$ + Settings.part_path$ + Scene.file$)
						If file$ <> ""
							If ExtractExt(file$) = "" Then file$ :+ ".par"
							Scene.Save(Replace$(file$, "\", "/"))
						End If
						SetStatusText win, "Material saved"
					Case MENU_EXIT
						PostEvent CreateEvent(EVENT_APPTERMINATE)
					Case MENU_OPTIONS
						RequestOptions 'RequestParticlesOptions
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
						SetGadgetShape partLabel, GadgetX(partLabel), toolbarHeight + 4, GadgetWidth(partLabel), 20
						SetGadgetShape partListbox, GadgetX(partListbox), toolbarHeight + 24, GadgetWidth(partListbox), 160
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
					Case partListbox
						Select EventData()
							Case PART_NAME
								Local name$ = RequestInput("Name:", Particles.Name$, win)
								If name$ <> "" Then Particles.Name$ = name$
							Case PART_MATERIAL
								Particles.Material$ = RequestParticlesMaterial$()
							Case PART_TYPE
								Particles.Type_ = RequestParticlesType()
							Case PART_BOX
								Local box$ = RequestInput$("Box (Width Height Depth):", Particles.Box#[0] + " " + Particles.Box#[1] + " " + Particles.Box#[2], win)
								If box$ <> ""
									Particles.Box#[0] = StringField$(box$, 1, " ").ToFloat()
									Particles.Box#[1] = StringField$(box$, 2, " ").ToFloat()
									Particles.Box#[2] = StringField$(box$, 3, " ").ToFloat()
								End If
							Case PART_DIRECTION
								Local dir$ = RequestInput$("Direction (X Y Z):", Particles.Direction#[0] + " " + Particles.Direction#[1] + " " + Particles.Direction#[2], win)
								If dir$ <> ""
									Particles.Direction#[0] = StringField$(dir$, 1, " ").ToFloat()
									Particles.Direction#[1] = StringField$(dir$, 2, " ").ToFloat()
									Particles.Direction#[2] = StringField$(dir$, 3, " ").ToFloat()
								End If
							Case PART_RATE
								Local dir$ = RequestInput$("Rate (Min Max):", Particles.Rate[0] + " " + Particles.Rate[1], win)
								If dir$ <> ""
									Particles.Rate[0] = StringField$(dir$, 1, " ").ToInt()
									Particles.Rate[1] = StringField$(dir$, 2, " ").ToInt()
								End If
							Case PART_MINCOLOR
								If RequestColor(csGetRed(Particles.MinColor), csGetGreen(Particles.MinColor), csGetBlue(Particles.MinColor)) Then Particles.MinColor = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255)
							Case PART_MAXCOLOR
								If RequestColor(csGetRed(Particles.MaxColor), csGetGreen(Particles.MaxColor), csGetBlue(Particles.MaxColor)) Then Particles.MaxColor = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255)
							Case PART_LIFETIME
								Local ltime$ = RequestInput$("Life Time (Min Max):", Particles.LifeTime[0] + " " + Particles.LifeTime[1], win)
								If ltime$ <> ""
									Particles.LifeTime[0] = StringField$(ltime$, 1, " ").ToInt()
									Particles.LifeTime[1] = StringField$(ltime$, 2, " ").ToInt()
								End If
							Case PART_MAXANGLE
								Local angle$ = RequestInput("Max Angle:", Particles.MaxAngle, win)
								If angle$ <> "" Then Particles.MaxAngle = angle$.ToInt()
							Case PART_SIZE
								Local size$ = RequestInput$("Size (Min Max):", Particles.Size#[0] + " " + Particles.Size#[1], win)
								If size$ <> ""
									Particles.Size#[0] = StringField$(size$, 1, " ").ToFloat()
									Particles.Size#[1] = StringField$(size$, 2, " ").ToFloat()
								End If
						End Select
						Particles.Update
					Case fAffAddButton
						Particles.AddAffector RequestFadeOutAffector()
					Case fAffRemoveButton
						Particles.RemoveFadeOutAffector SelectedGadgetItem(fAffListbox)
					Case gAffAddButton
						Particles.AddAffector RequestGravityAffector()
					Case gAffRemoveButton
						Particles.RemoveGravityAffector SelectedGadgetItem(gAffListbox)
				End Select
		End Select
	End Function
	
	Function Finish()
		FreeGadget win
		win = Null
	End Function
	
	Function UpdateListBox()
		'Update particle data listbox
		ClearGadgetItems partListbox
		AddGadgetItem partListbox, "Name: " + Particles.Name$
		AddGadgetItem partListbox, "Material: " + Particles.Material$
		Select Particles.Type_
			Case CSPT_POINT
				AddGadgetItem partListbox, "Type: Point"
			Case CSPT_BOX
				AddGadgetItem partListbox, "Type: Box"
		End Select
		AddGadgetItem partListbox, "Box (Width Height Depth): " + Particles.Box#[0] + " " + Particles.Box#[1] + " " + Particles.Box#[2]
		AddGadgetItem partListbox, "Direction (X Y Z): " + Particles.Direction#[0] + " " + Particles.Direction#[1] + " " + Particles.Direction#[2]
		AddGadgetItem partListbox, "Rate (Min Max): " + Particles.Rate[0] + " " + Particles.Rate[1]
		AddGadgetItem partListbox, "Min Color (R G B): " + csGetRed(Particles.MinColor) + " " + csGetGreen(Particles.MinColor) + " " + csGetBlue(Particles.MinColor)
		AddGadgetItem partListbox, "Max Color (R G B): " + csGetRed(Particles.MaxColor) + " " + csGetGreen(Particles.MaxColor) + " " + csGetBlue(Particles.MaxColor)
		AddGadgetItem partListbox, "Life Time (Min Max): " + Particles.LifeTime[0] + " " + Particles.LifeTime[1]
		AddGadgetItem partListbox, "Max Angle: " + Particles.MaxAngle
		AddGadgetItem partListbox, "Size (Width Height): " + Particles.Size#[0] + " " + Particles.Size#[1]
		
		'Update fade-out affectors listbox
		ClearGadgetItems fAffListbox
		For Local aff:TAffector = EachIn Particles.fadeoutAffectors
			AddGadgetItem fAffListbox, csGetRed(aff.Color) + " " + csGetGreen(aff.Color) + " " + csGetBlue(aff.Color) + " " + csGetAlpha(aff.Color) + ", " + aff.Time
		Next
		If CountGadgetItems(fAffListbox) Then SelectGadgetItem fAffListbox, CountGadgetItems(fAffListbox)-1
		
		'Update gravity affectors listbox
		ClearGadgetItems gAffListbox
		For Local aff:TAffector = EachIn Particles.gravityAffectors
			AddGadgetItem gAffListbox, aff.Grav#[0] + " " + aff.Grav#[1] + " " + aff.Grav#[2] + ", " + aff.Time
		Next
		If CountGadgetItems(gAffListbox) Then SelectGadgetItem gAffListbox, CountGadgetItems(gAffListbox)-1
	End Function
End Type