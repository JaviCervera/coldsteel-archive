#include "engine.h"

//-----------------------------------------------
//  File System functions
//-----------------------------------------------

csInt csFileRead(const char* file)
{
	csFile* f = new csFile;
	f->isreader = true;
	f->reader = Device->getFileSystem()->createAndOpenFile(file);
	if (!f->reader)
	{
		delete f;
		return 0;
	}
	return (int)f;
}

//-----------------------------------------------

csInt csFileWrite(const char* file)
{
	csFile* f = new csFile;
	f->isreader = false;
	f->writer = Device->getFileSystem()->createAndWriteFile(file);
	if (!f->writer)
	{
		delete f;
		return 0;
	}
	return (int)f;
}

//-----------------------------------------------

csVoid csFileClose(csFile* file)
{
	if (file->isreader)
		file->reader->drop();
	else
		file->writer->drop();
	delete file;
}

//-----------------------------------------------

csInt csFileSize(csFile* file)
{
	if (file->isreader)
		return file->reader->getSize();
	return 0;
}

//-----------------------------------------------

csInt csFilePos(csFile* file)
{
	if (file->isreader)
		return file->reader->getPos();
	return file->writer->getPos();
}

//-----------------------------------------------

csVoid csFileSeek(csFile* file, int pos, int relative)
{
	if (file->isreader)
		file->reader->seek(pos, relative);
	file->writer->seek(pos, relative);
}

//-----------------------------------------------

csInt csFileReadByte(csFile* file)
{
	char val = 0;
	if (file->isreader)
		file->reader->read(&val, sizeof(char));
	return (int) val;
}

//-----------------------------------------------

csInt csFileReadShort(csFile* file)
{
	short val = 0;
	if (file->isreader)
		file->reader->read(&val, sizeof(short));
	return (int) val;
}

//-----------------------------------------------

csInt csFileReadInt(csFile* file)
{
	int val = 0;
	if (file->isreader)
		file->reader->read(&val, sizeof(int));
	return val;
}

//-----------------------------------------------

csFloat csFileReadFloat(csFile* file)
{
	float val = 0.0;
	if (file->isreader)
		file->reader->read(&val, sizeof(float));
	return val;
}

//-----------------------------------------------

csString csFileReadString(csFile* file)
{
	static char str[1024];
	int pos = 0;
	if (file->isreader)
	{
		while (1)
		{
			char c;
			file->reader->read(&c, sizeof(char));
			if (c == 0)	break;
			str[pos] = c;
			pos++;
		}
	}
	str[pos] = (char) 0;
	return str;
}

//-----------------------------------------------

csVoid csFileReadBytes(csFile* file, int buffer, int size)
{
	if (file->isreader)
		file->reader->read((void*) buffer, size);
}

//-----------------------------------------------

csVoid csFileWriteByte(csFile* file, int val)
{
	char byte = (char) val;
	if (!file->isreader)
		file->writer->write(&byte, sizeof(char));
}

//-----------------------------------------------

csVoid csFileWriteShort(csFile* file, int val)
{
	short shor = (short) val;
	if (!file->isreader)
		file->writer->write(&shor, sizeof(short));
}

//-----------------------------------------------

csVoid csFileWriteInt(csFile* file, int val)
{
	if (!file->isreader)
		file->writer->write(&val, sizeof(int));
}

//-----------------------------------------------

csVoid csFileWriteFloat(csFile* file, float val)
{
	if (!file->isreader)
		file->writer->write(&val, sizeof(float));
}

//-----------------------------------------------

csVoid csFileWriteString(csFile* file, const char* str)
{
	if (!file->isreader)
	{
		char c = 0;
		file->writer->write(str, strlen(str));
		file->writer->write(&c, sizeof(char));
	}
}

//-----------------------------------------------

csVoid csFileWriteBytes(csFile* file, int buffer, int size)
{
	if (!file->isreader)
		file->writer->write((const void*) buffer, size);
}

//-----------------------------------------------

csString csFileGetExt(const char* str)
{
	static std::string retstr;
	retstr = "";
	int pos = 0;
	for (unsigned int i = 1; i <= strlen(str); i++)
		if (!strcmp(csStringMid(str, i, 1), "."))
			pos = i;
	if (pos > 0)
		retstr = csStringRight(str, (int)strlen(str) - pos);
	return retstr.c_str();
}

//-----------------------------------------------

csString csFileGetDir(const char* str)
{
	static std::string retstr;
	retstr = "";
	int pos = 0;
	for (unsigned int i = 1; i <= strlen(str); i++)
		if (!strcmp(csStringMid(str, i, 1), "/") || !strcmp(csStringMid(str, i, 1), "\\"))
			pos = i;
	if (pos > 0)
		//retstr = csStringMid(str, pos+1, (int)strlen(str) - pos);
		retstr = csStringRight(str, (int)strlen(str) - pos);
	return retstr.c_str();
}

//-----------------------------------------------

csString csFileStripExt(const char* str)
{
	static std::string retstr;
	retstr = str;
	int pos = 0;
	for (unsigned int i = 1; i <= strlen(str); i++)
		if (!strcmp(csStringMid(str, i, 1), "."))
			pos = i;
	if (pos > 0)
		retstr = csStringLeft(str, pos-1);
	return retstr.c_str();
}

//-----------------------------------------------

csString csFileStripDir(const char* str)
{
	static std::string retstr;
	retstr = str;
	int pos = 0;
	for (unsigned int i = 1; i <= strlen(str); i++)
		if (!strcmp(csStringMid(str, i, 1), "/") || !strcmp(csStringMid(str, i, 1), "\\"))
			pos = i;
	if (pos > 0)
		retstr = csStringMid(str, pos+1, (int)strlen(str) - pos);
	return retstr.c_str();
}
