#include "MyAtoi.h"

// sscanf(ch,"%[1-9]",num); 

/* Name:      int myAtoi(string str)
*  Function:  To make a function used like atoi
*  Example:	  " -42": -42  ;  "--32":0
*  Return:	  int
*/
int myAtoi(string str)
{
	//char A2I[];
	uint i = 0;
	uint j = 0;
	uint len = (uint)str.length();			      /*获得的字符串长度*/
	uint str2_len = 0;					      /*转换字符串长度*/
	long long int result = 0;				  /*-9223372036854775808-9223372036854775807*/
	bool Positive_Flag = false;
	bool Negative_Flag = false;
	bool Num_Flag = false;
	bool End_Flag = false;
	char A2I[100000];					      /*Int 型数组无结束符，故使用char型   可读取100000个字符*/
	
	/*解析数据*/
	while (len--)
	{
		if (str[i] == ' ' && Num_Flag == false && Negative_Flag == false && Positive_Flag == false)					            //空格 只有遇到数字前可以存在多个连续空格
			i++;					//      +10 2 1 w
		else if (str[i] == '0' && Num_Flag == false)
		{
			i++;
			Num_Flag = true;
		}
		else if (str[i] >= '0' && str[i] <= '9')		/* 0-9 出现数字立即将数字标志位置1*/
		{
			Num_Flag = true;							/*      000000123456789			*/	
			A2I[j] = str[i] - '0';
			i++, j++;
		}
		else if (str[i] == '-' && Negative_Flag == false && Num_Flag == false && Positive_Flag == false)	   //第一次遇到负号，标志位置1 ，且第二次遇到结束
		{											    /* -32-33  */
			Negative_Flag = true;						/* - --32  */
			i++;
		}
		else if (str[i] == '+' && Positive_Flag == false && Num_Flag == false && Negative_Flag == false)	   //第一次遇到正号，标志位置1 ，且第二次遇到结束
		{											    /* ++21519 w */
			Positive_Flag = true;
			i++;
		}
		else
			break;
	}

	str2_len = j;
	len = j;
	i = 0, j = 0;

	A2I[str2_len] = '\0';

	printf("%d", str2_len);

	/*转换为 LONG LONG INT型*/
	while (str2_len--)
	{
		result *= 10;
		result = result + A2I[i];
		i++;
		if (result > INT_MAX)
			break;
	}

	printf("\n%llu", result);

	/*输出判断*/
	if ((result > INT_MAX && Negative_Flag == true))	 /*输入大于 最大值 且为 负数*/
	{													 /* 返回 INT_MIN */
		return INT_MIN;
	} 
	/*输入大于 最大值 */
	if (result > INT_MAX)//|| len > 10)							
	{													 /* 返回 INT_MAX  */
		return INT_MAX;
	}
	else if (Negative_Flag == true)
		return -result;
	else
		return result;

}