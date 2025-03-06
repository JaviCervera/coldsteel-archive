Strict

'Include files
Import Koriolis.BriskVM
Import Usr.ColdSteel
Include "Invoker.bmx"

Function RunProgram$(hmodule, script$ = "")
	'Init BVM
	Local context = BVM_CreateContext()
		If context = BVM_INVALID_CONTEXT Then Return BVM_GetLastErrorMsg$()

	If script$ <> ""
		hmodule = BVM_LoadModule(script$)
		If hmodule = BVM_INVALID_MODULE Then Return BVM_GetLastErrorMsg$()
	End If
	BVM_MapModule(context, hmodule)

	Local entrypoint = BVM_FindEntryPoint(context, hmodule, "csMain")
		If entrypoint = BVM_INVALID_ENTRY_POINT Then Return BVM_GetLastErrorMsg$()

	'Delete script
	If script$ <> "" Then DeleteFile script$

	'Init ColdSteel
	csCoreInit

	'Main loop
	Local lastframe =	csCoreTimer()	'Holds the timer value in the last frame
	Local frametime					'Holds the milliseconds passed since last frame
	Local elapsed#					'Elapsed time in seconds since last frame, useful For frame-independent movement
	Local must_exit =	False		'Tells If we have To Exit
	While Not must_exit
		'Process all events in the queue
		While csEventPoll()	
			'Select context To execute
			BVM_SelectContext(context)

			'Push parameters
			BVM_PushInt(csEventId())
			BVM_PushInt(csEventFrom())
			BVM_PushInt(csEventTo())
			BVM_PushFloat(csEventA#())
			BVM_PushFloat(csEventB#())
			BVM_PushFloat(csEventC#())
			BVM_PushString(csEventData$())

			'Select entry point And call
			BVM_SelectEntryPoint(entrypoint)
			BVM_Invoke()

			'Pop Return value from the stack
			BVM_PopInt()

			'Send current event To out main Function
			'csMain(csEventId(), csEventFrom(), csEventTo(), csEventA(), csEventB(), csEventC(), csEventData())

			'If we have processed the CSEV_FINISH event, we have finished
			If csEventId() = CSEV_FINISH
				must_exit = True
				Exit
			End If
		Wend

		'All events in the queue processed, so send a frame And go For the Next frame
		frametime = csCoreTimer() - lastframe
		lastframe = csCoreTimer()
		elapsed# = frametime / 1000.0
		csEventPost(CSEV_FRAME, 0, 0, elapsed#, 0, 0, "")
	Wend

	'Shutdown ColdSteel
	csCoreFinish
End Function