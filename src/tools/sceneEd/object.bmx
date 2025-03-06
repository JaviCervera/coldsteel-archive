Type SceneObject
	Function Add(ntype, name$, file$, group$, colinfo$, pos$, rot$, scale$, properties$, posmode, otherdata)
		'Get parent
		Local parent
		If group$ = csNodeGetName$(Scene.root)
			parent = Scene.root
		Else
			parent = csNodeFindChild(Scene.root, group$, True)
		End If

		'Get collision info
		Local coltype
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

		'Create node
		Local node
		Select ntype
			Case CSNT_MESH
				Local shadows
				Local tangent
				If (otherdata And %0001) = %0001 Then shadows = True
				If (otherdata And %0010) = %0010 Then tangent = True
				Local mesh = csMeshLoad(Settings.path$ + file$)
				node = csMeshNode(mesh, parent, coltype, tangent)
				csMeshFree mesh
				If shadows Then csNodeCastShadow node, True
			Case CSNT_MESH_OCTREE
				Local shadows
				Local tangent
				If (otherdata And %0001) = %0001 Then shadows = True
				If (otherdata And %0010) = %0010 Then tangent = True
				Local mesh = csMeshLoad(Settings.path$ + file$)
				node = csMeshOctreeNode(mesh, parent, coltype, tangent)
				csMeshFree mesh
				If shadows Then csNodeCastShadow node, True
		End Select
		Select posmode
			Case 1	'In front of camera
				csNodePosition node, csNodeX(Scene.cam, True), csNodeY(Scene.cam, True), csNodeZ(Scene.cam, True)
				csNodeRotate node, csNodePitch(Scene.cam), csNodeYaw(Scene.cam), csNodeRoll(Scene.cam)
				csNodeMove node, 0, 0, 100
			Case 2	'Clone mode
			Case 3	'Specified position
				csNodePosition node, StringField$(pos$, 1).ToFloat(), StringField$(pos$, 2).ToFloat(), StringField$(pos$, 3).ToFloat()
		End Select
		csNodeRotate node, StringField$(rot$, 1).ToFloat(), StringField$(rot$, 2).ToFloat(), StringField$(rot$, 3).ToFloat()
		csNodeScale node, StringField$(scale$, 1).ToFloat(), StringField$(scale$, 2).ToFloat(), StringField$(scale$, 3).ToFloat()

		'Set node data
		csNodeSetName node, name$
		csNodeSetProperty node, "_sceneEd_file$_", file$
		csNodeSetProperty node, "_sceneEd_colinfo$_", colinfo$
		If otherdata = True Then csNodeSetProperty node, "_sceneEd_tangent$_", "true" Else csNodeSetProperty node, "_sceneEd_tangent$_", "false"
		Local index = 1
		Repeat
			Local name$ = StringField$(properties$, index, Chr(13)); If name$ = "" Then Exit
			Local value$ = StringField$(properties$, index+1, Chr(13))
			csNodeSetProperty node, name$, value$
			index :+ 2
		Forever

		Ui.UpdateTreeView()
	End Function
End Type
