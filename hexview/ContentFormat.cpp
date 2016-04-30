#include "stdafx.h"
#include "ContentFormat.h"


ContentFormat::ContentFormat()
{

}


ContentFormat::~ContentFormat()
{

}
void ContentFormat::Configure(byte * buffer, DWORD bufferSize)
{
	gBuffer = buffer;

	gBufferSize = bufferSize;
}
std::string ContentFormat::GetFormattedOutput()
{
	return gContentStream.str();
}
void ContentFormat::AsciiPrint()
{
	//00000000  7f 45 4c 46 01 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	const byte dot_ascii_code = 0x2e;
	const byte space_ascii_code = 0x20;
	const byte size = gNoOfBytes * 2;
	gContentStream.clear();
	for (i = 0; i < gBufferSize; i += size)
	{
		gContentStream << "0x" << std::setfill('0') << std::setw(8) << std::hex << offset << "  ";

		for (byte b = 0; b < 8; b++){
			gContentStream << std::setfill('0') << std::setw(2) << std::hex << (int)gBuffer[i + b] << ' ';
		}
		gContentStream << " ";
		for (byte b = 8; b < size; b++){
			gContentStream << std::setfill('0') << std::setw(2) << std::hex << (int)gBuffer[i + b] << ' ';
		}
		gContentStream << " |";
		for (byte b = 0; b < size; b++){
			if (gBuffer[i + b] < space_ascii_code || gBuffer[i]>0x73){
				gContentStream << dot_ascii_code;

			}
			else{
				gContentStream << gBuffer[i + b];
			}

		}
		gContentStream << "|" << std::endl;
		offset += gOffsetIncrement;//add 16 bytes to address
	}
	gContentStream.flush();

}

void ContentFormat::DefaultPrint()
{
	//0000000 457f 464c 0101 0001 0000 0000 0000 0000
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	gContentStream.clear();
	for (i = 0; i < gBufferSize; i += gNoOfBytes)
	{
		gContentStream << "0x" << std::setfill('0') << std::setw(8) << std::hex << offset << "  ";
		for (byte b = 0; b < gNoOfBytes; b++){
			gContentStream << std::setfill('0') << std::setw(4) << std::hex << (int)gBuffer[i + b] << ' ';
		}
		gContentStream << std::endl;
		offset += gOffsetIncrement;//add 16 bytes to address
	}
	gContentStream.flush();

}

void ContentFormat::OneByteOctalDisplay()
{
	//0000000 043 012 043 040 124 150 151 163 040 146 151 154 145 040 143 157
	//0000010 156 164 141 151 156 163 040 143 157 156 146 151 147 165 162 141
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	gContentStream.clear();
	const byte size = gNoOfBytes * 2;
	for (i = 0; i < gBufferSize; i += size)
	{
		gContentStream << "0x" << std::setfill('0') << std::setw(8) << std::hex << offset << "  ";
		for (byte b = 0; b < size; b++){
			gContentStream << std::setfill('0') << std::setw(3) << std::oct << (int)gBuffer[i + b] << ' ';

		}
		gContentStream << std::endl;
		offset += gOffsetIncrement;
	}
	gContentStream.flush();

}

void ContentFormat::CharacterDisplay()
{
	//	0000000   #  \n   #       T   h   i   s       f   i   l   e       c   o
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	const byte size = gNoOfBytes * 2;
	gContentStream.clear();
	for (i = 0; i < gBufferSize; i += size)
	{
		gContentStream << "0x" << std::setfill('0') << std::setw(8) << std::hex << offset << "  ";
		for (byte b = 0; b < size; b++){
			gContentStream << gBuffer[i + b] << ' ';
		}
		gContentStream << std::endl;
		offset += gOffsetIncrement;
	}
	gContentStream.flush();

}
void ContentFormat::DecimalDisplay()
{
	//0000000   02595   08227   26708   29545   26144   27753   08293   28515
	//0000010   29806   26977   29550   25376   28271   26982   30055   24946
	DWORD i;
	UINT32 offset = gStartOffsetValue;
	gContentStream.clear();
	for (i = 0; i < gBufferSize; i += gNoOfBytes)
	{
		gContentStream << "0x" << std::setfill('0') << std::setw(8) << std::hex << offset << "  ";
		for (byte b = 0; b < gNoOfBytes; b++){
			gContentStream << std::setfill('0') << std::setw(5) << std::dec << (int)gBuffer[i + b] << ' ';
		}
		gContentStream << std::endl;
		offset += gOffsetIncrement;
	}
	gContentStream.flush();

}