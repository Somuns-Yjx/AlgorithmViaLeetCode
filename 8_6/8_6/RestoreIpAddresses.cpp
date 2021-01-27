#include "RestoreIpAddresses.h"

/* Name:	 RestoreIpAddresses(string s)
*  Function: Output all the valid examples for IP address
*  Example:  Input = 25525511135
*			 Output = "255.255.11.135", "255.255.111.35"
*  Return:	 vector<string>
*/
vector<string> RestoreIpAddresses(string s)
{
	vector<string> result;
	string tmp = "";
	Recursion(s, result, tmp, 0);
	return result;
}

/* Name:	 Recursion(string s, vector<string>&result, string tmp, int depth)
*  Function: Recursion the tree to find all the Ip address
*  Parament: string s ; vector<string>&result ; string tmp ; int depth ; 
*
*  Return:	 void
*/
void Recursion(string s, vector<string>&result, string tmp, int depth)
{
	
	if (s.size() > 12 - (3 * depth))
		return;
	if (depth == 4 && s.size() == 0)
	{
		tmp.pop_back();
		result.push_back(tmp);		
	}
	for (int bit = 1; bit <= 3; bit++)
	{
		if (s.size() < bit)
			return;		
		int value = stoi(s.substr(0, bit));				/*判断0-255*/
		if (value > 255 || ( bit != 1 && s[0] == '0'))
			break;	
		tmp += s.substr(0, bit)+'.';				    /*临时string = string[0]--string[bit]+ "." */		
		Recursion(s.substr(bit), result, tmp, depth+1); /*递归*/	
		tmp = tmp.substr(0, tmp.size() - bit - 1);		/*从上一层返回*/

	}
}