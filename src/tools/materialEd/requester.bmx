Function RequestMaterialType()
	Local ret = Material.Type_
	Local win:TGadget = CreateWindow("Material Type:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 75, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 25, 150, 50, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	Local typeCombo:TGadget = CreateComboBox(4, 4, ClientWidth(win) - 4, 20, win)
	AddGadgetItem typeCombo, "Modulate"
	AddGadgetItem typeCombo, "Modulate 2X"
	AddGadgetItem typeCombo, "Modulate 4X"
	AddGadgetItem typeCombo, "Detail mapped"
	AddGadgetItem typeCombo, "Add"
	AddGadgetItem typeCombo, "Vertex Alpha"
	AddGadgetItem typeCombo, "Alpha"
	AddGadgetItem typeCombo, "Masked"
	AddGadgetItem typeCombo, "Reflection"
	AddGadgetItem typeCombo, "Reflection Alpha"
	AddGadgetItem typeCombo, "Normal Mapped"
	AddGadgetItem typeCombo, "Parallax Mapped"
	SelectGadgetItem typeCombo, ret - 1
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
	If ok Then ret = SelectedGadgetItem(typeCombo) + 1
	ActivateWindow Ui.win
	FreeGadget win
	Return ret
End Function

Function RequestMaterialFlags()
	Local ret = Material.Flags
	Local win:TGadget = CreateWindow("Material Flags:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 100, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 95, 200, 190, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	Local fullbrightFlag:TGadget = CreateButton("Fullbright", 4, 4, 200, 20, win, BUTTON_CHECKBOX)
	Local flatShadedFlag:TGadget = CreateButton("Flat-shaded", 4, 24, 200, 20, win, BUTTON_CHECKBOX)
	Local fogFlag:TGadget = CreateButton("Fog", 4, 44, 200, 20, win, BUTTON_CHECKBOX)
	Local noCullFlag:TGadget = CreateButton("No Cull", 4, 64, 200, 20, win, BUTTON_CHECKBOX)
	Local wireframeFlag:TGadget = CreateButton("Wireframe", 4, 84, 200, 20, win, BUTTON_CHECKBOX)
	Local noZDepthFlag:TGadget = CreateButton("No Z-Depth", 4, 104, 200, 20, win, BUTTON_CHECKBOX)
	Local noZWriteFlag:TGadget = CreateButton("No Z-Write", 4, 124, 200, 20, win, BUTTON_CHECKBOX)
	Local anisoFlag:TGadget = CreateButton("Anisotropic", 4, 144, 200, 20, win, BUTTON_CHECKBOX)
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)

	'Fill flags
	If (Material.Flags & CSMF_FULLBRIGHT) = CSMF_FULLBRIGHT Then SetButtonState fullbrightFlag, True
	If (Material.Flags & CSMF_FLATSHADING) = CSMF_FLATSHADING Then SetButtonState flatShadedFlag, True
	If (Material.Flags & CSMF_FOG) = CSMF_FOG Then SetButtonState fogFlag, True
	If (Material.Flags & CSMF_NOCULL) = CSMF_NOCULL Then SetButtonState noCullFlag, True
	If (Material.Flags & CSMF_WIREFRAME) = CSMF_WIREFRAME Then SetButtonState wireframeFlag, True
	If (Material.Flags & CSMF_NOZDEPTH) = CSMF_NOZDEPTH Then SetButtonState noZDepthFlag, True
	If (Material.Flags & CSMF_NOZWRITE) = CSMF_NOZWRITE Then SetButtonState noZWriteFlag, True
	If (Material.Flags & CSMF_ANISOTROPIC) = CSMF_ANISOTROPIC Then SetButtonState anisoFlag, True

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
		ret = 0
		If ButtonState(fullbrightFlag) Then ret :| CSMF_FULLBRIGHT
		If ButtonState(flatShadedFlag) Then ret :| CSMF_FLATSHADING
		If ButtonState(fogFlag) Then ret :| CSMF_FOG
		If ButtonState(noCullFlag) Then ret :| CSMF_NOCULL
		If ButtonState(wireframeFlag) Then ret :| CSMF_WIREFRAME
		If ButtonState(noZDepthFlag) Then ret :| CSMF_NOZDEPTH
		If ButtonState(noZWriteFlag) Then ret :| CSMF_NOZWRITE
		If ButtonState(anisoFlag) Then ret :| CSMF_ANISOTROPIC
	End If
	ActivateWindow Ui.win
	FreeGadget win
	Return ret
End Function

Function RequestMaterialOptions$(state, panel:TGadget)
	Global meshTField:TGadget
	Global meshButton:TGadget
	Global tangentButton:TGadget
	Select state
		Case REQUESTER_NAME
			Return "MaterialEd"
		Case REQUESTER_INIT
			CreateLabel("Mesh:", 4, 4, 100, 20, panel)
			meshTField = CreateTextField(4, 24, ClientWidth(panel) - 38, 20, panel)
			SetGadgetText meshTField, Settings.meshFile$
			meshButton = CreateButton("...", ClientWidth(panel) - 32, 24, 30, 20, panel)
			tangentButton = CreateButton("Tangent mesh", ClientWidth(panel) - 100, 48, 100, 20, panel, BUTTON_CHECKBOX)
			If Settings.meshTangent Then SetButtonState tangentButton, True
		Case REQUESTER_EVENT
			If EventID() = EVENT_GADGETACTION And EventSource() = meshButton
				Local file$ = RequestFile$("Mesh file", "Mesh Files:b3d,md2,ms3d,x", False, Settings.path$)
				If file$ <> "" And FileType(file$) = FILETYPE_FILE Then SetGadgetText meshTField, Replace$(Replace$(file$, "\", "/"), Settings.path$, "")
			End If
		Case REQUESTER_OK
			Settings.meshFile$ = TextFieldText$(meshTField)
			Settings.meshTangent = ButtonState(tangentButton)
			meshTField = Null
			meshButton = Null
			tangentButton = Null
		Case REQUESTER_CANCEL
			meshTField = Null
			meshButton = Null
			tangentButton = Null
	End Select
End Function