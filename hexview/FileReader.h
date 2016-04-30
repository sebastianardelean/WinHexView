#pragma once
class FileManagementException :public std::exception
{
private:
	std::string g_msg;
public:
	FileManagementException(const std::string& msg) :g_msg(msg)
	{}

	FileManagementException() :g_msg("FileManagementException thrown!"){}
	const char *what() const
	{
		return g_msg.c_str();
	}
};
class FileReader
{
public:
	FileReader(std::wstring filePath);
	virtual ~FileReader();
	void *LoadFileContent(DWORD *bufferSize) throw (std::exception);
private:
	DWORD Read(HANDLE hFile, void *buffer, INT64 count)throw (std::exception);
	std::wstring gFilePath;
	HANDLE gFileHandle;
	
	
};

