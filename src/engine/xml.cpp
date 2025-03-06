#include "engine.h"

//-----------------------------------------------
//  XML functions
//-----------------------------------------------

void xmlWriteSetting(csXMLFile* file, const char* name, const char* value)
{
	csXMLWriteElement(file, name, "", false); csXMLWriteLineBreak(file);
	csXMLWriteText(file, value); csXMLWriteLineBreak(file);
	csXMLWriteClosingTag(file, name); csXMLWriteLineBreak(file);
}

//-----------------------------------------------

csInt csXMLRead(const char* file)
{
	csXMLFile* f = new csXMLFile;
	f->isreader = true;
	f->reader = Device->getFileSystem()->createXMLReader(file);
	if (!f->reader)
	{
		delete f;
		return 0;
	}
	return (int)f;
}

//-----------------------------------------------

csInt csXMLWrite(const char* file)
{
	csXMLFile* f = new csXMLFile;
	f->isreader = false;
	f->writer = Device->getFileSystem()->createXMLWriter(file);
	if (!f->writer)
	{
		delete f;
		return 0;
	}
	return (int)f;
}

//-----------------------------------------------

csVoid csXMLClose(csXMLFile* file)
{
	if (file->isreader)
		file->reader->drop();
	else
		file->writer->drop();
	delete file;
}

//-----------------------------------------------

csInt csXMLReadNode(csXMLFile* file)
{
	if (file->isreader)
		return file->reader->read();
	else
		return 0;
}

//-----------------------------------------------

csInt csXMLNodeType(csXMLFile* file)
{
	if (file->isreader)
		return file->reader->getNodeType();
	else
		return 0;
}

//-----------------------------------------------

csString csXMLNodeName(csXMLFile* file)
{
	if (file->isreader)
		return csStringTrim(asString(file->reader->getNodeName()));
	else
		return NULL;
}

//-----------------------------------------------

csString csXMLNodeData(csXMLFile* file)
{
	if (file->isreader)
		return csStringTrim(asString(file->reader->getNodeData()));
	else
		return 0;
}

//-----------------------------------------------

csInt csXMLAttributeCount(csXMLFile* file)
{
	if (file->isreader)
		return file->reader->getAttributeCount();
	else
		return 0;
}

//-----------------------------------------------

csString csXMLAttributeName(csXMLFile* file, int index)
{
	if (file->isreader)
		return csStringTrim(asString(file->reader->getAttributeName(index-1)));
	else
		return NULL;
}

//-----------------------------------------------

csString csXMLAttributeValue(csXMLFile* file, int index)
{
	if (file->isreader)
		return csStringTrim(asString(file->reader->getAttributeValue(index-1)));
	else
		return NULL;
}

//-----------------------------------------------

csVoid csXMLWriteHeader(csXMLFile* file)
{
	if (!file->isreader)
		file->writer->writeXMLHeader();
}

//-----------------------------------------------

csVoid csXMLWriteElement(csXMLFile* file, const char* name, const char* attributes, int empty)
{
	std::string strname[5];
	std::string strvalue[5];
	wchar_t wstrname[5][1024];
	wchar_t wstrvalue[5][1024];
	int c = 1;
	for (int i = 0; i < 5; i++)
	{
		strname[i] = csStringField(attributes, "|", c);	c++;
		strvalue[i] = csStringField(attributes, "|", c);	c++;
	}
	for (int i = 0; i < 5; i++)
	{
		stringToWstring(strname[i].c_str(), wstrname[i], 1024);
		stringToWstring(strvalue[i].c_str(), wstrvalue[i], 1024);
	}
	if (!file->isreader)
		if (strname[4] != "")
			file->writer->writeElement(asWstring(name), empty, wstrname[0], wstrvalue[0], wstrname[1], wstrvalue[1], wstrname[2], wstrvalue[2], wstrname[3], wstrvalue[3], wstrname[4], wstrvalue[4]);
		else if (strname[3] != "")
			file->writer->writeElement(asWstring(name), empty, wstrname[0], wstrvalue[0], wstrname[1], wstrvalue[1], wstrname[2], wstrvalue[2], wstrname[3], wstrvalue[3]);
		else if (strname[2] != "")
			file->writer->writeElement(asWstring(name), empty, wstrname[0], wstrvalue[0], wstrname[1], wstrvalue[1], wstrname[2], wstrvalue[2]);
		else if (strname[1] != "")
			file->writer->writeElement(asWstring(name), empty, wstrname[0], wstrvalue[0], wstrname[1], wstrvalue[1]);
		else if (strname[0] != "")
			file->writer->writeElement(asWstring(name), empty, wstrname[0], wstrvalue[0]);
		else
			file->writer->writeElement(asWstring(name), empty);
}

//-----------------------------------------------

csVoid csXMLWriteClosingTag(csXMLFile* file, const char* name)
{
	if (!file->isreader)
		file->writer->writeClosingTag(asWstring(name));
}

//-----------------------------------------------

csVoid csXMLWriteText(csXMLFile* file, const char* text)
{
	if (!file->isreader)
		file->writer->writeText(asWstring(text));
}

//-----------------------------------------------

csVoid csXMLWriteLineBreak(csXMLFile* file)
{
	if (!file->isreader)
		file->writer->writeLineBreak();
}
