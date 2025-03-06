Const REQUESTER_NAME = 0
Const REQUESTER_INIT = 1
Const REQUESTER_EVENT = 2
Const REQUESTER_OK = 3
Const REQUESTER_CANCEL = 4

Function RequestInput$(msg$, deftext$ = "", parent:TGadget = Null)
	Local ret$ = ""
	Local win:TGadget = CreateWindow(AppTitle$, ClientWidth(Desktop())/2 - 150, ClientHeight(Desktop())/2 - 43, 300, 86, parent, WINDOW_TITLEBAR | WINDOW_CLIENTCOORDS | WINDOW_HIDDEN)
	CreateLabel(msg$, 4, 4, ClientWidth(win) - 8, 24, win)
	Local tfield:TGadget = CreateTextField(4, 28, ClientWidth(win) - 8, 24, win)
	SetGadgetText tfield, deftext$
	Local okbutton:TGadget = CreateButton("Ok", ClientWidth(win) - 104, ClientHeight(win) - 28, 100, 24, win, BUTTON_OK)
	ActivateGadget tfield
	ShowGadget win
	Local ok = False
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				If EventSource() = okbutton Then ok = True; Exit
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then Exit
		End Select
	Forever
	If ok Then ret$ = TextFieldText$(tfield)
	FreeGadget win
	Return ret$
End Function

Function RequestOptions(callback:String(state, panel:TGadget) = Null)
	Local backColor = Settings.backColor
	Local ambLight = Settings.ambLight
	Local panel:TGadget[3]

	Local win:TGadget = CreateWindow("Options:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 200, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 75, 400, 150, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)

	Local tabber:TGadget = CreateTabber(0, 0, ClientWidth(win), ClientHeight(win) - 26, win)
	AddGadgetItem tabber, "General"
	AddGadgetItem tabber, "Renderer"
	If callback <> Null Then Local title$ = callback(REQUESTER_NAME, Null); AddGadgetItem tabber, title$
	
	'General tab
	panel[0] = CreatePanel(0, 0, ClientWidth(tabber), ClientHeight(tabber), tabber)
	CreateLabel("Path:", 4, 6, 45, 20, panel[0])
	Local pathTField:TGadget = CreateTextField(50, 4, ClientWidth(panel[0]) - 88, 20, panel[0]); SetGadgetText pathTField, Settings.path$
	Local pathButton:TGadget = CreateButton("...", ClientWidth(panel[0]) - 32, 4, 30, 20, panel[0])
	CreateLabel("Materials:", 4, 28, 45, 20, panel[0])
	Local matpathTField:TGadget = CreateTextField(50, 26, ClientWidth(panel[0]) - 88, 20, panel[0]); SetGadgetText matpathTField, Settings.mat_path$
	Local matpathButton:TGadget = CreateButton("...", ClientWidth(panel[0]) - 32, 26, 30, 20, panel[0])
	CreateLabel("Particles:", 4, 50, 45, 20, panel[0])
	Local partpathTField:TGadget = CreateTextField(50, 48, ClientWidth(panel[0]) - 88, 20, panel[0]); SetGadgetText partpathTField, Settings.part_path$
	Local partpathButton:TGadget = CreateButton("...", ClientWidth(panel[0]) - 32, 48, 30, 20, panel[0])


	Local viewToolbarButton:TGadget = CreateButton("View toolbar", 4, 76, 100, 20, panel[0], BUTTON_CHECKBOX)
	SetButtonState viewToolbarButton, Settings.viewToolbar
	
	'Renderer tab
	panel[1] = CreatePanel(0, 0, ClientWidth(tabber), ClientHeight(tabber), tabber)
	CreateLabel("Renderer:", 4, 6, 100, 20, panel[1])
	Local renderCombo:TGadget = CreateComboBox(104, 4, ClientWidth(panel[1]) - 108, 20, panel[1])
	AddGadgetItem renderCombo, "Direct3D9"
	AddGadgetItem renderCombo, "OpenGL"
	'AddGadgetItem renderCombo, "Software"
	Select Settings.renderer$
		Case "Direct3D9"
			SelectGadgetItem renderCombo, 0
		Case "OpenGL"
			SelectGadgetItem renderCombo, 1
		Case "Software"
			SelectGadgetItem renderCombo, 2
	End Select
	CreateLabel("Background color:", 4, 32, 100, 20, panel[1])
	Local backPanel:TGadget = CreatePanel(104, 30, ClientWidth(panel[1]) - 140, 20, panel[1], PANEL_BORDER); SetPanelColor backPanel, csGetRed(backColor), csGetGreen(backColor), csGetBlue(backColor)
	Local backButton:TGadget = CreateButton("...", ClientWidth(panel[1]) - 32, 30, 30, 20, panel[1])
	CreateLabel("Ambient light:", 4, 56, 100, 20, panel[1])
	Local ambLightPanel:TGadget = CreatePanel(104, 54, ClientWidth(panel[1]) - 140, 20, panel[1], PANEL_BORDER); SetPanelColor ambLightPanel, csGetRed(ambLight), csGetGreen(ambLight), csGetBlue(ambLight)
	Local ambLightButton:TGadget = CreateButton("...", ClientWidth(panel[1]) - 32, 54, 30, 20, panel[1])
	Local invMouseButton:TGadget = CreateButton("Invert mouse", 4, 78, 100, 20, panel[1], BUTTON_CHECKBOX)
	SetButtonState invMouseButton, Settings.invMouse
	HideGadget panel[1]
	
	'Program tab
	panel[2] = CreatePanel(0, 0, ClientWidth(tabber), ClientHeight(tabber), tabber)
	If callback <> Null Then callback(REQUESTER_INIT, panel[2])
	HideGadget panel[2]
	
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)

	Local ok = False
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				Select EventSource()
					Case tabber
						For Local i = 0 Until CountGadgetItems(tabber)
							If i = SelectedGadgetItem(tabber) Then ShowGadget panel[i] Else HideGadget panel[i]
						Next
					Case pathButton
						Local dir$ = RequestDir$("Working folder:", TextFieldText$(pathTField))
						If dir$ <> "" Then SetGadgetText pathTField, Replace$(dir$, "\", "/") + "/"
					Case matpathButton
						Local dir$ = RequestDir$("Materials folder:", TextFieldText$(matpathTField))
						If dir$ <> "" Then SetGadgetText matpathTField, Replace$(Replace$(dir$, "\", "/") + "/", TextFieldText$(pathTField), "")
					Case partpathButton
						Local dir$ = RequestDir$("Particles folder:", TextFieldText$(partpathTField))
						If dir$ <> "" Then SetGadgetText partpathTField, Replace$(Replace$(dir$, "\", "/") + "/", TextFieldText$(pathTField), "")
					Case backButton
						If RequestColor(csGetRed(backColor), csGetGreen(backColor), csGetBlue(backColor)) Then backColor = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255); SetPanelColor backPanel, csGetRed(backColor), csGetGreen(backColor), csGetBlue(backColor)
					Case ambLightButton
						If RequestColor(csGetRed(ambLight), csGetGreen(ambLight), csGetBlue(ambLight)) Then ambLight = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), 255); SetPanelColor ambLightPanel, csGetRed(ambLight), csGetGreen(ambLight), csGetBlue(ambLight)
					Case okButton
						ok = True
						Exit
				End Select
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then Exit
			Case EVENT_TIMERTICK
				Scene.Loop
		End Select
		If callback <> Null Then callback(REQUESTER_EVENT, panel[2])
	Forever
	Local oldrenderer$ = Settings.renderer$
	If ok
		Settings.path$ = TextFieldText$(pathTField)
		Settings.mat_path$ = TextFieldText$(matpathTField)
		Settings.part_path$ = TextFieldText$(partpathTField)
		Select SelectedGadgetItem(renderCombo)
			Case 0
				Settings.renderer$ = "Direct3D9"
			Case 1
				Settings.renderer$ = "OpenGL"
			Case 2
				Settings.renderer$ = "Software"
		End Select
		Settings.backColor = backColor
		Settings.ambLight = ambLight
		If Settings.viewToolbar <> ButtonState(viewToolbarButton) Then EmitEvent CreateEvent(EVENT_MENUACTION, Null, MENU_VIEWTOOLBAR)
		If Settings.invMouse <> ButtonState(invMouseButton) Then EmitEvent CreateEvent(EVENT_MENUACTION, Null, MENU_INVMOUSE)
		If callback <> Null Then callback(REQUESTER_OK, panel[2])
		ChangeDir Settings.path$
	Else
		If callback <> Null Then callback(REQUESTER_CANCEL, panel[2])
	End If
	ActivateWindow Ui.win
	FreeGadget win
	If Settings.renderer$ <> oldrenderer$ Then Notify "Render has changed. Restart the program to apply changes."
End Function

Function RequesterTemplate()
	Local ret = 0	'Initial Return value
	Local win:TGadget = CreateWindow("Window:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 200, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 150, 400, 300, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
	Local ok = False
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				Select EventSource()
					Case okButton
						ok = True
						Exit
				End Select
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then Exit
			Case EVENT_TIMERTICK
				Scene.Loop
		End Select
	Forever
	If ok
		ret = 0	'Final Return value
	End If
	ActivateWindow Ui.win
	FreeGadget win
	Return ret
End Function