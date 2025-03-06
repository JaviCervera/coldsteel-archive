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

?Win32
Import "common/xpmanifest.o"
?

Import "common/key.bmx"

Include "sceneEd/app.bmx"
Include "sceneEd/ui.bmx"
Include "sceneEd/scene.bmx"
Include "sceneEd/object.bmx"
Include "sceneEd/requester.bmx"
Include "common/misc.bmx"
Include "common/requester.bmx"
Include "common/settings.bmx"

Const VERSION$ = "0.9"
Const ABOUT$ = "ColdSteel Scene Editor - Version " + VERSION$ + "~n    http://www.coldsteelengine.com"
Const WINTITLE$ = "ColdSteel Scene Editor"

'InitKey()

App.Init
Repeat
	App.Loop
Forever