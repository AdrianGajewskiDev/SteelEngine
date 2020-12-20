#include "Log.h"


void LOG(std::string message, int logLevel, bool clamp)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, logLevel);

	std::cout << message << std::endl;

	if (clamp)
		system("cls");
}