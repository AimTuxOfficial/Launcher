#include "load.h"

void Load::load()
{
	Logger::Log(Logger::DEBUG, "Loading");
	system("./AimTux/load");
}

void Load::unload()
{
	Logger::Log(Logger::DEBUG, "Unloading");
	system("./AimTux/uload");
}

void Load::reload()
{
	Logger::Log(Logger::DEBUG, "Reloading");
	system("./AimTux/rload");
}
