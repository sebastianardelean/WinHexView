#include "stdafx.h"
#include "Display.h"


Display::Display()
{
	
}


Display::~Display()
{
	
}
void Display::Configure(byte * buffer,DWORD bufferSize)
{
	gBuffer = buffer;
		
	gBufferSize = bufferSize;
}

void Display::AsciiPrint()
{
	//00000000  7f 45 4c 46 01 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	const byte dot_ascii_code = 0x2e;
	for (i = 0; i < gBufferSize; i += gNoOfBits)
	{
		printf("\n0x%08x  ", offset);
		printf("%02x %02x %02x %02x %02x %02x %02x %02x  ",
			gBuffer[i] >> 8, gBuffer[i], gBuffer[i + 1] >> 8, gBuffer[i + 1], gBuffer[i + 2] >> 8, gBuffer[i + 2], gBuffer[i + 3] >> 8, gBuffer[i + 3]);
		printf("%02x %02x %02x %02x %02x %02x %02x %02x  |",
			gBuffer[i + 4] >> 8, gBuffer[i + 4], gBuffer[i + 5] >> 8, gBuffer[i + 5], gBuffer[i + 6] >> 8, gBuffer[i + 6], gBuffer[i + 7] >> 8, gBuffer[i + 7] );
		for (byte b = 0; b < gNoOfBits; b++){
			if (gBuffer[i + b] < dot_ascii_code){//0x002e is ascii code for .
				printf("%c%c", (gBuffer[i + b] >> 8) + dot_ascii_code, gBuffer[i + b] + dot_ascii_code);
			}
			else{
				if ((gBuffer[i + b] >> 8) < dot_ascii_code){
					printf("%c%c", (gBuffer[i + b] >> 8) + dot_ascii_code, gBuffer[i + b]);
				}
				else{
					printf("%c%c", (gBuffer[i + b]) >> 8, gBuffer[i + b]);
				}
				
			}
		}
		printf("|");
		offset += 0x10;//add 16 bytes to address
	}
	fflush(stdout);
}

void Display::DefaultPrint()
{
	//0000000 457f 464c 0101 0001 0000 0000 0000 0000
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	for (i = 0; i < gBufferSize; i += gNoOfBits)
	{
		printf("\n0x%08x  ", offset);
		printf("%04x %04x %04x %04x %04x %04x %04x %04x", 
			gBuffer[i], gBuffer[i+1], gBuffer[i+2], gBuffer[i+3], gBuffer[i+4], gBuffer[i+5], gBuffer[i+6], gBuffer[i+7]);
		offset += 0x10;//add 16 bytes to address
	}
	fflush(stdout);
}

void Display::OneByteOctalDisplay()
{
//0000000 043 012 043 040 124 150 151 163 040 146 151 154 145 040 143 157
//0000010 156 164 141 151 156 163 040 143 157 156 146 151 147 165 162 141
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	for (i = 0; i < gBufferSize; i += gNoOfBits)
	{
		printf("\n0x%08x  ", offset);
		for (byte b = 0; b < gNoOfBits; b++){
			printf("%03o %03o ", gBuffer[i + b] >> 8, gBuffer[i + b]);
		}
		offset += 0x10;
	}
	fflush(stdout);
}