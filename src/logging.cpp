#include "logging.h"

void Logging::log(int lvl, const char* msg, ...)
{
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
	printf("%s%s%s\n", color, msg, COLOR_DEFAULT);
}
