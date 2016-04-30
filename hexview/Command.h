#pragma once

class Command
{
public:
	Command(std::shared_ptr<ContentFormat> obj);
	virtual ~Command();
	void SetExecuteMethod(void(ContentFormat::*method)());
	void Execute();
private:
	std::shared_ptr<ContentFormat>gObj;
	void(ContentFormat::*gMethod)();

};

