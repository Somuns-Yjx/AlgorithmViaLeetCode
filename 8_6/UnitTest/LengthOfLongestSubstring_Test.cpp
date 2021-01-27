#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/LengthOfLongestSubstring.h"
#include "LengthOfLongestSubstring_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void LengthOfLongestSubstring_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/LengthOfLongestSubstring.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		LPTSTR Input = new char[LengthOfLongestSubstringInput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, LengthOfLongestSubstringInput_Length_Max, theIniPath);

		int Output = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);  // ini 里面的样例个数


		/*输出判断*/
		bool Final;
		if (LengthOfLongestSubstring(Input) == Output)
			Final = true;
		else
			Final = false;
		Assert::IsTrue(Final);


		delete[] Input;
	}
	delete[] theIniPath;
}
