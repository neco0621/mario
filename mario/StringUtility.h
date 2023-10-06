#pragma once
#include <string>
class StringUtility
{
public:
	///<summary>
	///マルチバイト文字列からワイド文字列への変換
	///</summary>

	static std::wstring
		StringToWString(const std::string& str);
};

