Type Scene
	'Name of the scene (used to save file)
	Global file$

	'Store renderer settings (to detect if the ones in the Settings table have changed)
	Global meshFile$
	Global ambLight = -1

	'Mouse look options
	Global freeLook
	Global mx, my

	'Scenes nodes
	Global cam
	Global light
	Global node

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
		
		'Load mesh
		If Settings.meshFile$ <> meshFile$
			Local mesh = csMeshLoad(Settings.path$ + Settings.meshFile$)
			If mesh
				csMeshVerticesColor mesh, csGetColor(255, 255, 255, 128), True
				csNodeFree Scene.node
				node = csMeshNode(mesh, False, CSCI_NULL, Settings.meshTangent)
				csMeshFree mesh
				meshFile$ = Settings.meshFile$
				Material.Update
			End If
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
		Material.Reset()
	End Function
	
	Function Load(file$)
		Scene.file$ = file$
		SetGadgetText Ui.win, WINTITLE$ + " - " + file$
		Material.Load(file$)
	End Function
	
	Function Save(file$)
		If DEMO = 0
			Scene.file$ = file$
			SetGadgetText Ui.win, WINTITLE$ + " - " + file$
			Material.Save(file$)
		End If
	End Function
End Type