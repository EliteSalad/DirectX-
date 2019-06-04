#pragma once
#include <string>

///Singleton That converts strings to wide strings
class StringConverter
{
public:
	static std::wstring StringToWide(std::string str);
};

