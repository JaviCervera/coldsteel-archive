Function RequestMesh(node = 0)
	Local win:TGadget = CreateWindow("Add Mesh:", GadgetX(Ui.win) + GadgetWidth(Ui.win)/2 - 200, GadgetY(Ui.win) + GadgetHeight(Ui.win)/2 - 200, 400, 400, Ui.win, WINDOW_TITLEBAR | WINDOW_TOOL | WINDOW_CLIENTCOORDS)
	CreateLabel("Name:", 4, 6, 32, 20, win)
		Local nameText:TGadget = CreateTextField(40, 4, ClientWidth(win) - 44, 20, win)
		SetGadgetText nameText, RequestName$("mesh")
	CreateLabel("File:", 4, 30, 20, 20, win)
		Local fileText:TGadget = CreateTextField(28, 28, ClientWidth(win) - 33 - 34, 20, win)
		Local fileButton:TGadget = CreateButton("...", ClientWidth(win) - 33, 28, 30, 20, win)
	CreateLabel("Group:", 4, 52, 34, 20, win)
		Local groupCombo:TGadget = CreateComboBox(40, 50, 200, 20, win)
		Local groupButton:TGadget = CreateButton("Hide non group objects", ClientWidth(win) - 153, 52, 150, 20, win, BUTTON_CHECKBOX); SetButtonState groupButton, True
	Local group:TGadget = CreatePanel(4, 74, GadgetWidth(win) - 12, 40, win, PANEL_GROUP)
		CreateLabel("Mesh type:", 2, 2, 60, 20, group)
		Local typeNormalButton:TGadget = CreateButton("Normal", 100, 0, 100, 20, group, BUTTON_RADIO); SetButtonState typeNormalButton, True
		Local typeOctreeButton:TGadget = CreateButton("Octree", 200, 0, 100, 20, group, BUTTON_RADIO)
	group = CreatePanel(4, 118, GadgetWidth(win) - 12, 40, win, PANEL_GROUP)
		CreateLabel("Collisions:", 2, 2, 60, 20, group)
		Local colNoneButton:TGadget = CreateButton("None", 60, 0, 50, 20, group, BUTTON_RADIO); SetButtonState colNoneButton, True
		Local colBoxButton:TGadget = CreateButton("Box", 110, 0, 50, 20, group, BUTTON_RADIO)
		Local colTrisButton:TGadget = CreateButton("Triangles", 160, 0, 65, 20, group, BUTTON_RADIO)
		Local colOctreeButton:TGadget = CreateButton("Octree", 225, 0, 50, 20, group, BUTTON_RADIO)
	group = CreatePanel(4, 162, GadgetWidth(win) - 12, 144, win, PANEL_GROUP)
		CreateLabel("Position:", 2, 2, 60, 20, group)
		Local posFrontButton:TGadget = CreateButton("In front of camera", 2, 18, 120, 20, group, BUTTON_RADIO); SetButtonState posFrontButton, True
		Local posCloneButton:TGadget = CreateButton("Clone object", 2, 38, 120, 20, group, BUTTON_RADIO)
		Local posSpecifyButton:TGadget = CreateButton("At this position (X Y Z):", 2, 58, 150, 20, group, BUTTON_RADIO)
		Local posSpecifyText:TGadget = CreateTextField(2, 78, GadgetWidth(group) - 8, 20, group); SetGadgetText posSpecifyText, "0.0 0.0 0.0"; DisableGadget posSpecifyText
		Local posOntoGround:TGadget = CreateButton("Put onto ground", 2, 100, 120, 20, group, BUTTON_CHECKBOX)
	CreateLabel("Rotation (Pitch Yaw Roll):", 4, 310, 124, 20, win)
		Local rotationText:TGadget = CreateTextField(130, 308, ClientWidth(win) - 134, 20, win); SetGadgetText rotationText, "0.0 0.0 0.0"
	CreateLabel("Scale (X Y Z):", 4, 332, 66, 20, win)
		Local scaleText:TGadget = CreateTextField(72, 330, ClientWidth(win) - 76, 20, win); SetGadgetText scaleText, "1.0 1.0 1.0"
	Local shadowButton:TGadget = CreateButton("Cast shadows", 4, 352, 120, 20, win, BUTTON_CHECKBOX)
	Local tangentButton:TGadget = CreateButton("Tangent mesh", 4, 372, 120, 20, win, BUTTON_CHECKBOX)
	Local propButton:TGadget = CreateButton("Properties...", ClientWidth(win) - 78 - 103, ClientHeight(win) - 23, 100, 20, win)
	Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
		DisableGadget okButton
	
	'Fill combo box with groups
	Ui.AddGroups(Scene.root, groupCombo, ButtonState(groupButton))
	SelectGadgetItem groupCombo, 0
	
	Local ok = False
	Local properties$
	Repeat
		Select WaitEvent()
			Case EVENT_GADGETACTION
				Select EventSource()
					Case nameText
						If TextFieldText$(nameText) <> "" And TextFieldText$(fileText) <> "" Then EnableGadget okButton Else DisableGadget okButton
					Case fileText
						If TextFieldText$(nameText) <> "" And TextFieldText$(fileText) <> "" Then EnableGadget okButton Else DisableGadget okButton
					Case fileButton
						Local file$ = RequestFile$("Mesh file", "Mesh Files:md2,x,ms3d,my3d;Texture Files:bmp,png,jpg,tga,pcx,psd", False, Settings.path$)
						If FileType(file$) = FILETYPE_FILE Then SetGadgetText fileText, Replace$(Replace$(file$, "\", "/"), Settings.path$, "")
						If TextFieldText$(nameText) <> "" And TextFieldText$(fileText) <> "" Then EnableGadget okButton Else DisableGadget okButton
					Case groupButton
						ClearGadgetItems groupCombo
						Ui.AddGroups(Scene.root, groupCombo, ButtonState(groupButton))
						SelectGadgetItem groupCombo, 0
					Case posFrontButton
						DisableGadget posSpecifyText
					Case posCloneButton
						DisableGadget posSpecifyText
					Case posSpecifyButton
						EnableGadget posSpecifyText
					Case propButton
						'properties$ = RequestProperties$(node, win)
					Case okButton
						ok = True; Exit
				End Select
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then Exit
			Case EVENT_TIMERTICK
				Scene.Loop
		End Select
	Forever
	
	'If 'ok' pressed, create object
	If ok
		Local ntype = CSNT_MESH_OCTREE
		Local colinfo$
		Local posmode
		Local otherdata
		If ButtonState(typeNormalButton) Then ntype = CSNT_MESH
		If ButtonState(colNoneButton)
			colinfo$ = "none"
		Else If ButtonState(colBoxButton)
			colinfo$ = "box"
		Else If ButtonState(colTrisButton)
			colinfo$ = "triangles"
		Else If ButtonState(colOctreeButton)
			colinfo$ = "octree"
		End If
		If ButtonState(posFrontButton)
			posmode = 1
		Else If ButtonState(posCloneButton)
			posmode = 2
		Else If ButtonState(posSpecifyButton)
			posmode = 3
		End If
		If ButtonState(tangentButton) Then otherdata = otherdata Or %0001
		If ButtonState(tangentButton) Then otherdata = otherdata Or %0010
		SceneObject.Add ntype, TextFieldText$(nameText), TextFieldText$(fileText), GadgetItemText$(groupCombo, SelectedGadgetItem(groupCombo)), colinfo$, TextFieldText$(posSpecifyText), TextFieldText$(rotationText), TextFieldText$(scaleText), "properties", posmode, otherdata
	End If

	ActivateWindow Ui.win
	FreeGadget win
End Function

Function RequestName$(basename$)
	Local number = 1
	For Local i = 1 To csNodeChildren(Scene.root)
		Local id = Replace$(csNodeGetName$(csNodeChild(Scene.root, i)), basename$, "").ToInt()
		If id > number Then number = id
	Next
	Return basename$ + StringIntLen$(number, 3)
End Function

