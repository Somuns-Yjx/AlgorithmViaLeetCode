#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/Rotate.h"
#include "Rotate_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Rotate_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/Rotate.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		LPTSTR Input1 = new char[RotateInput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input1", "", Input1, RotateInput_Length_Max, theIniPath);

		// �ַ������� StrArr1 ת���� int���� int_arr
		int Inputlen = 0;
		char *Ptr = strtok(Input1, ",");
		vector<int> Input1vec;

		while (Ptr != NULL)
		{

			Input1vec.push_back(atoi(Ptr));
			Inputlen++;
			Ptr = strtok(NULL, ",");
		}

		int Input2 = GetPrivateProfileInt(Exp_Str, "Input2", 0, theIniPath);

		LPTSTR Output = new char[RotateOutput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, RotateOutput_Length_Max, theIniPath);

		// �ַ������� StrArr1 ת���� int���� int_arr
		int Outputlen = 0;
		char *Ptr1 = strtok(Output, ",");
		vector<int> Outputvec;

		while (Ptr1 != NULL)
		{

			Outputvec.push_back(atoi(Ptr1));
			Outputlen++;
			Ptr1 = strtok(NULL, ",");
		}

		/*����ж�*/
		bool Final;
		Rotate(Input1vec, Input2);
		if (Input1vec == Outputvec)
			Final = true;
		else
			Final = false;
		Assert::IsTrue(Final);


		delete[] Input1;
		delete[] Output;
	}
	delete[] theIniPath;
}
