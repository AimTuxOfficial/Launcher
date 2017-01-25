#include "load.h"

void Load::load()
{
	printf("Loading\n");
	system("./AimTux/load");
}

void Load::unload()
{
	printf("Unloading\n");
	system("./AimTux/uload");
}

void Load::reload()
{
	printf("Reloading\n");
	system("./AimTux/rload");
}
