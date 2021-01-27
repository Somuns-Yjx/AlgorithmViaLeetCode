#include "WordPattern.h"

/* Name:	 WordPattern(string pattern, string str)
*  Function: Judge whether the pattern and str is in 
*			 the correct relationship or not
*  Example:	 Pattern = "abba"		  	 Pattern = "abba"
*            Str = "dog cat cat dog"	 Str = "dog cat cat fish"
*            Output = true	 		  	 Output = false            
*  Return:	 int
*/
bool WordPattern(string pattern, string str)
{
	uint pat_len = (uint)pattern.length();
	uint str_len = (uint)str.length();
	uint map_len = 0;
	uint i = 0;
	uint j = 0;
	char pattern1[10000];
	char convstr[10000];
	int temp = 0;
	vector<string> convertstr; 

	strcpy(pattern1, pattern.c_str());
	strcpy(convstr, str.c_str());
	convstr[str_len] = '\0';

	char *p = strtok(convstr, " "); 

	while (p != NULL)
	{

		convertstr.push_back(p);        
		map_len++;						
		p = strtok(NULL, " ");
	}

	map<char,int> map_pat;
	map<string,uint> map_str;

	while (map_len--)
	{
		if (map_pat.find(pattern1[j]) == map_pat.end())
		{
			if (map_str.find(convertstr[j]) == map_str.end())
			{
				map_pat.insert(pair<char, int>(pattern1[j], j));
				map_str.insert(pair<string, uint>(convertstr[j], j));
				j++;
			}
			else
				return false;

		}
		else
		{	/*得到map中已存该key下标*/
			temp = map_pat.at(pattern1[j]);
			/*判断该下标对应map_str*/
			if (convertstr[j] == convertstr[temp])
				j++;
			else	
				return false;
		}
	}
	if (j == pat_len)
		return true;
	else
		return false;
}