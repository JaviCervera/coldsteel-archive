Type Settings
	'Global settings
	Global path$
	Global mat_path$
	Global part_path$
	Global renderer$
	Global viewToolbar
	Global backColor
	Global ambLight
	Global invMouse
	Global zoom
	
	'MaterialEd settings
	Global meshFile$
	Global meshTangent
	
	Function Init()
		Local element$
		Local xml = csXMLRead(AppDir$ + "/settings.xml")

		'Default settings
		ChangeDir "media"
		path$ = Replace$(CurrentDir$(), "\", "/") + "/"
		ChangeDir ".."
		mat_path$ = "materials/"
		part_path$ = "particles/"
		renderer$ = "Direct3D9"
		viewToolbar = True
		backColor = csGetColor(180, 180, 180, 255)
		ambLight = csGetColor(100, 100, 100, 255)
		invMouse = False
		zoom = 5
		
		'MaterialEd settings
		meshFile$ = "models/cube.x"
		
		'Parse XML settings
		If xml
			While csXMLReadNode(xml)
				If csXMLNodeType(xml) = CSXML_ELEMENT
					If csXMLNodeName(xml) = "common" Then element$ = "common"
					If csXMLNodeName(xml) = "materialEd" Then element$ = "materialEd"
					If csXMLNodeName(xml) = "particleEd" Then element$ = "particleEd"
					If element$ = "common" And csXMLNodeName(xml) = "path" Then csXMLReadNode(xml); path$ = csXMLNodeData$(xml)
					If element$ = "common" And csXMLNodeName(xml) = "materials_path" Then csXMLReadNode(xml); mat_path$ = csXMLNodeData$(xml)
					If element$ = "common" And csXMLNodeName(xml) = "particles_path" Then csXMLReadNode(xml); part_path$ = csXMLNodeData$(xml)
					If element$ = "common" And csXMLNodeName(xml) = "renderer" Then csXMLReadNode(xml); renderer$ = csXMLNodeData$(xml)
					If element$ = "common" And csXMLNodeName(xml) = "view_toolbar" Then csXMLReadNode(xml); If csXMLNodeData$(xml) = "true" Then viewToolbar = True Else viewToolbar = False
					If element$ = "common" And csXMLNodeName(xml) = "background_color" Then csXMLReadNode(xml); backColor = csGetColor(StringField$(csXMLNodeData$(xml), 1, " ").ToInt(), StringField$(csXMLNodeData$(xml), 2, " ").ToInt(), StringField$(csXMLNodeData$(xml), 3, " ").ToInt(), 255)
					If element$ = "common" And csXMLNodeName(xml) = "ambient_light" Then csXMLReadNode(xml); ambLight = csGetColor(StringField$(csXMLNodeData$(xml), 1, " ").ToInt(), StringField$(csXMLNodeData$(xml), 2, " ").ToInt(), StringField$(csXMLNodeData$(xml), 3, " ").ToInt(), 255)
					If element$ = "common" And csXMLNodeName(xml) = "invert_mouse" Then csXMLReadNode(xml); If csXMLNodeData$(xml) = "true" Then invMouse = True Else invMouse = False
					If element$ = "common" And csXMLNodeName(xml) = "zoom" Then csXMLReadNode(xml); zoom = csXMLNodeData(xml).ToInt()
					If element$ = "materialEd" And csXMLNodeName(xml) = "mesh" Then csXMLReadNode(xml); meshFile$ = csXMLNodeData(xml)
					If element$ = "materialEd" And csXMLNodeName(xml) = "mesh_tangent" Then csXMLReadNode(xml); If csXMLNodeData$(xml) = "true" Then meshTangent = True Else meshTangent = False
				End If
			Wend
			csXMLClose xml
		End If
		
		ChangeDir Settings.path$
	End Function

	Function Finish()
		Local xml = csXMLWrite(AppDir$ + "/settings.xml")
		If xml
			csXMLWriteHeader xml
			csXMLWriteElement xml, "settings", "", False; csXMLWriteLineBreak xml
				'Common settings
				csXMLWriteElement xml, "common", "", False; csXMLWriteLineBreak xml
					WriteSetting xml, "path", path$
					WriteSetting xml, "materials_path", mat_path$
					WriteSetting xml, "particles_path", part_path$
					WriteSetting xml, "renderer", renderer$
					If viewToolbar Then WriteSetting xml, "view_toolbar", "true" Else WriteSetting xml, "view_toolbar", "false"
					WriteSetting xml, "background_color", csGetRed(backColor) + " " + csGetGreen(backColor) + " " + csGetBlue(backColor)
					WriteSetting xml, "ambient_light", csGetRed(ambLight) + " " + csGetGreen(ambLight) + " " + csGetBlue(ambLight)
					If invMouse Then WriteSetting xml, "invert_mouse", "true" Else WriteSetting xml, "invert_mouse", "false"
					WriteSetting xml, "zoom", zoom
				csXMLWriteClosingTag xml, "common"; csXMLWriteLineBreak xml

				'Material Editor settings
				csXMLWriteElement xml, "materialEd", "", False; csXMLWriteLineBreak xml
					If meshFile$ <> "" Then WriteSetting xml, "mesh", meshFile$
					If meshTangent Then WriteSetting xml, "mesh_tangent", "true" Else WriteSetting xml, "mesh_tangent", "false"
				csXMLWriteClosingTag xml, "materialEd"; csXMLWriteLineBreak xml
				csXMLWriteClosingTag xml, "settings"
			csXMLClose xml
		End If
	End Function
	
	Function WriteSetting(xml, name$, val$)
		csXMLWriteElement xml, name$, "", False; csXMLWriteLineBreak xml
		csXMLWriteText xml, val$; csXMLWriteLineBreak xml
		csXMLWriteClosingTag xml, name$; csXMLWriteLineBreak xml
	End Function
End Type