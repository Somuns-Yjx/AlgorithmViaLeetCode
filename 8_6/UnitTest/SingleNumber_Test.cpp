#include "stdafx.h"
#include "CppUnitTest.h"

#include "../8_6/SingleNumber.h"
#include "./SingleNumber_Test.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;	

void SingleNumber_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/SingleNumber.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		LPTSTR Input = new char[Array_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, Array_Length_Max, theIniPath);

		// 字符串数组 StrArr1 转换到 int数组 int_arr
		int ArrLen = 0;
		char *Ptr = strtok(Input, ",");//分解字符串为一组字符串。1为要分解的字符串，2为分隔符字符串
		vector<int> Last_Array;        //声明一个新的vector,atoi 后转换到 vector 中
		
		while (Ptr != NULL)
		{

			Last_Array.push_back(atoi(Ptr));        //赋值到vector Last_Array 中
			ArrLen++;								//统计数组长度
			Ptr = strtok(NULL, ",");
		}
	


		/*输出判断*/
		//期望（数值）
		int Expect =  GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);

		bool Final = (SingleNumber(Last_Array) == Expect);
		Assert::IsTrue(Final);

		delete[] Input;

	}
	delete[] theIniPath;
}
