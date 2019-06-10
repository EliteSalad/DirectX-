#include "ErrorLogger.h"
#include <comdef.h>					//used for com error data type




///Error equals string that is first part of the error message concat with the message itself 
///MessageBoxA is asccii meaning it expects short strings
///MessageBoxA(Parent window, text, title, message box type)
///MessageBox Type is MB_ICONERROR default error message

void ErrorLogger::Log(std::string message)
{
	std::string error_message = "Error: " + message;
	MessageBoxA(NULL, error_message.c_str(), "Error", MB_ICONERROR);
}

///_com_error used. Takes in HRESULT meaning information can be gathered from the error by
///calling the error.ErrorMessage() funcaiton
///_com_error returns a wide string so using wide string
///L before strings because strings are wide strings
///MessageBoxW is for wide strings
void ErrorLogger::Log(HRESULT hr, std::string message)
{
	_com_error error(hr);
	std::wstring errorMessage = error.ErrorMessage();
	std::wstring error_message = L"Error: " + StringConverter::StringToWide(message) + L"\n" + errorMessage;
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);
}
