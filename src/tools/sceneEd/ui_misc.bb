Function UiUpdateTreeView()
	FreeGadget app\ui\treeView
	app\ui\treeView = CreateTreeView(ClientWidth(app\ui\win) - 196, 24, 192, ClientHeight(app\ui\win) - 52, app\ui\win)
	SetGadgetLayout app\ui\treeView, 0, 1, 1, 1
	UiAddTreeViewNodes app\scene\root, TreeViewRoot(app\ui\treeView)
End Function

Function UiAddTreeViewNodes(node, parent)
	parent = AddTreeViewNode(csNodeGetName$(node), parent)
	For i = 1 To csNodeChildren(node)
		UiAddTreeViewNodes csNodeChild(node, i), parent
	Next
End Function

Function UiClosePressed()
	Select Proceed("Save before exit?")
		Case 0	;No
			app\quit = 1
		Case 1	;Yes
			app\quit = 1
	End Select
End Function

Function UiAddGroups(node, gadget, hideNonGroups)
	;Add current node
	If hideNonGroups = 1 And csNodeType(node) = NT_EMPTY
		AddGadgetItem gadget, csNodeGetName$(node)
	Else If hideNonGroups = 0
		AddGadgetItem gadget, csNodeGetName$(node)
	End If

	;Add child nodes
	For i = 1 To csNodeChildren(node)
		UiAddGroups csNodeChild(node, i), gadget, hideNonGroups
	Next
End Function

Function UiFindName$(basename$)
	number = 1
	For i = 1 To csNodeChildren(app\scene\root)
		id = Int(Replace$(csNodeGetName$(csNodeChild(app\scene\root, i)), basename$, ""))
		If id > number Then number = id
	Next
	Return basename$ + StringIntLen$(number, 3)
End Function