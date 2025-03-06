Type Scene
	'Name of the scene (used to save file)
	Global file$

	'Store renderer settings (to detect if the ones in the Settings table have changed)
	Global ambLight

	'Mouse look options
	Global freeLook
	Global mx, my

	'Scene nodes
	Global cam
	Global light
	Global node
	
	'Material names list
	Global materials:TList = CreateList()

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
		
		ParseMaterials()
		
		cam = csCameraNode(0)
		csNodePosition cam, 0, 1, -5
		
		light = csLightNode(cam)
		
		node = csNodeEmpty(0)
		
		Reset()
	End Function
	
	Function Loop()
		'Resize device when window resizes
		Select EventID()
			Case EVENT_WINDOWSIZE
				csDisplayResize(ClientWidth(Ui.leftPanel), ClientHeight(Ui.leftPanel))
				csCameraAspectRatio cam, ClientWidth(Ui.leftPanel) * 1.0 / ClientHeight(Ui.leftPanel)
		End Select

		'Free look
		If freeLook
			Local mxs = csMouseX() - mx
			Local mys = csMouseY() - my
			Local pitch#
			'MoveMouse GadgetX(Ui.win) + ClientWidth(Ui.leftPanel)/2, GadgetY(Ui.win) + ClientHeight(Ui.leftPanel)/2
			csMousePosition ClientWidth(Ui.leftPanel)/2, ClientHeight(Ui.leftPanel)/2
			mx = csMouseX(); my = csMouseY()
			If Settings.invMouse Then pitch# = csNodePitch#(cam) + mys Else pitch# = csNodePitch#(cam) - mys
			If pitch# < -80 Then pitch# = -80
			If pitch# > 80 Then pitch# = 80
			csNodeRotate cam, pitch#, csNodeYaw#(cam) + mxs, 0
		End If
		
		'Update camera position
		csNodePosition cam, 0, 0, 0
		csNodeMove cam, 0, 0, -Settings.zoom
		
		'Ambient light
		If Settings.ambLight <> ambLight
			csSceneAmbient Settings.ambLight
			ambLight = Settings.ambLight
		End If

		'Render
		csCameraClearFlags cam, CSCF_BACKBUFFER | CSCF_ZBUFFER, Settings.backColor
		csSceneBegin 'CSCF_BACKBUFFER | CSCF_ZBUFFER, Settings.backColor
		csSceneRender cam
		csSceneEnd
	End Function
	
	Function Finish()
	
	End Function
	
	Function Reset()
		file$ = ""
		SetGadgetText Ui.win, WINTITLE$ + " - <untitled>"
		Particles.Reset
	End Function
	
	Function Load(file$)
		Scene.file$ = file$
		SetGadgetText Ui.win, WINTITLE$ + " - " + file$
		Particles.Load(file$)
	End Function
	
	Function Save(file$)
		If DEMO = 0
			Scene.file$ = file$
			SetGadgetText Ui.win, WINTITLE$ + " - " + file$
			Particles.Save(file$)
		End If
	End Function
	
	Function ParseMaterials()
		Local dir = ReadDir(Settings.path$ + Settings.mat_path$)
		If dir
			Repeat
				Local file$ = NextFile$(dir)
				If file$ = "" Then Exit
				If FileType(Settings.path$ + Settings.mat_path$ + file$) = FILETYPE_FILE And Lower$(ExtractExt$(file$)) = "mat"
					Local mat = csMaterialDataLoad(Settings.path$ + Settings.mat_path$ + file$)
					If mat
						Local name$ = csMaterialDataGetName(mat)
						ListAddLast materials, name$
					End If
				End If
			Forever
			CloseDir dir
		End If
	End Function
End Type