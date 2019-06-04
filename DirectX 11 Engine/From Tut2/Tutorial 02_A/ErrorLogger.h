#pragma once
#include "StringConverter.h"
#include <Windows.h>

//singleton class to logg errors with string errors or hresult
class ErrorLogger
{
public:
	static void Log(std::string message);
	static void Log(HRESULT hr, std::string message);
};

