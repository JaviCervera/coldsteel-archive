Function RepeatString$(str$, count)
	Local s$ = ""
	For Local i = 1 To count
		s$ :+ str$
	Next
	Return s$
End Function

Function StringIntLen$(number, l)
	Return RepeatString$("0", l - Len(number)) + number
End Function

Function StringField$(s$, index, delimiter$ = " ")
	If Len(s$) = 0 Or index < 1 Or delimiter$ = "" Then Return ""
	Local ofs = 1
	Local c = 0
	Local length = 0
	Repeat
		c :+ 1
		If c < index
			ofs = Instr(s$,delimiter$,ofs)
			If ofs Then ofs :+ 1
		Else
			length = Instr(s$, delimiter$, ofs) - ofs
			Return Mid$(s$, ofs, length)
		End If
	Until ofs=0
	Return ""
End Function

Function ARGB(alpha:Byte, red:Byte, green:Byte, blue:Byte)
	Return (alpha Shl 24) + (red Shl 16) + (green Shl 8) + blue
End Function

Function ClearPixmap(pixmap:TPixmap, color)
	For Local y = 0 Until PixmapHeight(pixmap)
		For Local x = 0 Until PixmapWidth(pixmap)
			WritePixel pixmap, x, y, color
		Next
	Next
End Function