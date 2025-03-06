Const AFFECTOR_FADEOUT =	0
Const AFFECTOR_GRAVITY =	1

Type TAffector
	Field Type_
	Field Color
	Field Time
	Field Grav#[3]
	
	Method New()
		Time = 1000
		Grav#[1] = -0.03
	End Method
End Type

Const PART_NAME = 0
Const PART_MATERIAL = 1
Const PART_TYPE = 2
Const PART_BOX = 3
Const PART_DIRECTION = 4
Const PART_RATE = 5
Const PART_MINCOLOR = 6
Const PART_MAXCOLOR = 7
Const PART_LIFETIME = 8
Const PART_MAXANGLE = 9
Const PART_SIZE = 10

Type Particles
	Global Name$
	Global Material$
	Global Type_
	Global Box#[3]
	Global Direction#[3]
	Global Rate[2]
	Global MinColor
	Global MaxColor
	Global LifeTime[2]
	Global MaxAngle
	Global Size#[2]
	Global fadeoutAffectors:TList = CreateList()
	Global gravityAffectors:TList = CreateList()

	Function Reset()
		Name$ = ""
		Material$ = ""
		Type_ = CSPT_POINT
		Box# = [1.0, 1.0, 1.0]
		Direction# = [0.0, 1.0, 0.0]
		Rate = [1, 10]
		MinColor = csGetColor(0, 0, 0, 255)
		MaxColor = csGetColor(255, 255, 255, 255)
		LifeTime = [1000, 5000]
		MaxAngle = 0
		Size# = [1.0, 1.0]
		Update
	End Function
	
	Function Update()
		'Create particle data
		Local pdata = csParticleDataCreate(Name$)
		csParticleDataSetMaterial pdata, Material$
		csParticleDataSetType pdata, Type_
		csParticleDataSetBox pdata, Box#[0], Box#[1], Box#[2]
		csParticleDataSetDirection pdata, Direction#[0], Direction#[1], Direction#[2]
		csParticleDataSetRate pdata, Rate[0], Rate[1]
		csParticleDataSetColor pdata, MinColor, MaxColor
		csParticleDataSetLifeTime pdata, LifeTime[0], LifeTime[1]
		csParticleDataSetMaxAngle pdata, MaxAngle
		csParticleDataSetSize pdata, Size#[0], Size#[1]
		
		'Add affectors
		For Local aff:TAffector = EachIn fadeoutAffectors
			csParticleDataAddFadeOutAffector pdata, aff.Color, aff.Time
		Next
		For Local aff:TAffector = EachIn gravityAffectors
			csParticleDataAddGravityAffector pdata, aff.Grav#[0], aff.Grav#[1], aff.Grav#[2], aff.Time
		Next

		'Create emitter
		csCoreMessage Scene.node, false
		csNodeFree Scene.node
		Scene.node = csEmitterNode(pdata, 0)
	
		'Free particle data
		csParticleDataFree pdata
		
		Ui.UpdateListBox
	End Function
	
	Function Load(file$)
		Local dir$ = CurrentDir$()
		ChangeDir Settings.path$
		Local pdata = csParticleDataLoad(file$)
		If Not pdata Then Notify "Could not load '" + file + "'", True; Return
		Name$ = csParticleDataGetName$(pdata)
		Material$ = csParticleDataGetMaterial$(pdata)
		Type_ = csParticleDataGetType(pdata)
		Box# = [csParticleDataGetBoxWidth#(pdata), csParticleDataGetBoxHeight#(pdata), csParticleDataGetBoxDepth#(pdata)]
		Direction# = [csParticleDataGetDirectionX#(pdata), csParticleDataGetDirectionY#(pdata), csParticleDataGetDirectionZ#(pdata)]
		Rate = [csParticleDataGetMinRate(pdata), csParticleDataGetMaxRate(pdata)]
		MinColor = csParticleDataGetMinColor(pdata)
		MaxColor = csParticleDataGetMaxColor(pdata)
		LifeTime = [csParticleDataGetMinLifeTime(pdata), csParticleDataGetMaxLifeTime(pdata)]
		MaxAngle = csParticleDataGetMaxAngle(pdata)
		Size# = [csParticleDataGetWidth#(pdata), csParticleDataGetHeight#(pdata)]
		ClearList fadeoutAffectors; ClearList gravityAffectors
		For Local i = 1 To csParticleDataAffectors(pdata)
			Local aff:TAffector = New TAffector
			aff.Type_ = csParticleDataGetAffectorType(pdata, i)
			aff.Color = csParticleDataGetAffectorColor(pdata, i)
			aff.Time = csParticleDataGetAffectorTime(pdata, i)
			aff.Grav# = [csParticleDataGetAffectorGravityX#(pdata, i), csParticleDataGetAffectorGravityY#(pdata, i), csParticleDataGetAffectorGravityZ#(pdata, i)]
			If aff.Type_ = AFFECTOR_FADEOUT Then ListAddLast fadeoutAffectors, aff
			If aff.Type_ = AFFECTOR_GRAVITY Then ListAddLast gravityAffectors, aff
		Next
		csParticleDataFree pdata
		ChangeDir dir$
		Update
	End Function
	
	Function Save(file$)
		'Create particle data
		Local pdata = csParticleDataCreate(Name$)
		csParticleDataSetMaterial pdata, Material$
		csParticleDataSetType pdata, Type_
		csParticleDataSetBox pdata, Box#[0], Box#[1], Box#[2]
		csParticleDataSetDirection pdata, Direction#[0], Direction#[1], Direction#[2]
		csParticleDataSetRate pdata, Rate[0], Rate[1]
		csParticleDataSetColor pdata, MinColor, MaxColor
		csParticleDataSetLifeTime pdata, LifeTime[0], LifeTime[1]
		csParticleDataSetMaxAngle pdata, MaxAngle
		csParticleDataSetSize pdata, Size#[0], Size#[1]
		
		'Add affectors
		For Local aff:TAffector = EachIn fadeoutAffectors
			csParticleDataAddFadeOutAffector pdata, aff.Color, aff.Time
		Next
		For Local aff:TAffector = EachIn gravityAffectors
			csParticleDataAddGravityAffector pdata, aff.Grav#[0], aff.Grav#[1], aff.Grav#[2], aff.Time
		Next
		
		'Save particle data
		csParticleDataSave pdata, file$

		'Free particle data		
		csParticleDataFree pdata
	End Function
	
	Function AddAffector(aff:TAffector)
		If aff = Null Then Return
		If aff.Type_ = AFFECTOR_FADEOUT Then ListAddLast fadeoutAffectors, aff
		If aff.Type_ = AFFECTOR_GRAVITY Then ListAddLast gravityAffectors, aff
		Update
	End Function
	
	Function RemoveFadeOutAffector(index)
		If index = -1 Then Return
		ListRemove fadeoutAffectors, fadeoutAffectors.ValueAtIndex(index)
		Update
	End Function
	
	Function RemoveGravityAffector(index)
		If index = -1 Then Return
		ListRemove gravityAffectors, gravityAffectors.ValueAtIndex(index)
		Update
	End Function
End Type