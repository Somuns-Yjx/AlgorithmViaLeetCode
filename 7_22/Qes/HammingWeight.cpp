#include "HammingWeight.h"

/* Name:      int HammingWeight(unsigned int n)
*  Parameter: int n
*  Function:  Count the total number of '1' in a binary array
			  convert from n
*  Return:    uint totalnums
*/
int HammingWeight(unsigned int n)
{
	uint number = n;
	uint StrLen = 0;
	uint totalnums = 0;
	uint i = 0;
	uint tmp = 0;
	while (number)
	{
		tmp = number & 0x01;
		number >>= 1;
		if (tmp == 1)
			totalnums++;

	}
	return totalnums;
}