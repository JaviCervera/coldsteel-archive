Import "common/checkuser.bmx"
Import Usr.ColdSteel

f = ReadFile("users.txt")
f2 = WriteFile("users2.txt")
While Not Eof(f)
	lin$ = ReadLine$(f)
	If Trim$(lin$) = "" Then Continue
	name$ = Trim$(csStringField$(lin$, "-", 1))
	mail$ = Trim$(csStringField$(lin$, "-", 2))
	WriteLine f2, name$ + " - " + mail$ + " - " + GetKey$(name$)
Wend
CloseFile f
CloseFile f2

Notify "Done."