                    Template version 0.1 released in "30-01-2016" author "23ars"

# WinHexView


## Release notes

| WinHexView-1.0 |              |                          |               |           |            |
| ------------ | -------------- | ------------------------- | ------------- | --------- | ---------- |
| **Issue Id** | **Issue Name** | **Description**           | **Milestone** | **Label** | **Author** |
|   1          | Read Class     | See issue                 | v1.0          | feature   |  23ars     |
|   2          | Format Class   | See issue                 | v1.0          | feature   |  23ars     |
|   3          | Default format | See issue                 | v1.0          | feature   |  23ars     |
|   4          | /A format      | See issue                 | v1.0          | feature   |  23ars     |
|   5          | Help           | See issue                 | v1.0          | feature   |  23ars     |
|   8          | /O format      | See issue                 | v1.0          | feature   |  23ars     |
|   9          | /C format      | See issue                 | v1.0          | feature   |  23ars     |
|   10         | /D format      | See issue                 | v1.0          | feature   |  23ars     |
|   11         | Format option  | See issue                 | v1.0          | bug       |  23ars     |
|   12         | Fix format     | See issue                 | v1.0          | bug       |  23ars     |
|   13         | Split          | See issue                 | v1.0          | feature   |  23ars     |
|   14         | File Output    | See issue                 | v1.0          | feature   |  23ars     |

---

## Compiler flags

```
/GS /GL /analyze- /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Fd"Release\vc120.pdb" /fp:precise /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_LIB" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /Oi /MD /Fa"Release\" /EHsc /nologo /Fo"Release\" /Fp"Release\hexview.pch" 
```
## Linker flags

```
/OUT:"C:\Users\Mihai\documents\visual studio 2013\Projects\hexview\Release\hexview.exe" /MANIFEST /LTCG /NXCOMPAT /PDB:"C:\Users\Mihai\documents\visual studio 2013\Projects\hexview\Release\hexview.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /DEBUG /MACHINE:X86 /OPT:REF /SAFESEH /INCREMENTAL:NO /PGD:"C:\Users\Mihai\documents\visual studio 2013\Projects\hexview\Release\hexview.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Release\hexview.exe.intermediate.manifest" /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1 
```

## Compiler Messages 

```
1>------ Build started: Project: hexview, Configuration: Release Win32 ------
1>  Command.cpp
1>  ContentFormat.cpp
1>  FileReader.cpp
1>c:\users\mihai\documents\visual studio 2013\projects\hexview\hexview\FileReader.h(21): warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
1>c:\users\mihai\documents\visual studio 2013\projects\hexview\hexview\FileReader.h(24): warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
1>FileReader.cpp(21): warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
1>FileReader.cpp(29): warning C4244: 'argument' : conversion from 'INT64' to 'DWORD', possible loss of data
1>FileReader.cpp(40): warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
1>FileReader.cpp(76): warning C4244: 'initializing' : conversion from 'UINT64' to 'unsigned int', possible loss of data
1>FileReader.cpp(77): warning C4244: 'argument' : conversion from 'UINT64' to 'size_t', possible loss of data
1>  hexview.cpp
1>c:\users\mihai\documents\visual studio 2013\projects\hexview\hexview\FileReader.h(21): warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
1>c:\users\mihai\documents\visual studio 2013\projects\hexview\hexview\FileReader.h(24): warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
1>  stdafx.cpp
1>  Generating code
1>  Finished generating code
1>  hexview.vcxproj -> C:\Users\Mihai\documents\visual studio 2013\Projects\hexview\Release\hexview.exe
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========

```

Note: post a list of compiler warnings.





