#include "load.h"

void Load::Load()
{
	Logger::Info("Loading");
	system("./AimTux/load");
}

void Load::Unload()
{
	Logger::Info("Unloading");
	system("./AimTux/uload");
}

void Load::Reload()
{
	Logger::Info("Reloading");
	system("./AimTux/rload");
}
