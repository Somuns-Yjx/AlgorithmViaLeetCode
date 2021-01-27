#include "ContainsNearbyDuplicate.h"

/*	Name:		bool ContainsNearbyDuplicate(vector<int>& nums, int k)
*	Function:	Find if two same numbers between width of key are in an array
*	Return:		bool 
*/
bool ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> umap; // key: 数组元素， value：元素所在下表
	for (uint i = 0; i < nums.size(); i++) 
	{
		if (umap.find(nums[i]) != umap.end()) 
		{ 
			/*找到了在索引i之前就出现过nums[i]这个元素*/
			int distance = i - umap[nums[i]];
			if (distance <= k) 
			{
				return true;
			}
			umap[nums[i]] = i; 
			/*更新元素nums[i]所在的最新位置i*/
		}
		else 
		{ 
			umap[nums[i]] = i;
		}
	}
	return false;	
}
