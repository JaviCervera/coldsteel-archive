Type App
	Function Init()
		AppTitle$ = WINTITLE$
		csCoreInit
		Settings.Init
		Ui.Init
		Scene.Init
		SetGadgetShape Ui.win, ClientWidth(Desktop())/2 - 455, ClientHeight(Desktop())/2 - 297, 910, 594
	End Function
	
	Function Loop()
		WaitEvent()
		If EventID() = EVENT_APPTERMINATE Then App.Quit
		Ui.Loop
		Scene.Loop
	End Function
	
	Function Finish()
		Ui.Finish
		Scene.Finish
		Settings.Finish
		csCoreFinish
	End Function
	
	Function Quit()
		Select Proceed("Save before exit?")
			Case 0	'No
				Finish
				End
			Case 1	'Yes
				If Scene.file$ = "" Then
					Local file$ = RequestFile$("Save gui", "Gui Files:gui", True, Settings.path$ + Scene.file$)
					If file$ <> "" And FileType(file$) <> FILETYPE_DIR
						If ExtractExt(file$) = "" Then file$ :+ ".gui"
						Scene.Save(Replace$(file$, "\", "/"))
						Finish; End
					Else If file$ = ""
						Quit
					End If
				Else
					Scene.Save(Scene.file$)
					Finish; End
				End If
		End Select
	End Function
End Type