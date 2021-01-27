#include "stdafx.h"
#include "CppUnitTest.h"

/***1***/
#include "../8_6/myAtoi.h"
#include "./myAtoi_Test.h"


//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void myAtoi_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/myAtoi.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引(节名)
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 读取Input
		LPTSTR InputArr = new char[mAti_Input_Length];
		GetPrivateProfileString(Exp_Str, "Input", "", InputArr, mAti_Input_Length, theIniPath);

		// 读取Output
		int Output = 0;        //
		Output = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);

		string Input = InputArr;

		/*输出判断*/
		
		bool Final = (myAtoi(Input) == Output);
		Assert::IsTrue(Final);


		delete[] InputArr;
	}
	delete[] theIniPath;
}
