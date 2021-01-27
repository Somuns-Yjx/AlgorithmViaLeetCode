#include "ReverseBits.h"

/* Name:	 unsigned int ReverseBits(unsigned int n)
*  Function: Reverse the binary bits of a given 32-bit unsigned integer
*  Example:  Input = 43261596
*			 Output = 964176192
*  Return:	 unit
*/

unsigned int ReverseBits(unsigned int n)
{
	uint number = n;
	uint result = 0;
	uint temp = 0;
	uint times = 32;
	while (times--)
	{
		temp = number & 0x01;
		number >>= 1;
		result <<= 1;
		result = result + temp;
	
	}
	return result;

}