Const MAT_NAME = 0
Const MAT_TYPE = 1
Const MAT_FLAGS = 2
Const MAT_TEX0 = 3
Const MAT_TEX1 = 4
Const MAT_AMBIENT = 5
Const MAT_DIFFUSE = 6
Const MAT_EMISSIVE = 7
Const MAT_SPECULAR = 8
Const MAT_SHININESS = 9
Const MAT_PARAM = 10

Type Material
	Global Name$
	Global Type_
	Global Flags
	Global Tex$[2]
	Global Ambient
	Global Diffuse
	Global Emissive
	Global Specular
	Global Shininess#
	Global Param#
	Global TexHandle[2]
	
	Function Reset()
		Name$ = ""
		Type_ = CSMT_MODULATE
		Flags = 0
		Tex$[0] = ""
		Tex$[1] = ""
		Ambient = csGetColor(255, 255, 255, 0)
		Diffuse = csGetColor(255, 255, 255, 0)
		Emissive = csGetColor(0, 0, 0, 0)
		Specular = csGetColor(255, 255, 255, 0)
		Shininess# = 0.0
		Param# = 0.0
		Update
	End Function
	
	Function Update()
		If TexHandle[0] Then csTextureFree TexHandle[0]; TexHandle[0] = 0
		If TexHandle[1] Then csTextureFree TexHandle[1]; TexHandle[1] = 0
		If Tex$[0] <> "" Then TexHandle[0] = csTextureLoad(Settings.path$ + Tex$[0], True)
		If Tex$[1] <> "" Then TexHandle[1] = csTextureLoad(Settings.path$ + Tex$[1], True)

		Local mat = csMaterialCreate(Name)
		csMaterialSetType mat, Type_
		csMaterialSetFlags mat, Flags
		csMaterialSetTexture mat, TexHandle[0], 0
		csMaterialSetTexture mat, TexHandle[1], 1
		csMaterialSetAmbient mat, Ambient
		csMaterialSetDiffuse mat, Diffuse
		csMaterialSetEmissive mat, Emissive
		csMaterialSetSpecular mat, Specular
		csMaterialSetShininess mat, Shininess#
		csMaterialSetParam mat, Param#

		csNodeSetMaterial Scene.node, mat, 0

		csMaterialFree mat

		Ui.UpdateListBox()
	End Function
	
	Function Load(file$)
		Local dir$ = CurrentDir$()
		ChangeDir Settings.path$
		Local mat = csMaterialLoad(file$)
		If Not mat Then Notify "Could not load '" + file$ + "'", True; Return
		Name$ = csMaterialGetName$(mat)
		Type_ = csMaterialGetType(mat)
		Flags = csMaterialGetFlags(mat)
		If csMaterialGetTexture(mat, 0) Then Tex$[0] = csTextureFile$(csMaterialGetTexture(mat, 0))
		If csMaterialGetTexture(mat, 1) Then Tex$[1] = csTextureFile$(csMaterialGetTexture(mat, 1))
		Ambient = csMaterialGetAmbient(mat)
		Diffuse = csMaterialGetDiffuse(mat)
		Emissive = csMaterialGetEmissive(mat)
		Specular = csMaterialGetSpecular(mat)
		Shininess# = csMaterialGetShininess(mat)
		Param# = csMaterialGetParam#(mat)
		csMaterialFree mat
		ChangeDir dir$
		Update()
	End Function
	
	Function Save(file$)
		Local mat = csMaterialCreate(Name)
		csMaterialSetType mat, Type_
		csMaterialSetFlags mat, Flags
		csMaterialSetTexture mat, TexHandle[0], 0
		csMaterialSetTexture mat, TexHandle[1], 1
		csMaterialSetAmbient mat, Ambient
		csMaterialSetDiffuse mat, Diffuse
		csMaterialSetEmissive mat, Emissive
		csMaterialSetSpecular mat, Specular
		csMaterialSetShininess mat, Shininess#
		csMaterialSetParam mat, Param#
		csMaterialSave mat, file$, Settings.path$
		csMaterialFree mat
	End Function
End Type