#pragma once

class Command
{
public:
	Command(std::shared_ptr<Display> obj);
	virtual ~Command();
	void SetExecuteMethod(void(Display::*method)());
	void Execute();
private:
	std::shared_ptr<Display>gObj;
	void(Display::*gMethod)();
	
};

