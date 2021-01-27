#include "IsUgly.h"
/* Name:      bool IsUgly( int num )
*  Parameter: int num
*  Function:  judge whether a number is an ugly number
*  Range:	  -2^31 ~ 2^31-1
*  Return:    bool
*/
bool IsUgly(int num)
{
	int number = num;

	if (number == 1 )
		return true;	

	if (number <= 0 )
		return false;
	do
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}
		else if (number % 3 == 0)
		{
			number /= 3;
		}
		else if (number % 5 == 0)
		{
			number /= 5;
		}
		else
			return false;

	} while (number > 1 );

	return true;
}