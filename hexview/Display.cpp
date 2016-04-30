#include "stdafx.h"
#include "Display.h"


Display::Display()
{

}


Display::~Display()
{

}
void Display::Configure(byte * buffer, DWORD bufferSize)
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
	const byte space_ascii_code = 0x20;
	const byte size = gNoOfBytes * 2;
	for (i = 0; i < gBufferSize; i += size)
	{
		printf("\n0x%08x  ", offset);
		printf("%02x %02x %02x %02x %02x %02x %02x %02x  ",
			gBuffer[i], gBuffer[i+1], gBuffer[i + 2] , gBuffer[i + 3], gBuffer[i + 4] , gBuffer[i + 5], gBuffer[i + 6], gBuffer[i + 7]);
		printf("%02x %02x %02x %02x %02x %02x %02x %02x  |",
			gBuffer[i + 8], gBuffer[i + 9], gBuffer[i + 10] , gBuffer[i + 11], gBuffer[i + 12] , gBuffer[i + 13], gBuffer[i + 14] , gBuffer[i + 15]);
		
		for (byte b = 0; b < size; b++){
			if (gBuffer[i + b]  < space_ascii_code || gBuffer[i]>0x73){
				printf("%c", dot_ascii_code);
			}
			else{
				printf("%c", gBuffer[i + b]);
			}

		}
		printf("|");
		offset += gOffsetIncrement;//add 16 bytes to address
	}

	fflush(stdout);
}

void Display::DefaultPrint()
{
	//0000000 457f 464c 0101 0001 0000 0000 0000 0000
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	for (i = 0; i < gBufferSize; i += gNoOfBytes)
	{
		printf("\n0x%08x  ", offset);
		printf("%04x %04x %04x %04x %04x %04x %04x %04x",
			gBuffer[i], gBuffer[i + 1], gBuffer[i + 2], gBuffer[i + 3], gBuffer[i + 4], gBuffer[i + 5], gBuffer[i + 6], gBuffer[i + 7]);
		offset += gOffsetIncrement;//add 16 bytes to address
	}
	fflush(stdout);
}

void Display::OneByteOctalDisplay()
{
	//0000000 043 012 043 040 124 150 151 163 040 146 151 154 145 040 143 157
	//0000010 156 164 141 151 156 163 040 143 157 156 146 151 147 165 162 141
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	for (i = 0; i < gBufferSize; i += gNoOfBytes)
	{
		printf("\n0x%08x  ", offset);
		for (byte b = 0; b < gNoOfBytes; b++){
			printf("%03o %03o ", gBuffer[i + b] >> 8, gBuffer[i + b]);
		}
		offset += gOffsetIncrement;
	}
	fflush(stdout);
}

void Display::CharacterDisplay()
{
	//	0000000   #  \n   #       T   h   i   s       f   i   l   e       c   o
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	const byte size = gNoOfBytes * 2;
	for (i = 0; i < gBufferSize; i += size)
	{
		printf("\n0x%08x  ", offset);
		for (byte b = 0; b < size; b++){
			printf("%c ", gBuffer[i + b]);
		}
		offset += gOffsetIncrement;
	}
	fflush(stdout);
}
void Display::DecimalDisplay()
{
	//0000000   02595   08227   26708   29545   26144   27753   08293   28515
	//0000010   29806   26977   29550   25376   28271   26982   30055   24946
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	for (i = 0; i < gBufferSize; i += gNoOfBytes)
	{
		printf("\n0x%08x  ", offset);
		printf("%05d %05d %05d %05d %05d %05d %05d %05d",
			gBuffer[i], gBuffer[i + 1], gBuffer[i + 2], gBuffer[i + 3], gBuffer[i + 4], gBuffer[i + 5], gBuffer[i + 6], gBuffer[i + 7]);
		offset += gOffsetIncrement;
	}
	fflush(stdout);
}