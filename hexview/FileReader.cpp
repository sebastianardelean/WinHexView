#include "stdafx.h"
#include "FileReader.h"


FileReader::FileReader(std::wstring filePath)
{
	gFilePath = filePath;
	gFileHandle = nullptr;
	
}


FileReader::~FileReader()
{
	if (gFileHandle != nullptr){
		(void)CloseHandle(gFileHandle);
	}
	
}

DWORD FileReader::Read(HANDLE hFile, void *buffer, INT64 count)throw (std::exception)
{
	DWORD read_bytes = 0;
	if (ReadFile(hFile,//fileHandle
		buffer,//void *buffer, will store read data
		count,//file size/number of Bytes to Read
		&read_bytes,//bytes that were read
		NULL
		) == FALSE){
		throw new FileManagementException("File Read operation reported error!");

	}

	return read_bytes;
}

void *FileReader::LoadFileContent(DWORD *bufferSize) throw (std::exception)
{
	
	LARGE_INTEGER file_size;
	UINT64 size;
	memset(&file_size, 0, sizeof(LARGE_INTEGER));//set default to 0
	gFileHandle = CreateFile(gFilePath.c_str(),//filename, in UNICODE
		GENERIC_READ,// open only for read,
		FILE_SHARE_READ,//it can be shared with other process for read purpose
		NULL,// file security attributes set to null
		OPEN_EXISTING,//open only existing files
		FILE_ATTRIBUTE_READONLY,// file is readonly
		NULL//hTemplateFile is null
		);
	if (gFileHandle == INVALID_HANDLE_VALUE){
		gFileHandle = nullptr;
		throw new FileManagementException("Could not open file!");
		return nullptr;
	}
	
	if (GetFileSizeEx(gFileHandle, &file_size) == FALSE){
		memset(&file_size, 0, sizeof(LARGE_INTEGER));
		throw new FileManagementException("Could not get file size!");
		return nullptr;
	}
	
	if (file_size.QuadPart % 8 == 0){
		size = file_size.QuadPart;
	}
	else{
		size = file_size.QuadPart + (8 - file_size.QuadPart % 8);
	}
	byte *buffer = new byte[size];
	memset(buffer, 0, size);
	try
	{
		*bufferSize=Read(gFileHandle, &buffer[0], size);//don't care about how much it reads for now
		if (*bufferSize % 8 != 0){
			*bufferSize = *bufferSize + (8 - *bufferSize % 8);
		}
		
	}
	catch (std::exception &e){
		e.what();
		return nullptr;
	}
	return buffer;
}