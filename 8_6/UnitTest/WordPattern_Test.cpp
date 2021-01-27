#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/WordPattern.h"
#include "WordPattern_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void WordPattern_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/WordPattern.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ��ȡPattern
		LPTSTR Pattern_str = new char[Pattern_Length];
		GetPrivateProfileString(Exp_Str, "Pattern", "", Pattern_str, Pattern_Length, theIniPath);
		// ��ȡStr
		LPTSTR Str_str = new char[Str_Length];
		GetPrivateProfileString(Exp_Str, "Str","", Str_str, Str_Length,theIniPath);

		// ��ȡOutput
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);

		string Pattern = Pattern_str;
		string Str = Str_str;
		/*����ж�*/
		bool Expect;					   //�������߼���
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;


		bool Final = (WordPattern(Pattern,Str) == Expect);
		Assert::IsTrue(Final);

		


		delete[] Pattern_str;
		delete[] Str_str;
		delete[] OutputArr;
	}
	delete[] theIniPath;
}
