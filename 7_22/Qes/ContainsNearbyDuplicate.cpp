#include "ContainsNearbyDuplicate.h"

/*	Name:		bool ContainsNearbyDuplicate(vector<int>& nums, int k)
*	Function:	Find if two same numbers between width of key are in an array
*	Return:		bool 
*/
bool ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> umap; // key: ����Ԫ�أ� value��Ԫ�������±�
	for (uint i = 0; i < nums.size(); i++) 
	{
		if (umap.find(nums[i]) != umap.end()) 
		{ 
			/*�ҵ���������i֮ǰ�ͳ��ֹ�nums[i]���Ԫ��*/
			int distance = i - umap[nums[i]];
			if (distance <= k) 
			{
				return true;
			}
			umap[nums[i]] = i; 
			/*����Ԫ��nums[i]���ڵ�����λ��i*/
		}
		else 
		{ 
			umap[nums[i]] = i;
		}
	}
	return false;	
}
