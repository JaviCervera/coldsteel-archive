Type Scene
	'Name of the scene (used to save file)
	Global file$

	'Store renderer settings (to detect if the ones in the Settings table have changed)
	Global ambLight = -1

	'Mouse look options
	Global freeLook
	Global mx, my

	'Scenes nodes
	Global cam
	Global light
	Global root

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
		
		cam = csCameraNode(0)
		
		light = csLightNode(cam)
		
		root = csNodeEmpty(0)
		
		Reset
	End Function
	
	Function Loop()
		'Resize device when window resizes
		Select EventID()
			Case EVENT_WINDOWSIZE
				csDisplayResize(ClientWidth(Ui.leftPanel), ClientHeight(Ui.leftPanel))
				'csCameraAspectRatio cam, ClientWidth(Ui.leftPanel) * 1.0 / ClientHeight(Ui.leftPanel)
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
		csSceneBegin CSCF_BACKBUFFER | CSCF_ZBUFFER, Settings.backColor
		csSceneRender cam
		csSceneEnd
	End Function
	
	Function Finish()
	
	End Function
	
	Function Reset()
		'Delete previous scene
		csNodeFree root
		
		file$ = ""
		SetGadgetText Ui.win, WINTITLE$ + " - <untitled>"
		
		root = csNodeEmpty(0)
		csNodeSetName root, "Scene Root"
		
		Ui.UpdateTreeView
	End Function
	
	Function Load()
	
	End Function
	
	Function Save()
	
	End Function
	
	Function AddObject()
	
	End Function
End Type