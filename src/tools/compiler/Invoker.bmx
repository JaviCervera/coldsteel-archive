Const BVM_MAIN_CMD_SET_DEF_$ = ".set ~qcoldsteel~q~n"+..
	"Function BillboardHeight<csBillboardHeight>#(%)~n"+..
	"Function BillboardNode<csBillboardNode>%(%)~n"+..
	"Function BillboardResize<csBillboardResize>(%,#,#)~n"+..
	"Function BillboardWidth<csBillboardWidth>#(%)~n"+..
	"Function CameraAspectRatio<csCameraAspectRatio>(%,#)~n"+..
	"Function CameraClearFlags<csCameraClearFlags>(%,%,%)~n"+..
	"Function CameraFov<csCameraFov>(%,#)~n"+..
	"Function CameraLine<csCameraLine>(%,%,%,%,%)~n"+..
	"Function CameraNode<csCameraNode>%(%)~n"+..
	"Function CameraPickNode<csCameraPickNode>%(%,%,%,%)~n"+..
	"Function CameraProjection<csCameraProjection>(%,#,#,#,#,%)~n"+..
	"Function CameraRange<csCameraRange>(%,#,#)~n"+..
	"Function CameraRenderTarget<csCameraRenderTarget>(%,%)~n"+..
	"Function CameraToScreen<csCameraToScreen>(%,#,#,#,%)~n"+..
	"Function CameraViewport<csCameraViewport>(%,#,#,#,#)~n"+..
	"Function ChannelFinished<csChannelFinished>%(%)~n"+..
	"Function ChannelGetMaxDistance<csChannelGetMaxDistance>#(%)~n"+..
	"Function ChannelGetMinDistance<csChannelGetMinDistance>#(%)~n"+..
	"Function ChannelGetPan<csChannelGetPan>#(%)~n"+..
	"Function ChannelGetPlayPosition<csChannelGetPlayPosition>%(%)~n"+..
	"Function ChannelGetVolume<csChannelGetVolume>#(%)~n"+..
	"Function ChannelLooped<csChannelLooped>%(%)~n"+..
	"Function ChannelPause<csChannelPause>(%)~n"+..
	"Function ChannelPaused<csChannelPaused>%(%)~n"+..
	"Function ChannelResume<csChannelResume>(%)~n"+..
	"Function ChannelSetDistance<csChannelSetDistance>(%,#,#)~n"+..
	"Function ChannelSetPan<csChannelSetPan>(%,#)~n"+..
	"Function ChannelSetPosition<csChannelSetPosition>(%,#,#,#)~n"+..
	"Function ChannelSetVolume<csChannelSetVolume>(%,#)~n"+..
	"Function ChannelStop<csChannelStop>(%)~n"+..
	"Function ChannelX<csChannelX>#(%)~n"+..
	"Function ChannelY<csChannelY>#(%)~n"+..
	"Function ChannelZ<csChannelZ>#(%)~n"+..
	"Function CollisionLineNode<csCollisionLineNode>%(#,#,#,#,#,#)~n"+..
	"Function CollisionLinePick<csCollisionLinePick>%(%,#,#,#,#,#,#,%,%,%,%)~n"+..
	"Function CollisionSlide<csCollisionSlide>(%,#,#,#,#,#,#,#,#,#,%,%,%,%)~n"+..
	"Function CoreFinish<csCoreFinish>()~n"+..
	"Function CoreInit<csCoreInit>()~n"+..
	"Function CoreMessage<csCoreMessage>($,%)~n"+..
	"Function CoreTimer<csCoreTimer>%()~n"+..
	"Function DirClose<csDirClose>(%)~n"+..
	"Function DirFileCount<csDirFileCount>%(%)~n"+..
	"Function DirFileIsDir<csDirFileIsDir>%(%,%)~n"+..
	"Function DirFileName<csDirFileName>$(%,%)~n"+..
	"Function DirList<csDirList>%($)~n"+..
	"Function DisplayActive<csDisplayActive>%()~n"+..
	"Function DisplayCaption<csDisplayCaption>($)~n"+..
	"Function DisplayClose<csDisplayClose>()~n"+..
	"Function DisplayClosed<csDisplayClosed>%()~n"+..
	"Function DisplayFeature<csDisplayFeature>%(%)~n"+..
	"Function DisplayFps<csDisplayFps>%()~n"+..
	"Function DisplayHeight<csDisplayHeight>%()~n"+..
	"Function DisplayOpen<csDisplayOpen>(%,%,%,%,%)~n"+..
	"Function DisplayResize<csDisplayResize>(%,%)~n"+..
	"Function DisplayScreenshot<csDisplayScreenshot>($)~n"+..
	"Function DisplayWidth<csDisplayWidth>%()~n"+..
	"Function DrawLine<csDrawLine>(%,%,%,%)~n"+..
	"Function DrawRect<csDrawRect>(%,%,%,%)~n"+..
	"Function DrawText<csDrawText>(%,$,%,%)~n"+..
	"Function DrawTexture<csDrawTexture>(%,%,%)~n"+..
	"Function EffectRegister<csEffectRegister>%($,%)~n"+..
	"Function EffectRegisterFile<csEffectRegisterFile>%($,%)~n"+..
	"Function EffectSetBool<csEffectSetBool>(%,$,%)~n"+..
	"Function EffectSetFloat<csEffectSetFloat>(%,$,#)~n"+..
	"Function EffectSetInt<csEffectSetInt>(%,$,%)~n"+..
	"Function EffectSetMatrix<csEffectSetMatrix>(%,$,%)~n"+..
	"Function EffectSetTechnique<csEffectSetTechnique>(%,$)~n"+..
	"Function EffectSetTexture<csEffectSetTexture>(%,$,%)~n"+..
	"Function EffectSetVector<csEffectSetVector>(%,$,%)~n"+..
	"Function EmitterAddFadeOutAffector<csEmitterAddFadeOutAffector>(%,%,%)~n"+..
	"Function EmitterAddGravityAffector<csEmitterAddGravityAffector>(%,#,#,#,%)~n"+..
	"Function EmitterNode<csEmitterNode>%(%,%)~n"+..
	"Function EmitterRemoveAffectors<csEmitterRemoveAffectors>(%)~n"+..
	"Function EventA<csEventA>#()~n"+..
	"Function EventB<csEventB>#()~n"+..
	"Function EventC<csEventC>#()~n"+..
	"Function EventData<csEventData>$()~n"+..
	"Function EventFrom<csEventFrom>%()~n"+..
	"Function EventGet<csEventGet>%()~n"+..
	"Function EventId<csEventId>%()~n"+..
	"Function EventPoll<csEventPoll>%()~n"+..
	"Function EventPost<csEventPost>(%,%,%,#,#,#,$)~n"+..
	"Function EventTo<csEventTo>%()~n"+..
	"Function FileClose<csFileClose>(%)~n"+..
	"Function FileGetDir<csFileGetDir>$($)~n"+..
	"Function FileGetExt<csFileGetExt>$($)~n"+..
	"Function FilePos<csFilePos>%(%)~n"+..
	"Function FileRead<csFileRead>%($)~n"+..
	"Function FileReadByte<csFileReadByte>%(%)~n"+..
	"Function FileReadBytes<csFileReadBytes>(%,%,%)~n"+..
	"Function FileReadFloat<csFileReadFloat>#(%)~n"+..
	"Function FileReadInt<csFileReadInt>%(%)~n"+..
	"Function FileReadShort<csFileReadShort>%(%)~n"+..
	"Function FileReadString<csFileReadString>$(%)~n"+..
	"Function FileSeek<csFileSeek>(%,%,%)~n"+..
	"Function FileSize<csFileSize>%(%)~n"+..
	"Function FileStripDir<csFileStripDir>$($)~n"+..
	"Function FileStripExt<csFileStripExt>$($)~n"+..
	"Function FileWrite<csFileWrite>%($)~n"+..
	"Function FileWriteByte<csFileWriteByte>(%,%)~n"+..
	"Function FileWriteBytes<csFileWriteBytes>(%,%,%)~n"+..
	"Function FileWriteFloat<csFileWriteFloat>(%,#)~n"+..
	"Function FileWriteInt<csFileWriteInt>(%,%)~n"+..
	"Function FileWriteShort<csFileWriteShort>(%,%)~n"+..
	"Function FileWriteString<csFileWriteString>(%,$)~n"+..
	"Function FontFree<csFontFree>(%)~n"+..
	"Function FontLoad<csFontLoad>%($)~n"+..
	"Function GadgetAddItem<csGadgetAddItem>%(%,$,%)~n"+..
	"Function GadgetChild<csGadgetChild>%(%,%)~n"+..
	"Function GadgetChildren<csGadgetChildren>%(%)~n"+..
	"Function GadgetCountItems<csGadgetCountItems>%(%)~n"+..
	"Function GadgetEnable<csGadgetEnable>(%,%)~n"+..
	"Function GadgetEnableItem<csGadgetEnableItem>(%,%,%)~n"+..
	"Function GadgetFree<csGadgetFree>(%)~n"+..
	"Function GadgetGetItemId<csGadgetGetItemId>%(%,%)~n"+..
	"Function GadgetGetItemText<csGadgetGetItemText>$(%,%)~n"+..
	"Function GadgetGetState<csGadgetGetState>%(%)~n"+..
	"Function GadgetGetText<csGadgetGetText>$(%)~n"+..
	"Function GadgetParent<csGadgetParent>%(%)~n"+..
	"Function GadgetRemoveItem<csGadgetRemoveItem>(%,%)~n"+..
	"Function GadgetRemoveItems<csGadgetRemoveItems>(%)~n"+..
	"Function GadgetSelectedItem<csGadgetSelectedItem>%(%)~n"+..
	"Function GadgetSelectItem<csGadgetSelectItem>(%,%)~n"+..
	"Function GadgetSetColor<csGadgetSetColor>(%,%,%)~n"+..
	"Function GadgetSetFont<csGadgetSetFont>(%,%)~n"+..
	"Function GadgetSetImage<csGadgetSetImage>(%,%,%,%,%,%,%)~n"+..
	"Function GadgetSetItemText<csGadgetSetItemText>(%,%,$)~n"+..
	"Function GadgetSetState<csGadgetSetState>(%,%)~n"+..
	"Function GadgetSetText<csGadgetSetText>(%,$)~n"+..
	"Function GadgetShape<csGadgetShape>(%,%,%,%,%)~n"+..
	"Function GadgetType<csGadgetType>%(%)~n"+..
	"Function GadgetVisible<csGadgetVisible>(%,%)~n"+..
	"Function GetAlpha<csGetAlpha>%(%)~n"+..
	"Function GetBlue<csGetBlue>%(%)~n"+..
	"Function GetColor<csGetColor>%(%,%,%,%)~n"+..
	"Function GetGreen<csGetGreen>%(%)~n"+..
	"Function GetRed<csGetRed>%(%)~n"+..
	"Function GuiButton<csGuiButton>%(%,%,%,%,%)~n"+..
	"Function GuiCheckBox<csGuiCheckBox>%(%,%,%,%,%)~n"+..
	"Function GuiComboBox<csGuiComboBox>%(%,%,%,%,%)~n"+..
	"Function GuiContextMenu<csGuiContextMenu>%(%,%,%,%,%)~n"+..
	"Function GuiDraw<csGuiDraw>()~n"+..
	"Function GuiEditBox<csGuiEditBox>%(%,%,%,%,%,%,%)~n"+..
	"Function GuiGroup<csGuiGroup>%(%,%,%,%,%)~n"+..
	"Function GuiListBox<csGuiListBox>%(%,%,%,%,%,%)~n"+..
	"Function GuiMenu<csGuiMenu>%(%)~n"+..
	"Function GuiMessageBox<csGuiMessageBox>%(%,$,$,%)~n"+..
	"Function GuiScrollBar<csGuiScrollBar>%(%,%,%,%,%,%,%,%)~n"+..
	"Function GuiTabber<csGuiTabber>%(%,%,%,%,%,%)~n"+..
	"Function GuiText<csGuiText>%(%,%,%,%,%,%)~n"+..
	"Function GuiTexture<csGuiTexture>%(%,%,%,%,%)~n"+..
	"Function GuiToolbar<csGuiToolbar>%(%)~n"+..
	"Function GuiWindow<csGuiWindow>%(%,%,%,%,%,%)~n"+..
	"Function JoyAxis<csJoyAxis>#(%,%)~n"+..
	"Function JoyButton<csJoyButton>%(%,%)~n"+..
	"Function JoyName<csJoyName>$(%)~n"+..
	"Function JoyNumAxes<csJoyNumAxes>%(%)~n"+..
	"Function KeyDown<csKeyDown>%(%)~n"+..
	"Function KeyGet<csKeyGet>%()~n"+..
	"Function KeyHit<csKeyHit>%(%)~n"+..
	"Function KeyReleased<csKeyReleased>%()~n"+..
	"Function LightAmbient<csLightAmbient>(%,%)~n"+..
	"Function LightDiffuse<csLightDiffuse>(%,%)~n"+..
	"Function LightNode<csLightNode>%(%)~n"+..
	"Function LightRadius<csLightRadius>(%,#)~n"+..
	"Function LightSpecular<csLightSpecular>(%,%)~n"+..
	"Function LightType<csLightType>(%,%)~n"+..
	"Function ListenerUpdate<csListenerUpdate>(%)~n"+..
	"Function MaterialCreate<csMaterialCreate>%($)~n"+..
	"Function MaterialFind<csMaterialFind>%($)~n"+..
	"Function MaterialFree<csMaterialFree>(%)~n"+..
	"Function MaterialGetAmbient<csMaterialGetAmbient>%(%)~n"+..
	"Function MaterialGetDiffuse<csMaterialGetDiffuse>%(%)~n"+..
	"Function MaterialGetEmissive<csMaterialGetEmissive>%(%)~n"+..
	"Function MaterialGetFlags<csMaterialGetFlags>%(%)~n"+..
	"Function MaterialGetName<csMaterialGetName>$(%)~n"+..
	"Function MaterialGetParam<csMaterialGetParam>#(%)~n"+..
	"Function MaterialGetShininess<csMaterialGetShininess>#(%)~n"+..
	"Function MaterialGetSpecular<csMaterialGetSpecular>%(%)~n"+..
	"Function MaterialGetTexture<csMaterialGetTexture>%(%,%)~n"+..
	"Function MaterialGetType<csMaterialGetType>%(%)~n"+..
	"Function MaterialLoad<csMaterialLoad>%($)~n"+..
	"Function MaterialSave<csMaterialSave>(%,$,$)~n"+..
	"Function MaterialSetAmbient<csMaterialSetAmbient>(%,%)~n"+..
	"Function MaterialSetDiffuse<csMaterialSetDiffuse>(%,%)~n"+..
	"Function MaterialSetEmissive<csMaterialSetEmissive>(%,%)~n"+..
	"Function MaterialSetFlags<csMaterialSetFlags>(%,%)~n"+..
	"Function MaterialSetParam<csMaterialSetParam>(%,#)~n"+..
	"Function MaterialSetShininess<csMaterialSetShininess>(%,#)~n"+..
	"Function MaterialSetSpecular<csMaterialSetSpecular>(%,%)~n"+..
	"Function MaterialSetTexture<csMaterialSetTexture>(%,%,%)~n"+..
	"Function MaterialSetType<csMaterialSetType>(%,%)~n"+..
	"Function MathAbs<csMathAbs>#(#)~n"+..
	"Function MathACos<csMathACos>#(#)~n"+..
	"Function MathASin<csMathASin>#(#)~n"+..
	"Function MathATan<csMathATan>#(#)~n"+..
	"Function MathATan2<csMathATan2>#(#,#)~n"+..
	"Function MathCeil<csMathCeil>#(#)~n"+..
	"Function MathCos<csMathCos>#(#)~n"+..
	"Function MathExp<csMathExp>#(#)~n"+..
	"Function MathFloor<csMathFloor>#(#)~n"+..
	"Function MathLog<csMathLog>#(#)~n"+..
	"Function MathLog10<csMathLog10>#(#)~n"+..
	"Function MathRand<csMathRand>%(%,%)~n"+..
	"Function MathRandSeed<csMathRandSeed>(%)~n"+..
	"Function MathSin<csMathSin>#(#)~n"+..
	"Function MathSqr<csMathSqr>#(#)~n"+..
	"Function MathTan<csMathTan>#(#)~n"+..
	"Function MatrixAdd<csMatrixAdd>(%,%)~n"+..
	"Function MatrixCopy<csMatrixCopy>(%,%)~n"+..
	"Function MatrixCreate<csMatrixCreate>%()~n"+..
	"Function MatrixDiv<csMatrixDiv>(%,%)~n"+..
	"Function MatrixElement<csMatrixElement>#(%,%,%)~n"+..
	"Function MatrixEqual<csMatrixEqual>%(%,%)~n"+..
	"Function MatrixFree<csMatrixFree>(%)~n"+..
	"Function MatrixGetRotation<csMatrixGetRotation>(%,%)~n"+..
	"Function MatrixGetTranslation<csMatrixGetTranslation>(%,%)~n"+..
	"Function MatrixIdentity<csMatrixIdentity>(%)~n"+..
	"Function MatrixInterpolate<csMatrixInterpolate>(%,%,#)~n"+..
	"Function MatrixInvert<csMatrixInvert>%(%)~n"+..
	"Function MatrixMul<csMatrixMul>(%,%)~n"+..
	"Function MatrixSet<csMatrixSet>(%,%,%,#)~n"+..
	"Function MatrixSetRotation<csMatrixSetRotation>(%,%)~n"+..
	"Function MatrixSetScale<csMatrixSetScale>(%,%)~n"+..
	"Function MatrixSetTranslation<csMatrixSetTranslation>(%,%)~n"+..
	"Function MatrixSub<csMatrixSub>(%,%)~n"+..
	"Function MatrixTranspose<csMatrixTranspose>(%)~n"+..
	"Function MeshDepth<csMeshDepth>#(%)~n"+..
	"Function MeshFlip<csMeshFlip>(%)~n"+..
	"Function MeshFree<csMeshFree>(%)~n"+..
	"Function MeshHeight<csMeshHeight>#(%)~n"+..
	"Function MeshLoad<csMeshLoad>%($)~n"+..
	"Function MeshNode<csMeshNode>%(%,%,%,%)~n"+..
	"Function MeshOctreeNode<csMeshOctreeNode>%(%,%,%,%)~n"+..
	"Function MeshPlanarMapping<csMeshPlanarMapping>(%,#)~n"+..
	"Function MeshScale<csMeshScale>(%,#,#,#)~n"+..
	"Function MeshTerrainLoad<csMeshTerrainLoad>%($)~n"+..
	"Function MeshUpdateNormals<csMeshUpdateNormals>(%)~n"+..
	"Function MeshVerticesColor<csMeshVerticesColor>(%,%,%)~n"+..
	"Function MeshWidth<csMeshWidth>#(%)~n"+..
	"Function MouseDown<csMouseDown>%(%)~n"+..
	"Function MouseGet<csMouseGet>%()~n"+..
	"Function MouseHide<csMouseHide>(%)~n"+..
	"Function MouseHit<csMouseHit>%(%)~n"+..
	"Function MousePosition<csMousePosition>(%,%)~n"+..
	"Function MouseReleased<csMouseReleased>%()~n"+..
	"Function MouseX<csMouseX>%()~n"+..
	"Function MouseY<csMouseY>%()~n"+..
	"Function NodeAttachToBone<csNodeAttachToBone>(%,%,$)~n"+..
	"Function NodeCastShadow<csNodeCastShadow>(%,%)~n"+..
	"Function NodeChild<csNodeChild>%(%,%)~n"+..
	"Function NodeChildren<csNodeChildren>%(%)~n"+..
	"Function NodeDepth<csNodeDepth>#(%)~n"+..
	"Function NodeEmpty<csNodeEmpty>%(%)~n"+..
	"Function NodeFindChild<csNodeFindChild>%(%,$,%)~n"+..
	"Function NodeFindProperty<csNodeFindProperty>%(%,$)~n"+..
	"Function NodeFree<csNodeFree>(%)~n"+..
	"Function NodeGetFrame<csNodeGetFrame>%(%)~n"+..
	"Function NodeGetMaterial<csNodeGetMaterial>%(%,%)~n"+..
	"Function NodeGetName<csNodeGetName>$(%)~n"+..
	"Function NodeGetParent<csNodeGetParent>%(%)~n"+..
	"Function NodeHeight<csNodeHeight>#(%)~n"+..
	"Function NodeHide<csNodeHide>(%,%)~n"+..
	"Function NodeLookAt<csNodeLookAt>(%,#,#,#)~n"+..
	"Function NodeLoop<csNodeLoop>(%,%)~n"+..
	"Function NodeMaterials<csNodeMaterials>%(%)~n"+..
	"Function NodeMove<csNodeMove>(%,#,#,#)~n"+..
	"Function NodePitch<csNodePitch>#(%)~n"+..
	"Function NodePosition<csNodePosition>(%,#,#,#)~n"+..
	"Function NodeProperties<csNodeProperties>%(%)~n"+..
	"Function NodePropertyName<csNodePropertyName>$(%,%)~n"+..
	"Function NodePropertyValue<csNodePropertyValue>$(%,%)~n"+..
	"Function NodeRemoveProperty<csNodeRemoveProperty>(%,%)~n"+..
	"Function NodeRoll<csNodeRoll>#(%)~n"+..
	"Function NodeRotate<csNodeRotate>(%,#,#,#)~n"+..
	"Function NodeScale<csNodeScale>(%,#,#,#)~n"+..
	"Function NodeScaleX<csNodeScaleX>#(%)~n"+..
	"Function NodeScaleY<csNodeScaleY>#(%)~n"+..
	"Function NodeScaleZ<csNodeScaleZ>#(%)~n"+..
	"Function NodeSetFrame<csNodeSetFrame>(%,%,%)~n"+..
	"Function NodeSetMaterial<csNodeSetMaterial>(%,%,%)~n"+..
	"Function NodeSetMaterialFast<csNodeSetMaterialFast>(%,%,%,%,%,%)~n"+..
	"Function NodeSetMaterialFlag<csNodeSetMaterialFlag>(%,%,%,%)~n"+..
	"Function NodeSetName<csNodeSetName>(%,$)~n"+..
	"Function NodeSetParent<csNodeSetParent>(%,%)~n"+..
	"Function NodeSetPickGroup<csNodeSetPickGroup>(%,%)~n"+..
	"Function NodeSetProperty<csNodeSetProperty>(%,$,$)~n"+..
	"Function NodeSpeed<csNodeSpeed>(%,#)~n"+..
	"Function NodeTurn<csNodeTurn>(%,#,#,#)~n"+..
	"Function NodeType<csNodeType>%(%)~n"+..
	"Function NodeWidth<csNodeWidth>#(%)~n"+..
	"Function NodeX<csNodeX>#(%,%)~n"+..
	"Function NodeY<csNodeY>#(%,%)~n"+..
	"Function NodeYaw<csNodeYaw>#(%)~n"+..
	"Function NodeZ<csNodeZ>#(%,%)~n"+..
	"Function PackageAdd<csPackageAdd>($)~n"+..
	"Function ParticleDataAddFadeOutAffector<csParticleDataAddFadeOutAffector>(%,%,%)~n"+..
	"Function ParticleDataAddGravityAffector<csParticleDataAddGravityAffector>(%,#,#,#,%)~n"+..
	"Function ParticleDataAffectors<csParticleDataAffectors>%(%)~n"+..
	"Function ParticleDataCreate<csParticleDataCreate>%($)~n"+..
	"Function ParticleDataFind<csParticleDataFind>%($)~n"+..
	"Function ParticleDataFree<csParticleDataFree>(%)~n"+..
	"Function ParticleDataGetAffectorColor<csParticleDataGetAffectorColor>%(%,%)~n"+..
	"Function ParticleDataGetAffectorGravityX<csParticleDataGetAffectorGravityX>#(%,%)~n"+..
	"Function ParticleDataGetAffectorGravityY<csParticleDataGetAffectorGravityY>#(%,%)~n"+..
	"Function ParticleDataGetAffectorGravityZ<csParticleDataGetAffectorGravityZ>#(%,%)~n"+..
	"Function ParticleDataGetAffectorTime<csParticleDataGetAffectorTime>%(%,%)~n"+..
	"Function ParticleDataGetAffectorType<csParticleDataGetAffectorType>%(%,%)~n"+..
	"Function ParticleDataGetBoxDepth<csParticleDataGetBoxDepth>#(%)~n"+..
	"Function ParticleDataGetBoxHeight<csParticleDataGetBoxHeight>#(%)~n"+..
	"Function ParticleDataGetBoxWidth<csParticleDataGetBoxWidth>#(%)~n"+..
	"Function ParticleDataGetDirectionX<csParticleDataGetDirectionX>#(%)~n"+..
	"Function ParticleDataGetDirectionY<csParticleDataGetDirectionY>#(%)~n"+..
	"Function ParticleDataGetDirectionZ<csParticleDataGetDirectionZ>#(%)~n"+..
	"Function ParticleDataGetHeight<csParticleDataGetHeight>#(%)~n"+..
	"Function ParticleDataGetMaterial<csParticleDataGetMaterial>$(%)~n"+..
	"Function ParticleDataGetMaxAngle<csParticleDataGetMaxAngle>%(%)~n"+..
	"Function ParticleDataGetMaxColor<csParticleDataGetMaxColor>%(%)~n"+..
	"Function ParticleDataGetMaxLifeTime<csParticleDataGetMaxLifeTime>%(%)~n"+..
	"Function ParticleDataGetMaxRate<csParticleDataGetMaxRate>%(%)~n"+..
	"Function ParticleDataGetMinColor<csParticleDataGetMinColor>%(%)~n"+..
	"Function ParticleDataGetMinLifeTime<csParticleDataGetMinLifeTime>%(%)~n"+..
	"Function ParticleDataGetMinRate<csParticleDataGetMinRate>%(%)~n"+..
	"Function ParticleDataGetName<csParticleDataGetName>$(%)~n"+..
	"Function ParticleDataGetType<csParticleDataGetType>%(%)~n"+..
	"Function ParticleDataGetWidth<csParticleDataGetWidth>#(%)~n"+..
	"Function ParticleDataLoad<csParticleDataLoad>%($)~n"+..
	"Function ParticleDataSave<csParticleDataSave>(%,$)~n"+..
	"Function ParticleDataSetBox<csParticleDataSetBox>(%,#,#,#)~n"+..
	"Function ParticleDataSetColor<csParticleDataSetColor>(%,%,%)~n"+..
	"Function ParticleDataSetDirection<csParticleDataSetDirection>(%,#,#,#)~n"+..
	"Function ParticleDataSetLifeTime<csParticleDataSetLifeTime>(%,%,%)~n"+..
	"Function ParticleDataSetMaterial<csParticleDataSetMaterial>(%,$)~n"+..
	"Function ParticleDataSetMaxAngle<csParticleDataSetMaxAngle>(%,%)~n"+..
	"Function ParticleDataSetRate<csParticleDataSetRate>(%,%,%)~n"+..
	"Function ParticleDataSetSize<csParticleDataSetSize>(%,#,#)~n"+..
	"Function ParticleDataSetType<csParticleDataSetType>(%,%)~n"+..
	"Function SceneAmbient<csSceneAmbient>(%)~n"+..
	"Function SceneBegin<csSceneBegin>()~n"+..
	"Function SceneEnd<csSceneEnd>()~n"+..
	"Function SceneFog<csSceneFog>(%,#,#)~n"+..
	"Function SceneRender<csSceneRender>(%)~n"+..
	"Function SceneShadow<csSceneShadow>(%)~n"+..
	"Function SceneSkybox<csSceneSkybox>(%,%,%,%,%,%)~n"+..
	"Function SceneSkydome<csSceneSkydome>(%,#,#,#,#)~n"+..
	"Function SceneTransformation<csSceneTransformation>(%,%)~n"+..
	"Function SetColor<csSetColor>(%)~n"+..
	"Function ShaderAsmRegister<csShaderAsmRegister>%($,$,%)~n"+..
	"Function ShaderAsmRegisterFile<csShaderAsmRegisterFile>%($,$,%)~n"+..
	"Function ShaderPixelConstant<csShaderPixelConstant>(%,$,%,%,%)~n"+..
	"Function ShaderRegister<csShaderRegister>%($,$,%,$,$,%,%)~n"+..
	"Function ShaderRegisterFile<csShaderRegisterFile>%($,$,%,$,$,%,%)~n"+..
	"Function ShaderVertexConstant<csShaderVertexConstant>(%,$,%,%,%)~n"+..
	"Function SoundFree<csSoundFree>(%)~n"+..
	"Function SoundGetMasterVolume<csSoundGetMasterVolume>#(#)~n"+..
	"Function SoundIsPlaying<csSoundIsPlaying>%(%)~n"+..
	"Function SoundLoad<csSoundLoad>%($)~n"+..
	"Function SoundPlay2D<csSoundPlay2D>%(%,%)~n"+..
	"Function SoundPlay3D<csSoundPlay3D>%(%,#,#,#,%)~n"+..
	"Function SoundSetMasterVolume<csSoundSetMasterVolume>(#)~n"+..
	"Function StringAscii<csStringAscii>%($)~n"+..
	"Function StringChar<csStringChar>$(%)~n"+..
	"Function StringField<csStringField>$($,$,%)~n"+..
	"Function StringFind<csStringFind>%($,$,%)~n"+..
	"Function StringFromFloat<csStringFromFloat>$(#)~n"+..
	"Function StringFromInt<csStringFromInt>$(%)~n"+..
	"Function StringLeft<csStringLeft>$($,%)~n"+..
	"Function StringLen<csStringLen>%($)~n"+..
	"Function StringLower<csStringLower>$($)~n"+..
	"Function StringMid<csStringMid>$($,%,%)~n"+..
	"Function StringReplace<csStringReplace>$($,$,$)~n"+..
	"Function StringRight<csStringRight>$($,%)~n"+..
	"Function StringToFloat<csStringToFloat>#($)~n"+..
	"Function StringToInt<csStringToInt>%($)~n"+..
	"Function StringTrim<csStringTrim>$($)~n"+..
	"Function StringUpper<csStringUpper>$($)~n"+..
	"Function TerrainNode<csTerrainNode>%($,%,#,#,#,%)~n"+..
	"Function TerrainScaleTexture<csTerrainScaleTexture>(%,#,#)~n"+..
	"Function TextHeight<csTextHeight>%(%,$)~n"+..
	"Function TextureColorKey<csTextureColorKey>(%,%)~n"+..
	"Function TextureCreate<csTextureCreate>%(%,%)~n"+..
	"Function TextureFile<csTextureFile>$(%)~n"+..
	"Function TextureFree<csTextureFree>(%)~n"+..
	"Function TextureHeight<csTextureHeight>%(%,%)~n"+..
	"Function TextureHWPointer<csTextureHWPointer>%(%)~n"+..
	"Function TextureLoad<csTextureLoad>%($,%)~n"+..
	"Function TextureLock<csTextureLock>%(%)~n"+..
	"Function TextureNormalize<csTextureNormalize>(%,#)~n"+..
	"Function TextureTargetCreate<csTextureTargetCreate>%(%,%)~n"+..
	"Function TextureUnlock<csTextureUnlock>(%)~n"+..
	"Function TextureWidth<csTextureWidth>%(%,%)~n"+..
	"Function TextWidth<csTextWidth>%(%,$)~n"+..
	"Function VectorAdd<csVectorAdd>(%,%)~n"+..
	"Function VectorAddScale<csVectorAddScale>(%,%,#)~n"+..
	"Function VectorBetween<csVectorBetween>%(%,#,#,#,#,#,#)~n"+..
	"Function VectorCopy<csVectorCopy>(%,%)~n"+..
	"Function VectorCreate<csVectorCreate>%()~n"+..
	"Function VectorCrossProduct<csVectorCrossProduct>(%,%)~n"+..
	"Function VectorDistance<csVectorDistance>#(%,#,#,#)~n"+..
	"Function VectorDistanceSquared<csVectorDistanceSquared>#(%,#,#,#)~n"+..
	"Function VectorDiv<csVectorDiv>(%,%)~n"+..
	"Function VectorDotProduct<csVectorDotProduct>#(%,%)~n"+..
	"Function VectorEqual<csVectorEqual>%(%,%,#)~n"+..
	"Function VectorFree<csVectorFree>(%)~n"+..
	"Function VectorInterpolate<csVectorInterpolate>(%,%,#)~n"+..
	"Function VectorInvert<csVectorInvert>(%)~n"+..
	"Function VectorLength<csVectorLength>#(%)~n"+..
	"Function VectorLengthSquared<csVectorLengthSquared>#(%)~n"+..
	"Function VectorMul<csVectorMul>(%,%)~n"+..
	"Function VectorNormalize<csVectorNormalize>(%)~n"+..
	"Function VectorScale<csVectorScale>(%,#)~n"+..
	"Function VectorSet<csVectorSet>(%,#,#,#)~n"+..
	"Function VectorSub<csVectorSub>(%,%)~n"+..
	"Function VectorX<csVectorX>#(%)~n"+..
	"Function VectorY<csVectorY>#(%)~n"+..
	"Function VectorZ<csVectorZ>#(%)~n"+..
	"Function Viewport<csViewport>(%,%,%,%)~n"+..
	"Function XMLAttributeCount<csXMLAttributeCount>%(%)~n"+..
	"Function XMLAttributeName<csXMLAttributeName>$(%,%)~n"+..
	"Function XMLAttributeValue<csXMLAttributeValue>$(%,%)~n"+..
	"Function XMLClose<csXMLClose>(%)~n"+..
	"Function XMLNodeData<csXMLNodeData>$(%)~n"+..
	"Function XMLNodeName<csXMLNodeName>$(%)~n"+..
	"Function XMLNodeType<csXMLNodeType>%(%)~n"+..
	"Function XMLRead<csXMLRead>%($)~n"+..
	"Function XMLReadNode<csXMLReadNode>%(%)~n"+..
	"Function XMLWrite<csXMLWrite>%($)~n"+..
	"Function XMLWriteClosingTag<csXMLWriteClosingTag>(%,$)~n"+..
	"Function XMLWriteElement<csXMLWriteElement>(%,$,$,%)~n"+..
	"Function XMLWriteHeader<csXMLWriteHeader>(%)~n"+..
	"Function XMLWriteLineBreak<csXMLWriteLineBreak>(%)~n"+..
	"Function XMLWriteText<csXMLWriteText>(%,$)~n"+..
	""
Const BVM_INVALID_INT_SESSION% = 0

Global BVM_gMainCmdSet_% = 0
Global BVM_gInteractiveSessionCounter% = 0
Global BVM_TempModuleCounter% = 0

Type BVM_TInteractiveSession


	Field hModule%

	Field hContext%

	Field hCmdSet%

	Field tmpModuleName1$

	Field tmpModuleName2$

	Field mainProgCode$

End Type



Function BVM_Invoke%(withTimeOut% = False)
	Local sparam3$
	Local sparam4$
	Local sparam2$
	Local iparam6%
	Local sparam6$
	Local sparam1$
	Local sparam0$
	Local fparam7#
	Local fparam8#
	Local fparam9#
	Local iparam11%
	Local iparam12%
	Local iparam13%
	Local fparam6#
	Local iparam7%
	Local iparam8%
	Local iparam9%
	Local iparam10%
	Local fparam0#
	Local fparam5#
	Local fparam3#
	Local fparam4#
	Local iparam5%
	Local iparam3%
	Local iparam4%
	Local iparam1%
	Local iparam2%
	Local fparam1#
	Local fparam2#
	Local iparam0%
	Local ret%
	Repeat 
		If withTimeOut% Then
			ret% = BVM_RunWithTimeOut()
		Else
			ret% = BVM_Run()
		End If
		Select ret%
			Case 0
				BVM_FlushDebugLog()
				Return 1
			Case 1
				' If with time out, return special code '-1' to say we have yielded,
				If withTimeOut% Then
					Return -1
				Else
					BVM_ReportDebugError(BVM_GetLastErrorMsg())
					Return 0
				End If

			Case 30
				BVM_PushInt(BVM_OnDebugStep())

			Case -1
				' Execution error
				BVM_ReportDebugError(BVM_GetLastErrorMsg())
				Return 0
			Case 256
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csBillboardHeight(iparam0%))
			Case 257
				iparam0% = BVM_PopInt()
				BVM_PushInt(csBillboardNode(iparam0%))
			Case 258
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csBillboardResize(iparam0%, fparam1#, fparam2#)
			Case 259
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csBillboardWidth(iparam0%))
			Case 260
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCameraAspectRatio(iparam0%, fparam1#)
			Case 261
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csCameraClearFlags(iparam0%, iparam1%, iparam2%)
			Case 262
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCameraFov(iparam0%, fparam1#)
			Case 263
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csCameraLine(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%)
			Case 264
				iparam0% = BVM_PopInt()
				BVM_PushInt(csCameraNode(iparam0%))
			Case 265
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csCameraPickNode(iparam0%, iparam1%, iparam2%, iparam3%))
			Case 266
				iparam5% = BVM_PopInt()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCameraProjection(iparam0%, fparam1#, fparam2#, fparam3#, fparam4#, iparam5%)
			Case 267
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCameraRange(iparam0%, fparam1#, fparam2#)
			Case 268
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csCameraRenderTarget(iparam0%, iparam1%)
			Case 269
				iparam4% = BVM_PopInt()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCameraToScreen(iparam0%, fparam1#, fparam2#, fparam3#, iparam4%)
			Case 270
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCameraViewport(iparam0%, fparam1#, fparam2#, fparam3#, fparam4#)
			Case 271
				iparam0% = BVM_PopInt()
				BVM_PushInt(csChannelFinished(iparam0%))
			Case 272
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelGetMaxDistance(iparam0%))
			Case 273
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelGetMinDistance(iparam0%))
			Case 274
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelGetPan(iparam0%))
			Case 275
				iparam0% = BVM_PopInt()
				BVM_PushInt(csChannelGetPlayPosition(iparam0%))
			Case 276
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelGetVolume(iparam0%))
			Case 277
				iparam0% = BVM_PopInt()
				BVM_PushInt(csChannelLooped(iparam0%))
			Case 278
				iparam0% = BVM_PopInt()
				csChannelPause(iparam0%)
			Case 279
				iparam0% = BVM_PopInt()
				BVM_PushInt(csChannelPaused(iparam0%))
			Case 280
				iparam0% = BVM_PopInt()
				csChannelResume(iparam0%)
			Case 281
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csChannelSetDistance(iparam0%, fparam1#, fparam2#)
			Case 282
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csChannelSetPan(iparam0%, fparam1#)
			Case 283
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csChannelSetPosition(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 284
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csChannelSetVolume(iparam0%, fparam1#)
			Case 285
				iparam0% = BVM_PopInt()
				csChannelStop(iparam0%)
			Case 286
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelX(iparam0%))
			Case 287
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelY(iparam0%))
			Case 288
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csChannelZ(iparam0%))
			Case 289
				fparam5# = BVM_PopFloat()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				fparam0# = BVM_PopFloat()
				BVM_PushInt(csCollisionLineNode(fparam0#, fparam1#, fparam2#, fparam3#, fparam4#, fparam5#))
			Case 290
				iparam10% = BVM_PopInt()
				iparam9% = BVM_PopInt()
				iparam8% = BVM_PopInt()
				iparam7% = BVM_PopInt()
				fparam6# = BVM_PopFloat()
				fparam5# = BVM_PopFloat()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csCollisionLinePick(iparam0%, fparam1#, fparam2#, fparam3#, fparam4#, fparam5#, fparam6#, iparam7%, iparam8%, iparam9%, iparam10%))
			Case 291
				iparam13% = BVM_PopInt()
				iparam12% = BVM_PopInt()
				iparam11% = BVM_PopInt()
				iparam10% = BVM_PopInt()
				fparam9# = BVM_PopFloat()
				fparam8# = BVM_PopFloat()
				fparam7# = BVM_PopFloat()
				fparam6# = BVM_PopFloat()
				fparam5# = BVM_PopFloat()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csCollisionSlide(iparam0%, fparam1#, fparam2#, fparam3#, fparam4#, fparam5#, fparam6#, fparam7#, fparam8#, fparam9#, iparam10%, iparam11%, iparam12%, iparam13%)
			Case 292
				csCoreFinish()
			Case 293
				csCoreInit()
			Case 294
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				csCoreMessage(sparam0$, iparam1%)
			Case 295
				BVM_PushInt(csCoreTimer())
			Case 296
				iparam0% = BVM_PopInt()
				csDirClose(iparam0%)
			Case 297
				iparam0% = BVM_PopInt()
				BVM_PushInt(csDirFileCount(iparam0%))
			Case 298
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csDirFileIsDir(iparam0%, iparam1%))
			Case 299
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushString(csDirFileName(iparam0%, iparam1%))
			Case 300
				sparam0$ = BVM_PopString()
				BVM_PushInt(csDirList(sparam0$))
			Case 301
				BVM_PushInt(csDisplayActive())
			Case 302
				sparam0$ = BVM_PopString()
				csDisplayCaption(sparam0$)
			Case 303
				csDisplayClose()
			Case 304
				BVM_PushInt(csDisplayClosed())
			Case 305
				iparam0% = BVM_PopInt()
				BVM_PushInt(csDisplayFeature(iparam0%))
			Case 306
				BVM_PushInt(csDisplayFps())
			Case 307
				BVM_PushInt(csDisplayHeight())
			Case 308
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csDisplayOpen(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%)
			Case 309
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csDisplayResize(iparam0%, iparam1%)
			Case 310
				sparam0$ = BVM_PopString()
				csDisplayScreenshot(sparam0$)
			Case 311
				BVM_PushInt(csDisplayWidth())
			Case 312
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csDrawLine(iparam0%, iparam1%, iparam2%, iparam3%)
			Case 313
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csDrawRect(iparam0%, iparam1%, iparam2%, iparam3%)
			Case 314
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csDrawText(iparam0%, sparam1$, iparam2%, iparam3%)
			Case 315
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csDrawTexture(iparam0%, iparam1%, iparam2%)
			Case 316
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csEffectRegister(sparam0$, iparam1%))
			Case 317
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csEffectRegisterFile(sparam0$, iparam1%))
			Case 318
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetBool(iparam0%, sparam1$, iparam2%)
			Case 319
				fparam2# = BVM_PopFloat()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetFloat(iparam0%, sparam1$, fparam2#)
			Case 320
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetInt(iparam0%, sparam1$, iparam2%)
			Case 321
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetMatrix(iparam0%, sparam1$, iparam2%)
			Case 322
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetTechnique(iparam0%, sparam1$)
			Case 323
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetTexture(iparam0%, sparam1$, iparam2%)
			Case 324
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csEffectSetVector(iparam0%, sparam1$, iparam2%)
			Case 325
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csEmitterAddFadeOutAffector(iparam0%, iparam1%, iparam2%)
			Case 326
				iparam4% = BVM_PopInt()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csEmitterAddGravityAffector(iparam0%, fparam1#, fparam2#, fparam3#, iparam4%)
			Case 327
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csEmitterNode(iparam0%, iparam1%))
			Case 328
				iparam0% = BVM_PopInt()
				csEmitterRemoveAffectors(iparam0%)
			Case 329
				BVM_PushFloat(csEventA())
			Case 330
				BVM_PushFloat(csEventB())
			Case 331
				BVM_PushFloat(csEventC())
			Case 332
				BVM_PushString(csEventData())
			Case 333
				BVM_PushInt(csEventFrom())
			Case 334
				BVM_PushInt(csEventGet())
			Case 335
				BVM_PushInt(csEventId())
			Case 336
				BVM_PushInt(csEventPoll())
			Case 337
				sparam6$ = BVM_PopString()
				fparam5# = BVM_PopFloat()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csEventPost(iparam0%, iparam1%, iparam2%, fparam3#, fparam4#, fparam5#, sparam6$)
			Case 338
				BVM_PushInt(csEventTo())
			Case 339
				iparam0% = BVM_PopInt()
				csFileClose(iparam0%)
			Case 340
				sparam0$ = BVM_PopString()
				BVM_PushString(csFileGetDir(sparam0$))
			Case 341
				sparam0$ = BVM_PopString()
				BVM_PushString(csFileGetExt(sparam0$))
			Case 342
				iparam0% = BVM_PopInt()
				BVM_PushInt(csFilePos(iparam0%))
			Case 343
				sparam0$ = BVM_PopString()
				BVM_PushInt(csFileRead(sparam0$))
			Case 344
				iparam0% = BVM_PopInt()
				BVM_PushInt(csFileReadByte(iparam0%))
			Case 345
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csFileReadBytes(iparam0%, iparam1%, iparam2%)
			Case 346
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csFileReadFloat(iparam0%))
			Case 347
				iparam0% = BVM_PopInt()
				BVM_PushInt(csFileReadInt(iparam0%))
			Case 348
				iparam0% = BVM_PopInt()
				BVM_PushInt(csFileReadShort(iparam0%))
			Case 349
				iparam0% = BVM_PopInt()
				BVM_PushString(csFileReadString(iparam0%))
			Case 350
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csFileSeek(iparam0%, iparam1%, iparam2%)
			Case 351
				iparam0% = BVM_PopInt()
				BVM_PushInt(csFileSize(iparam0%))
			Case 352
				sparam0$ = BVM_PopString()
				BVM_PushString(csFileStripDir(sparam0$))
			Case 353
				sparam0$ = BVM_PopString()
				BVM_PushString(csFileStripExt(sparam0$))
			Case 354
				sparam0$ = BVM_PopString()
				BVM_PushInt(csFileWrite(sparam0$))
			Case 355
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csFileWriteByte(iparam0%, iparam1%)
			Case 356
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csFileWriteBytes(iparam0%, iparam1%, iparam2%)
			Case 357
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csFileWriteFloat(iparam0%, fparam1#)
			Case 358
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csFileWriteInt(iparam0%, iparam1%)
			Case 359
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csFileWriteShort(iparam0%, iparam1%)
			Case 360
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csFileWriteString(iparam0%, sparam1$)
			Case 361
				iparam0% = BVM_PopInt()
				csFontFree(iparam0%)
			Case 362
				sparam0$ = BVM_PopString()
				BVM_PushInt(csFontLoad(sparam0$))
			Case 363
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetAddItem(iparam0%, sparam1$, iparam2%))
			Case 364
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetChild(iparam0%, iparam1%))
			Case 365
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetChildren(iparam0%))
			Case 366
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetCountItems(iparam0%))
			Case 367
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetEnable(iparam0%, iparam1%)
			Case 368
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetEnableItem(iparam0%, iparam1%, iparam2%)
			Case 369
				iparam0% = BVM_PopInt()
				csGadgetFree(iparam0%)
			Case 370
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetGetItemId(iparam0%, iparam1%))
			Case 371
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushString(csGadgetGetItemText(iparam0%, iparam1%))
			Case 372
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetGetState(iparam0%))
			Case 373
				iparam0% = BVM_PopInt()
				BVM_PushString(csGadgetGetText(iparam0%))
			Case 374
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetParent(iparam0%))
			Case 375
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetRemoveItem(iparam0%, iparam1%)
			Case 376
				iparam0% = BVM_PopInt()
				csGadgetRemoveItems(iparam0%)
			Case 377
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetSelectedItem(iparam0%))
			Case 378
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetSelectItem(iparam0%, iparam1%)
			Case 379
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetSetColor(iparam0%, iparam1%, iparam2%)
			Case 380
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetSetFont(iparam0%, iparam1%)
			Case 381
				iparam6% = BVM_PopInt()
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetSetImage(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%, iparam6%)
			Case 382
				sparam2$ = BVM_PopString()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetSetItemText(iparam0%, iparam1%, sparam2$)
			Case 383
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetSetState(iparam0%, iparam1%)
			Case 384
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csGadgetSetText(iparam0%, sparam1$)
			Case 385
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetShape(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%)
			Case 386
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGadgetType(iparam0%))
			Case 387
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csGadgetVisible(iparam0%, iparam1%)
			Case 388
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGetAlpha(iparam0%))
			Case 389
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGetBlue(iparam0%))
			Case 390
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGetColor(iparam0%, iparam1%, iparam2%, iparam3%))
			Case 391
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGetGreen(iparam0%))
			Case 392
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGetRed(iparam0%))
			Case 393
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiButton(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%))
			Case 394
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiCheckBox(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%))
			Case 395
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiComboBox(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%))
			Case 396
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiContextMenu(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%))
			Case 397
				csGuiDraw()
			Case 398
				iparam6% = BVM_PopInt()
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiEditBox(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%, iparam6%))
			Case 399
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiGroup(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%))
			Case 400
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiListBox(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%))
			Case 401
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiMenu(iparam0%))
			Case 402
				iparam3% = BVM_PopInt()
				sparam2$ = BVM_PopString()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiMessageBox(iparam0%, sparam1$, sparam2$, iparam3%))
			Case 403
				iparam7% = BVM_PopInt()
				iparam6% = BVM_PopInt()
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiScrollBar(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%, iparam6%, iparam7%))
			Case 404
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiTabber(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%))
			Case 405
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiText(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%))
			Case 406
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiTexture(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%))
			Case 407
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiToolbar(iparam0%))
			Case 408
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csGuiWindow(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%))
			Case 409
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csJoyAxis(iparam0%, iparam1%))
			Case 410
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csJoyButton(iparam0%, iparam1%))
			Case 411
				iparam0% = BVM_PopInt()
				BVM_PushString(csJoyName(iparam0%))
			Case 412
				iparam0% = BVM_PopInt()
				BVM_PushInt(csJoyNumAxes(iparam0%))
			Case 413
				iparam0% = BVM_PopInt()
				BVM_PushInt(csKeyDown(iparam0%))
			Case 414
				BVM_PushInt(csKeyGet())
			Case 415
				iparam0% = BVM_PopInt()
				BVM_PushInt(csKeyHit(iparam0%))
			Case 416
				BVM_PushInt(csKeyReleased())
			Case 417
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csLightAmbient(iparam0%, iparam1%)
			Case 418
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csLightDiffuse(iparam0%, iparam1%)
			Case 419
				iparam0% = BVM_PopInt()
				BVM_PushInt(csLightNode(iparam0%))
			Case 420
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csLightRadius(iparam0%, fparam1#)
			Case 421
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csLightSpecular(iparam0%, iparam1%)
			Case 422
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csLightType(iparam0%, iparam1%)
			Case 423
				iparam0% = BVM_PopInt()
				csListenerUpdate(iparam0%)
			Case 424
				sparam0$ = BVM_PopString()
				BVM_PushInt(csMaterialCreate(sparam0$))
			Case 425
				sparam0$ = BVM_PopString()
				BVM_PushInt(csMaterialFind(sparam0$))
			Case 426
				iparam0% = BVM_PopInt()
				csMaterialFree(iparam0%)
			Case 427
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetAmbient(iparam0%))
			Case 428
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetDiffuse(iparam0%))
			Case 429
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetEmissive(iparam0%))
			Case 430
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetFlags(iparam0%))
			Case 431
				iparam0% = BVM_PopInt()
				BVM_PushString(csMaterialGetName(iparam0%))
			Case 432
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csMaterialGetParam(iparam0%))
			Case 433
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csMaterialGetShininess(iparam0%))
			Case 434
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetSpecular(iparam0%))
			Case 435
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetTexture(iparam0%, iparam1%))
			Case 436
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMaterialGetType(iparam0%))
			Case 437
				sparam0$ = BVM_PopString()
				BVM_PushInt(csMaterialLoad(sparam0$))
			Case 438
				sparam2$ = BVM_PopString()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csMaterialSave(iparam0%, sparam1$, sparam2$)
			Case 439
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetAmbient(iparam0%, iparam1%)
			Case 440
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetDiffuse(iparam0%, iparam1%)
			Case 441
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetEmissive(iparam0%, iparam1%)
			Case 442
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetFlags(iparam0%, iparam1%)
			Case 443
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csMaterialSetParam(iparam0%, fparam1#)
			Case 444
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csMaterialSetShininess(iparam0%, fparam1#)
			Case 445
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetSpecular(iparam0%, iparam1%)
			Case 446
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetTexture(iparam0%, iparam1%, iparam2%)
			Case 447
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMaterialSetType(iparam0%, iparam1%)
			Case 448
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathAbs(fparam0#))
			Case 449
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathACos(fparam0#))
			Case 450
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathASin(fparam0#))
			Case 451
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathATan(fparam0#))
			Case 452
				fparam1# = BVM_PopFloat()
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathATan2(fparam0#, fparam1#))
			Case 453
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathCeil(fparam0#))
			Case 454
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathCos(fparam0#))
			Case 455
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathExp(fparam0#))
			Case 456
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathFloor(fparam0#))
			Case 457
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathLog(fparam0#))
			Case 458
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathLog10(fparam0#))
			Case 459
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMathRand(iparam0%, iparam1%))
			Case 460
				iparam0% = BVM_PopInt()
				csMathRandSeed(iparam0%)
			Case 461
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathSin(fparam0#))
			Case 462
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathSqr(fparam0#))
			Case 463
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csMathTan(fparam0#))
			Case 464
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixAdd(iparam0%, iparam1%)
			Case 465
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixCopy(iparam0%, iparam1%)
			Case 466
				BVM_PushInt(csMatrixCreate())
			Case 467
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixDiv(iparam0%, iparam1%)
			Case 468
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csMatrixElement(iparam0%, iparam1%, iparam2%))
			Case 469
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMatrixEqual(iparam0%, iparam1%))
			Case 470
				iparam0% = BVM_PopInt()
				csMatrixFree(iparam0%)
			Case 471
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixGetRotation(iparam0%, iparam1%)
			Case 472
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixGetTranslation(iparam0%, iparam1%)
			Case 473
				iparam0% = BVM_PopInt()
				csMatrixIdentity(iparam0%)
			Case 474
				fparam2# = BVM_PopFloat()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixInterpolate(iparam0%, iparam1%, fparam2#)
			Case 475
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMatrixInvert(iparam0%))
			Case 476
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixMul(iparam0%, iparam1%)
			Case 477
				fparam3# = BVM_PopFloat()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixSet(iparam0%, iparam1%, iparam2%, fparam3#)
			Case 478
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixSetRotation(iparam0%, iparam1%)
			Case 479
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixSetScale(iparam0%, iparam1%)
			Case 480
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixSetTranslation(iparam0%, iparam1%)
			Case 481
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMatrixSub(iparam0%, iparam1%)
			Case 482
				iparam0% = BVM_PopInt()
				csMatrixTranspose(iparam0%)
			Case 483
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csMeshDepth(iparam0%))
			Case 484
				iparam0% = BVM_PopInt()
				csMeshFlip(iparam0%)
			Case 485
				iparam0% = BVM_PopInt()
				csMeshFree(iparam0%)
			Case 486
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csMeshHeight(iparam0%))
			Case 487
				sparam0$ = BVM_PopString()
				BVM_PushInt(csMeshLoad(sparam0$))
			Case 488
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMeshNode(iparam0%, iparam1%, iparam2%, iparam3%))
			Case 489
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMeshOctreeNode(iparam0%, iparam1%, iparam2%, iparam3%))
			Case 490
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csMeshPlanarMapping(iparam0%, fparam1#)
			Case 491
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csMeshScale(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 492
				sparam0$ = BVM_PopString()
				BVM_PushInt(csMeshTerrainLoad(sparam0$))
			Case 493
				iparam0% = BVM_PopInt()
				csMeshUpdateNormals(iparam0%)
			Case 494
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMeshVerticesColor(iparam0%, iparam1%, iparam2%)
			Case 495
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csMeshWidth(iparam0%))
			Case 496
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMouseDown(iparam0%))
			Case 497
				BVM_PushInt(csMouseGet())
			Case 498
				iparam0% = BVM_PopInt()
				csMouseHide(iparam0%)
			Case 499
				iparam0% = BVM_PopInt()
				BVM_PushInt(csMouseHit(iparam0%))
			Case 500
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csMousePosition(iparam0%, iparam1%)
			Case 501
				BVM_PushInt(csMouseReleased())
			Case 502
				BVM_PushInt(csMouseX())
			Case 503
				BVM_PushInt(csMouseY())
			Case 504
				sparam2$ = BVM_PopString()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeAttachToBone(iparam0%, iparam1%, sparam2$)
			Case 505
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeCastShadow(iparam0%, iparam1%)
			Case 506
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeChild(iparam0%, iparam1%))
			Case 507
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeChildren(iparam0%))
			Case 508
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeDepth(iparam0%))
			Case 509
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeEmpty(iparam0%))
			Case 510
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeFindChild(iparam0%, sparam1$, iparam2%))
			Case 511
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeFindProperty(iparam0%, sparam1$))
			Case 512
				iparam0% = BVM_PopInt()
				csNodeFree(iparam0%)
			Case 513
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeGetFrame(iparam0%))
			Case 514
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeGetMaterial(iparam0%, iparam1%))
			Case 515
				iparam0% = BVM_PopInt()
				BVM_PushString(csNodeGetName(iparam0%))
			Case 516
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeGetParent(iparam0%))
			Case 517
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeHeight(iparam0%))
			Case 518
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeHide(iparam0%, iparam1%)
			Case 519
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodeLookAt(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 520
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeLoop(iparam0%, iparam1%)
			Case 521
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeMaterials(iparam0%))
			Case 522
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodeMove(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 523
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodePitch(iparam0%))
			Case 524
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodePosition(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 525
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeProperties(iparam0%))
			Case 526
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushString(csNodePropertyName(iparam0%, iparam1%))
			Case 527
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushString(csNodePropertyValue(iparam0%, iparam1%))
			Case 528
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeRemoveProperty(iparam0%, iparam1%)
			Case 529
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeRoll(iparam0%))
			Case 530
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodeRotate(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 531
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodeScale(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 532
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeScaleX(iparam0%))
			Case 533
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeScaleY(iparam0%))
			Case 534
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeScaleZ(iparam0%))
			Case 535
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeSetFrame(iparam0%, iparam1%, iparam2%)
			Case 536
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeSetMaterial(iparam0%, iparam1%, iparam2%)
			Case 537
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeSetMaterialFast(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%)
			Case 538
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeSetMaterialFlag(iparam0%, iparam1%, iparam2%, iparam3%)
			Case 539
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csNodeSetName(iparam0%, sparam1$)
			Case 540
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeSetParent(iparam0%, iparam1%)
			Case 541
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csNodeSetPickGroup(iparam0%, iparam1%)
			Case 542
				sparam2$ = BVM_PopString()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csNodeSetProperty(iparam0%, sparam1$, sparam2$)
			Case 543
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodeSpeed(iparam0%, fparam1#)
			Case 544
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csNodeTurn(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 545
				iparam0% = BVM_PopInt()
				BVM_PushInt(csNodeType(iparam0%))
			Case 546
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeWidth(iparam0%))
			Case 547
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeX(iparam0%, iparam1%))
			Case 548
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeY(iparam0%, iparam1%))
			Case 549
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeYaw(iparam0%))
			Case 550
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csNodeZ(iparam0%, iparam1%))
			Case 551
				sparam0$ = BVM_PopString()
				csPackageAdd(sparam0$)
			Case 552
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csParticleDataAddFadeOutAffector(iparam0%, iparam1%, iparam2%)
			Case 553
				iparam4% = BVM_PopInt()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csParticleDataAddGravityAffector(iparam0%, fparam1#, fparam2#, fparam3#, iparam4%)
			Case 554
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataAffectors(iparam0%))
			Case 555
				sparam0$ = BVM_PopString()
				BVM_PushInt(csParticleDataCreate(sparam0$))
			Case 556
				sparam0$ = BVM_PopString()
				BVM_PushInt(csParticleDataFind(sparam0$))
			Case 557
				iparam0% = BVM_PopInt()
				csParticleDataFree(iparam0%)
			Case 558
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetAffectorColor(iparam0%, iparam1%))
			Case 559
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetAffectorGravityX(iparam0%, iparam1%))
			Case 560
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetAffectorGravityY(iparam0%, iparam1%))
			Case 561
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetAffectorGravityZ(iparam0%, iparam1%))
			Case 562
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetAffectorTime(iparam0%, iparam1%))
			Case 563
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetAffectorType(iparam0%, iparam1%))
			Case 564
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetBoxDepth(iparam0%))
			Case 565
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetBoxHeight(iparam0%))
			Case 566
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetBoxWidth(iparam0%))
			Case 567
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetDirectionX(iparam0%))
			Case 568
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetDirectionY(iparam0%))
			Case 569
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetDirectionZ(iparam0%))
			Case 570
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetHeight(iparam0%))
			Case 571
				iparam0% = BVM_PopInt()
				BVM_PushString(csParticleDataGetMaterial(iparam0%))
			Case 572
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMaxAngle(iparam0%))
			Case 573
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMaxColor(iparam0%))
			Case 574
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMaxLifeTime(iparam0%))
			Case 575
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMaxRate(iparam0%))
			Case 576
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMinColor(iparam0%))
			Case 577
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMinLifeTime(iparam0%))
			Case 578
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetMinRate(iparam0%))
			Case 579
				iparam0% = BVM_PopInt()
				BVM_PushString(csParticleDataGetName(iparam0%))
			Case 580
				iparam0% = BVM_PopInt()
				BVM_PushInt(csParticleDataGetType(iparam0%))
			Case 581
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csParticleDataGetWidth(iparam0%))
			Case 582
				sparam0$ = BVM_PopString()
				BVM_PushInt(csParticleDataLoad(sparam0$))
			Case 583
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csParticleDataSave(iparam0%, sparam1$)
			Case 584
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csParticleDataSetBox(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 585
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csParticleDataSetColor(iparam0%, iparam1%, iparam2%)
			Case 586
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csParticleDataSetDirection(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 587
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csParticleDataSetLifeTime(iparam0%, iparam1%, iparam2%)
			Case 588
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csParticleDataSetMaterial(iparam0%, sparam1$)
			Case 589
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csParticleDataSetMaxAngle(iparam0%, iparam1%)
			Case 590
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csParticleDataSetRate(iparam0%, iparam1%, iparam2%)
			Case 591
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csParticleDataSetSize(iparam0%, fparam1#, fparam2#)
			Case 592
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csParticleDataSetType(iparam0%, iparam1%)
			Case 593
				iparam0% = BVM_PopInt()
				csSceneAmbient(iparam0%)
			Case 594
				csSceneBegin()
			Case 595
				csSceneEnd()
			Case 596
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csSceneFog(iparam0%, fparam1#, fparam2#)
			Case 597
				iparam0% = BVM_PopInt()
				csSceneRender(iparam0%)
			Case 598
				iparam0% = BVM_PopInt()
				csSceneShadow(iparam0%)
			Case 599
				iparam5% = BVM_PopInt()
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csSceneSkybox(iparam0%, iparam1%, iparam2%, iparam3%, iparam4%, iparam5%)
			Case 600
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csSceneSkydome(iparam0%, fparam1#, fparam2#, fparam3#, fparam4#)
			Case 601
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csSceneTransformation(iparam0%, iparam1%)
			Case 602
				iparam0% = BVM_PopInt()
				csSetColor(iparam0%)
			Case 603
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csShaderAsmRegister(sparam0$, sparam1$, iparam2%))
			Case 604
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csShaderAsmRegisterFile(sparam0$, sparam1$, iparam2%))
			Case 605
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csShaderPixelConstant(iparam0%, sparam1$, iparam2%, iparam3%, iparam4%)
			Case 606
				iparam6% = BVM_PopInt()
				iparam5% = BVM_PopInt()
				sparam4$ = BVM_PopString()
				sparam3$ = BVM_PopString()
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csShaderRegister(sparam0$, sparam1$, iparam2%, sparam3$, sparam4$, iparam5%, iparam6%))
			Case 607
				iparam6% = BVM_PopInt()
				iparam5% = BVM_PopInt()
				sparam4$ = BVM_PopString()
				sparam3$ = BVM_PopString()
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csShaderRegisterFile(sparam0$, sparam1$, iparam2%, sparam3$, sparam4$, iparam5%, iparam6%))
			Case 608
				iparam4% = BVM_PopInt()
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csShaderVertexConstant(iparam0%, sparam1$, iparam2%, iparam3%, iparam4%)
			Case 609
				iparam0% = BVM_PopInt()
				csSoundFree(iparam0%)
			Case 610
				fparam0# = BVM_PopFloat()
				BVM_PushFloat(csSoundGetMasterVolume(fparam0#))
			Case 611
				iparam0% = BVM_PopInt()
				BVM_PushInt(csSoundIsPlaying(iparam0%))
			Case 612
				sparam0$ = BVM_PopString()
				BVM_PushInt(csSoundLoad(sparam0$))
			Case 613
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csSoundPlay2D(iparam0%, iparam1%))
			Case 614
				iparam4% = BVM_PopInt()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csSoundPlay3D(iparam0%, fparam1#, fparam2#, fparam3#, iparam4%))
			Case 615
				fparam0# = BVM_PopFloat()
				csSoundSetMasterVolume(fparam0#)
			Case 616
				sparam0$ = BVM_PopString()
				BVM_PushInt(csStringAscii(sparam0$))
			Case 617
				iparam0% = BVM_PopInt()
				BVM_PushString(csStringChar(iparam0%))
			Case 618
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringField(sparam0$, sparam1$, iparam2%))
			Case 619
				iparam2% = BVM_PopInt()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csStringFind(sparam0$, sparam1$, iparam2%))
			Case 620
				fparam0# = BVM_PopFloat()
				BVM_PushString(csStringFromFloat(fparam0#))
			Case 621
				iparam0% = BVM_PopInt()
				BVM_PushString(csStringFromInt(iparam0%))
			Case 622
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringLeft(sparam0$, iparam1%))
			Case 623
				sparam0$ = BVM_PopString()
				BVM_PushInt(csStringLen(sparam0$))
			Case 624
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringLower(sparam0$))
			Case 625
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringMid(sparam0$, iparam1%, iparam2%))
			Case 626
				sparam2$ = BVM_PopString()
				sparam1$ = BVM_PopString()
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringReplace(sparam0$, sparam1$, sparam2$))
			Case 627
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringRight(sparam0$, iparam1%))
			Case 628
				sparam0$ = BVM_PopString()
				BVM_PushFloat(csStringToFloat(sparam0$))
			Case 629
				sparam0$ = BVM_PopString()
				BVM_PushInt(csStringToInt(sparam0$))
			Case 630
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringTrim(sparam0$))
			Case 631
				sparam0$ = BVM_PopString()
				BVM_PushString(csStringUpper(sparam0$))
			Case 632
				iparam5% = BVM_PopInt()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csTerrainNode(sparam0$, iparam1%, fparam2#, fparam3#, fparam4#, iparam5%))
			Case 633
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csTerrainScaleTexture(iparam0%, fparam1#, fparam2#)
			Case 634
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextHeight(iparam0%, sparam1$))
			Case 635
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csTextureColorKey(iparam0%, iparam1%)
			Case 636
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextureCreate(iparam0%, iparam1%))
			Case 637
				iparam0% = BVM_PopInt()
				BVM_PushString(csTextureFile(iparam0%))
			Case 638
				iparam0% = BVM_PopInt()
				csTextureFree(iparam0%)
			Case 639
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextureHeight(iparam0%, iparam1%))
			Case 640
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextureHWPointer(iparam0%))
			Case 641
				iparam1% = BVM_PopInt()
				sparam0$ = BVM_PopString()
				BVM_PushInt(csTextureLoad(sparam0$, iparam1%))
			Case 642
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextureLock(iparam0%))
			Case 643
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csTextureNormalize(iparam0%, fparam1#)
			Case 644
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextureTargetCreate(iparam0%, iparam1%))
			Case 645
				iparam0% = BVM_PopInt()
				csTextureUnlock(iparam0%)
			Case 646
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextureWidth(iparam0%, iparam1%))
			Case 647
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csTextWidth(iparam0%, sparam1$))
			Case 648
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorAdd(iparam0%, iparam1%)
			Case 649
				fparam2# = BVM_PopFloat()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorAddScale(iparam0%, iparam1%, fparam2#)
			Case 650
				fparam6# = BVM_PopFloat()
				fparam5# = BVM_PopFloat()
				fparam4# = BVM_PopFloat()
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csVectorBetween(iparam0%, fparam1#, fparam2#, fparam3#, fparam4#, fparam5#, fparam6#))
			Case 651
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorCopy(iparam0%, iparam1%)
			Case 652
				BVM_PushInt(csVectorCreate())
			Case 653
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorCrossProduct(iparam0%, iparam1%)
			Case 654
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorDistance(iparam0%, fparam1#, fparam2#, fparam3#))
			Case 655
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorDistanceSquared(iparam0%, fparam1#, fparam2#, fparam3#))
			Case 656
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorDiv(iparam0%, iparam1%)
			Case 657
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorDotProduct(iparam0%, iparam1%))
			Case 658
				fparam2# = BVM_PopFloat()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushInt(csVectorEqual(iparam0%, iparam1%, fparam2#))
			Case 659
				iparam0% = BVM_PopInt()
				csVectorFree(iparam0%)
			Case 660
				fparam2# = BVM_PopFloat()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorInterpolate(iparam0%, iparam1%, fparam2#)
			Case 661
				iparam0% = BVM_PopInt()
				csVectorInvert(iparam0%)
			Case 662
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorLength(iparam0%))
			Case 663
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorLengthSquared(iparam0%))
			Case 664
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorMul(iparam0%, iparam1%)
			Case 665
				iparam0% = BVM_PopInt()
				csVectorNormalize(iparam0%)
			Case 666
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csVectorScale(iparam0%, fparam1#)
			Case 667
				fparam3# = BVM_PopFloat()
				fparam2# = BVM_PopFloat()
				fparam1# = BVM_PopFloat()
				iparam0% = BVM_PopInt()
				csVectorSet(iparam0%, fparam1#, fparam2#, fparam3#)
			Case 668
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csVectorSub(iparam0%, iparam1%)
			Case 669
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorX(iparam0%))
			Case 670
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorY(iparam0%))
			Case 671
				iparam0% = BVM_PopInt()
				BVM_PushFloat(csVectorZ(iparam0%))
			Case 672
				iparam3% = BVM_PopInt()
				iparam2% = BVM_PopInt()
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				csViewport(iparam0%, iparam1%, iparam2%, iparam3%)
			Case 673
				iparam0% = BVM_PopInt()
				BVM_PushInt(csXMLAttributeCount(iparam0%))
			Case 674
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushString(csXMLAttributeName(iparam0%, iparam1%))
			Case 675
				iparam1% = BVM_PopInt()
				iparam0% = BVM_PopInt()
				BVM_PushString(csXMLAttributeValue(iparam0%, iparam1%))
			Case 676
				iparam0% = BVM_PopInt()
				csXMLClose(iparam0%)
			Case 677
				iparam0% = BVM_PopInt()
				BVM_PushString(csXMLNodeData(iparam0%))
			Case 678
				iparam0% = BVM_PopInt()
				BVM_PushString(csXMLNodeName(iparam0%))
			Case 679
				iparam0% = BVM_PopInt()
				BVM_PushInt(csXMLNodeType(iparam0%))
			Case 680
				sparam0$ = BVM_PopString()
				BVM_PushInt(csXMLRead(sparam0$))
			Case 681
				iparam0% = BVM_PopInt()
				BVM_PushInt(csXMLReadNode(iparam0%))
			Case 682
				sparam0$ = BVM_PopString()
				BVM_PushInt(csXMLWrite(sparam0$))
			Case 683
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csXMLWriteClosingTag(iparam0%, sparam1$)
			Case 684
				iparam3% = BVM_PopInt()
				sparam2$ = BVM_PopString()
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csXMLWriteElement(iparam0%, sparam1$, sparam2$, iparam3%)
			Case 685
				iparam0% = BVM_PopInt()
				csXMLWriteHeader(iparam0%)
			Case 686
				iparam0% = BVM_PopInt()
				csXMLWriteLineBreak(iparam0%)
			Case 687
				sparam1$ = BVM_PopString()
				iparam0% = BVM_PopInt()
				csXMLWriteText(iparam0%, sparam1$)
			Default 
				BVM_SetLastError(BVM_ERR_ERROR%, "Fatal error : unknown command of id " + BVM_IntToStr(ret%) + ", the invoker seems to be out of sync with the 'coldsteel' command set")
				BVM_ReportDebugError(BVM_GetLastErrorMsg())
				Return 0
		End Select
	Forever
End Function


Function BVM_FlushMem%(hContext% = 0)
	Local ret%
	Local hPrevCtxt%
	ret% = BVM_GarbageCollect_(hContext%)
	If ret% = -1 Then
		Return False
	Else
		If ret% = 1 Then
			hPrevCtxt% = BVM_GetSelectedContext()
			If hContext% = 0 Then
				hContext% = BVM_GetSelectedContext()
			End If
			If (BVM_Invoke(False) = 0) Then
				BVM_SelectContext(hPrevCtxt%)
				Return False
			End If
			BVM_SelectContext(hPrevCtxt%)
			Return True
		End If
	End If
	Return True
End Function


Function BVM_FlushMemAll%(ignoreErrors% = False)
	Local count%
	Local i%
	Local hContext%
	Local ret%
	ret% = True
	count% = BVM_CountContexts()
	For i% = 0 To count% - 1
		hContext% = BVM_GetContext(i%)
		ret% = ret% And BVM_FlushMem(hContext%)
		If (ret% = 0) And (ignoreErrors% = 0) Then
			Return False
		End If
	Next
	Return ret%
End Function


Function BVM_MapModule%(hContext%, hModule%, bStartHalted% = False)
	Local hMainProgEntryPoint%
	Local hPrevContext%
	' Maps a module into a context
	' 	hContext : context to map the module in
	' 	hModule : the module to map
	' 	bStartHalted : in debug mode, start halted (in effect, add a breakpoint at the start of the main program)
	hPrevContext% = BVM_GetSelectedContext()

	If (BVM_SelectContext(hContext%) = 0) Then
		Return False
	End If

	If (BVM_MapModule_(hContext%, hModule%) = 0) Then
		Return False
	End If

	hMainProgEntryPoint% = BVM_FindEntryPoint(hContext%, hModule%, "_main")
	If (BVM_SelectEntryPoint(hMainProgEntryPoint%) = 0) Then
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	If bStartHalted% Then
		BVM_SetBreakPoint("", 0, True)
	End If
	If (BVM_Invoke() = 0) Then
		BVM_SelectContext(hPrevContext%)
		Return False
	End If
	' Pop the main program return value (which is always 0)
	BVM_PopInt()

	BVM_SelectContext(hPrevContext%)
	Return True
End Function


Function BVM_HELPER_LoadAndInvoke%(moduleFileName$, functionName$ = "_main", bEnableDebug% = False, bStartHalted% = False, bDynamic% = True)
	Local hEntryPoint%
	Local hModule%
	Local hContext%
	Local hPrevContext%

	hPrevContext% = BVM_GetSelectedContext()

	' We load the module
	hModule% = BVM_LoadModule(moduleFileName$)
	If hModule% = BVM_INVALID_MODULE% Then
		Return False
	End If

	' We create a new execution context. An execution context holds the current state of execution.
	hContext% = BVM_CreateContext(bDynamic%)
	If hContext% = BVM_INVALID_CONTEXT% Then
		BVM_ReleaseModule(hModule%)
		Return False
	End If

	' We select the current execution context
	If (BVM_SelectContext(hContext%) = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		Return False
	End If

	If bEnableDebug% Then
		BVM_StartDebug(hContext%)
	End If

	' ; We map the module into this context
	If (BVM_MapModule(hContext%, hModule%, bStartHalted%) = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		Return False
	End If

	' Do we just have to execute the main program? If so it's already done,
	' (by the mapping) so just return
	If BVM_StrIEq(functionName$, "_main") Or functionName$ = "" Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_SelectContext(hPrevContext%)
		Return True
	End If

	' We get an entry point handle for the function we want to execute
	hEntryPoint% = BVM_FindEntryPoint(hContext%, hModule%, functionName$)
	If hEntryPoint% = BVM_INVALID_ENTRY_POINT% Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	' We select the entry point
	If (BVM_SelectEntryPoint(hEntryPoint%) = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	' We run the code
	If (BVM_Invoke() = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	BVM_ReleaseModule(hModule%)
	BVM_DeleteContext(hContext%)
	BVM_SelectContext(hPrevContext%)

	Return True
End Function


Function BVM_CreateContext%(bDynamic% = True)
	Local hContext%
	If BVM_gMainCmdSet_% = 0 Then
		BVM_gMainCmdSet_% = BVM_CreateCommandSet(BVM_MAIN_CMD_SET_DEF_$)
		If BVM_gMainCmdSet_% = 0 Then
			BVM_SetLastError(1, "Execution context creation failed : unable to create associated command set 'coldsteel" + "'. Reason : " + BVM_GetLastErrorMsg())
			Return 0
		End If
	End If
	hContext% = BVM_CreateUninitializedContext_(BVM_gMainCmdSet_%, "coldsteel", bDynamic%, 0)
	Return hContext%
End Function


Function BVM_CreateInteractiveSession%(cmdSetName$, mainProgCode$ = "", bDynamic% = True)
	Local srcCode$
	Local session:BVM_TInteractiveSession
	session = New BVM_TInteractiveSession
	session.tmpModuleName1$ = ".test_interactive_console_tmp_old" + BVM_gInteractiveSessionCounter% + ".bbm"
	session.tmpModuleName2$ = ".test_interactive_console_tmp_new" + BVM_gInteractiveSessionCounter% + ".bbm"
	session.mainProgCode$ = mainProgCode$
	session.hCmdSet% = BVM_LoadCommandSet(cmdSetName$)
	srcCode$ = session.mainProgCode$ + "~n"+..
	"" + "Function UpdateConsole__()" + "~n"+..
	"" + "End Function"
	session.hModule% = BVM_CompileString(srcCode$, session.hCmdSet%, session.tmpModuleName1$, 3)
	session.hContext% = BVM_CreateContext(bDynamic%)
	BVM_MapModule(session.hContext%, session.hModule%)
	BVM_gInteractiveSessionCounter% = BVM_gInteractiveSessionCounter% + 1
	Return HandleFromObject (session)
End Function


Function BVM_UpdateInteractiveSession%(hSession% = 0, newSourceCode$)
	Local srcCode$
	Local hTmpModule%
	Local session:BVM_TInteractiveSession
	Local hEntryPoint%
	session = BVM_TInteractiveSession(HandleToObject(hSession%))
	If session = Null Then
		BVM_SetLastError(1, "Invalid session handle")
		Return BVM_INVALID_INT_SESSION%
	End If
	srcCode$ = session.mainProgCode$ + "~n"+..
	"" + "Function UpdateConsole__()" + "~n"+..
	"" + newSourceCode$ + "~n"+..
	"" + "End Function"
	hTmpModule% = BVM_CompileString(srcCode$, session.hCmdSet%, session.tmpModuleName2$, 3)
	If hTmpModule% = 0 Then
		Return False
	End If
	If (BVM_ReplaceModule(session.hModule%, hTmpModule%) = 0) Then
		Return False
	End If
	hEntryPoint% = BVM_FindEntryPoint(session.hContext%, session.hModule%, "UpdateConsole__")
	BVM_SelectContext(session.hContext%)
	BVM_SelectEntryPoint(hEntryPoint%)
	BVM_Invoke()
	BVM_PopInt()
	Return True
End Function


Function BVM_DeleteInteractiveSession%(hSession% = 0)
	Local session:BVM_TInteractiveSession
	session = BVM_TInteractiveSession(HandleToObject(hSession%))
	If session <> Null Then
		If session.hContext% <> 0 Then
			BVM_DeleteContext(session.hContext%)
			session.hContext% = 0
			BVM_ReleaseModule(session.hModule%)
		End If
	End If
	Return True
End Function


Function BVM_HELPER_InterpretFile%(sourceFileName$, cmdSetFileName$, functionName$ = "_main", compilationFlags% = 0, bEnableDebug% = False, bStartHalted% = False, bDynamic% = True)
	Local hEntryPoint%
	Local hModule%
	Local hContext%
	Local hCommandSet%
	Local hPrevContext%

	hPrevContext% = BVM_GetSelectedContext()

	' We load the 'coldsteel' command set
	hCommandSet% = BVM_LoadCommandSet(cmdSetFileName$)
	If hCommandSet% = BVM_INVALID_CMD_SET% Then
		Return False
	End If

	' We compile the temporary file
	hModule% = BVM_CompileFile(sourceFileName$, hCommandSet%, "___tmp_mod___" + BVM_IntToStr(BVM_TempModuleCounter%) + ".bbm", compilationFlags%)
	If hModule% = BVM_INVALID_MODULE% Then
		BVM_DeleteCommandSet(hCommandSet%)
		Return False
	End If

	BVM_TempModuleCounter% = BVM_TempModuleCounter% + 1

	' We create a context
	hContext% = BVM_CreateContext(bDynamic%)
	If hContext% = BVM_INVALID_CONTEXT% Then
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		Return False
	End If

	' We Select the context
	If (BVM_SelectContext(hContext%) = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		Return False
	End If

	If bEnableDebug% Then
		BVM_StartDebug(hContext%)
	End If

	' We map the module
	If (BVM_MapModule(hContext%, hModule%, bStartHalted%) = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		Return False
	End If

	' Do we just have to execute the main program? If so it's already done,
	' (by the mapping) so just return
	If BVM_StrIEq(functionName$, "_main") Or functionName$ = "" Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		BVM_SelectContext(hPrevContext%)
		Return True
	End If

	' We get the entry point
	hEntryPoint% = BVM_FindEntryPoint(hContext%, hModule%, functionName$)
	If hEntryPoint% = BVM_INVALID_ENTRY_POINT% Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	' We select the entry point
	If (BVM_SelectEntryPoint(hEntryPoint%) = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	' We execute the code
	If (BVM_Invoke() = 0) Then
		BVM_ReleaseModule(hModule%)
		BVM_DeleteContext(hContext%)
		BVM_DeleteCommandSet(hCommandSet%)
		BVM_SelectContext(hPrevContext%)
		Return False
	End If

	BVM_ReleaseModule(hModule%)
	BVM_DeleteContext(hContext%)
	BVM_DeleteCommandSet(hCommandSet%)
	BVM_SelectContext(hPrevContext%)

	Return True
End Function


Function BVM_GetCallByNameEntryPoint_%(hContext__% = 0, modName__$, funcName__$)
	Local hModule%
	If hContext__% = BVM_INVALID_CONTEXT% Then
		hContext__% = BVM_GetSelectedContext()
	End If
	If modName__$ = "" Then
		hModule% = BVM_GetMappedModule(hContext__%, BVM_CountMappedModules(hContext__%) - 1)
	Else
		hModule% = BVM_FindMappedModule(hContext__%, modName__$)
	End If
	Return BVM_FindEntryPoint(hContext__%, hModule%, funcName__$)
End Function


Function BVM_RegisterObject%(hContext%, obj:Object)
	' Explicitely registers a host object
	Return BVM_RegisterObject_(hContext%, obj, BVM_HostObjectToTypeId_(obj))
End Function


Function BVM_HostObjectToTypeId_%(obj:Object)
	Return -1
End Function


Function BVM_RealObj2Hnd__%(obj:Object)
	Return BVM_RealObj2Hnd_(obj, BVM_HostObjectToTypeId_(obj))
End Function


Function BVM_TContext_RealObj2Hnd__%(context:BVM_TContext, obj:Object)
	Return context.RegisterObject_(obj, BVM_HostObjectToTypeId_(obj))
End Function


