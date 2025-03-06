Strict

Framework BRL.MaxGui
Import Axe.Win32MaxGUI
Import BRL.CocoaMaxGUI
Import BRL.FLTKMaxGUI
Import BRL.Retro
Import BRL.PNGLoader
Import BRL.EventQueue

?Win32
Import "../common/xpmanifest.o"
?

'Incbin
Incbin "logo.png"
Rem
Incbin "Aurora/PROJECTNAME.src"
Incbin "BlitzMax/PROJECTNAME.bmx"
Incbin "BlitzPlus/PROJECTNAME.bb"
Incbin "BlitzPlus/coldsteel.bb"
Incbin "C/main.cpp"
Incbin "C/coldsteel.c"
Incbin "C/coldsteel.h"
Incbin "CodeBlocks/PROJECTNAME.cbp"
Incbin "DevCpp/PROJECTNAME.dev"
Incbin "IBPro/PROJECTNAME.iba"
Incbin "PureBasic/coldsteel.pbi"
Incbin "PureBasic/PROJECTNAME.pb"
Incbin "VisualC8/PROJECTNAME.vcproj"
End Rem

'Constants
Const WINDOW_WIDTH = 400
Const WINDOW_HEIGHT = 300
Const HEADER_WIDTH = WINDOW_WIDTH
Const HEADER_HEIGHT = 64
Const BODY_WIDTH = WINDOW_WIDTH
Const BODY_HEIGHT = WINDOW_HEIGHT - HEADER_HEIGHT - 48

Const PAGE_WELCOME = 1
Const PAGE_PROJECTINFO = 2
Const PAGE_READY = 3
Const PAGE_WORKING = 4

Type project
	Global title$
	Global location$
End Type

Type ui
	Global win:TGadget
	Global logo:TPixmap
	Global boldFont:TGuiFont
	Global pageTitle:TGadget	
	Global pageHeader:TGadget
	Global pageBody:TGadget
	Global backButton:TGadget
	Global nextButton:TGadget
	Global cancelButton:TGadget
	Global currentPage
	Global projectTypes$[] = ["Aurora", "BlitzMax", "BlitzPlus", "Code::Blocks", "Dev-C++", "Emergence Basic", "IBasic Professional", "PureBasic", "Visual C++ 2005"]
	Global projectType
	Global projectTitle$
	Global projectLocation$
	Global projectExporters:Int(path$)[] = [ExportAurora, ExportBlitzMax, ExportBlitzPlus, ExportCodeBlocks, ExportDevCpp, ExportEBasic, ExportIBasic, ExportPureBasic, ExportVisualC8]
End Type

'Main program
'--------------------------------------

ui.logo = LoadPixmap("incbin::logo.png")
ui.boldFont = LoadGuiFont("Tahoma", 9, True)

'Create window
ui.win = CreateWindow("ColdSteel Project Wizard", (ClientWidth(Desktop()) - WINDOW_WIDTH)/2, (ClientHeight(Desktop()) - WINDOW_HEIGHT)/2, WINDOW_WIDTH, WINDOW_HEIGHT, Null, WINDOW_TITLEBAR | WINDOW_CLIENTCOORDS)

'Ui upper section
SetPanelPixmap CreatePanel(0, 0, PixmapWidth(ui.logo), HEADER_HEIGHT, ui.win), ui.logo, PANELPIXMAP_CENTER
Local p:TGadget = CreatePanel(PixmapWidth(ui.logo), 0, HEADER_WIDTH - PixmapWidth(ui.logo), HEADER_HEIGHT, ui.win)
SetPanelColor p, 255, 255, 255

'Page title
ui.pageTitle = CreateLabel("", 8, 8, HEADER_WIDTH - 32, 16, p)
SetGadgetFont ui.pageTitle, ui.boldFont
SetGadgetColor ui.pageTitle, 255, 255, 255

'Page header
ui.pageHeader = CreateLabel("", 16, 28, HEADER_WIDTH - 32, HEADER_HEIGHT - 32, p)
SetGadgetColor ui.pageHeader, 255, 255, 255

'Page body
CreateLabel("", 0, HEADER_HEIGHT, BODY_WIDTH, 1, ui.win, LABEL_FRAME)
CreateLabel("", 0, HEADER_HEIGHT + BODY_HEIGHT, BODY_WIDTH, 1, ui.win, LABEL_FRAME)
ui.pageBody = CreatePanel(0, HEADER_HEIGHT+1, BODY_WIDTH, BODY_HEIGHT-2, ui.win)

'Buttons
ui.backButton = CreateButton("< Back", WINDOW_WIDTH - 250, WINDOW_HEIGHT - 34, 75, 24, ui.win)
ui.nextButton = CreateButton("Next >", WINDOW_WIDTH - 170, WINDOW_HEIGHT - 34, 75, 24, ui.win)
ui.cancelButton = CreateButton("Cancel", WINDOW_WIDTH - 90, WINDOW_HEIGHT - 34, 75, 24, ui.win)

ui.currentPage = PAGE_WELCOME
Repeat
	ClearPage()
	Select ui.currentPage
		Case PAGE_WELCOME
			PageWelcome()
		Case PAGE_PROJECTINFO
			PageProjectInfo()
		Case PAGE_READY
			PageReady()
		Case PAGE_WORKING
			PageWorking()
	End Select
Forever

Function ClearPage()
	FreeGadget ui.pageBody
	ui.pageBody = CreatePanel(0, HEADER_HEIGHT+1, BODY_WIDTH, BODY_HEIGHT-2, ui.win)
	EnableGadget ui.backButton
	EnableGadget ui.nextButton
End Function

Function PageWelcome()
	DisableGadget ui.backButton
	PageTitle("Welcome", "Welcome to the ColdSteel Engine Project Wizard")
	CreateLabel("This wizard will help you to create the needed project files to make a game in the ColdSteel Engine. In a few mouse clicks, you will have a project ready to run.", 16, 16, BODY_WIDTH - 100, BODY_HEIGHT - 32, ui.pageBody)
	Repeat
		Select WaitEvent()
			Case EVENT_APPTERMINATE
				End
			Case EVENT_WINDOWCLOSE
				If EventSource() = ui.win Then PostEvent CreateEvent(EVENT_APPTERMINATE)
			Case EVENT_GADGETACTION
				Select EventSource()
					Case ui.cancelButton
						PostEvent CreateEvent(EVENT_WINDOWCLOSE, ui.win)
					Case ui.nextButton
						ui.currentPage = PAGE_PROJECTINFO
						Exit
				End Select
		End Select
	Forever
End Function

Function PageProjectInfo()
	DisableGadget ui.nextButton
	PageTitle("Project name, location and type", "Choose a name, a location and a type for your new project")
	CreateLabel("Project Title", 16, 46, 100, 20, ui.pageBody)
	Local titleGad:TGadget = CreateTextField(116, 40, WINDOW_WIDTH - 130, 24, ui.pageBody)
	SetGadgetText titleGad, ui.projectTitle$
	CreateLabel("Project Location", 16, 76, 100, 20, ui.pageBody)
	Local locGad:TGadget = CreateTextField(116, 70, WINDOW_WIDTH - 200, 24, ui.pageBody)
	SetGadgetText locGad, ui.projectLocation$
	Local browseGad:TGadget = CreateButton("Browse", WINDOW_WIDTH - 80, 70, 64, 24, ui.pageBody)
	CreateLabel("Project Type", 16, 106, 100, 20, ui.pageBody)
	Local typeGad:TGadget = CreateComboBox(116, 100, WINDOW_WIDTH - 130, 26, ui.pageBody)
		For Local t$ = EachIn ui.projectTypes$
			AddGadgetItem typeGad, t$
		Next
		SelectGadgetItem typeGad, ui.projectType
	Local infoGad:TGadget = CreateLabel("", 16, 150, WINDOW_WIDTH - 32, 40, ui.pageBody)
	UpdateProjectInfo(titleGad, locGad, infoGad)
	Repeat
		Select WaitEvent()
			Case EVENT_APPTERMINATE
				End
			Case EVENT_WINDOWCLOSE
				If EventSource() = ui.win Then PostEvent CreateEvent(EVENT_APPTERMINATE)
			Case EVENT_GADGETACTION
				Select EventSource()
					Case ui.cancelButton
						PostEvent CreateEvent(EVENT_WINDOWCLOSE, ui.win)
					Case ui.backButton
						ui.currentPage = PAGE_WELCOME
						Exit
					Case ui.nextButton
						ui.currentPage = PAGE_READY
						Exit
					Case titleGad
						UpdateProjectInfo(titleGad, locGad, infoGad)
					Case locGad
						UpdateProjectInfo(titleGad, locGad, infoGad)
					Case browseGad
						Local path$ = RequestDir$("")
						If path$ <> ""
							SetGadgetText locGad, path$
							UpdateProjectInfo(titleGad, locGad, infoGad)
						End If
					Case typeGad
						ui.projectType = SelectedGadgetItem(typeGad)
				End Select
		End Select
	Forever
End Function

Function PageReady()
?Win32
	Local sepstr$ = "\"
?Mac
	Local sepstr$ = "/"
?Linux
	Local sepstr$ = "/"
?
	PageTitle("Ready", "The Project Wizard has collected the required information")
	Local text$ = "~n~nCreating a project with the following settings:~n~n"
		text :+ "~tTitle: " + ui.projectTitle$ + "~n"
		text :+ "~tLocation: " + ui.projectLocation$ + sepstr$ + ui.projectTitle$ + "~n"
		text :+ "~tType: " + ui.projectTypes$[ui.projectType] + "~n~n"
		text :+ "Click 'Next' to create the project and finish the process."
	CreateLabel(text$, 16, 16, BODY_WIDTH - 48, BODY_HEIGHT - 48, ui.pageBody)
	Repeat
		Select WaitEvent()
			Case EVENT_APPTERMINATE
				End
			Case EVENT_WINDOWCLOSE
				If EventSource() = ui.win Then PostEvent CreateEvent(EVENT_APPTERMINATE)
			Case EVENT_GADGETACTION
				Select EventSource()
					Case ui.cancelButton
						PostEvent CreateEvent(EVENT_WINDOWCLOSE, ui.win)
					Case ui.backButton
						ui.currentPage = PAGE_PROJECTINFO
						Exit
					Case ui.nextButton
						ui.currentPage = PAGE_WORKING
						Exit
				End Select
		End Select
	Forever
End Function

Function PageWorking()
	DisableGadget ui.backButton
	DisableGadget ui.nextButton
	DisableGadget ui.cancelButton
	PageTitle("Working...", "The project files are being created")
	
	'Create folder
	If FileType(ui.projectLocation$ + "/" + ui.projectTitle$) <> FILETYPE_DIR Then CreateDir(ui.projectLocation$ + "/" + ui.projectTitle$, True)
	
	'Copy dlls
	CopyFile("coldsteel.dll", ui.projectLocation$ + "/" + ui.projectTitle$ + "/coldsteel.dll")
	CopyFile("irrKlang.dll", ui.projectLocation$ + "/" + ui.projectTitle$ + "/irrKlang.dll")
	
	Export(ui.projectType)
	
	CreateLabel("Project generated.", 16, 16, BODY_WIDTH - 100, BODY_HEIGHT - 32, ui.pageBody)
	
	SetGadgetText ui.cancelButton, "Done"
	EnableGadget ui.cancelButton
	
	Repeat
		Select WaitEvent()
			Case EVENT_APPTERMINATE
				End
			Case EVENT_WINDOWCLOSE
				If EventSource() = ui.win Then PostEvent CreateEvent(EVENT_APPTERMINATE)
			Case EVENT_GADGETACTION
				Select EventSource()
					Case ui.cancelButton
						PostEvent CreateEvent(EVENT_WINDOWCLOSE, ui.win)
					'Case ui.backButton
					'	ui.currentPage = PAGE_READY
					'	Exit
				End Select
		End Select
	Forever
End Function

Function PageTitle(title$, desc$)
	SetGadgetText ui.pageTitle, title$
	SetGadgetText ui.pageHeader, desc$
	'HideGadget ui.pageTitle; ShowGadget ui.pageTitle	'Workaround to prevent the label having a background
	'HideGadget ui.pageHeader; ShowGadget ui.pageHeader	'Workaround to prevent the label having a background
End Function

Function UpdateProjectInfo(titleGad:TGadget, locGad:TGadget, infoGad:TGadget)
?Win32
	Local sepstr$ = "\"
?Mac
	Local sepstr$ = "/"
?Linux
	Local sepstr$ = "/"
?
	Local title$ = "<Enter Title>"
	Local loc$ = "<Enter Location>"
	If titleGad Then ui.projectTitle$ = TextFieldText$(titleGad)
	If locGad Then ui.projectLocation$ = TextFieldText$(locGad)
	If ui.projectTitle$ <> "" Then title$ = ui.projectTitle$
	If ui.projectLocation$ <> "" Then loc$ = ui.projectLocation$
	If infoGad Then SetGadgetText(infoGad, "Project will be created at '" + loc$ + sepstr$ + title$ + "'")
	If ui.projectTitle$ <> "" And ui.projectLocation$ <> "" Then EnableGadget(ui.nextButton) Else DisableGadget(ui.nextButton)
	HideGadget infoGad; ShowGadget infoGad	'Workaround to prevent the label having a background
End Function

Function Export(projType)
	ui.projectExporters[projType](ui.projectLocation$ + "/" + ui.projectTitle$ + "/")
End Function

Function ExportAurora:Int(path$)
	CopyFile("wrappers/Aurora/template.src", path$ + ui.projectTitle$ + ".src")
	Return True
End Function

Function ExportBlitzMax:Int(path$)
	CopyFile("wrappers/BlitzMax/template.bmx", path$ + ui.projectTitle$ + ".bmx")
	Return True
End Function

Function ExportBlitzPlus:Int(path$)
	CopyFile("wrappers/BlitzPlus/coldsteel.bb", path$ + "coldsteel.bb")
	CopyFile("wrappers/BlitzPlus/template.bb", path$ + ui.projectTitle$ + ".bb")
	Return True
End Function

Function ExportCodeBlocks:Int(path$)
	Local s$ = LoadText$("wrappers/CodeBlocks/template.cbp")
	s$ = Replace$(s$, "PROJECTNAME", ui.projectTitle$)
	SaveText(s$, path$ + ui.projectTitle$ + ".cbp")
	CopyFile("wrappers/C/coldsteel.c", path$ + "coldsteel.c")
	CopyFile("wrappers/C/coldsteel.h", path$ + "coldsteel.h")
	CopyFile("wrappers/C/main.cpp", path$ + "main.cpp")
	Return True
End Function

Function ExportDevCpp:Int(path$)
	Local s$ = LoadText$("wrappers/DevCpp/template.dev")
	s$ = Replace$(s$, "PROJECTNAME", ui.projectTitle$)
	SaveText(s$, path$ + ui.projectTitle$ + ".dev")
	CopyFile("wrappers/C/coldsteel.c", path$ + "coldsteel.c")
	CopyFile("wrappers/C/coldsteel.h", path$ + "coldsteel.h")
	CopyFile("wrappers/C/main.cpp", path$ + "main.cpp")
	Return True
End Function

Function ExportEBasic:Int(path$)
	CopyFile("wrappers/EBasic/template.eba", path$ + ui.projectTitle$ + ".eba")
	Return True
End Function

Function ExportIBasic:Int(path$)
	CopyFile("wrappers/EBasic/template.eba", path$ + ui.projectTitle$ + ".iba")
	Return True
End Function

Function ExportPureBasic:Int(path$)
	CopyFile("wrappers/PureBasic/coldsteel.pbi", path$ + "coldsteel.pbi")
	CopyFile("wrappers/PureBasic/template.pb", path$ + ui.projectTitle$ + ".pb")
	Return True
End Function

Function ExportVisualC8:Int(path$)
	Local s$ = LoadText$("wrappers/VisualC8/template.vcproj")
	s$ = Replace$(s$, "PROJECTNAME", ui.projectTitle$)
	SaveText(s$, path$ + ui.projectTitle$ + ".vcproj")
	CopyFile("wrappers/C/coldsteel.c", path$ + "coldsteel.c")
	CopyFile("wrappers/C/coldsteel.h", path$ + "coldsteel.h")
	CopyFile("wrappers/C/main.cpp", path$ + "main.cpp")
	Return True
End Function