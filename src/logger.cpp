#include "logger.h"

enum Color
{
	RED = 31,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	DEFAULT = 39
};

void Print(const char *text, va_list args)
{
	char formatted[256];
	vsnprintf(formatted, 255, text, args);
	va_end(args);
	printf("%s\n", formatted);
}

void ColorPrint(int color, const char *text, va_list args)
{
	char formatted[256];
	vsnprintf(formatted, 255, text, args);
	va_end(args);
	printf("\033[%dm%s\033[39m\n", color, formatted);
}

void Logger::Info(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	Print(msg, args);
	va_end(args);
}

void Logger::Warning(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);
	ColorPrint(Color::YELLOW, msg, args);
	va_end(args);
}

void Logger::Error(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);
	ColorPrint(Color::RED, msg, args);
	va_end(args);
}
