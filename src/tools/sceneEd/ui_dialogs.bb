Function UiAddMeshDialog(node)
	;Create window
	win = CreateWindow("Add Mesh...", GadgetX(app\ui\win) + GadgetWidth(app\ui\win)/2 - 200, GadgetY(app\ui\win) + GadgetHeight(app\ui\win)/2 - 155, 400, 330, app\ui\win, 1+16+32)
	CreateLabel("Name:", 4, 6, 32, 20, win)
		nameText = CreateTextField(40, 6, ClientWidth(win) - 44, 20, win)
		SetGadgetText nameText, UiFindName$("mesh")
	CreateLabel("File:", 4, 30, 20, 20, win)
		fileText = CreateTextField(28, 28, ClientWidth(win) - 33 - 34, 20, win)
		fileButton = CreateButton("...", ClientWidth(win) - 33, 28, 30, 20, win)
	CreateLabel("Group:", 4, 52, 34, 20, win)
		groupCombo = CreateComboBox(40, 50, 200, 20, win)
		groupButton = CreateButton("Hide non group objects", ClientWidth(win) - 153, 52, 150, 20, win, 2) : SetButtonState groupButton, True
	group = CreatePanel(4, 74, GadgetWidth(win) - 12, 20, win, 1)
		CreateLabel("Mesh type:", 2, 2, 60, 20, group)
		typeNormalButton = CreateButton("Normal", 100, 0, 100, 20, group, 3) : SetButtonState typeNormalButton, True
		typeOctreeButton = CreateButton("Octree", 200, 0, 100, 20, group, 3)
	group = CreatePanel(4, 98, GadgetWidth(win) - 12, 20, win, 1)
		CreateLabel("Collisions:", 2, 2, 60, 20, group)
		colNoneButton = CreateButton("None", 60, 0, 50, 20, group, 3) : SetButtonState colNoneButton, True
		colBoxButton = CreateButton("Box", 110, 0, 50, 20, group, 3)
		colTrisButton = CreateButton("Triangles", 160, 0, 65, 20, group, 3)
		colOctreeButton = CreateButton("Octree", 225, 0, 50, 20, group, 3)
	group = CreatePanel(4, 122, GadgetWidth(win) - 12, 124, win, 1)
		CreateLabel("Position:", 2, 2, 60, 20, group)
		posFrontButton = CreateButton("In front of camera", 2, 18, 120, 20, group, 3) : SetButtonState posFrontButton, True
		posCloneButton = CreateButton("Clone object", 2, 38, 120, 20, group, 3)
		posSpecifyButton = CreateButton("At this position (X Y Z):", 2, 58, 150, 20, group, 3)
		posSpecifyText = CreateTextField(2, 78, GadgetWidth(group) - 8, 20, group) : SetGadgetText posSpecifyText, "0.0 0.0 0.0" : DisableGadget posSpecifyText
		posOntoGround = CreateButton("Put onto ground", 2, 100, 120, 20, group, 2)
	CreateLabel("Rotation (Pitch Yaw Roll):", 4, 250, 124, 20, win)
		rotationText = CreateTextField(130, 248, ClientWidth(win) - 134, 20, win)
		SetGadgetText rotationText, "0.0 0.0 0.0"
	CreateLabel("Scale (X Y Z):", 4, 272, 66, 20, win)
		scaleText = CreateTextField(72, 270, ClientWidth(win) - 76, 20, win)
		SetGadgetText scaleText, "1.0 1.0 1.0"
	shadowButton = CreateButton("Cast shadows", 4, 292, 120, 20, win, 2)
	tangentButton = CreateButton("Tangent mesh", 4, 312, 120, 20, win, 2)
	propButton = CreateButton("Properties...", ClientWidth(win) - 78 - 103, ClientHeight(win) - 23, 100, 20, win)
	okButton = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
		DisableGadget okButton

	;Fill combo box with groups
	UiAddGroups(app\scene\root, groupCombo, ButtonState(groupButton))
	SelectGadgetItem groupCombo, 0

	Repeat
		Select WaitEvent()
			Case $401	;Gadget action
				Select EventSource()
					Case nameText
						If TextFieldText$(nameText) <> "" And TextFieldText$(fileText) <> "" Then EnableGadget okButton Else DisableGadget okButton
					Case fileText
						If TextFieldText$(nameText) <> "" And TextFieldText$(fileText) <> "" Then EnableGadget okButton Else DisableGadget okButton
					Case fileButton
						file$ = RequestFile$("Mesh file", "md2;*.x;*.ms3d;*.my3d,bmp;*.png;*.jpg;*.tga;*.pcx;*.psd", False, app\path$ + "file...")
						If file$ <> "" And FileType(file$) = 1 Then SetGadgetText fileText,Replace$(Replace$(file$, app\path$, ""), "\", "/")
						If TextFieldText$(nameText) <> "" And TextFieldText$(fileText) <> "" Then EnableGadget okButton Else DisableGadget okButton
					Case groupButton
						ClearGadgetItems groupCombo
						UiAddGroups(app\scene\root, groupCombo, ButtonState(groupButton))
						SelectGadgetItem groupCombo, 0
					Case posFrontButton
						DisableGadget posSpecifyText
					Case posCloneButton
						DisableGadget posSpecifyText
					Case posSpecifyButton
						EnableGadget posSpecifyText
					Case propButton
						properties$ = UiNodePropertiesDialog$(node, win)
					Case okButton
						ok = True
						Exit
				End Select
			Case $803	;Close window
				If EventSource() = win Then Exit
			Case $4001	;Timer tick
				SceneLoop()
		End Select
	Forever

	;If 'Ok' pressed, create object
	If ok
		If ButtonState(typeNormalButton) Then ntype = CSNT_MESH Else ntype = CSNT_MESH_OCTREE
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
		SceneAddObject ntype, TextFieldText$(nameText), TextFieldText$(fileText), GadgetItemText$(groupCombo, SelectedGadgetItem(groupCombo)), colinfo$, TextFieldText$(posSpecifyText), TextFieldText$(rotationText), TextFieldText$(scaleText), "properties", posmode, otherdata
	End If

	ActivateWindow app\ui\win
	FreeGadget win
End Function

Function UiNodePropertiesDialog$(node, parentwin)
	;Get old properties list, to return in case of cancel
	If node
		For i = 1 To csNodeProperties(node)
			properties$ = properties$ + csNodePropertyName$(node, i) + Chr(13) + csNodePropertyValue$(node, i) + Chr(13)
		Next
	End If

	;Create window
	win = CreateWindow("Node Properties...", GadgetX(app\ui\win) + GadgetWidth(app\ui\win)/2 - 150, GadgetY(app\ui\win) + GadgetHeight(app\ui\win)/2 - 125, 300, 250, parentwin, 1+16+32)
	CreateLabel("Name:", 4, 4, 100, 20, win)
	nameList = CreateListBox(4, 24, ClientWidth(win)/2 - 4, ClientHeight(win) - 52, win)
	CreateLabel("Value:", ClientWidth(win)/2 + 2, 4, 100, 20, win)
	valueList = CreateListBox(ClientWidth(win)/2 + 2, 24, ClientWidth(win)/2 - 4, ClientHeight(win) - 52, win)
	okButton = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)

	;Fill name-value pairs
	If node
		For i = 1 To csNodeProperties(node)
			AddGadgetItem nameList, csNodePropertyName$(node, i)
			AddGadgetItem valueList, csNodePropertyValue$(node, i)
		Next
	End If
	AddGadgetItem nameList, ""
	AddGadgetItem valueList, ""

	Repeat
		Select WaitEvent()
			Case $401	;Gadget action
				Select EventSource()
					Case nameList
						If GadgetItemText$(nameList, SelectedGadgetItem(nameList)) = ""
							prop$ = UiAddPropertyDialog$("Add Property...", "", "", win)
							If StringField$(prop$, 1, Chr(13)) <> ""
								ModifyGadgetItem nameList, SelectedGadgetItem(nameList), StringField$(prop$, 1, Chr(13))
								ModifyGadgetItem valueList, SelectedGadgetItem(nameList), StringField$(prop$, 2, Chr(13))
								AddGadgetItem nameList, ""
								AddGadgetItem valueList, ""
							End If
						Else
							prop$ = UiAddPropertyDialog$("Change Property...", GadgetItemText$(nameList, SelectedGadgetItem(nameList)), GadgetItemText$(valueList, SelectedGadgetItem(nameList)), win)
							If StringField$(prop$, 1, Chr(13)) <> ""
								ModifyGadgetItem nameList, SelectedGadgetItem(nameList), StringField$(prop$, 1, Chr(13))
								ModifyGadgetItem valueList, SelectedGadgetItem(nameList), StringField$(prop$, 2, Chr(13))
							End If
						End If
					Case okButton
						ok = True
						Exit
				End Select
			Case $803	;Close window
				If EventSource() = win Then Exit
			Case $4001	;Timer tick
				SceneLoop()
		End Select
	Forever

	;Update properties list
	If ok
		properties$ = ""
		For i = 0 To CountGadgetItems(nameList) - 2
			properties$ = properties$ + GadgetItemText$(nameList, i) + Chr(13) + GadgetItemText$(valueList, i) + Chr(13)
		Next
	End If

	ActivateWindow parentwin
	FreeGadget win

	Return properties$
End Function

Function UiAddPropertyDialog$(title$, name$, value$, parentwin)
	property$ = name$ + Chr(13) + value$
	win = CreateWindow(title$, GadgetX(app\ui\win) + GadgetWidth(app\ui\win)/2 - 100, GadgetY(app\ui\win) + GadgetHeight(app\ui\win)/2 - 60, 200, 120, parentwin, 1+16+32)
	CreateLabel("Name:", 4, 4, 100, 20, win)
		nameText = CreateTextField(4, 24, ClientWidth(win) - 8, 20, win)
		SetGadgetText nameText, name$
	CreateLabel("Value:", 4, 52, 100, 20, win)
		valueText = CreateTextField(4, 72, ClientWidth(win) - 8, 20, win)
		SetGadgetText valueText, value$
	okButton = CreateButton("Ok", ClientWidth(win) - 78, ClientHeight(win) - 23, 75, 20, win)
	Repeat
		Select WaitEvent()
			Case $401	;Gadget action
				Select EventSource()
					Case okButton
						ok = True
						Exit
				End Select
			Case $803	;Close window
				If EventSource() = win Then Exit
			Case $4001	;Timer tick
				SceneLoop()
		End Select
	Forever
	If ok Then property$ = TextFieldText$(nameText) + Chr(13) + TextFieldText$(valueText)
	ActivateWindow parentwin
	FreeGadget win
	Return property$
End Function