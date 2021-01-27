#include "stdafx.h"
#include "CppUnitTest.h"

/***1***/
#include "../8_6/myAtoi.h"
#include "./myAtoi_Test.h"


//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void myAtoi_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/myAtoi.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����(����)
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ��ȡInput
		LPTSTR InputArr = new char[mAti_Input_Length];
		GetPrivateProfileString(Exp_Str, "Input", "", InputArr, mAti_Input_Length, theIniPath);

		// ��ȡOutput
		int Output = 0;        //
		Output = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);

		string Input = InputArr;

		/*����ж�*/
		
		bool Final = (myAtoi(Input) == Output);
		Assert::IsTrue(Final);


		delete[] InputArr;
	}
	delete[] theIniPath;
}
