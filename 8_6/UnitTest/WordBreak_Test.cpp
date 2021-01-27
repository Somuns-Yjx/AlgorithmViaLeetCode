#include "stdafx.h"
#include "CppUnitTest.h"


#include "../8_6/WordBreak.h"
#include "WordBreak_Test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void WordBreak_Test()
{
		
	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/WordBreak.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

		// ��ȡInput1
		LPTSTR Input1 = new char[Input1_len];
		GetPrivateProfileString(Exp_Str, "Input1", "", Input1, Input1_len, theIniPath);
		// ��ȡInput2
		LPTSTR Input2 = new char[Input2_len];
		GetPrivateProfileString(Exp_Str, "Input2", "", Input2, Input2_len, theIniPath);

		// ��ȡOutput
		LPTSTR OutputArr = new char[WBOut_len];
		GetPrivateProfileString(Exp_Str, "Output", "", OutputArr, WBOut_len, theIniPath);


		string Input = Input1;
		string Input_2 = Input2;
		vector<string> wordDict;
		wordDict.push_back(Input_2);


		/*����ж�*/
		bool Expect;					   //�������߼���
		if (strcmp(OutputArr, "true") == 0)
			Expect = true;
		else
			Expect = false;


		bool Final = (WordBreak(Input,wordDict) == Expect);
		Assert::IsTrue(Final);




		delete[] Input1;
		delete[] Input2;
		
	}
	delete[] theIniPath;
}
