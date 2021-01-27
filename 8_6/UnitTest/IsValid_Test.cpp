#include "stdafx.h"
#include "CppUnitTest.h"

/***1***/
#include "../8_6/IsValid.h"
#include "./IsValid_Test.h"


//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void IsValid_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/IsValid.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引(节名)
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 读取Output
		LPTSTR InputArr = new char[IsV_Input_Length];
		GetPrivateProfileString(Exp_Str, "Input", "", InputArr, IsV_Input_Length, theIniPath);

		// 读取Output
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);
		
		string Input = InputArr;

		/*输出判断*/
		bool Expect;					   //期望（逻辑）
		if (strcmp(OutputArr, "true") == 0)   // S1=S2 0  S1>S2  >0  S1<S2  <0
			Expect = true;
		else
			Expect = false;


		bool Final = (IsValid(Input) == Expect);
		Assert::IsTrue(Final);

		delete[] InputArr;
		delete[] OutputArr;
	}
	delete[] theIniPath;
}
