Function CreateFontPixmap:TPixmap(pixmapsize = 256)
	Local firstChar = 32, lastChar = 381
	Local charCount = lastChar - firstChar

	Local testString$ = ""
	For Local i = 0 Until charCount
		testString$ :+ Chr$(firstChar + i)
	Next

	Local win:TGadget = CreateWindow("", 0, 0, 100, 100, Null, WINDOW_HIDDEN)
	Local canvas:TGadget = CreateCanvas(0, 0, pixmapsize, pixmapsize, win)
	SetGraphics CanvasGraphics(canvas)
	Local f:TImageFont = LoadImageFont(Ui.fntFile$, Ui.fntSize, Ui.fntFlags)
	SetImageFont f
	Local x = 0, y = 0
	For Local i = 0 Until charCount
		SetColor 255, 255, 255; DrawText Chr$(firstChar + i), x, y
		SetColor 255, 255, 0; Plot x, y
		SetColor 255, 0, 0; Plot x + TextWidth(Chr$(firstChar + i)), y + TextHeight(Chr$(firstChar + i))
		x :+ TextWidth(Chr$(firstChar + i)) + 1
		If x + TextWidth(Chr$(firstChar + i)) => GraphicsWidth() Then x = 0; y :+ TextHeight(Chr$(firstChar + i)) + 1
	Next
	SetColor 255, 255, 0; Plot 0, 0
	SetColor 255, 0, 0; Plot 1, 0
	SetColor 0, 0, 0; Plot 2, 0
	Local pixmap:TPixmap = GrabPixmap(0, 0, GraphicsWidth(), GraphicsHeight())
	FreeGadget win
	Return pixmap
End Function