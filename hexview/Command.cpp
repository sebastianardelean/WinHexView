#include "stdafx.h"
#include "ContentFormat.h"
#include "Command.h"


Command::Command(std::shared_ptr<ContentFormat> obj)
{
	
	gObj = obj;
}

void Command::SetExecuteMethod(void(ContentFormat::*method)())
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