#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/WordBreak.h"
#include "WordBreak_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void WordBreak_Test()
{
		
	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/WordBreak.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 读取Input1
		LPTSTR Input1 = new char[Input1_len];
		GetPrivateProfileString(Exp_Str, "Input1", "", Input1, Input1_len, theIniPath);
		// 读取Input2
		LPTSTR Input2 = new char[Input2_len];
		GetPrivateProfileString(Exp_Str, "Input2", "", Input2, Input2_len, theIniPath);

		// 读取Output
		LPTSTR OutputArr = new char[WBOut_len];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, WBOut_len, theIniPath);


		string Input = Input1;
		string Input_2 = Input2;
		vector<string> wordDict;
		wordDict.push_back(Input_2);


		/*输出判断*/
		bool Expect;					   //期望（逻辑）
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;


		bool Final = (WordBreak(Input,wordDict) == Expect);
		Assert::IsTrue(Final);




		delete[] Input1;
		delete[] Input2;
		
	}
	delete[] theIniPath;
}
