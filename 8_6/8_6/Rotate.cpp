#include "Rotate.h"

/* Name:	 Rotate(vector<int>& nums, int k)
*  Function: Move the elements in the array k positions to the right,
*			 of the given array, k is a non-negative number.		 
*  Example:  Input1 = 1,2,3,4,5,6,7
*			 Input2 = 3
*			 Output = 5,6,7,1,2,3,4
*  Return:	 void
*/
#ifdef Rotate_Method1
	   /*三次逆序*/
void Rotate(vector<int>& nums, int k)
{
	uint n = (uint)nums.size();
	if (n == 0)
		return;
	
	if (n < k)								/*求真正要移的位数*/
		k %= n;									/*123456 789*/
	reverse(nums.begin(), nums.begin() + n - k);/*654321 789*/
	reverse(nums.begin() + n - k, nums.end());	/*654321 987*/
	reverse(nums.begin(), nums.end());			/*789 123456*/

}

#endif 


#ifdef Rotate_Method2
	   /*增，删*/
void Rotate(vector<int>& nums, int k)
{
	uint len1 = nums.size()-1;
	uint len2 = nums.size()-1;
	int tmp = 0;
	while (k--)
	{
		tmp = nums[len2];
			nums.erase(nums.begin()+len2);
			nums.insert(nums.begin(), tmp);

	}



}
#endif

#ifdef Rotate_Method3 
	  /*时间复杂度高*/

void Rotate(vector<int>& nums, int k)
{

	uint i = 0;
	uint j = 0;
	uint len1 = nums.size() - 1;
	uint len2 = nums.size() - 1;
	int tmp = 0;
	while (k--)
	{
		tmp = nums[len2];
		i = len2;
		j = len2 - 1;
		while (len1--)
		{
			nums[i] = nums[j];
			i--;
			j--;
		}
		nums[0] = tmp;
		len1 = len2;

	}


}
#endif