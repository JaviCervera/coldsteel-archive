#include "engine.h"

/*#ifndef COLDSTEEL_LITE
std::vector<std::string> zip_list;
#endif*/

//-----------------------------------------------
//  Dir functions
//-----------------------------------------------

csVoid csPackageAdd(const char* pak)
{
#ifndef COLDSTEEL_LITE
	//zip_list.push_back(std::string(pak));
	Device->getFileSystem()->addZipFileArchive(pak);
#endif
}

//-----------------------------------------------

csInt csDirList(const char* dir)
{
	std::string curdir = Device->getFileSystem()->getWorkingDirectory();
	Device->getFileSystem()->changeWorkingDirectoryTo(dir);
	IFileList* list = Device->getFileSystem()->createFileList();
	Device->getFileSystem()->changeWorkingDirectoryTo(curdir.c_str());
	return (int) list;
}

//-----------------------------------------------

csVoid csDirClose(IFileList* list)
{
	list->drop();
}

//-----------------------------------------------

csInt csDirFileCount(IFileList* list)
{
	return list->getFileCount();
}

//-----------------------------------------------

csString csDirFileName(IFileList* list, int index)
{
	return list->getFileName(index-1);
}

//-----------------------------------------------

csInt csDirFileIsDir(IFileList* list, int index)
{
	return list->isDirectory(index-1);
}
