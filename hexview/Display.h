#pragma once
class Display
{
public:
	Display();
	virtual ~Display();
	void DefaultPrint();
	void AsciiPrint();
	void Configure(byte * buffer, DWORD bufferSize);
	
private:
	byte *gBuffer;
	DWORD gBufferSize;
	const byte gNoOfBits = 8;
	
};

