#include "load.h"

#define RESETCOL "\e[0m"
#define GREENCOL "\e[0;32m"

void Load::printColor(const char* output, const char* col)
{
	printf("%s%s%s\n", col, output, RESETCOL);
}

void Load::load()
{
	Load::printColor("Loading", GREENCOL);
	system("./AimTux/load");
}

void Load::unload()
{
	Load::printColor("Unloading", GREENCOL);
	system("./AimTux/uload");
}

void Load::reload()
{
	Load::printColor("Reloading", GREENCOL);
	system("./AimTux/rload");
}
