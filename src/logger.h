#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cstdarg>

namespace Logger
{
	void Info(const char* msg, ...);
	void Warning(const char* msg, ...);
	void Error(const char* msg, ...);
}
