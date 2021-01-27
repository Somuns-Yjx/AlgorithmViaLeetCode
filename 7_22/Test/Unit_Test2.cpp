#include "stdafx.h"
#include "CppUnitTest.h"

/***2***/
#include "../Qes/ExcelSheetColumnTitle.h"
#include "./Unit_Test2.h"



//#define theIniPath "../Test_Ini/Test1.ini"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest2()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/ExcelSheetColumnTitle.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ��ȡInput
		int Input = 0;      
		Input = GetPrivateProfileInt(Exp_Str, "Input", 0, theIniPath);

		// ��ȡOutput
		LPTSTR OutputStr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputStr, Output_Length, theIniPath);

		string Expect = OutputStr;
		
		/*����ж�*/
		string Actual;
		Actual = ExcelSheetColumnTitle(Input);  //�������ַ��� 
		
		Assert::AreEqual(Expect, Actual);

		delete[] OutputStr;
	}
	delete[] theIniPath;
}
