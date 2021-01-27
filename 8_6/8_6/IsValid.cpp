#include "IsValid.h"

/* Name:      bool IsValid(string s )
*  Function:  To judge whether a string is valid in someway or not
*  Example:	  [({})] true ; {] false ; 
*  Return:	  Bool
*/
bool IsValid(string s )
{
	stack<char> stack;						
	if ((s.length() % 2) == 1)						/*括号闭合则一定为偶数，奇数非闭合*/
	{  
		return false;
	}
	if (s.length() == 0)							 /*空*/
	{ 
		return true;
	}	
	for (char&c : s)								 /* & */
	{
		if ((c == '(') || (c == '{') || (c == '['))
		{
			switch (c)
			{
			case '{': stack.push('}'); break;
			case '[': stack.push(']'); break;
			case '(': stack.push(')'); break;
			default:
				break;
			}
		}	
		else if (stack.empty() == false)			/*栈非空*/
		{
		
			if (stack.top() == c)
			{
				stack.pop();
			}
			else 
			{
				return false;
			}
		}
		else if (stack.empty() == true)				/*栈空*/
			return false;
	}
	return stack.empty();
}