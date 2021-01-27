#include "stdafx.h"
#include "CppUnitTest.h"


/***9***/
#include "../Qes/AddBinary.h"
#include "./Unit_Test9.h"
//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest9()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/AddBinary.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		LPTSTR Input1 = new char[Unit9_Input_Len];
		GetPrivateProfileString(Exp_Str, "Input1", "", Input1, Unit9_Input_Len, theIniPath);

		LPTSTR Input2 = new char[Unit9_Input_Len];
		GetPrivateProfileString(Exp_Str, "Input2", "", Input2, Unit9_Input_Len, theIniPath);
		
		// ��ȡOutput
		LPTSTR Output = new char[Unit9_Output_Len];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, Unit9_Output_Len, theIniPath);

		string InputA = Input1;
		string InputB = Input2;

		/*����ж�*/
		string Expect = Output;						//�������ַ���ƥ�䣩
		string Final = AddBinary(InputA,InputB);
		
		Assert::AreEqual(Expect, Final);

		delete[] Input1;
		delete[] Input2;
		delete[] Output;
	}
	delete[] theIniPath;
}
