#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//1
#include "NimGame_Test.h"
//2
#include "IsValid_Test.h"
//3
#include "myAtoi_Test.h"
//4
#include "SingleNumber_Test.h"
//5
#include "WordPattern_Test.h"
//6
#include "ReverseBits_Test.h"
//7
#include "WordBreak_Test.h"
//8
#include "PlusOne_Test.h"
//9
#include "Sqrt_Test.h"
//10
#include "MoveZeroes_Test.h"
//11
#include "Reverse_Test.h"
//12
#include "Rotate_Test.h"
//13
#include "RestoreIpAddresses_Test.h"
//14
#include "LengthOfLongestSubstring_Test.h"
//15
#include "Partition_Test.h"
namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(NimGame)
		{
			NimGame_Test();
		}
		TEST_METHOD(IsValid)
		{
			IsValid_Test();
		}
		TEST_METHOD(myAtoi)
		{
			myAtoi_Test();
		}
		TEST_METHOD(SingleNumber)
		{
			SingleNumber_Test();
		}
		TEST_METHOD(WordPattern)
		{
			WordPattern_Test();
		}
		TEST_METHOD(ReverseBits)
		{
			ReverseBits_Test();
		}
		TEST_METHOD(WordBreak)
		{
			WordBreak_Test();
		}
		TEST_METHOD(PlusOne)
		{
			PlusOne_Test();
		}
		TEST_METHOD(Sqrt)
		{
			Sqrt_Test();
		}
		TEST_METHOD(MoveZeroes)
		{
			MoveZeroes_Test();
		}
		TEST_METHOD(Reverse)
		{
			Reverse_Test();
		}
		TEST_METHOD(Rotate)
		{
			Rotate_Test();
		}
		TEST_METHOD(RestoreIpAddresses)
		{
			RestoreIpAddresses_Test();
		}
		TEST_METHOD(LengthOfLongestSubstring)
		{
			LengthOfLongestSubstring_Test();
		}
		TEST_METHOD(Partition)
		{
			Partition_Test();
		}
	};
}