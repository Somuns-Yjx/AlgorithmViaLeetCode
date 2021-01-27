#include "AddBinary.h"

/* Name:     string AddBinary(string a , string  b)
*  Function: Calculate the sum of two strings and output it
*            of binary
*  Return:   string addstr
*/
string AddBinary(string a, string b)
{
	int i = (int)a.size() - 1;
	int j = (int)b.size() - 1;
	uint CY = 0;
	string addstr = "";
	while (i >= 0 || j >= 0 || CY)
	{
		int res = CY;
		if (i >= 0)
		{
			res += (a[i] - '0');
			i--;
		}
		if (j >= 0)
		{
			res += (b[j] - '0');
			j--;
		}
		CY = res / 2;
		addstr.push_back('0' + res % 2);
	}
	reverse(addstr.begin(), addstr.end());


	return addstr;
}