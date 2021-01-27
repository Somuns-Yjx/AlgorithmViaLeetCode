#include "stdafx.h"
#include "CppUnitTest.h"

/***1***/
#include "../8_6/IsValid.h"
#include "./IsValid_Test.h"


//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void IsValid_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/IsValid.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����(����)
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ��ȡOutput
		LPTSTR InputArr = new char[IsV_Input_Length];
		GetPrivateProfileString(Exp_Str, "Input", "", InputArr, IsV_Input_Length, theIniPath);

		// ��ȡOutput
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);
		
		string Input = InputArr;

		/*����ж�*/
		bool Expect;					   //�������߼���
		if (strcmp(OutputArr, "true") == 0)   // S1=S2 0  S1>S2  >0  S1<S2  <0
			Expect = true;
		else
			Expect = false;


		bool Final = (IsValid(Input) == Expect);
		Assert::IsTrue(Final);

		delete[] InputArr;
		delete[] OutputArr;
	}
	delete[] theIniPath;
}
