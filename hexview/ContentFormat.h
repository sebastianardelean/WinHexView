#pragma once
class ContentFormat
{
public:
	ContentFormat();
	virtual ~ContentFormat();
	void DefaultPrint();
	void AsciiPrint();
	void OneByteOctalDisplay();
	void CharacterDisplay();
	void DecimalDisplay();
	void Configure(byte * buffer, DWORD bufferSize);
	std::string GetFormattedOutput();
	
private:
	byte *gBuffer;
	DWORD gBufferSize;
	const byte gNoOfBytes = 8;
	const UINT32 gStartOffsetValue = 0x00000000;
	const byte gOffsetIncrement = 0x10;
	std::stringstream gContentStream;
};

