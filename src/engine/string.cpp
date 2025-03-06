#include "engine.h"
#include <algorithm>

//-----------------------------------------------
//  String functions
//-----------------------------------------------

void stringToWstring(const char* string, wchar_t* wstring, int maxchars)
{
	mbstowcs(wstring, string, maxchars);
}

//-----------------------------------------------

void wstringToString(const wchar_t* wstring, char* string, int maxchars)
{
	wcstombs(string, wstring, maxchars);
}

//-----------------------------------------------

const wchar_t* asWstring(const char* string)
{
	static wchar_t wstring[1024];
	stringToWstring(string, wstring, 1024);
	return wstring;
}

//-----------------------------------------------

const char* asString(const wchar_t* wstring)
{
	static char string[1024];
	wstringToString(wstring, string, 1024);
	return string;
}

//-----------------------------------------------

csInt csStringToInt(const char* str)
{
	return atoi(str);
}

//-----------------------------------------------

csFloat csStringToFloat(const char* str)
{
	return (float) atof(str);
}

//-----------------------------------------------

csString csStringFromInt(int number)
{
	static char str[32];
	sprintf(str, "%i", number);
	return str;
}

//-----------------------------------------------

csString csStringFromFloat(float number)
{
	static char str[32];
	sprintf(str, "%f", number);
	return str;
}

//-----------------------------------------------

csString csStringLeft(const char* str, int num)
{
	static std::string retstr;
	retstr = str;
	retstr.resize(num);
	return retstr.c_str();
}

//-----------------------------------------------

csString csStringRight(const char* str, int num)
{
	static std::string retstr;
	retstr = str;
	retstr.erase(0, strlen(str) - num);
	return retstr.c_str();
}

//-----------------------------------------------

csString csStringMid(const char* str, int pos, int num)
{
	static std::string retstr;
	retstr = str;
	if (num < 1) num = (int) strlen(str) - pos + 1;
	retstr.erase(0, pos - 1);
	retstr.resize(num);
	return retstr.c_str();
}

//-----------------------------------------------

csString csStringReplace(const char* str, const char* find, const char* replace)
{
	static std::string retstr;
	retstr = str;
	while (csStringFind(retstr.c_str(), find, 1))
		retstr.replace(csStringFind(retstr.c_str(), find, 1)-1, std::string(find).length(), std::string(replace));
	return retstr.c_str();
}

//-----------------------------------------------

csInt csStringFind(const char* str, const char* find, int offset)
{
	std::string retstr = str;
	return (int) retstr.find(find, offset - 1) + 1;
}

//-----------------------------------------------

csString csStringUpper(const char* str)
{
	static std::string retstr;
	retstr = str;
	std::transform(retstr.begin(), retstr.end(), retstr.begin(), ::toupper);
	return retstr.c_str();
}

//-----------------------------------------------

csString csStringLower(const char* str)
{
	static std::string retstr;
	retstr = str;
	std::transform(retstr.begin(), retstr.end(), retstr.begin(), ::tolower);
	return retstr.c_str();
}

//-----------------------------------------------

csString csStringTrim(const char* str)
{
	static std::string retstr;
	int begin = 0, end = (int) strlen(str);
	retstr = "";
	while (begin < end && str[begin] <= ' ') ++begin;
	if (begin == end) return retstr.c_str();
	while (str[end-1] <= ' ') --end;
	if (end - begin == strlen(str)) { retstr = str; return retstr.c_str(); }
	retstr = csStringRight(str, (int) strlen(str) - begin);
	retstr = csStringLeft(retstr.c_str(), end - begin);
	return retstr.c_str();
}

//-----------------------------------------------

csString csStringChar(int ascii)
{
	static std::string retstr;
	retstr = " ";
	retstr[0] = (char) ascii;
	return retstr.c_str();
}

//-----------------------------------------------

csInt csStringAscii(const char* str)
{
	return (int) str[0];
}

//-----------------------------------------------

csInt csStringLen(const char* str)
{
	return (int) strlen(str);
}

//-----------------------------------------------

csString csStringField(const char* str, const char* delimiter, int index)
{
	static std::string retstr;
	int c = 0, l = 0, ofs = 1;
	retstr = "";
	if (strlen(str) == 0 || index < 1 || !strcmp(delimiter, ""))  return retstr.c_str();
	do
	{
		c++;
		if (c < index)
		{
			ofs = csStringFind(str, delimiter, ofs);
			if (ofs)  ofs++;
		} else {
			l = csStringFind(str, delimiter, ofs) - ofs;
			retstr = csStringMid(str, ofs, l);
			return retstr.c_str();
		}
	} while(ofs);
	return retstr.c_str();
}
