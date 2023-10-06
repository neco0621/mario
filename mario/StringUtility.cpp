#include "StringUtility.h"
#include<DxLib.h>
#include<cassert>

std::wstring
StringUtility::StringToWString(const std::string& str)
{
	//in : ��񑤂�string(���炩���߂킩���Ă�)
	//out : �߂�l��wstring(��������킩��Ȃ�)
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
