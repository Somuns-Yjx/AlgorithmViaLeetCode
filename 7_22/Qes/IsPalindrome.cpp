#include "IsPalindrome.h"
#pragma warning(disable: 4996)

/* Name:      bool IsPalindrome(int x)
*  Parameter: int x
*  Function:  judge whether a number is a Palindrome
*  Return:    bool
*/
bool IsPalindrome(int x)
{
	int result = 0;
	int tmp = 0;
	int number = x;
	if (x < 0)
		return false;
	while (number)
	{
		tmp = number % 10;
		number /= 10;
		if (result > INT_MAX / 10)
			return false;
		result *= 10;
		result += tmp;
	}

	if (result == x)
		return true;
	else
		return false;
}
