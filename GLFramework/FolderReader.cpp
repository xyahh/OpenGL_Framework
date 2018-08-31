#include "stdafx.h"
#include "FolderReader.h"

WIN32_FIND_DATAA	FolderReader::m_DataFinder;
HANDLE				FolderReader::m_Handle;

std::list<std::string> FolderReader::readFolder(std::string path, std::string type)
{
	std::string filetypes(path);
	filetypes.erase(filetypes.find_last_not_of("\\") + 1);
	filetypes += "\\*." + type;
	if (filetypes.length() > MAX_PATH)
	{
		std::cout << std::endl << "Directory path is too long." << std::endl;
		return std::list<std::string>();
	}
	finder(filetypes.c_str());
	std::list<std::string> filenames = getFilenames();
	FindClose(m_Handle);
	return filenames;
}

std::list<std::string> FolderReader::readFolder(std::string path)
{
	return readFolder(path, std::string("*"));
}

std::list<std::string> FolderReader::readFolder(std::string path, std::vector<std::string> supportedTypes)
{
	std::list<std::string> filenames;
	for (auto& type : supportedTypes)
		filenames.merge(readFolder(path, type));
	return filenames;
}

std::string FolderReader::findFirstFile()
{
	if (m_Handle != INVALID_HANDLE_VALUE)
		return m_DataFinder.cFileName;
	return std::string();
}

std::string FolderReader::findNextFile()
{
	if (FindNextFileA(m_Handle, &m_DataFinder))
		return m_DataFinder.cFileName;
	return std::string();
}

void FolderReader::finder(std::string a)
{
	m_Handle = FindFirstFileA(a.c_str(), &m_DataFinder);
}

std::list<std::string> FolderReader::getFilenames()
{
	std::list<std::string> result;
	for (std::string name = findFirstFile(); !name.empty(); name = findNextFile())
		result.push_back(name);
	return result;
}
