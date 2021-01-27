#include "Sqrt.h"


/* Name:      Sqrt(int x)
*  Function:  Make a function like sqrt
*  Example:	  Input  = 4		Input  = 2147395599
*			  Output = 2		Output = 46339
*  Return:	  int
*/

/*ʹ�����к���*/
#ifdef Use_math_h
int Sqrt(int x)
{		
	int res = (int)sqrt(x);
	return res;
}
#endif

/*��ʹ�����к���*/
#ifndef Use_math_h

int Sqrt(int x)
{

	/*����*/
	
	unsigned long long  low = 0;
	unsigned long long  high = x;
	unsigned long long  mid = (high + low) / 2;
	unsigned long long  power = mid * mid;

	if (x == 1)
		return 1;

	/*�ж�power��x�Ĺ�ϵ*/
	while (true)
	{
		if (power < x)
			low = mid;
		if (power == x || high - low == 1)
			return mid;
		if (power > x)
			high = mid;

			mid = (high + low) / 2;
		
			power = mid * mid;
	}
	return mid;

}
#endif

#ifdef method3

int Sqrt(int x)
{
    int mid = x / 2;
    
       if (x == 0)
       	return 0;
       if (x < 4)
       	return 1; 
       /*�����㷨*/
       if ((INT_MAX / mid) < mid)
       {
       	mid = 46340;
       }
       int power = mid * mid;
       
       while (power > x )
       {
       	mid -= 1;
       	power = mid * mid;
       }
       return mid;
#endif 

