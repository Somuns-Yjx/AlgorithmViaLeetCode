#include "stdafx.h"
#include "CppUnitTest.h"

/***1***/
#include "../Qes/ContainsNearbyDuplicate.h"
#include "./Unit_Test1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest1()
{
	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath,"../Test_Ini/ContainsNearbyDuplicate.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num,Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		// 解析Example Index 下的Array标识符后面的内容
		LPTSTR Array_Str = new char[Array_Length_Max];    
		GetPrivateProfileString(Exp_Str, "Array", "", Array_Str, Array_Length_Max, theIniPath);   
		//从INI文件中读取到键值为Array的字符串赋予Array_Str 

		// 字符串数组 StrArr1 转换到 int数组 int_arr
		int ArrLen = 0;
		char *Ptr = strtok(Array_Str, ",");//分解字符串为一组字符串。1为要分解的字符串，2为分隔符字符串
		vector<int> Last_Array;        //声明一个新的vector,atoi 后转换到 vector 中
		while (Ptr != NULL)
		{

			Last_Array.push_back(atoi(Ptr));        //赋值到vector Last_Array 中
			ArrLen++;								//统计数组长度
			Ptr = strtok(NULL, ",");               
		}

		// 读取Key
		int Key = 0;        //
		Key = GetPrivateProfileInt(Exp_Str, "Key", 0, theIniPath);

		// 读取Output
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);  

		
		/*输出判断*/
		bool Expect;					   //期望（逻辑）
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;

		bool Final = (ContainsNearbyDuplicate(Last_Array, Key) == Expect);
		Assert::IsTrue(Final);

		delete[] Array_Str;
		delete[] OutputArr;
	}
	delete[] theIniPath;
}
