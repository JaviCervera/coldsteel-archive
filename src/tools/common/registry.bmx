Import "-ladvapi32"

Extern "Win32"
	Function RegCloseKey:Int(hKey:Int)
	Function RegCreateKeyA:Int(hKey:Int, SubKey$z, phkResult:Int Var)
	Function RegDeleteKeyA:Int(hKey:Int, lpSubKey$z)
	Function RegDeleteValueA:Int(hKey:Int, ValueName$z)
	Function RegEnumKeyA:Int(hKey:Int, dwIndex:Int, lpName:Byte Ptr, cchName:Int)
	Function RegEnumValueA:Int(hKey:Int, dwIndex:Int, lpValueName:Byte Ptr, lpcValueName:Int Var, lpReserved:Int Var, lpType:Int Var, lpData:Byte Ptr, lpcbData:Int Var)
	Function RegOpenKeyA:Int(hKey:Int, SubKey$z, phkResult:Int Var)
	Function RegQueryValueExA:Int(hKey:Int, lpValueName$z, MustBeNull:Int, DataType:Int Var, lpData:Byte Ptr, BufferSize:Int Var)
	Function RegSetValueExA:Int(hKey:Int, lpValueName$z, Reserved:Int, dwType:Int, Data$z, cbData:Int)
End Extern

'Registry roots
Const HKEY_CLASSES_ROOT =	$80000000
Const HKEY_CURRENT_USER =	$80000001
Const HKEY_LOCAL_MACHINE =	$80000002
Const HKEY_USERS =			$80000003

'Return value constants
Const ERROR_SUCCESS =	0	'No errors
Const ERROR_EOF =		259	'No more entries in key

'Data types for keys
Const REG_SZ =	1	'Data string
Const REG_BINARY =	3	'Binary Data in any form.
Const REG_DWORD =	4	'A 32-bit number.

'Global var holding last error
Global LastRegError = ERROR_SUCCESS

'Enumerates the keys contained in the passed subkey And returns them as a delimited String in 
'the format: KEY=VALUE|KEY=VALUE|KEY=VALUE
Function EnumRegValues$(regkey, subkey$, delim$ = "|", types = False)
	Local cRetVal$ = "", key$ = "", val$ = ""
	Local keyBank:TBank = CreateBank(100), keySize = 100, valBank:TBank = CreateBank(100), valSize = 100
	Local char = 0, nIdx = 0, nType = 0, reserved = 0

	'open the key 
	Local hKey = OpenRegKey(RegKey,SubKey$)
	If hKey <> -1
		'read in the values
		Repeat
			'clear out the temp values
			key$=""
			val$=""

			If RegEnumValueA(hKey, nIdx, keyBank.Buf(), keySize, reserved, nType, valBank.Buf(), valSize) <> ERROR_EOF
				'tack on the delimiter
				If cRetVal$ <> "" Then cRetVal$ :+ delim$

				'build the key name
				For char = 0 Until keySize
					If PeekByte(keyBank, char) = 0 Then Exit
					key$ :+ Chr$(PeekByte(keyBank, char))
				Next

				Select nType
					'read in a String Or binary value
					Case REG_SZ, REG_BINARY
						'build the value
						For char = 0 Until valSize
							If PeekByte(valBank, char) = 0 Then Exit
							val$ :+ Chr$(PeekByte(valBank, char))
						Next
					'read in an integer
					Case REG_DWORD
						val$ = PeekInt(valBank, 0)
				End Select

				If types
					cRetVal$ = (cRetVal$ + nType + ";" + key$ + "=" + val$)
				Else
					cRetVal$ = (cRetVal$ + key$ + "=" + val$)
				EndIf
			Else
				Exit
			EndIf

			nIdx:+1
		Forever
		CloseRegkey(hKey)
	EndIf
	Return cRetVal$
End Function

'enumerates the keys contained in the passed subkey And returns them as a delimited String in 
'the format: KEY|KEY|KEY
Function EnumRegKeys$(RegKey%, SubKey$, delim$="|")
	Local cRetVal$ = ""
	Local keyBank:TBank = CreateBank(100)
	Local nIdx = 0

	'open the key first
	Local hKey = OpenRegKey(RegKey,SubKey$)
	If hKey <> -1
		Repeat
			If RegEnumKeyA(hKey, nIdx, keyBank.Buf(), BankSize(keyBank)) <> ERROR_EOF
				'tack on the delimiter
				If cRetVal$ <> "" Then cRetVal$ :+ delim$

				For Local char = 0 Until BankSize(keyBank)
					If PeekByte(keyBank, char) = 0 Then Exit
					cRetVal$ :+ Chr$(PeekByte(keyBank, char))
				Next
			Else
				Exit
			EndIf

			nIdx:+1
		Forever
		CloseRegKey(hKey)
	EndIf
	Return cRetVal$
End Function

'deletes a value from the registry.  returns True/False.
Function DeleteRegValue%(RegKey%,SubKey$,ValueName$)
	Local hKey = OpenRegKey(RegKey, SubKey$)
	Local lRetVal = False
	If hKey <> -1
		Local nRslt = RegDeleteValueA(hKey, ValueName$)
		If nRslt = ERROR_SUCCESS
			lRetVal = True
		Else
			LastRegError = nRslt
		EndIf
		CloseRegKey(hKey)
	EndIf
	Return lRetVal
End Function

'gets a value from the registry And returns it as a string.  will Return the passed Default
'If the value requested is Not found in the registry.
Function GetRegValue$(RegKey%, SubKey$, ValueName$, Dflt$="", types=False)
	Local cRetVal$ = Dflt$
	Local hKey = OpenRegKey(RegKey,SubKey$)
	Local char = 0, nType = 0

	'open the key 
	If hKey <> -1
		Local valBank:TBank = CreateBank(100), valSize = 100

		Local nRslt = RegQueryValueExA(hKey, ValueName$, 0,nType, valBank.Buf(), valSize)
		If (nRslt=ERROR_SUCCESS)
			cRetVal$=""

			'build the value
			Select nType
				'read in a String Or binary value
				Case REG_SZ, REG_BINARY
					'build the value
					For char = 0 Until valSize
						If PeekByte(valbank, char) = 0 Then Exit
						cRetVal$ :+ Chr$(PeekByte(valBank, char))
					Next
				'read in an integer
				Case REG_DWORD
					cRetVal$ = PeekInt(valBank,0)
			End Select

			'tack on the Type If requested
			If types Then cRetVal$ = nType + ";" + cRetVal$
		Else
			LastRegError = nRslt
		EndIf
		CloseRegKey(hKey)
	EndIf
	Return cRetVal$
End Function

'sets a value in the registry.  defaults To Type String, but can pass REG_DWORD And REG_BINARY.
'returns True/False.
Function SetRegValue%(RegKey%, SubKey$, ValueName$, Value$, nType=REG_SZ)
	Local hKey = OpenRegKey(RegKey, SubKey$)
	Local lRetVal = False

	If hKey<>-1
		Local valBank

		Rem
		'create a bank To hold the info
		Select nType
			Case REG_SZ, REG_BINARY
				valBank = CreateBank(Len(Value$))
				For i = 1 To Len(Value$)
					PokeByte(valbank, i-1, Asc(Mid$(Value$, i, 1)))
				Next
			Case REG_DWORD
				valBank = CreateBank(4)
				PokeInt(valBank, 0, Value$.ToInt())
		End Select
		End Rem

		Local nRslt = RegSetValueExA(hKey, ValueName$, 0, nType, Value$, Len(Value$))
		If (nRslt=ERROR_SUCCESS)
			lRetVal = True
		Else
			LastRegError = nRslt
		EndIf
		CloseRegKey(hKey)
	EndIf
	Return lRetVal
End Function

'deletes the passed key from the registry.  returns True/False.
Function DeleteRegKey%(RegKey%, KeyName$)
	LastRegError = ERROR_SUCCESS
	Local nRslt = RegDeleteKeyA(RegKey, KeyName$)
	If nRslt <> ERROR_SUCCESS Then LastRegError = nRslt
	Return (nRslt = ERROR_SUCCESS)
End Function

'returns the registry handle Or -1 If failed.
Function CreateRegKey%(RegKey%,KeyName$)
	LastRegError=ERROR_SUCCESS
	Local hKey=-1
	Local nRslt=RegCreateKeyA(RegKey%, KeyName$, hKey)
	If nRslt <> ERROR_SUCCESS Then LastRegError=nRslt; hKey = -1
	Return hKey
End Function 

'returns the registry handle Or -1 If failed
Function OpenRegKey%(RegKey%,KeyName$)
	LastRegError=ERROR_SUCCESS
	Local hKey = -1
	Local nRslt=RegOpenKeyA(RegKey%, KeyName$, hKey)
	If nRslt <> ERROR_SUCCESS Then LastRegError=nRslt; hKey = -1
	Return hKey
End Function 

'closes the registry key.  returns True/False.
Function CloseRegKey%(RegKey%)
	LastRegError=ERROR_SUCCESS
	Local nRslt = RegCloseKey(RegKey)
	If nRslt<>ERROR_SUCCESS Then LastRegError=nRslt
	Return (nRslt=ERROR_SUCCESS)
End Function

'Returns True If the key exists
Function IsRegKey%(RegKey%,KeyName$)
	Local hKey = OpenRegKey(RegKey,KeyName$)
	Local lRetVal = False
	If hKey <> -1 Then CloseRegKey(hKey); lRetVal=True
	Return lRetVal
End Function