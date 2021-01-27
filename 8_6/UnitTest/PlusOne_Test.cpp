#include "stdafx.h"
#include "CppUnitTest.h"

#include "../8_6/PlusOne.h"
#include "./PlusOne_Test.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void PlusOne_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/PlusOne.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		LPTSTR Input = new char[PLSInput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, PLSInput_Length_Max, theIniPath);

		// 字符串数组 StrArr1 转换到 int数组 int_arr
		int Inputlen = 0;
		char *Ptr = strtok(Input, ",");
		vector<int> InputArr;       

		while (Ptr != NULL)
		{

			InputArr.push_back(atoi(Ptr));       
			Inputlen++;							
			Ptr = strtok(NULL, ",");
		}

		LPTSTR Output = new char[PLSOutput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, PLSOutput_Length_Max, theIniPath);

		int Outputlen = 0;
		char *P = strtok(Output, ",");
		vector<int> OutputArr;        

		while (P != NULL)
		{

			OutputArr.push_back(atoi(P));       
			Outputlen++;						
			P = strtok(NULL, ",");
		}

		/*输出判断*/

		//期望(动态数组相等)

		bool Final = (PlusOne(InputArr) == OutputArr);
		Assert::IsTrue(Final);

		delete[] Input;
		delete[] Output;
	}
	delete[] theIniPath;
}
