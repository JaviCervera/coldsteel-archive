Incbin "toolbar.png"

Const TOOLBAR_PREVIEW = 0
Const TOOLBAR_SAVE = 2
Const TOOLBAR_ABOUT = 4

Type Ui
	Global win:TGadget
	Global toolbar:TGadget
	Global fontGroup:TGadget
	Global fntFileButton:TGadget
	Global fntSizeCombo:TGadget
	Global fntBoldButton:TGadget
	Global fntItalicButton:TGadget
	Global fntFile$
	Global fntSize = 12
	Global fntFlags = SMOOTHFONT
	Global previewGroup:TGadget
	Global previewPanel:TGadget
	Global previewCanvas:TGadget
	Global pixmapSizeCombo:TGadget

	Function Init()
		'Create window
		win = CreateWindow(WINTITLE$, ClientWidth(Desktop())/2 - WINWIDTH/2, ClientHeight(Desktop())/2 - WINHEIGHT/2, WINWIDTH, WINHEIGHT, Null, WINDOW_TITLEBAR | WINDOW_STATUS | WINDOW_CLIENTCOORDS | WINDOW_HIDDEN)

		'Create toolbar
		toolbar = CreateToolBar("incbin::toolbar.png", 0, 0, 100, 0, win)
		SetToolBarTips toolbar, ["Preview", "", "Save", "", "About"]
		
		fontGroup = CreatePanel(4, GadgetY(toolbar) + GadgetHeight(toolbar) + 4, ClientWidth(win) - 8, 50, win, PANEL_GROUP, "Font:")
		fntFileButton = CreateButton("Font", 4, 4, 200, 20, fontGroup)
		fntSizeCombo = CreateComboBox(208, 4, 50, 20, fontGroup)
		fntBoldButton = CreateButton("Bold", 262, 4, 40, 20, fontGroup, BUTTON_CHECKBOX)
		fntItalicButton = CreateButton("Italic", 306, 4, 40, 20, fontGroup, BUTTON_CHECKBOX)
		Local sizes[] = [4, 6, 8, 9, 10, 11, 12, 14, 16, 18, 20, 22, 24, 26, 28, 36, 48, 56, 68, 72]
		For Local i = EachIn sizes
			AddGadgetItem fntSizeCombo, i
		Next
		SelectGadgetItem fntSizeCombo, 6
		
		previewGroup = CreatePanel(4, GadgetY(toolbar) + GadgetHeight(toolbar) + 60, ClientWidth(win) - 8, ClientHeight(win) - GadgetY(toolbar) - GadgetHeight(toolbar) - 94, win, PANEL_GROUP, "Preview:")
		previewPanel = CreatePanel(4, 4, ClientWidth(previewGroup) - 8, ClientHeight(previewGroup) - 8, previewGroup, PANEL_BORDER)
		previewCanvas = CreateCanvas(0, 0, ClientWidth(previewPanel), ClientHeight(previewPanel), previewPanel)
		UpdatePreview()

		CreateLabel("Bitmap font size:", ClientWidth(win) - 202, ClientHeight(win) - 26, 100, 20, win)
		pixmapSizeCombo = CreateComboBox(ClientWidth(win) - 102, ClientHeight(win) - 28, 100, 20, win)
		AddGadgetItem pixmapSizeCombo, "128x128"
		AddGadgetItem pixmapSizeCombo, "256x256", GADGETITEM_DEFAULT
		AddGadgetItem pixmapSizeCombo, "512x512"
		AddGadgetItem pixmapSizeCombo, "1024x1024"

		'Show window
		SetStatusText win, "Ready"
		ShowGadget win
		
	End Function
	
	Function Loop()
		Select EventID()
			Case EVENT_APPTERMINATE
				App.Quit
			Case EVENT_WINDOWCLOSE
				If EventSource() = win Then App.Quit
			Case EVENT_GADGETACTION
				Select EventSource()
					Case toolbar
						Select EventData()
							Case TOOLBAR_PREVIEW
								PreviewFont()
							Case TOOLBAR_SAVE
								Local pixmap:TPixmap = CreateFontPixmap(GadgetItemText$(pixmapSizeCombo, SelectedGadgetItem(pixmapSizeCombo)).ToInt())
								If pixmap
									Local file$ = RequestFile$("Save font:", "PNG Files:png", True, CurrentDir$() + "/" + StripDir$(StripExt$(fntFile$)) + fntSize + ".png")
									If file$ <> ""
										If Lower$(ExtractExt$(file$)) <> "png" Then file$ :+ ".png"
										SavePixmapPNG pixmap, file$, 9
										SetStatusText win, "Saved '" + file$ + "'"
									End If
								End If
							Case TOOLBAR_ABOUT
								Notify ABOUT$
						End Select
					Case fntFileButton
						Local file$ = RequestFileFont$()
						If file$ <> "" And FileType(file$) = FILETYPE_FILE Then fntFile$ = file$; SetGadgetText fntFileButton, "Font: " + StripDir$(file$)
					Case fntSizeCombo
						fntSize = GadgetItemText$(fntSizeCombo, SelectedGadgetItem(fntSizeCombo)).ToInt()
					Case fntBoldButton
						fntFlags = SMOOTHFONT
						If ButtonState(fntBoldButton) Then fntFlags :| BOLDFONT
						If ButtonState(fntItalicButton) Then fntFlags :| ITALICFONT
					Case fntItalicButton
						fntFlags = SMOOTHFONT
						If ButtonState(fntBoldButton) Then fntFlags :| BOLDFONT
						If ButtonState(fntItalicButton) Then fntFlags :| ITALICFONT
				End Select
				UpdatePreview()
			Case EVENT_GADGETPAINT
				If EventSource() = previewCanvas Then SetGraphics CanvasGraphics(previewCanvas); Flip
		End Select
	End Function
	
	Function Finish()
		FreeGadget win
		win = Null
	End Function
	
	Function UpdatePreview()
		Local t$ = "ABCDEF abcdef αινσϊÿ 1234567890"
		SetGraphics CanvasGraphics(previewCanvas)
		Local f:TImageFont = LoadImageFont(fntFile$, fntSize, fntFlags)
		SetImageFont f
		SetColor 255, 255, 255
		Cls
		DrawText t$, GraphicsWidth()/2 - TextWidth(t$)/2, GraphicsHeight()/2 - TextHeight(t$)/2
		Flip
	End Function
	
	Function PreviewFont()
		Local pixmap:TPixmap = CreateFontPixmap(GadgetItemText$(pixmapSizeCombo, SelectedGadgetItem(pixmapSizeCombo)).ToInt())
		Local win:TGadget = CreateWindow("Preview:", ClientWidth(Desktop())/2 - PixmapWidth(pixmap)/2, ClientHeight(Desktop())/2 - PixmapHeight(pixmap)/2, PixmapWidth(pixmap), PixmapHeight(pixmap), Ui.win, WINDOW_TITLEBAR | WINDOW_CLIENTCOORDS | WINDOW_TOOL)
		Local canvas:TGadget = CreateCanvas(0, 0, PixmapWidth(pixmap), PixmapHeight(pixmap), win)
		SetGraphics CanvasGraphics(canvas)
		DrawPixmap pixmap, 0, 0
		Repeat
			Select WaitEvent()
				Case EVENT_WINDOWCLOSE
					Exit
				Case EVENT_GADGETPAINT
					If EventSource() = canvas Then Flip
			End Select
		Forever
		FreeGadget win
		ActivateGadget Ui.win
	End Function
End Type
