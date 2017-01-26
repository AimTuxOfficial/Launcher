#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../logger.h"

namespace Load
{
	void PrintColor(const char*, const char*);
	void Load();
	void Unload();
	void Reload();
}
