Incbin "grid.dat"

Type Scene
	Global file$	'Name of the scene (used to save file)
	Global root		'Root gui gadget
	Global backtex	'Texture with the grid background drawn on it
	
	Global editmode		'Object we arecurrently drawing
	Global drawing		'Tells if we are drawing an object
	Global editStart[2]	'Start position of the gadget being created

	Function Init()
		Local width = 640
		Local height = 480
		Local flags = 0
		Select Settings.renderer$
			Case "OpenGL"
				flags :| CSDF_OPENGL
			Case "Software"
				width = -width
				height = -height
		End Select
		csDisplayOpen width, height, 32, flags, QueryGadget(Ui.leftPanel, QUERY_HWND)

		root = csGuiGroup(0, 0, 640, 480, 0); csGadgetSetText(root, "Gui Root")
		
		'Create grid texture
		Local griddata:Byte[] = LoadByteArray("incbin::grid.dat")
		backtex = csTextureCreate(1024, 512)
		Local buffer:Byte Ptr = Byte Ptr(csTextureLock(backtex))
		MemCopy buffer, griddata, Len griddata
		csTextureUnlock(backtex)

		Reset
	End Function

	Function Loop()
		'Resize device when window resizes
		Select EventID()
			Case EVENT_WINDOWSIZE
				csDisplayResize(ClientWidth(Ui.leftPanel), ClientHeight(Ui.leftPanel))
				'csCameraAspectRatio cam, ClientWidth(Ui.workspace) * 1.0 / ClientHeight(Ui.workspace)
		End Select
		
		'Process engine events to grab mouse inputs
		While csEventPoll()
			DebugLog csEventId()
			Select csEventId()
				Case CSEV_MOUSE_HIT
					If csEventFrom() = CSMB_LEFT Then MouseDown(csMouseX()+GadgetX(ui.leftPanel), csMouseY()+GadgetY(ui.leftPanel))
				Case CSEV_MOUSE_RELEASE
					If csEventFrom() = CSMB_LEFT Then MouseUp(csMouseX()+GadgetX(ui.leftPanel), csMouseY()+GadgetY(ui.leftPanel))
			End Select
		Wend

		'Render
		csSceneBegin 'CSCF_BACKBUFFER | CSCF_ZBUFFER, csGetColor(255, 255, 255, 255)
		
		'Clear background
		csSetColor csGetColor(255, 255, 255, 255); csDrawRect(0, 0, csDisplayWidth(), csDisplayHeight())
		
		'Draw grid
		csDrawTexture(backtex, 0, 0)
		Rem
		csSetColor csGetColor(255, 120, 120, 120)
		For Local x = 0 Until csDisplayWidth() Step 4 csDrawLine x, 0, x, csDisplayHeight()-1 Next
		For Local y = 0 Until csDisplayHeight() Step 4 csDrawLine 0, y, csDisplayWidth()-1, y Next
		End Rem

		'Draw gui
		csGuiDraw()
		
		'Draw rect if drawing a new object
		If drawing
			Local x = ((csMouseX()+GadgetX(ui.leftPanel)) / 4) * 4
			Local y = ((csMouseY()+GadgetY(ui.leftPanel)) / 4) * 4
			csSetColor csGetColor(255, 255, 255, 0)
			csDrawLine editStart[0], editStart[1], x, editStart[1]
			csDrawLine editStart[0], y, x, y
			csDrawLine editStart[0], editStart[1], editStart[0], y
			csDrawLine x, editStart[1], x, y
			csDrawLine editStart[0]-1, editStart[1]-1, x+1, editStart[1]-1
			csDrawLine editStart[0]-1, y+1, x+1, y+1
			csDrawLine editStart[0]-1, editStart[1]-1, editStart[0]-1, y+1
			csDrawLine x-1, editStart[1]-1, x-1, y+1
		End If

		csSceneEnd
	End Function
	
	Function Finish()
	
	End Function
	
	Function Reset()
		file$ = ""
		SetGadgetText Ui.win, WINTITLE$ + " - <untitled>"
		
		'Clear all children of 'root'
		csGadgetFree root
		root = csGuiGroup(0, 0, 640, 480, 0); csGadgetSetText(root, "Gui Root")
		
		Ui.UpdateTreeView
	End Function
	
	Function Load(file$)
	
	End Function
	
	Function Save(file$)
	
	End Function

	Function MouseDown(x, y)
		If Not ui.editmode Then Return
		Notify ""
		drawing = True
		editmode = ui.editmode
		editStart[0] = (x / 4) * 4
		editStart[1] = (y / 4) * 4
	End Function
	
	Function MouseUp(x, y)
		drawing = False
		If editmode <> ui.editmode Then Return
		Local gx, gy, gw, gh
		If x > editStart[0] Then gx = editStart[0]; gw = x - editStart[0] Else gx = x; gw = editStart[0] - x
		If y > editStart[1] Then gy = editStart[1]; gh = y - editStart[1] Else gy = y; gh = editStart[1] - y
		Select editmode
			Case EDIT_ADDBUTTON
				csGadgetSetText csGuiButton(gx, gy, gw, gh, root), RequestGadgetName$("Button")
			Case EDIT_ADDWINDOW
				csGadgetSetText csGuiWindow(gx, gy, gw, gh, root, False), RequestGadgetName$("Window")
		End Select
		editmode = 0
		Ui.UpdateTreeView()
	End Function
	
	Function RequestGadgetName$(basename$)
		Local number = 1
		For Local i = 1 To csGadgetChildren(root)
			Local id = Replace$(csGadgetGetText$(csGadgetChild(root, i)), basename$, "").ToInt()
			If id => number Then number = id+1
		Next
		Return basename$ + StringIntLen$(number, 3)
	End Function
End Type