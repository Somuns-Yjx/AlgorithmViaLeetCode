#include "stdafx.h"
#include "CppUnitTest.h"


/***4***/
#include "../Qes/IsPalindrome.h"
#include "./Unit_Test4.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest4()
{
	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/IsPalindrome.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ��ȡInput
		int Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);

		// ��ȡOutput
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);

		/*����ж�*/
		bool Expect;					   //�������߼���
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;

		bool Final = IsPalindrome(Input);
		Assert::AreEqual(Expect, Final);

		delete[] OutputArr;
	}
	delete[] theIniPath;
}