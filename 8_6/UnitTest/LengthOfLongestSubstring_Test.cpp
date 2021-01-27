#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/LengthOfLongestSubstring.h"
#include "LengthOfLongestSubstring_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void LengthOfLongestSubstring_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/LengthOfLongestSubstring.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		LPTSTR Input = new char[LengthOfLongestSubstringInput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, LengthOfLongestSubstringInput_Length_Max, theIniPath);

		int Output = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);  // ini �������������


		/*����ж�*/
		bool Final;
		if (LengthOfLongestSubstring(Input) == Output)
			Final = true;
		else
			Final = false;
		Assert::IsTrue(Final);


		delete[] Input;
	}
	delete[] theIniPath;
}
