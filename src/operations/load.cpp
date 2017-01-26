#include "load.h"

void Load::Load()
{
	Logger::Log(Logger::DEBUG, "Loading");
	system("./AimTux/load");
}

void Load::Unload()
{
	Logger::Log(Logger::DEBUG, "Unloading");
	system("./AimTux/uload");
}

void Load::Reload()
{
	Logger::Log(Logger::DEBUG, "Reloading");
	system("./AimTux/rload");
}
