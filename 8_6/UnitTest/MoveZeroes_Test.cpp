#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/MoveZeroes.h"
#include "MoveZeroes_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void MoveZeroes_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/MoveZeroes.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		LPTSTR Input = new char[MZsInput1_len];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, MZsInput1_len, theIniPath);

		// �ַ������� StrArr1 ת���� int���� int_arr
		int Inputlen = 0;
		char *Ptr = strtok(Input, ",");
		vector<int> InputArr;

		while (Ptr != NULL)
		{

			InputArr.push_back(atoi(Ptr));
			Inputlen++;
			Ptr = strtok(NULL, ",");
		}

		LPTSTR Output = new char[MZsOut_len];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, MZsOut_len, theIniPath);

		int Outputlen = 0;
		char *P = strtok(Output, ",");
		vector<int> OutputArr;

		while (P != NULL)
		{

			OutputArr.push_back(atoi(P));
			Outputlen++;
			P = strtok(NULL, ",");
		}


		/*����ж�*/
		MoveZeroes(InputArr);
		bool Final = (InputArr == OutputArr);
		Assert::IsTrue(Final);




		delete[] Input;
		delete[] Output;

	}
	delete[] theIniPath;
}
