#pragma once
#include <iostream>
#include <Windows.h>

#define LOG_INFORMATION 10
#define LOG_WARNING 14
#define LOG_ERROR 12


void LOG(std::string message, int logLevel)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(color, logLevel);

	std::cout << message << std::endl;
}