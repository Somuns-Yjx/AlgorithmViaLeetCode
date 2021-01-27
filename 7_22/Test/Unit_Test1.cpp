#include "stdafx.h"
#include "CppUnitTest.h"

/***1***/
#include "../Qes/ContainsNearbyDuplicate.h"
#include "./Unit_Test1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UnitTest1()
{
	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath,"../Test_Ini/ContainsNearbyDuplicate.ini");

	int Total_Num = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num,Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ����Example Index �µ�Array��ʶ�����������
		LPTSTR Array_Str = new char[Array_Length_Max];    
		GetPrivateProfileString(Exp_Str, "Array", "", Array_Str, Array_Length_Max, theIniPath);   
		//��INI�ļ��ж�ȡ����ֵΪArray���ַ�������Array_Str 

		// �ַ������� StrArr1 ת���� int���� int_arr
		int ArrLen = 0;
		char *Ptr = strtok(Array_Str, ",");//�ֽ��ַ���Ϊһ���ַ�����1ΪҪ�ֽ���ַ�����2Ϊ�ָ����ַ���
		vector<int> Last_Array;        //����һ���µ�vector,atoi ��ת���� vector ��
		while (Ptr != NULL)
		{

			Last_Array.push_back(atoi(Ptr));        //��ֵ��vector Last_Array ��
			ArrLen++;								//ͳ�����鳤��
			Ptr = strtok(NULL, ",");               
		}

		// ��ȡKey
		int Key = 0;        //
		Key = GetPrivateProfileInt(Exp_Str, "Key", 0, theIniPath);

		// ��ȡOutput
		LPTSTR OutputArr = new char[Output_Length];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, Output_Length, theIniPath);  

		
		/*����ж�*/
		bool Expect;					   //�������߼���
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;

		bool Final = (ContainsNearbyDuplicate(Last_Array, Key) == Expect);
		Assert::IsTrue(Final);

		delete[] Array_Str;
		delete[] OutputArr;
	}
	delete[] theIniPath;
}
