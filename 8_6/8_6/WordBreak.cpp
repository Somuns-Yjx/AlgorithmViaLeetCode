#include "WordBreak.h"
bool WordBreak(string s, vector<string>& wordDict)
{
	set<string> st(wordDict.begin(), wordDict.end());
	int lenStr = (int)s.length();
	vector<bool> dp(lenStr + 5, false);
	dp[0] = true;
	for (int i = 1; i <= lenStr; i++)
	{
		for (int j = i; j >= 0; j--) 
		{	
			/* 从j下标开始取i-j个字符 */
			string lst = s.substr(j, i - j); 
			if (st.find(lst) != st.end() && dp[j] == true)
			{
				dp[i] = true;  
				break;
			}
		}
	}
	return dp[lenStr];
}