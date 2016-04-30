#pragma once
class Display
{
public:
	Display();
	virtual ~Display();
	void DefaultPrint();
	void AsciiPrint();
	void OneByteOctalDisplay();
	void Configure(byte * buffer, DWORD bufferSize);
	
private:
	byte *gBuffer;
	DWORD gBufferSize;
	const byte gNoOfBits = 8;
	const UINT32 gStartOffsetValue = 0x00000000;
	
};

