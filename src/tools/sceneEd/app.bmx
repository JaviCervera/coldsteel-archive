Type App
	Function Init()
		AppTitle$ = WINTITLE$
		csLibInit
		Settings.Init
		Ui.Init
		Scene.Init
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
		csLibFinish
	End Function
	
	Function Quit()
		Finish; End
	End Function
End Type
