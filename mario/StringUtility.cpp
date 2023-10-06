#include "StringUtility.h"
#include<DxLib.h>
#include<cassert>

std::wstring
StringUtility::StringToWString(const std::string& str)
{
	//in : 情報側はstring(あらかじめわかってる)
	//out : 戻り値はwstring(文字列もわからない)
	std::wstring ret;
	int result = MultiByteToWideChar(
		CP_ACP,
		MB_PRECOMPOSED | MB_ERR_INVALID_CHARS,
		str.data(),
		str.size(),
		nullptr,
		0);
	assert(result >= 0);
	ret.resize(result);
	result = MultiByteToWideChar(
		CP_ACP,
		0,
		str.data(),
		str.size(),
		ret.data(),
		ret.size());



	return ret;
}
