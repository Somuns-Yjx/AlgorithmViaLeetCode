#include "stdafx.h"
#include "CppUnitTest.h"

//1
#include "Unit_Test1.h"
//2
#include "Unit_Test2.h"
//3
#include "Unit_Test3.h"
//4
#include "Unit_Test4.h"
//5
#include "Unit_Test5.h"
//6
#include "Unit_Test6.h"
//7
//#include "Unit_Test7.h"
//8
#include "Unit_Test8.h"
//9
#include "Unit_Test9.h"
//10
#include "Unit_Test10.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Test
{		
	TEST_CLASS(All_Test)
	{
	public:
		
		TEST_METHOD(Test1)
		{

			UnitTest1();

		}
		TEST_METHOD(Test2)
		{

			UnitTest2();

		}

		TEST_METHOD(Test3)
		{

			UnitTest3();

		}
		TEST_METHOD(Test4)
		{

			UnitTest4();

		}
		TEST_METHOD(Test5)
		{

			UnitTest5();

		}
		TEST_METHOD(Test6)
		{

			UnitTest6();

		}
		TEST_METHOD(Test7)
		{

			UnitTest7();

		}
		TEST_METHOD(Test8)
		{

			UnitTest8();

		}
		TEST_METHOD(Test9)
		{

			UnitTest9();

		}
		TEST_METHOD(Test10)
		{

			UnitTest10();

		}
	};
}