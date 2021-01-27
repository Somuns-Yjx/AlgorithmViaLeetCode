#include "./LengthOfLongestSubstring.h"
/* Name:	 LengthOfLongestSubstring(string s)
*  Function: Find out the the longest length of substring 
*		     that does not contain repeated characters of
*			 the given string
*  Example:  Input = abcabcbb
*			 Output = 3;
*  Return:	 int
*/
#ifdef LengthOfLongestSubstringMethod1
/*************** Map *****************/
	/*	abcdebfgh
	*	abcde
	*	  cdbfghs
	*/
int LengthOfLongestSubstring(string s)
{

	unordered_map<char, int> map;
	uint maxlen = 0;
	uint len = (uint)s.size();
	uint In_index = 0;
	uint Out_index = 0;
	uint temp_index = 0;
	uint tmplen = 0;
	while (maxlen < len - Out_index)
	{
		for (In_index = Out_index; In_index < len; In_index++)
		{	
			if (map.find(s[In_index]) == map.end())				/*未找到*/

			map.insert(pair<char, int>(s[In_index], temp_index));
		
			else												/*找到*/
			{
				Out_index = Out_index + map.at(s[In_index]) + 1;
				map.clear();
				break;
			}
			tmplen++;
			temp_index++;
		}
																
		if (tmplen > maxlen)			/*判断最大长度*/
			maxlen = tmplen;

		tmplen = 0;
		temp_index = 0;

	}
	return maxlen;
}
#endif

#ifdef LengthOfLongestSubstringMethod2
/**************** C ****************/

int LengthOfLongestSubstring(char * s)
{
	int start = 0, end = 0, maxlen = 0;
	char map[256] = { 0 };

	int x = (int)*(s + start);

	map[(int)*(s + start)] = 1;

	while (*(s + end) != 0)
	{
		maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
		++end;
		while (0 != map[(int)*(s + end)])		/*将要加入的新元素与map内元素冲突*/
		{
			map[(int)*(s + start)] = 0;
			++start;
		}
		map[(int)*(s + end)] = 1;
	}

	return maxlen;
}
#endif


#ifdef LengthOfLongestSubstringMethod3
/**************** Set *****************/
int LengthOfLongestSubstring(string s)
{	/* abcdebghi
	*  abcde
	*   bcde
	*    cdebghi
	*/
	unordered_set<char> set1;
	uint maxlen = 0;
	uint len = s.size();
	uint In_index = 0;
	uint Out_index = 0;
	uint tmplen = 0;
	for (; maxlen < len - Out_index; Out_index++)
	{
		for (In_index = Out_index; In_index < len; In_index++)			/*未找到*/
		{	
			if (set1.find(s[In_index]) == set1.end())
				set1.insert(s[In_index]);
			
			else			/*找到*/
			{
				set1.clear();
				break;
			}
			tmplen++;
		}
		/*判断最大长度*/
		if (tmplen > maxlen)
			maxlen = tmplen;

		tmplen = 0;
	}
	return maxlen;
}

#endif 