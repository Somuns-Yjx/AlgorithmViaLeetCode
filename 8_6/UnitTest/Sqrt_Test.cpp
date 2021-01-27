#include "stdafx.h"
#include "CppUnitTest.h"

#include "../8_6/Sqrt.h"
#include "Sqrt_Test.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Sqrt_Test()
{

	LPTSTR theIniPath = new char[Path_Length];        // ����·��
	strcpy(theIniPath, "../Test_Ini/Sqrt.ini");

	int Total_Num = GetPrivateProfileInt("Total", "total", 0, theIniPath);  // ini �������������

	for (int Exp_Num = 1; Exp_Num <= Total_Num; Exp_Num++)
	{
		// ���� Example + ���
		char Exp_Index[Exp_Index_Length];
		itoa(Exp_Num, Exp_Index, 10);//����ת�����ַ�������һ�������������������������ɼ�����ת��

		char Exp_Str[Exp_Str_Length] = { "Example" }; // Exp_Str = Example + ����
		strcat(Exp_Str, Exp_Index);//���ڶ����ַ���׷�ӵ���һ���ַ���ĩβ���ڶ����ַ���ֵ���䣬��һ���䳤��

	
		int Input = GetPrivateProfileInt(Exp_Str, "Input", 0,theIniPath);
		
		int Output = GetPrivateProfileInt(Exp_Str, "Output", 0, theIniPath);


		/*����ж�*/

		//����(��ֵ���)

		bool Final = (Sqrt(Input) == Output);
		Assert::IsTrue(Final);

	}
	delete[] theIniPath;
}
