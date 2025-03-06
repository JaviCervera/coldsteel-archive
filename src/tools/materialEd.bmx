Strict

Framework BRL.MaxGUI
Import BRL.Win32MaxGUI
Import BRL.CocoaMaxGUI
Import BRL.FLTKMaxGUI
Import BRL.PNGLoader
Import BRL.Retro
Import BRL.Timer
Import BRL.EventQueue
Import Usr.ColdSteel

?Win32
Import "common/xpmanifest.o"
?

Import "common/key.bmx"

Include "materialEd/app.bmx"
Include "materialEd/ui.bmx"
Include "materialEd/scene.bmx"
Include "materialEd/material.bmx"
Include "materialEd/requester.bmx"
Include "common/misc.bmx"
Include "common/requester.bmx"
Include "common/settings.bmx"

Const VERSION$ = "0.9.5"
Const ABOUT$ = "ColdSteel Material Editor - Version " + VERSION$ + "~n    http://www.coldsteelengine.com"
Const WINTITLE$ = "ColdSteel Material Editor"
Const DEMO = 0

If DEMO = 0 Then InitKey()

'DebugStop

App.Init
Repeat
	App.Loop
Forever