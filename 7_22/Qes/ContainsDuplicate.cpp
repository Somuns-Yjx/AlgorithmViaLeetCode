#include "ContainsDuplicate.h"

 /*	Name:		bool ContainsDuplicate(vector<int>& nums)
*	Function:	Find if two same numbers are in an array
*	Return:		bool
*/
bool ContainsDuplicate(vector<int>& nums)
{
	set<int>numss(nums.begin(), nums.end());
	if (nums.size() == numss.size())
		return false;
	else
		return true;	
}

