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
	DWORD upper_limit = 0;
	bool is_display_option_set = false;
	std::wstring file_path = L"";

	std::shared_ptr<Display>display = std::make_shared<Display>();
	std::unique_ptr<Command> command(new Command(display));
	std::unique_ptr<FileReader> reader(new FileReader());

	//set default print
	command->SetExecuteMethod(&Display::DefaultPrint);

	//Start parsing arguments
	int arg_index;
	for (arg_index = 1; arg_index < argc; arg_index++){
		if (wcscmp(argv[arg_index], L"/A") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&Display::AsciiPrint);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/F") == 0){
			file_path = argv[arg_index + 1];
		}
		if (wcscmp(argv[arg_index], L"/O") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&Display::OneByteOctalDisplay);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/C") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&Display::CharacterDisplay);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/D") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&Display::DecimalDisplay);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/N") == 0){
			upper_limit = std::stoi(argv[arg_index + 1]);
		}

	}
	if (file_path.empty() == true){
		goto end;
	}

	reader->SetInputFile(file_path);
	try{
		
		if ((buffer = reader->LoadFileContent(&buffer_size)) != nullptr){
			if (upper_limit == 0){
				upper_limit = buffer_size;
			}
			display->Configure((byte*)buffer, upper_limit);
			command->Execute();
		}

	}
	catch (std::exception &e){
		e.what();
		return -1;
	}

	delete[]buffer;
end:
	return 0;
}

void print_help(_TCHAR *argv)
{
	std::wcout << argv << L" [Options]\n";
	std::wcout << L"/F\t\tinput file[if not specified, stdin is used]\n";
	std::wcout << L"/A\t\tdisplay ASCII characters\n";
	std::wcout << L"/O\t\toctal display\n";
	std::wcout << L"/C\t\toctal display\n";
	std::wcout << L"/D\t\tdecimal display\n";
}

/*
TODO:
-n xx -C (-n xx= first xx bytes of file)
00000000  23 0a 23 20 54 68 69 73  20 66 69 6c 65 20 63 6f  |#.# This file co|
00000010  6e 74 61 69 6e 73 20 63  6f 6e 66 69 67 75 72 61  |ntains configura|
*/
//TODO: add output file option:)