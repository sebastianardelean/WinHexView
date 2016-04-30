#include "stdafx.h"
#include "Display.h"
#include "Command.h"


Command::Command(std::shared_ptr<Display> obj)
{
	
	gObj = obj;
}

void Command::SetExecuteMethod(void(Display::*method)())
{
	gMethod = method;
}

Command::~Command()
{

}

void Command::Execute()
{
	(gObj.get()->*gMethod)();

}