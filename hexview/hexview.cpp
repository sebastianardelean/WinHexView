// hexview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Display.h"
#include "Command.h"
#include "FileReader.h"

static void print_help(_TCHAR *argv);
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 1){
		print_help(argv[0]);
		return 0;
	}
	void *buffer;
	DWORD buffer_size;

	std::unique_ptr<FileReader> reader(new FileReader(argv[1]));
	std::shared_ptr<Display>display = std::make_shared<Display>();
	std::unique_ptr<Command> command(new Command(display));
	
	//set default print
	command->SetExecuteMethod(&Display::DefaultPrint);

	int arg_index;
	for (arg_index = 1; arg_index < argc; arg_index++){
		if (wcscmp(argv[arg_index], L"/A") == 0){
			command->SetExecuteMethod(&Display::AsciiPrint);
		}
	}
	try{
		if ((buffer = reader->LoadFileContent(&buffer_size)) != nullptr){
			display->Configure((byte*)buffer, buffer_size);
			command->Execute();
		}

	}
	catch (std::exception &e){
		e.what();
		return -1;
	}

	delete []buffer;
	return 0;
}

void print_help(_TCHAR *argv)
{
	std::wcout << argv;
}