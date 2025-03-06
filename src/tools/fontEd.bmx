Strict

Framework BRL.MaxGUI
Import BRL.Win32MaxGUI
Import BRL.CocoaMaxGUI
Import BRL.FLTKMaxGUI
Import BRL.Max2D
Import BRL.GLMax2D
Import BRL.FreeTypeFont
Import BRL.PNGLoader
Import BRL.Retro
Import BRL.EventQueue

?Win32
Import "common/xpmanifest.o"
?

Include "fontEd/app.bmx"
Include "fontEd/ui.bmx"
Include "fontEd/font.bmx"
Include "fontEd/requester.bmx"

Const VERSION$ = "0.9.5"
Const ABOUT$ = "ColdSteel Font Editor - Version " + VERSION$ + "~n http://www.coldsteelengine.com"
Const WINTITLE$ = "ColdSteel Font Editor"
Const WINWIDTH = 400
Const WINHEIGHT = 300

App.Init
Repeat
	App.Loop
Forever