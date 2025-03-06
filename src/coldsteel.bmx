Strict

Module Usr.ColdSteel

ModuleInfo "Version: 0.9.4"
ModuleInfo "Author: Javier 'Jedive' San Juan"
ModuleInfo "License: Commercial"

Import "ColdSteelImports.bmx"

Const CSDFE_RENDERTOTEXTURE = 0
Const CSDFE_BILINEARFILTER = 1
Const CSDFE_HARDWARETNL = 2
Const CSDFE_MIPMAP = 3
Const CSDFE_STENCILBUFFER = 4
Const CSDFE_VERTEXSHADER11 = 5
Const CSDFE_VERTEXSHADER20 = 6
Const CSDFE_VERTEXSHADER30 = 7
Const CSDFE_PIXELSHADER11 = 8
Const CSDFE_PIXELSHADER12 = 9
Const CSDFE_PIXELSHADER13 = 10
Const CSDFE_PIXELSHADER14 = 11
Const CSDFE_PIXELSHADER20 = 12
Const CSDFE_PIXELSHADER30 = 13
Const CSDFE_ARB_VERTEXPROGRAM1 = 14
Const CSDFE_ARB_FRAGMENTPROGRAM1 = 15
Const CSDF_FULLSCREEN = 1
Const CSDF_VSYNC = 2
Const CSDF_ANTIALIAS = 4
Const CSDF_OPENGL = 65536
Const CSEV_INIT = 101
Const CSEV_FINISH = 102
Const CSEV_FRAME = 103
Const CSEV_DISPLAY_OPEN = 201
Const CSEV_KEY_HIT = 301
Const CSEV_KEY_RELEASE = 302
Const CSEV_MOUSE_MOVE = 401
Const CSEV_MOUSE_HIT = 402
Const CSEV_MOUSE_RELEASE = 403
Const CSMB_LEFT = 1
Const CSMB_RIGHT = 2
Const CSMB_MIDDLE = 3
Const CSKEY_LBUTTON = $01
Const CSKEY_RBUTTON = $02
Const CSKEY_CANCEL = $03
Const CSKEY_MBUTTON = $04
Const CSKEY_XBUTTON1 = $05
Const CSKEY_XBUTTON2 = $06
Const CSKEY_BACK = $08
Const CSKEY_TAB = $09
Const CSKEY_CLEAR = $0C
Const CSKEY_RETURN = $0D
Const CSKEY_ENTER = $0D
Const CSKEY_SHIFT = $10
Const CSKEY_CONTROL = $11
Const CSKEY_MENU = $12
Const CSKEY_PAUSE = $13
Const CSKEY_CAPITAL = $14
Const CSKEY_KANA = $15
Const CSKEY_HANGUEL = $15
Const CSKEY_HANGUL = $15
Const CSKEY_JUNJA = $17
Const CSKEY_FINAL = $18
Const CSKEY_HANJA = $19
Const CSKEY_KANJI = $19
Const CSKEY_ESC = $1B
Const CSKEY_ESCAPE = $1B
Const CSKEY_CONVERT = $1C
Const CSKEY_NONCONVERT = $1D
Const CSKEY_ACCEPT = $1E
Const CSKEY_MODECHANGE = $1F
Const CSKEY_SPACE = $20
Const CSKEY_PRIOR = $21
Const CSKEY_NEXT = $22
Const CSKEY_END = $23
Const CSKEY_HOME = $24
Const CSKEY_LEFT = $25
Const CSKEY_UP = $26
Const CSKEY_RIGHT = $27
Const CSKEY_DOWN = $28
Const CSKEY_SELECT = $29
Const CSKEY_PRINT = $2A
Const CSKEY_EXECUT = $2B
Const CSKEY_SNAPSHOT = $2C
Const CSKEY_INSERT = $2D
Const CSKEY_DELETE = $2E
Const CSKEY_HELP = $2F
Const CSKEY_0 = $30
Const CSKEY_1 = $31
Const CSKEY_2 = $32
Const CSKEY_3 = $33
Const CSKEY_4 = $34
Const CSKEY_5 = $35
Const CSKEY_6 = $36
Const CSKEY_7 = $37
Const CSKEY_8 = $38
Const CSKEY_9 = $39
Const CSKEY_A = $41
Const CSKEY_B = $42
Const CSKEY_C = $43
Const CSKEY_D = $44
Const CSKEY_E = $45
Const CSKEY_F = $46
Const CSKEY_G = $47
Const CSKEY_H = $48
Const CSKEY_I = $49
Const CSKEY_J = $4A
Const CSKEY_K = $4B
Const CSKEY_L = $4C
Const CSKEY_M = $4D
Const CSKEY_N = $4E
Const CSKEY_O = $4F
Const CSKEY_P = $50
Const CSKEY_Q = $51
Const CSKEY_R = $52
Const CSKEY_S = $53
Const CSKEY_T = $54
Const CSKEY_U = $55
Const CSKEY_V = $56
Const CSKEY_W = $57
Const CSKEY_X = $58
Const CSKEY_Y = $59
Const CSKEY_Z = $5A
Const CSKEY_LWIN = $5B
Const CSKEY_RWIN = $5C
Const CSKEY_APPS = $5D
Const CSKEY_SLEEP = $5F
Const CSKEY_NUMPAD0 = $60
Const CSKEY_NUMPAD1 = $61
Const CSKEY_NUMPAD2 = $62
Const CSKEY_NUMPAD3 = $63
Const CSKEY_NUMPAD4 = $64
Const CSKEY_NUMPAD5 = $65
Const CSKEY_NUMPAD6 = $66
Const CSKEY_NUMPAD7 = $67
Const CSKEY_NUMPAD8 = $68
Const CSKEY_NUMPAD9 = $69
Const CSKEY_MULTIPLY = $6A
Const CSKEY_ADD = $6B
Const CSKEY_SEPARATOR = $6C
Const CSKEY_SUBTRACT = $6D
Const CSKEY_DECIMAL = $6E
Const CSKEY_DIVIDE = $6F
Const CSKEY_F1 = $70
Const CSKEY_F2 = $71
Const CSKEY_F3 = $72
Const CSKEY_F4 = $73
Const CSKEY_F5 = $74
Const CSKEY_F6 = $75
Const CSKEY_F7 = $76
Const CSKEY_F8 = $77
Const CSKEY_F9 = $78
Const CSKEY_F10 = $79
Const CSKEY_F11 = $7A
Const CSKEY_F12 = $7B
Const CSKEY_F13 = $7C
Const CSKEY_F14 = $7D
Const CSKEY_F15 = $7E
Const CSKEY_F16 = $7F
Const CSKEY_F17 = $80
Const CSKEY_F18 = $81
Const CSKEY_F19 = $82
Const CSKEY_F20 = $83
Const CSKEY_F21 = $84
Const CSKEY_F22 = $85
Const CSKEY_F23 = $86
Const CSKEY_F24 = $87
Const CSKEY_NUMLOCK = $90
Const CSKEY_SCROLL = $91
Const CSKEY_LSHIFT = $A0
Const CSKEY_RSHIFT = $A1
Const CSKEY_LCONTROL = $A2
Const CSKEY_RCONTROL = $A3
Const CSKEY_LMENU = $A4
Const CSKEY_RMENU = $A5
Const CSKEY_COMMA = $BC
Const CSKEY_PLUS = $BB
Const CSKEY_MINUS = $BD
Const CSKEY_PERIOD = $BE
Const CSKEY_ATTN = $F6
Const CSKEY_CRSEL = $F7
Const CSKEY_EXSEL = $F8
Const CSKEY_EREOF = $F9
Const CSKEY_PLAY = $FA
Const CSKEY_ZOOM = $FB
Const CSKEY_PA1 = $FD
Const CSKEY_OEM_CLEAR = $FE
Const CSLT_POINT = 0
Const CSLT_DIRECTIONAL = 1
Const CSMF_FULLBRIGHT = 1
Const CSMF_FLATSHADING = 2
Const CSMF_FOG = 4
Const CSMF_NOCULL = 8
Const CSMF_WIREFRAME = 16
Const CSMF_NOZDEPTH = 32
Const CSMF_NOZWRITE = 64
Const CSMF_ANISOTROPIC = 128
Const CSMT_MODULATE = 1
Const CSMT_MODULATE2X = 2
Const CSMT_MODULATE4X = 3
Const CSMT_DETAIL = 4
Const CSMT_ADD = 5
Const CSMT_VERTEX_ALPHA = 6
Const CSMT_ALPHA = 7
Const CSMT_MASKED = 8
Const CSMT_REFLECTION = 9
Const CSMT_REFLECTION_ALPHA = 10
Const CSMT_NORMAL = 11
Const CSMT_PARALLAX = 12
Const CSCI_NULL = 0
Const CSCI_BBOX = 1
Const CSCI_TRIANGLES = 2
Const CSCI_OCTREE = 3
Const CSNT_EMPTY = 0
Const CSNT_BILLBOARD = 1
Const CSNT_BODY = 2
Const CSNT_CAMERA = 3
Const CSNT_EMITTER = 4
Const CSNT_LIGHT = 5
Const CSNT_MESH = 6
Const CSNT_MESH_OCTREE = 7
Const CSNT_TERRAIN = 8
Const CSNT_WATER = 9
Const CSPT_POINT = 0
Const CSPT_BOX = 1
Const CSCF_BACKBUFFER = 1
Const CSCF_ZBUFFER = 2
Const CSTS_VIEW = 0
Const CSTS_WORLD = 1
Const CSTS_PROJECTION = 2
Const CSPSF_11 = 0
Const CSPSF_12 = 1
Const CSPSF_13 = 2
Const CSPSF_14 = 3
Const CSPSF_20 = 4
Const CSPSF_2A = 5
Const CSPSF_2B = 6
Const CSPSF_30 = 7
Const CSVSF_11 = 0
Const CSVSF_20 = 1
Const CSVSF_2A = 2
Const CSVSF_30 = 3
Const CSXML_NONE = 0
Const CSXML_ELEMENT = 1
Const CSXML_ELEMENTEND = 2
Const CSXML_TEXT = 3
Const CSXML_COMMENT = 4
Const CSXML_UNKNOWN = 5

Extern
Function csCoreInit%()
Function csCoreFinish%()
Function csCoreMessage%(msg_$z, error_)
Function csBillboardNode%(parent_)
Function csBillboardResize%(billboard_, width_#, height_#)
Function csBillboardWidth#(billboard_)
Function csBillboardHeight#(billboard_)
Function csCameraNode%(parent_)
Function csCameraViewport%(cam_, x1_#, y1_#, x2_#, y2_#)
Function csCameraRange%(cam_, near_#, far_#)
Function csCameraFov%(cam_, fov_#)
Function csCameraAspectRatio%(cam_, ratio_#)
Function csCameraProjection%(cam_, width_#, height_#, near_#, far_#, ortho_)
Function csCameraLine%(cam_, x_, y_, line_vec_start_, line_vec_end_)
Function csCameraPickNode%(cam_, x_, y_, group_)
Function csCameraToScreen%(cam_, x_#, y_#, z_#, vec_out_)
Function csCameraRenderTarget%(cam_, texture_)
Function csCollisionSlide%(node_, pos_x_#, pos_y_#, pos_z_#, dest_x_#, dest_y_#, dest_z_#, rad_x_#, rad_y_#, rad_z_#, vec_pos_, vec_tri_a_, vec_tri_b_, vec_tri_c_)
Function csCollisionLinePick%(node_, pos_x_#, pos_y_#, pos_z_#, dest_x_#, dest_y_#, dest_z_#, vec_pos_, vec_tri_a_, vec_tri_b_, vec_tri_c_)
Function csCollisionLineNode%(pos_x_#, pos_y_#, pos_z_#, dest_x_#, dest_y_#, dest_z_#)
Function csPackageAdd%(pak_$z)
Function csDirList%(dir_$z)
Function csDirClose%(dir_)
Function csDirFileCount%(dir_)
Function csDirFileName$z(dir_, index_)
Function csDirFileIsDir%(dir_, index_)
Function csDisplayOpen%(width_, height_, depth_, flags_, win_)
Function csDisplayClose%()
Function csDisplayCaption%(caption_$z)
Function csDisplayClosed%()
Function csDisplayWidth%()
Function csDisplayHeight%()
Function csDisplayFps%()
Function csDisplayFeature%(feature_)
Function csDisplayResize%(width_, height_)
Function csDisplayActive%()
Function csGetColor%(red_, green_, blue_, alpha_)
Function csGetRed%(color_)
Function csGetGreen%(color_)
Function csGetBlue%(color_)
Function csGetAlpha%(color_)
Function csSetColor%(color_)
Function csViewport%(x_, y_, w_, h_)
Function csDrawLine%(x_, y_, x1_, y1_)
Function csDrawRect%(x_, y_, w_, h_)
Function csDrawTexture%(tex_, x_, y_)
Function csDrawText%(font_, text_$z, x_, y_)
Function csTextWidth%(font_, text_$z)
Function csTextHeight%(font_, text_$z)
Function csEffectRegister%(effect_$z, base_mat_)
Function csEffectRegisterFile%(effect_file_$z, base_mat_)
Function csEffectSetTechnique%(effect_, technique_$z)
Function csEffectSetTexture%(effect_, var_name_$z, texture_)
Function csEffectSetBool%(effect_, var_name_$z, value_)
Function csEffectSetInt%(effect_, var_name_$z, value_)
Function csEffectSetFloat%(effect_, var_name_$z, value_#)
Function csEffectSetVector%(effect_, var_name_$z, vector_)
Function csEffectSetMatrix%(effect_, var_name_$z, matrix_)
Function csEmitterNode%(particle_data_, parent_)
Function csEmitterAddFadeOutAffector%(emitter_, color_, time_)
Function csEmitterAddGravityAffector%(emitter_, grav_x_#, grav_y_#, grav_z_#, time_)
Function csEmitterRemoveAffectors%(emitter_)
Function csEventGet%()
Function csEventPoll%()
Function csEventPost%(id_, from_, to_, a_#, b_#, c_#, str_$z)
Function csEventId%()
Function csEventFrom%()
Function csEventTo%()
Function csEventA#()
Function csEventB#()
Function csEventC#()
Function csEventData$z()
Function csFileRead%(file_$z)
Function csFileWrite%(file_$z)
Function csFileClose%(file_)
Function csFileSize%(file_)
Function csFilePos%(file_)
Function csFileSeek%(file_, pos_, relative_)
Function csFileReadByte%(file_)
Function csFileReadShort%(file_)
Function csFileReadInt%(file_)
Function csFileReadFloat#(file_)
Function csFileReadString$z(file_)
Function csFileReadBytes%(file_, buf_, size_)
Function csFileWriteByte%(file_, value_)
Function csFileWriteShort%(file_, value_)
Function csFileWriteInt%(file_, value_)
Function csFileWriteFloat%(file_, value_#)
Function csFileWriteString%(file_, str_$z)
Function csFileWriteBytes%(file_, buf_, size_)
Function csFileGetExt$z(filename_$z)
Function csFileGetDir$z(filename_$z)
Function csFileStripExt$z(filename_$z)
Function csFileStripDir$z(filename_$z)
Function csFontLoad%(file_$z)
Function csFontFree%(font_)
Function csMousePosition%(x_, y_)
Function csMouseHide%(hide_)
Function csMouseX%()
Function csMouseY%()
Function csMouseHit%(button_)
Function csMouseDown%(button_)
Function csMouseGet%()
Function csMouseReleased%()
Function csKeyHit%(key_)
Function csKeyDown%(key_)
Function csKeyGet%()
Function csKeyReleased%()
Function csJoyName$z(id_)
Function csJoyButton%(id_, button_)
Function csJoyAxis#(id_, axis_)
Function csJoyNumAxes%(id_)
Function csLightNode%(parent_)
Function csLightType%(light_, type_)
Function csLightRadius%(light_, radius_#)
Function csLightAmbient%(light_, color_)
Function csLightDiffuse%(light_, color_)
Function csLightSpecular%(light_, color_)
Function csMaterialCreate%(name_$z)
Function csMaterialLoad%(file_$z)
Function csMaterialSave%(mat_, file_$z, rel_path_$z)
Function csMaterialFree%(mat_)
Function csMaterialFind%(name_$z)
Function csMaterialSetType%(mat_, newtype_)
Function csMaterialSetFlags%(mat_, flags_)
Function csMaterialSetTexture%(mat_, tex_, layer_)
Function csMaterialSetAmbient%(mat_, color_)
Function csMaterialSetDiffuse%(mat_, color_)
Function csMaterialSetEmissive%(mat_, color_)
Function csMaterialSetSpecular%(mat_, color_)
Function csMaterialSetShininess%(mat_, shininess_#)
Function csMaterialSetParam%(mat_, param_#)
Function csMaterialGetName$z(mat_)
Function csMaterialGetType%(mat_)
Function csMaterialGetFlags%(mat_)
Function csMaterialGetTexture%(mat_, layer_)
Function csMaterialGetAmbient%(mat_)
Function csMaterialGetDiffuse%(mat_)
Function csMaterialGetEmissive%(mat_)
Function csMaterialGetSpecular%(mat_)
Function csMaterialGetShininess#(mat_)
Function csMaterialGetParam#(mat_)
Function csMathFloor#(val_#)
Function csMathCeil#(val_#)
Function csMathAbs#(val_#)
Function csMathSqr#(val_#)
Function csMathSin#(val_#)
Function csMathCos#(val_#)
Function csMathTan#(val_#)
Function csMathASin#(val_#)
Function csMathACos#(val_#)
Function csMathATan#(val_#)
Function csMathATan2#(x_#, y_#)
Function csMathExp#(val_#)
Function csMathLog#(val_#)
Function csMathLog10#(val_#)
Function csMathRand%(min_, max_)
Function csMathRandSeed%(seed_)
Function csMatrixCreate%()
Function csMatrixFree%(matrix_)
Function csMatrixAdd%(matrix_, matrix2_)
Function csMatrixCopy%(matrix_, matrix2_)
Function csMatrixDiv%(matrix_, matrix2_)
Function csMatrixElement#(matrix_, row_, column_)
Function csMatrixEqual%(matrix_, matrix2_)
Function csMatrixGetRotation%(matrix_, vector_)
Function csMatrixGetTranslation%(matrix_, vector_)
Function csMatrixIdentity%(matrix_)
Function csMatrixInterpolate%(matrix_, matrix2_, time_#)
Function csMatrixInvert%(matrix_)
Function csMatrixMul%(matrix_, matrix2_)
Function csMatrixSet%(matrix_, row_, column_, val_#)
Function csMatrixSetRotation%(matrix_, vector_)
Function csMatrixSetScale%(matrix_, vector_)
Function csMatrixSetTranslation%(matrix_, vector_)
Function csMatrixSub%(matrix_, matrix2_)
Function csMatrixTranspose%(matrix_)
Function csMeshLoad%(file_$z)
Function csMeshTerrainLoad%(heightmap_$z)
Function csMeshFree%(mesh_)
Function csMeshNode%(mesh_, parent_, col_info_, tangent_mesh_)
Function csMeshOctreeNode%(mesh_, parent_, col_info_, tangent_mesh_)
Function csMeshScale%(mesh_, sx_#, sy_#, sz_#)
Function csMeshFlip%(mesh_)
Function csMeshUpdateNormals%(mesh_)
Function csMeshVerticesColor%(mesh_, color_, change_alpha_)
Function csMeshPlanarMapping%(mesh_, resolution_#)
Function csMeshWidth#(mesh_)
Function csMeshHeight#(mesh_)
Function csMeshDepth#(mesh_)
Function csNodeEmpty%(parent_)
Function csNodeFree%(node_)
Function csNodeType%(node_)
Function csNodeSetName%(node_, name_$z)
Function csNodeGetName$z(node_)
Function csNodePosition%(node_, x_#, y_#, z_#)
Function csNodeMove%(node_, x_#, y_#, z_#)
Function csNodeRotate%(node_, pitch_#, yaw_#, roll_#)
Function csNodeTurn%(node_, pitch_#, yaw_#, roll_#)
Function csNodeScale%(node_, x_#, y_#, z_#)
Function csNodeX#(node_, absolute_)
Function csNodeY#(node_, absolute_)
Function csNodeZ#(node_, absolute_)
Function csNodePitch#(node_)
Function csNodeYaw#(node_)
Function csNodeRoll#(node_)
Function csNodeScaleX#(node_)
Function csNodeScaleY#(node_)
Function csNodeScaleZ#(node_)
Function csNodeWidth#(node_)
Function csNodeHeight#(node_)
Function csNodeDepth#(node_)
Function csNodeCastShadow%(node_, cast_)
Function csNodeHide%(node_, state_)
Function csNodeMaterials%(node_)
Function csNodeGetMaterial%(node_, mat_index_)
Function csNodeSetMaterial%(node_, mat_, mat_index_)
Function csNodeSetMaterialFast%(node_, index_, type_, flags_, tex1_, tex2_)
Function csNodeSetMaterialFlag%(node_, index_, flag_, state_)
Function csNodeSetPickGroup%(n_, group_)
Function csNodeSetProperty%(node_, name_$z, value_$z)
Function csNodeProperties%(node_)
Function csNodeFindProperty%(node_, name_$z)
Function csNodePropertyName$z(node_, index_)
Function csNodePropertyValue$z(node_, index_)
Function csNodeRemoveProperty%(node_, index_)
Function csNodeSetParent%(node_, parent_)
Function csNodeGetParent%(node_)
Function csNodeChildren%(node_)
Function csNodeChild%(node_, index_)
Function csNodeFindChild%(node_, name_$z, recursive_)
Function csNodeSpeed%(node_, fps_)
Function csNodeLoop%(node_, loop_)
Function csNodeSetFrame%(node_, start_, finish_)
Function csNodeGetFrame%(node_)
Function csNodeAttachToBone%(n_, n2_, bonename_$z)
Function csNodeLookAt%(node_, x_#, y_#, z_#)
Function csParticleDataCreate%(name_$z)
Function csParticleDataLoad%(file_$z)
Function csParticleDataSave%(part_data_, file_$z)
Function csParticleDataFree%(part_data_)
Function csParticleDataFind%(name_$z)
Function csParticleDataSetMaterial%(part_data_, mat_name_$z)
Function csParticleDataSetType%(part_data_, type_)
Function csParticleDataSetBox%(part_data_, width_#, height_#, depth_#)
Function csParticleDataSetDirection%(part_data_, x_#, y_#, z_#)
Function csParticleDataSetRate%(part_data_, min_, max_)
Function csParticleDataSetColor%(part_data_, min_, max_)
Function csParticleDataSetLifeTime%(part_data_, min_, max_)
Function csParticleDataSetMaxAngle%(part_data_, angle_)
Function csParticleDataSetSize%(part_data_, width_#, height_#)
Function csParticleDataAddFadeOutAffector%(part_data_, color_, time_)
Function csParticleDataAddGravityAffector%(part_data_, grav_x_#, grav_y_#, grav_z_#, time_)
Function csParticleDataGetName$z(part_)
Function csParticleDataGetMaterial$z(part_)
Function csParticleDataGetType%(part_)
Function csParticleDataGetBoxWidth#(part_)
Function csParticleDataGetBoxHeight#(part_)
Function csParticleDataGetBoxDepth#(part_)
Function csParticleDataGetDirectionX#(part_)
Function csParticleDataGetDirectionY#(part_)
Function csParticleDataGetDirectionZ#(part_)
Function csParticleDataGetMinRate%(part_)
Function csParticleDataGetMaxRate%(part_)
Function csParticleDataGetMinColor%(part_)
Function csParticleDataGetMaxColor%(part_)
Function csParticleDataGetMinLifeTime%(part_)
Function csParticleDataGetMaxLifeTime%(part_)
Function csParticleDataGetMaxAngle%(part_)
Function csParticleDataGetWidth#(part_)
Function csParticleDataGetHeight#(part_)
Function csParticleDataAffectors%(part_)
Function csParticleDataGetAffectorType%(part_, index_)
Function csParticleDataGetAffectorColor%(part_, index_)
Function csParticleDataGetAffectorTime%(part_, index_)
Function csParticleDataGetAffectorGravityX#(part_, index_)
Function csParticleDataGetAffectorGravityY#(part_, index_)
Function csParticleDataGetAffectorGravityZ#(part_, index_)
Function csSceneBegin%(clear_flags_, color_)
Function csSceneEnd%()
Function csSceneRender%(camera_)
Function csSceneAmbient%(color_)
Function csSceneFog%(color_, near_#, far_#)
Function csSceneSkybox%(top_, bottom_, left_, right_, front_, back_)
Function csSceneTransformation%(state_, matrix_)
Function csShaderRegister%(pixel_shader_$z, pixel_entry_$z, pixel_format_, vertex_shader_$z, vertex_entry_$z, vertex_format_, base_mat_)
Function csShaderRegisterFile%(pixel_file_$z, pixel_entry_$z, pixel_format_, vertex_file_$z, vertex_entry_$z, vertex_format_, base_mat_)
Function csShaderAsmRegister%(pixel_shader_$z, vertex_shader_$z, base_material_)
Function csShaderAsmRegisterFile%(pixel_file_$z, vertex_file_$z, base_mat_)
Function csShaderPixelConstant%(shader_, name_$z, start_register_, data_, count_)
Function csShaderVertexConstant%(shader_, name_$z, start_register_, data_, count_)
Function csStringToInt%(str_$z)
Function csStringToFloat#(str_$z)
Function csStringFromInt$z(number_)
Function csStringFromFloat$z(number_#)
Function csStringLeft$z(str_$z, number_)
Function csStringRight$z(str_$z, num_)
Function csStringMid$z(str_$z, pos_, num_)
Function csStringReplace$z(str_$z, find_$z, replace_$z)
Function csStringFind%(str_$z, find_$z, offset_)
Function csStringUpper$z(str_$z)
Function csStringLower$z(str_$z)
Function csStringTrim$z(str_$z)
Function csStringChar$z(ascii_)
Function csStringAscii%(str_$z)
Function csStringLen%(str_$z)
Function csStringField$z(str_$z, delimiter_$z, index_)
Function csTerrainNode%(heightmap_$z, parent_, width_#, height_#, depth_#, col_info_)
Function csTerrainScaleTexture%(terrain_, scale1_#, scale2_#)
Function csTextureCreate%(width_, height_)
Function csTextureTargetCreate%(width_, height_)
Function csTextureLoad%(file_$z, mipmaps_)
Function csTextureFree%(tex_)
Function csTextureFile$z(tex_)
Function csTextureWidth%(tex_, original_)
Function csTextureHeight%(tex_, original_)
Function csTextureLock%(tex_)
Function csTextureUnlock%(tex_)
Function csTextureColorKey%(tex_, color_)
Function csTextureNormalize%(tex_, amplitude_#)
Function csTextureHWPointer%(tex_)
Function csVectorCreate%()
Function csVectorFree%(vector_)
Function csVectorAdd%(vector_, vector2_)
Function csVectorAddScale%(vector_, vector2_, scale_#)
Function csVectorBetween%(vector_, x0_#, y0_#, z0_#, x1_#, y1_#, z1_#)
Function csVectorCopy%(vector_, other_vector_)
Function csVectorCrossProduct%(vector_, vector2_)
Function csVectorDotProduct#(vector_, other_vector_)
Function csVectorEqual%(vector_, other_vector_, epsilon_#)
Function csVectorDistance#(vector_, x_#, y_#, z_#)
Function csVectorDistanceSquared#(vector_, x_#, y_#, z_#)
Function csVectorDiv%(vector_, vector2_)
Function csVectorInterpolate%(vector_, vector2_, d_#)
Function csVectorInvert%(vector_)
Function csVectorLength#(vector_)
Function csVectorLengthSquared#(vector_)
Function csVectorMul%(vector_, vector2_)
Function csVectorNormalize%(vector_)
Function csVectorScale%(vector_, scale_#)
Function csVectorSet%(vector_, x_#, y_#, z_#)
Function csVectorSub%(vector_, vector2_)
Function csVectorX#(vector_)
Function csVectorY#(vector_)
Function csVectorZ#(vector_)
Function csXMLRead%(file_$z)
Function csXMLWrite%(file_$z)
Function csXMLClose%(xml_)
Function csXMLReadNode%(xml_)
Function csXMLNodeType%(xml_)
Function csXMLNodeName$z(xml_)
Function csXMLNodeData$z(xml_)
Function csXMLAttributeCount%(xml_)
Function csXMLAttributeName$z(xml_, index_)
Function csXMLAttributeValue$z(xml_, index_)
Function csXMLWriteHeader%(xml_)
Function csXMLWriteElement%(xml_, name_$z, attributes_$z, empty_)
Function csXMLWriteClosingTag%(xml_, name_$z)
Function csXMLWriteText%(xml_, text_$z)
Function csXMLWriteLineBreak%(xml_)
End Extern
