#include "SingleNumber.h"

/* Name:	 SingleNumber(vector<int>& nums)
*  Function: Find the number which appears once
*  Example:	 Input: 1,1,2          Output: 2  
*  Return:	 int
*/
int SingleNumber(vector<int>& nums)
{
	uint vec_len = (uint)nums.size();
	uint i = 0;
	sort(nums.begin(), nums.end());
	
	
	do
	{	if (vec_len == 1)
			return nums[i];
		if (nums[i] == nums[i + 1])
			i+=2;
		else
			return nums[i];
		
	} while (vec_len -= 2);

	return 0;

}