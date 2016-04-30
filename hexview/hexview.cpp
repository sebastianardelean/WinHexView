// hexview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ContentFormat.h"
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
	bool use_output_file = false;
	std::wstring file_path = L"";
	std::wstring output_file = L"";
	std::shared_ptr<ContentFormat>format = std::make_shared<ContentFormat>();
	std::unique_ptr<Command> command(new Command(format));
	std::unique_ptr<FileReader> reader(new FileReader());

	//set default print
	command->SetExecuteMethod(&ContentFormat::DefaultPrint);

	//Start parsing arguments
	int arg_index;
	for (arg_index = 1; arg_index < argc; arg_index++){
		if (wcscmp(argv[arg_index], L"/A") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&ContentFormat::AsciiPrint);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/I") == 0){
			file_path = argv[arg_index + 1];
		}
		if (wcscmp(argv[arg_index], L"/O") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&ContentFormat::OneByteOctalDisplay);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/C") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&ContentFormat::CharacterDisplay);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/D") == 0){
			if (!is_display_option_set){
				command->SetExecuteMethod(&ContentFormat::DecimalDisplay);
				is_display_option_set = true;
			}
		}
		if (wcscmp(argv[arg_index], L"/N") == 0){
			upper_limit = std::stoi(argv[arg_index + 1]);
		}
		if (wcscmp(argv[arg_index], L"/F") == 0){
			output_file = argv[arg_index + 1];
			use_output_file = true;
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
			format->Configure((byte*)buffer, upper_limit);
			command->Execute();
			if (use_output_file == true){
				std::ofstream file;
				file.open(output_file);
				file << format->GetFormattedOutput() << std::flush;
				file.close();
			}
			else{
				std::cout << format->GetFormattedOutput() << std::flush;
			}
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
	std::wcout << argv << L"[/I input file] [Options]\n";
	std::wcout << L"/A\t\tdisplay ASCII characters\n";
	std::wcout << L"/O\t\toctal display\n";
	std::wcout << L"/C\t\toctal display\n";
	std::wcout << L"/D\t\tdecimal display\n";
	std::wcout << L"/F\t\toutput file\n";
}


