Function RequestParticlesMaterial$()
	Local ret$ = Particles.Material$
	Local win:TGadget = CreateWindow("Particles Material:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 200, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 150, 150, 64, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	Local tfield:TGadget = CreateTextField(4, 4, ClientWidth(win) - 8, 20, win); SetGadgetText tfield, Particles.Material$
	Local tcombo:TGadget = CreateComboBox(4, 24, ClientWidth(win) - 8, 20, win)
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
	Local ok = False
	
	'Add material names
	For Local name$ = EachIn Scene.materials
		AddGadgetItem tcombo, name$
	Next
	If CountGadgetItems(tcombo) Then SelectGadgetItem tcombo, 0
	
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				Select EventSource()
					Case tcombo
						SetGadgetText tfield, GadgetItemText$(tcombo, SelectedGadgetItem(tcombo))
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
	If ok Then ret$ = TextFieldText$(tfield)
	ActivateWindow Ui.win
	FreeGadget win
	Return ret$
End Function

Function RequestParticlesType()
	Local ret = Particles.Type_
	Local win:TGadget = CreateWindow("Particles Type:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 75, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 25, 150, 50, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	Local typeCombo:TGadget = CreateComboBox(4, 4, ClientWidth(win) - 4, 20, win)
	AddGadgetItem typeCombo, "Point"
	AddGadgetItem typeCombo, "Box"
	SelectGadgetItem typeCombo, Particles.Type_
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
	If ok Then ret = SelectedGadgetItem(typeCombo)
	ActivateWindow Ui.win
	FreeGadget win
	Return ret
End Function

Function RequestFadeOutAffector:TAffector()
	Local aff:TAffector = New TAffector; aff.Type_ = AFFECTOR_FADEOUT
	Local win:TGadget = CreateWindow("Fade-Out Affector:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 100, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 43, 280, 86, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	Local alphaLabel:TGadget = CreateLabel("Alpha (1.0):", 4, 6, 120, 20, win)
	Local alphaSlider:TGadget = CreateSlider(ClientWidth(win) - 134, 4, 100, 20, win, SLIDER_HORIZONTAL | SLIDER_TRACKBAR); SetSliderRange alphaSlider, 0, 100; SetSliderValue alphaSlider, 100
	CreateLabel("Color:", 4, 28, 50, 20, win)
	Local colorPanel:TGadget = CreatePanel(ClientWidth(win) - 134, 26, 100, 20, win, PANEL_BORDER); SetPanelColor colorPanel, csGetRed(aff.Color), csGetGreen(aff.Color), csGetBlue(aff.Color)
	Local colorButton:TGadget = CreateButton("...", ClientWidth(win) - 32, 26, 30, 20, win)
	CreateLabel("Time:", 4, 50, 50, 20, win)
	Local timeTfield:TGadget = CreateTextField(ClientWidth(win) - 134, 48, 130, 20, win); SetGadgetText timeTField, aff.Time
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
	Local ok = False
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				Select EventSource()
					Case alphaSlider
						SetGadgetText alphaLabel, "Alpha (" + (SliderValue(alphaSlider) / 100.0) + "):"
					Case colorButton
						If RequestColor(csGetRed(aff.Color), csGetGreen(aff.Color), csGetBlue(aff.Color)) Then aff.Color = csGetColor(RequestedRed(), RequestedGreen(), RequestedBlue(), SliderValue(alphaSlider) / 100.0); SetPanelColor colorPanel, csGetRed(aff.Color), csGetGreen(aff.Color), csGetBlue(aff.Color)
					Case timeTfield
						SetGadgetText timeTField, TextFieldText$(timeTField).ToInt()
						aff.Time = TextFieldText$(timeTField).ToInt()
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
	Local ret:TAffector = Null
	If ok Then ret = aff
	ActivateWindow Ui.win
	FreeGadget win
	Return ret
End Function

Function RequestGravityAffector:TAffector()
	Local aff:TAffector = New TAffector; aff.Type_ = AFFECTOR_GRAVITY
	Local win:TGadget = CreateWindow("Gravity Affector:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 150, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 32, 300, 64, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	CreateLabel("Gravity (X Y Z):", 4, 6, 80, 20, win)
	Local gravTfield:TGadget = CreateTextField(ClientWidth(win) - 204, 4, 200, 20, win); SetGadgetText gravTField, aff.Grav#[0] + " " + aff.Grav#[1] + " " + aff.Grav#[2]
	CreateLabel("Time:", 4, 28, 50, 20, win)
	Local timeTfield:TGadget = CreateTextField(ClientWidth(win) - 204, 26, 300, 20, win); SetGadgetText timeTField, aff.Time
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
	Local ok = False
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				Select EventSource()
					Case gravTfield
						aff.Grav#[0] = StringField$(TextFieldText$(gravTfield), 1, " ").ToFloat()
						aff.Grav#[1] = StringField$(TextFieldText$(gravTfield), 2, " ").ToFloat()
						aff.Grav#[2] = StringField$(TextFieldText$(gravTfield), 3, " ").ToFloat()
					Case timeTfield
						SetGadgetText timeTField, TextFieldText$(timeTField).ToInt()
						aff.Time = TextFieldText$(timeTField).ToInt()
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
	Local ret:TAffector = Null
	If ok Then ret = aff
	ActivateWindow Ui.win
	FreeGadget win
	Return ret
End Function

Rem
Function RequestParticlesOptions$(state, panel:TGadget)
	Global matPathTField:TGadget
	Global matPathButton:TGadget
	Select state
		Case REQUESTER_NAME
			Return "ParticleEd"
		Case REQUESTER_INIT
			CreateLabel("Material path:", 4, 4, 100, 20, panel)
			matPathTField = CreateTextField(4, 24, ClientWidth(panel) - 38, 20, panel)
			SetGadgetText matPathTField, Settings.mat_path$
			matPathButton = CreateButton("...", ClientWidth(panel) - 32, 24, 30, 20, panel)
		Case REQUESTER_EVENT
			If EventID() = EVENT_GADGETACTION And EventSource() = matPathButton
				Local dir$ = RequestDir$("Mesh file", Settings.path$ + Settings.mat_path$)
				If dir$ <> "" Then SetGadgetText matPathTField, Replace$(Replace$(dir$, "\", "/"), Settings.path$, "") + "/"
			End If
		Case REQUESTER_OK
			If Settings.mat_path$ <> TextFieldText$(matPathTField) Then Notify "Material Path has changed. Restart the program to apply changes."
			Settings.mat_path$ = TextFieldText$(matPathTField)
			matPathTField = Null
			matPathButton = Null
		Case REQUESTER_CANCEL
			matPathTField = Null
			matPathButton = Null
	End Select
End Function
End Rem