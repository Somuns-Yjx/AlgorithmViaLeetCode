#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/RestoreIpAddresses.h"
#include "RestoreIpAddresses_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void RestoreIpAddresses_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/RestoreIpAddresses.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		LPTSTR Input = new char[RestoreAddressesInput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, RestoreAddressesInput_Length_Max, theIniPath);

		LPTSTR Output = new char[RestoreAddressesOutput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, RestoreAddressesOutput_Length_Max, theIniPath);

		string Inputstr = Input;

		vector<string> Outputvec;
		//Outputvec.push_back(Output);

		int Outputlen = 0;
		char *Ptr = strtok(Output, ",");

		while (Ptr != NULL)
		{

			Outputvec.push_back(Ptr);
			Outputlen++;
			Ptr = strtok(NULL, ",");
		}


		/*输出判断*/
		bool Final;
		if (RestoreIpAddresses(Input) == Outputvec)
			Final = true;
		else
			Final = false;
		Assert::IsTrue(Final);


		delete[] Input;
		delete[] Output;
	}
	delete[] theIniPath;
}
