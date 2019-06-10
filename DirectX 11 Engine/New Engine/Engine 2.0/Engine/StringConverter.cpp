#include "StringConverter.h"




std::wstring StringConverter::StringToWide(std::string str)
{
	//begin itterator and end itterator
	std::wstring wide_string(str.begin(), str.end());
	return wide_string;
}
