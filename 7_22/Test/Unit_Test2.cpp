#include "stdafx.h"
#include "CppUnitTest.h"

/***2***/
#include "../Qes/ExcelSheetColumnTitle.h"
#include "./Unit_Test2.h"



//#define theIniPath "../Test_Ini/Test1.ini"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest2()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/ExcelSheetColumnTitle.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 读取Input
		int Input = 0;      
		Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);

		// 读取Output
		LPTSTR OutputStr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputStr, Output_Length, theIniPath);

		string Expect = OutputStr;
		
		/*输出判断*/
		string Actual;
		Actual = ExcelSheetColumnTitle(Input);  //期望（字符） 
		
		Assert::AreEqual(Expect, Actual);

		delete[] OutputStr;
	}
	delete[] theIniPath;
}
