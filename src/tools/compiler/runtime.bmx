Strict

Framework BRL.Retro
Import BRL.System
Import "RunProgram.bmx"

'Extract bytecode from file
Local f:TStream = ReadFile(AppFile$)
Local end_ = StreamSize(f) - 4 ; SeekStream f, end_
Local ofs = ReadInt(f) ; SeekStream f, ofs 
Local f2:TStream = WriteFile("temp.bbm")
'Local buffer[end_-ofs+1]
For Local i = ofs To end_
	'buffer[i-ofs] = ReadByte(f)
	WriteByte f2, ReadByte(f)
Next
CloseFile f2
CloseFile f

Local retstr$ = RunProgram(0, "temp.bbm")
If retstr$ <> "" Then Notify retstr$, True ; End

End