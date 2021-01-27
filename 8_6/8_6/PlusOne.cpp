#include "PlusOne.h"
/* Name:      vector<int> PlusOne(vector<int>& digits)
*  Function:  Increase the number in the dynamic array by one
*  Example:	  Input  = 1,9,9		Input  = 9,9,9
			  Output = 2,0,0		Output = 1,0,0,0
*  Return:	  Vector<int>
*/
vector<int> PlusOne(vector<int>& digits)
{
	int len = (int)digits.size()-1 ;
	for (len; len >= 0; len--)
	{
		digits[len] += 1;	
	
		if (digits[len] == 10)	/*如果末位等于10*/
		{
			digits[len] = 0;
		}
	
		else 				   /*如果不等于10，则返回该动态数组*/
		{
			return digits;
		}
	}
	digits.insert(digits.begin(), 1);
	return digits;

}

