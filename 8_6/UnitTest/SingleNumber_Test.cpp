#include "stdafx.h"
#include "CppUnitTest.h"

#include "../8_6/SingleNumber.h"
#include "./SingleNumber_Test.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;	

void SingleNumber_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/SingleNumber.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		LPTSTR Input = new char[Array_Length_Max];
		GetPrivateProfileString(Exp_Str, "Input", "", Input, Array_Length_Max, theIniPath);

		// �ַ������� StrArr1 ת���� int���� int_arr
		int ArrLen = 0;
		char *Ptr = strtok(Input, ",");//�ֽ��ַ���Ϊһ���ַ�����1ΪҪ�ֽ���ַ�����2Ϊ�ָ����ַ���
		vector<int> Last_Array;        //����һ���µ�vector,atoi ��ת���� vector ��
		
		while (Ptr != NULL)
		{

			Last_Array.push_back(atoi(Ptr));        //��ֵ��vector Last_Array ��
			ArrLen++;								//ͳ�����鳤��
			Ptr = strtok(NULL, ",");
		}
	


		/*����ж�*/
		//��������ֵ��
		int Expect =  GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);

		bool Final = (SingleNumber(Last_Array) == Expect);
		Assert::IsTrue(Final);

		delete[] Input;

	}
	delete[] theIniPath;
}
