Strict

Rem
Framework BRL.MaxGUI
Import BRL.Win32MaxGUI
Import BRL.CocoaMaxGUI
Import BRL.FLTKMaxGUI
Import BRL.PNGLoader
Import BRL.Retro
Import BRL.Timer
End Rem
Import Usr.ColdSteel

Import "common/key.bmx"

Include "guiEd/app.bmx"
Include "guiEd/ui.bmx"
Include "guiEd/scene.bmx"
'Include "materialEd/material.bmx"
'Include "materialEd/requester.bmx"
Include "common/misc.bmx"
Include "common/requester.bmx"
Include "common/settings.bmx"

Const VERSION$ = "0.9.2"
Const ABOUT$ = "ColdSteel Gui Editor - Version " + VERSION$ + "~n  http://www.coldsteelengine.com"
Const WINTITLE$ = "ColdSteel Gui Editor"

'InitKey()

App.Init
Repeat
	App.Loop
Forever