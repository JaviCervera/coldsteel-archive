Strict

Framework BRL.Retro
Import Koriolis.BriskVM

Import "RunProgram.bmx"

Const MODE_COMPILE = 1
Const MODE_BUILD = 2
Const MODE_RUN = 3

Local CompilerMode = MODE_BUILD
Local srcfile$
Local exefile$

'Ensure we are on the app's dir
ChangeDir AppDir$

'Welcome message
Print "ColdSteel Script Compiler v0.9.6"
Print ""

'Get command line
If AppArgs.length < 2 Or AppArgs.length > 3 Then Usage()

'Get command line options
Select AppArgs$[1]
	Case "-c"
		srcfile$ = AppArgs$[2]
		CompilerMode = MODE_COMPILE
	Case "-b"
		srcfile$ = AppArgs$[2]
		CompilerMode = MODE_BUILD
	Case "-r"
		srcfile$ = AppArgs$[2]
		CompilerMode = MODE_RUN
	Default
		srcfile$ = AppArgs$[1]
End Select

'Get source and exe filenames
exefile$ = StripExt$(srcfile$) + ".exe"

'Check command line
If srcfile$ = "" Then Usage()

'Check script file
If FileType(srcfile$) <> FILETYPE_FILE
	Print "Error: Could not find source file."
	End
End If

'Check constants file
If FileType("constants.dat") <> 1
	Print "Error: Could not find constant definitions file."
	End
End If

'Create a script which includes the constants
Local fconstants:TStream = ReadFile("constants.dat")
Local fsource:TStream = ReadFile(srcfile$)
Local ftemp:TStream = WriteFile("temp.bbs")
While Not Eof(fconstants)
	WriteLine ftemp, ReadLine$(fconstants)
Wend
While Not Eof(fsource)
	WriteLine ftemp, ReadLine$(fsource)
Wend
CloseFile fconstants
CloseFile fsource
CloseFile ftemp

'Load command set
Local cmd = BVM_LoadCommandSet("ColdSteel.bcs")
If Not cmd Then Print BVM_GetLastErrorMsg$() ; End

'Compile script
Local hModule = BVM_CompileFile("temp.bbs", cmd, "temp.bbm")
If hModule = 0 Then Print BVM_GetLastErrorMsg$() ; End

Select CompilerMode
	Case MODE_BUILD
		'Save Module To disk
		If Not BVM_SaveModule(hModule) Then Print BVM_GetLastErrorMsg$() ; End

		'Create exe
		If FileType(exefile$) = FILETYPE_FILE Then DeleteFile exefile$
		CopyFile "runtime.dat", exefile$
		Local f:TStream = OpenFile(exefile$)

		'Go To the End of the exe
		SeekStream f, FileSize(exefile$)
		Local pos = StreamPos(f)

		'Copy bytecode To exe
		Local f2:TStream = ReadFile("temp.bbm")
		For Local i = 1 To FileSize("temp.bbm")
			WriteByte f, ReadByte(f2)
		Next
		CloseFile f2

		'Save bytecode offset
		WriteInt f, pos

		CloseFile f

		DeleteFile "temp.bbm"
	Case MODE_RUN
		RunProgram(hModule)
End Select

DeleteFile "temp.bbs"

'Print Exit message
Print ""
Print "'" + srcfile$ + "' sucessfully compiled."

End

Function StringField$(s$,index,delimiter$=" ")
	If Len(s$)=0 Or index<1 Or delimiter$="" Then Return ""
	Local ofs=1
	Local c = 0
	Repeat
		c=c+1
		If c<index
			ofs=Instr(s$,delimiter$,ofs)
			If ofs Then ofs=ofs+1
		Else
			Local l=Instr(s$,delimiter$,ofs)-ofs
			Return Mid$(s$,ofs,l)
		End If
	Until ofs=0
	Return ""
End Function

Function Usage()
	Print "Usage: cscompiler.exe [options] <source_file>"
	Print "Options:"
	Print Chr$(9) + "-c: Check syntax. Do not generate executable."
	Print Chr$(9) + "-b: Build executable (default)."
	Print Chr$(9) + "-r: Run program. Do not generate executable."
	End
End Function