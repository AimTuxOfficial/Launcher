#include "logging.h"

void Logging::log(int lvl, const char* msg, ...)
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
		case Logging::DEBUG:
			color = COLOR_GREEN;
			break;
		case Logging::WARNING:
			color = COLOR_YELLOW;
			break;
		case Logging::ERROR:
			color = COLOR_RED;
			break;
	}
	printf("%s%s%s\n", color, formatted, COLOR_DEFAULT);
}
