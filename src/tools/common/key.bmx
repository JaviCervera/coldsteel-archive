Import BRL.EventQueue

Import "registry.bmx"
Import "checkuser.bmx"

Function InitKey()
	If Not IsRegKey(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK")
		Local win:TGadget = CreateWindow("ColdSteel Engine Registration", ClientWidth(Desktop())/2 - 175, ClientHeight(Desktop())/2 - 60, 350, 120, Null, WINDOW_TITLEBAR | WINDOW_CLIENTCOORDS)
		CreateLabel("You will receive your user and key after purchase.", 8, 8, ClientWidth(win) - 8, 20, win)
		CreateLabel("User:", 8, 34, 30, 20, win)
		Local userTfield:TGadget = CreateTextField(ClientWidth(win) - 308, 30, 300, 24, win)
		CreateLabel("Key:", 8, 66, 30, 20, win)
		Local keyTfield:TGadget = CreateTextField(ClientWidth(win) - 308, 62, 300, 24, win)
		Local cancelButton:TGadget = CreateButton("Cancel", ClientWidth(win) - 178, ClientHeight(win) - 28, 75, 24, win)
		Local okButton:TGadget = CreateButton("Ok", ClientWidth(win) - 82, ClientHeight(win) - 28, 75, 24, win)
		Local ok = False
		Repeat
			Select WaitEvent()
				Case EVENT_GADGETACTION
					Select EventSource()
						Case cancelButton
							Notify "You need to use a valid serial of ColdSteel to use it"
							End
						Case okButton
							If CheckUser(TextFieldText$(userTfield), TextFieldText$(keyTfield)) = True
								CreateRegKey(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK")
								SetRegValue(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK", "user", TextFieldText$(userTfield))
								SetRegValue(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK", "key", TextFieldText$(keyTfield))
								Notify "Thank you for registering ColdSteel Engine!"
								Exit
							Else
								Notify "Wrong user or key"
							End If

					End Select
				Case EVENT_WINDOWCLOSE
					PostEvent CreateEvent(EVENT_GADGETACTION, cancelButton)
			End Select
		Forever
		FreeGadget win
	Else
		If Not CheckUser(GetRegValue$(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK", "user"), GetREgValue$(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK", "key"))
			DeleteRegKey(HKEY_LOCAL_MACHINE, "SOFTWARE\ColdSteelSDK")
			InitKey()
		End If
	End If
End Function