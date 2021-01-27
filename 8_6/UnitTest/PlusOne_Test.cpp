#include "stdafx.h"
#include "CppUnitTest.h"

#include "../8_6/PlusOne.h"
#include "./PlusOne_Test.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void PlusOne_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/PlusOne.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		LPTSTR Input = new char[PLSInput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, PLSInput_Length_Max, theIniPath);

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

		LPTSTR Output = new char[PLSOutput_Length_Max];
		GetPrivateProfileString(Exp_Str, "Output", "", Output, PLSOutput_Length_Max, theIniPath);

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

		//����(��̬�������)

		bool Final = (PlusOne(InputArr) == OutputArr);
		Assert::IsTrue(Final);

		delete[] Input;
		delete[] Output;
	}
	delete[] theIniPath;
}
