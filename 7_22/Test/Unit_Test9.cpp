#include "stdafx.h"
#include "CppUnitTest.h"


/***9***/
#include "../Qes/AddBinary.h"
#include "./Unit_Test9.h"
//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest9()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/AddBinary.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		LPTSTR Input1 = new char[Unit9_Input_Len];
		GetPrivateProfileString(Exp_Str, "Input1", "", Input1, Unit9_Input_Len, theIniPath);

		LPTSTR Input2 = new char[Unit9_Input_Len];
		GetPrivateProfileString(Exp_Str, "Input2", "", Input2, Unit9_Input_Len, theIniPath);
		
		// 读取Output
		LPTSTR Output = new char[Unit9_Output_Len];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, Unit9_Output_Len, theIniPath);

		string InputA = Input1;
		string InputB = Input2;

		/*输出判断*/
		string Expect = Output;						//期望（字符串匹配）
		string Final = AddBinary(InputA,InputB);
		
		Assert::AreEqual(Expect, Final);

		delete[] Input1;
		delete[] Input2;
		delete[] Output;
	}
	delete[] theIniPath;
}
