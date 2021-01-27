#include "stdafx.h"
#include "CppUnitTest.h"


/***4***/
#include "../Qes/IsPalindrome.h"
#include "./Unit_Test4.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest4()
{
	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/IsPalindrome.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 读取Input
		int Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);

		// 读取Output
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);

		/*输出判断*/
		bool Expect;					   //期望（逻辑）
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;

		bool Final = IsPalindrome(Input);
		Assert::AreEqual(Expect, Final);

		delete[] OutputArr;
	}
	delete[] theIniPath;
}
