Type scene_t
	Field file$
	Field cam
	Field root
End Type

Function SceneInit()
	csDeviceOpen ClientWidth(Desktop()), ClientHeight(Desktop()), 32, CSDF_STENCILBUFFER, QueryObject(app\ui\leftPanel, 1)
	;csDeviceOpen 640, 480, 32, CSDF_STENCILBUFFER, QueryObject(app\ui\leftPanel, 1)

	app\scene\file$ = "untitled"

	app\scene\cam = csCameraNode(0)

	SceneNew()
End Function

Function SceneLoop()
	csSceneBegin CSCF_BACKBUFFER Or CSCF_ZBUFFER, csGetColor(255, 180, 180, 180)
	csSceneRender app\scene\cam
	csSceneEnd
End Function

Function SceneFinish()

End Function

Function SceneNew()
	;Delete previous scene
	;...

	app\scene\file$ = "untitled"
	SetGadgetText app\ui\win, app\ui\winTitle$ + " - " + app\scene\file$

	app\scene\root = csNodeEmpty(0)
	csNodeSetName app\scene\root, "Scene Root"

	UiUpdateTreeView()
End Function

Function SceneAddObject(ntype, name$, file$, group$, colinfo$, pos$, rot$, scale$, properties$, posmode, otherdata)
	;Get parent
	If group$ = csNodeGetName$(app\scene\root)
		parent = app\scene\root
	Else
		parent = csNodeFindChild(app\scene\root, group$, True)
	End If

	;Get collision info
	Select colinfo$
		Case "none"
			coltype = CSCI_NULL
		Case "box"
			coltype = CSCI_BBOX
		Case "triangles"
			coltype = CSCI_TRIANGLES
		Case "octree"
			coltype = CSCI_OCTREE
	End Select

	;Create node
	Select ntype
		Case CSNT_MESH
			If (otherdata And %0001) = %0001 Then shadows = True
			If (otherdata And %0010) = %0010 Then tangent = True
			mesh = csMeshLoad(app\path$ + file$)
			node = csMeshNode(mesh, parent, colinfo, tangent)
			csMeshFree mesh
			If shadows Then csNodeCastShadow node, True
		Case CSNT_MESH_OCTREE
			If (otherdata And %0001) = %0001 Then shadows = True
			If (otherdata And %0010) = %0010 Then tangent = True
			mesh = csMeshLoad(app\path$ + file$)
			node = csMeshOctreeNode(mesh, parent, colinfo, tangent)
			csMeshFree mesh
			If shadow Then csNodeCastShadow node, True
	End Select
	Select posmode
		Case 1	;In front of camera
			csNodePosition node, csNodeX(app\scene\cam, True), csNodeY(app\scene\cam, True), csNodeZ(app\scene\cam, True)
			csNodeRotate node, csNodePitch(app\scene\cam), csNodeYaw(app\scene\cam), csNodeRoll(app\scene\cam)
			csNodeMove node, 0, 0, 100
		Case 2	;Clone mode
		Case 3	;Specified position
			csNodePosition node, StringField$(pos$, 1), StringField$(pos$, 2), StringField$(pos$, 3)
	End Select
	csNodeRotate node, StringField$(rot$, 1), StringField$(rot$, 2), StringField$(rot$, 3)
	csNodeScale node, StringField$(scale$, 1), StringField$(scale$, 2), StringField$(scale$, 3)

	;Set node data
	csNodeSetName node, name$
	csNodeSetProperty node, "_sceneEd_file$_", file$
	csNodeSetProperty node, "_sceneEd_colinfo$_", colinfo$
	If otherdata = True Then csNodeSetProperty node, "_sceneEd_tangent$_", "true" Else csNodeSetProperty node, "_sceneEd_tangent$_", "false"
	index = 1
	Repeat
		name$ = StringField$(properties$, index, Chr(13)) : If name$ = "" Then Exit
		value$ = StringField$(properties$, index+1, Chr(13))
		csNodeSetProperty node, name$, value$
		index = index + 2
	Forever

	UiUpdateTreeView()
End Function