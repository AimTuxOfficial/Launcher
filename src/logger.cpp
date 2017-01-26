#include "logger.h"

void Logger::Log(int lvl, const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char formatted[256];
	vsnprintf(formatted, 255, msg, args);
	va_end(args);

	char* color;
	switch (lvl)
	{
		default:
		case Logger::DEBUG:
			color = COLOR_GREEN;
			break;
		case Logger::WARNING:
			color = COLOR_YELLOW;
			break;
		case Logger::ERROR:
			color = COLOR_RED;
			break;
	}
	printf("%s%s%s\n", color, formatted, COLOR_DEFAULT);
}
