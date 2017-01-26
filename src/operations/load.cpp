#include "load.h"

//RCol='\e[0m'    # Text Reset
//Gre='\e[0;32m';

void Load::load()
{
	system("echo '\e[0;32mLoading\e[0m'");
	system("./AimTux/load");
}

void Load::unload()
{
	system("echo '\e[0;32mUnloading\e[0m'");
	system("./AimTux/uload");
}

void Load::reload()
{
	system("echo '\e[0;32mReloading\e[0m'");
	system("./AimTux/rload");
}
