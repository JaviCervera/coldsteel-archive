Strict

Framework BRL.MaxGUI
Import BRL.Win32MaxGUI
Import BRL.CocoaMaxGUI
Import BRL.FLTKMaxGUI
Import BRL.PNGLoader
Import BRL.Retro
Import BRL.Timer
Import Usr.ColdSteel

?Win32
Import "common/xpmanifest.o"
?

Import "common/key.bmx"

Include "particleEd/app.bmx"
Include "particleEd/ui.bmx"
Include "particleEd/scene.bmx"
Include "particleEd/particles.bmx"
Include "particleEd/requester.bmx"
Include "common/misc.bmx"
Include "common/requester.bmx"
Include "common/settings.bmx"

Const VERSION$ = "0.9.6"
Const ABOUT$ = "ColdSteel Particle Editor - Version " + VERSION$ + "~n    http://www.coldsteelengine.com"
Const WINTITLE$ = "ColdSteel Particle Editor"
Const DEMO = 0

If DEMO = 0 Then InitKey()

App.Init
Repeat
	App.Loop
Forever