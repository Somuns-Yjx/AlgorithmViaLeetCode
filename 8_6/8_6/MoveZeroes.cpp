#include "MoveZeroes.h"
//#define Mz_Mthd1
#define Mz_Mthd2
/* Name:      MoveZeroes(vector<int>& nums)
*  Function:  Move all the number "0" to the end of vector
*  Example:	  Input = 0,1,0,3,12
*			  Output = 1,3,12,0,0
*  Return:	  void
*/
#ifdef Mz_Mthd1  /*实际操作次数多*/

void MoveZeroes(vector<int>& nums)
{
	uint len1 = nums.size();
	uint len2 = 0;
	/*删除所有0*/
	/*
	* vector中的remove的作用是将等于value的元素放到vector的尾部，
	* 但并不减少vector的size。若要真正移除，需要搭配使用erase()。
	*/
	nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());  
	
	len2 = nums.size();

	while (len1 - len2 )
	{
		nums.push_back(0);
		len1--;
	}
	

}
#endif

#ifdef Mz_Mthd2  /*遍历一次*/

void MoveZeroes(vector<int>& nums)
{
		uint len = (uint)nums.size();
		uint i = 0;
		uint j = 0;
		while (len--)//{ 0,1,0,3,12 };
		{
			if (nums[i] == 0)
			{
				i++;
			}
			else
			{
				nums[j] = nums[i];
				i++;
				j++;
			}
		}
		while (i - j)
		{
			nums[j] = 0;
			j++;
		}
}


#endif 
