#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cstdarg>

#define COLOR_DEFAULT "\e[0m"
#define COLOR_GREEN "\e[0;32m"
#define COLOR_YELLOW "\e[0;33m"
#define COLOR_RED "\e[0;31m"

namespace Logger
{
	enum
	{
		DEBUG,
		WARNING,
		ERROR,
	};

	void Info(const char* msg, ...);
	void Warning(const char* msg, ...);
	void Error(const char* msg, ...);
}
