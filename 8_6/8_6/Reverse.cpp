#include "Reverse.h"
/* Name:      Reverse(int x)
*  Function:  Reverse the given number range [−2^31,  2^31 − 1]
*  Example:	  Input = 123
*			  Output = 321	  
*  Return:	  int
*/
#ifdef RvMethd1
int Reverse(int x )
{
	int result = 0;
	int tmp = 0;
	while (x != 0) 
	{
		tmp = x % 10;
		x /= 10;											
		if (result > INT_MAX / 10 )		/* 2147483647 */
			return 0;					/* 7463847412 */	
		if (result < INT_MIN / 10 )
			return 0;					/* -2147483648 */
		result *= 10;					/* -8463847412 */
		result += tmp;
	}
	return result;
	
}
#endif 

#ifdef RvMethd2
int Reverse(int x)
{
	long long result = 0;
	int tmp = 0;
	bool neg_flag = false;
	if (x == INT_MIN)
		return 0;
	if (x < 0)
	{
		neg_flag = true;
		x = -x;
	}

	while (x)
	{
		tmp = x % 10;
		x /= 10;
		result *= 10;
		result += tmp;
		
	}
	if (result > INT_MAX )
		return 0;
	else if (neg_flag == true)
		return -result;
	else
		return result;
}
#endif 
