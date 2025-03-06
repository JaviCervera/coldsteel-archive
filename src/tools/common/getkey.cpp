#include <stdio.h>
#include <string>
#include <algorithm>

const char* StringMid(const char* str, int pos, int num)
{
	static std::string retstr;
	retstr = str;
	if (num < 1) num = strlen(str) - pos + 1;
	retstr.erase(0, pos - 1);
	retstr.resize(num);
	return retstr.c_str();
}

const char* StringChar(int ascii)
{
	static std::string retstr;
	retstr = " ";
	retstr[0] = (char) ascii;
	return retstr.c_str();
}

int StringAscii(const char* str)
{
	return (int) str[0];
}

extern "C" const char* bb_GetColdSteelKey(const char* username)
{
  std::string v = "YRMLK3L2TKJH7PBZHMPLGAUL2H8NECUBPFCFVVHGHCKK88TGG8WAXBN2R2FQ997PKN3ZDD97";
	std::string tname = username;
	std::string temp = "";
  std::string encrypt = "";
  int ee = 1, a = 0, t1 = 0, e = 0;
	static std::string encrypted;

  encrypted = "";

	//make name longer if necessary
	//again adjust this to make your keys unique
	int namel = 128;
	do
	{
		if (tname.length() <= namel)
		{
			temp = "";
			for (int n = 1; n <= tname.length(); n++)
				temp += StringChar(StringAscii(StringMid(tname.c_str(), n, 1)) + 1);
			tname += temp;
		}
	} while (tname.length() <= namel);

	//this bit makes sure that you don't get any obvious repetitions over the 20 character key
	for (int n = 5; n <= 100; n += 5)
		if (tname.length() == n) tname += "~";

	//create encrypt string
	for (int n = 0; n < 20; n++)
		encrypt += StringChar(1);

	// over load encrypt 30 times
	// change this to make your keys unique further
	for (int l = 1; l <= 30; l++)
	{
		for (int n = 1; n <= tname.length(); n++)
		{
			a = StringAscii(StringMid(tname.c_str(), n, 1));
			a -= 32;
			temp = "";
			for (int nn = 1; nn <= 20; nn++)
			{
				int tl = StringAscii(StringMid(encrypt.c_str(), nn, 1));
				if (nn == ee) temp += StringChar((tl + a) % 256); else temp += StringChar(tl);
			}
			encrypt = temp;
			ee += 1;
			if (ee == 20) ee = 1;
		}
	}

	// suck out the key
	for (int ee = 1; ee <= 20; ee++)
	{
		e = StringAscii(StringMid(encrypt.c_str(), ee, 1)) % v.length();
		if (e == 0) e = 1;
		encrypted += StringMid(v.c_str(), e, 1);
	}

	// format the key with -'s
  encrypted = std::string(StringMid(encrypted.c_str(), 1, 5)) + "-" + StringMid(encrypted.c_str(), 6, 5) + "-" + StringMid(encrypted.c_str(), 11, 5) + "-" + StringMid(encrypted.c_str(), 16, 5);

	// return the key
	return encrypted.c_str();
}
