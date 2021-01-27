#include "stdafx.h"
#include "CppUnitTest.h"

#include "../8_6/ReverseBits.h"
#include "ReverseBits_Test.h"
//#include <limits>
//UINT_MAX
//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ReverseBits_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/ReverseBits.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini 里面的样例个数

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// 解析 Example + 编号
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//整型转换成字符串，第一参数是整型数，第三参数是由几进制转换

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + 索引
		strcat(Exp_Str, Exp_Index);//将第二个字符串追加到第一个字符串末尾，第二个字符串值不变，第一个变长。

		int Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);  

		/*输出判断*/
		//期望（数值）
		int Expect = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);

		bool Final = ((ReverseBits(Input)) == Expect);
		Assert::IsTrue(Final);


	}
	delete[] theIniPath;
}
