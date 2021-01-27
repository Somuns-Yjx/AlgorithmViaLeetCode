#include "IsValid.h"

/* Name:      bool IsValid(string s )
*  Function:  To judge whether a string is valid in someway or not
*  Example:	  [({})] true ; {] false ; 
*  Return:	  Bool
*/
bool IsValid(string s )
{
	stack<char> stack;						
	if ((s.length() % 2) == 1)						/*���űպ���һ��Ϊż���������Ǳպ�*/
	{  
		return false;
	}
	if (s.length() == 0)							 /*��*/
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
		else if (stack.empty() == false)			/*ջ�ǿ�*/
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
		else if (stack.empty() == true)				/*ջ��*/
			return false;
	}
	return stack.empty();
}