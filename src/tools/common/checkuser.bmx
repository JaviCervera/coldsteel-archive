Import "getkey.cpp"

Extern
	Function bb_GetColdSteelKey:Byte Ptr(username:Byte Ptr)
End Extern

Function GetKey$(username$)
	Return String.FromCString(bb_GetColdSteelKey(username.ToCString()))
End Function

Function CheckUser:Int(user$, key$)
	If user$ = "" Then Return False
	If GetKey$(user$) = key$ Then Return True
	Return False
End Function