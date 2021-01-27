#include "stdafx.h"
#include "CppUnitTest.h"


/***8***/
#include "../Qes/HammingWeight.h"
#include "./Unit_Test8.h"
//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest8()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/HammingWeight.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 读取Input
		unsigned int Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);

		// 读取Output
		LPTSTR OutputArr = new char[Unit8_Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Unit8_Output_Length, theIniPath);

		/*输出判断*/
		int Expect = 0;					   //期望（数值相等）
		Expect = atoi(OutputArr);

		int Final = HammingWeight(Input);
		Assert::AreEqual(Expect, Final);

		delete[] OutputArr;
	}
	delete[] theIniPath;
}
