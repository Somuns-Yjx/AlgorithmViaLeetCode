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

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/ReverseBits.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		int Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);  

		/*����ж�*/
		//��������ֵ��
		int Expect = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);

		bool Final = ((ReverseBits(Input)) == Expect);
		Assert::IsTrue(Final);


	}
	delete[] theIniPath;
}
