#pragma once
class Display
{
public:
	Display();
	virtual ~Display();
	void DefaultPrint();
	void AsciiPrint();
	void OneByteOctalDisplay();
	void CharacterDisplay();
	void DecimalDisplay();
	void Configure(byte * buffer, DWORD bufferSize);

	
private:
	byte *gBuffer;
	DWORD gBufferSize;
	const byte gNoOfBits = 8;
	const UINT32 gStartOffsetValue = 0x00000000;
	const byte gOffsetIncrement = 0x10;
};

