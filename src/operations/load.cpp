#include "load.h"

void Load::load()
{
	Logging::log(Logging::DEBUG, "Loading");
	system("./AimTux/load");
}

void Load::unload()
{
	Logging::log(Logging::DEBUG, "Unloading");
	system("./AimTux/uload");
}

void Load::reload()
{
	Logging::log(Logging::DEBUG, "Reloading");
	system("./AimTux/rload");
}
