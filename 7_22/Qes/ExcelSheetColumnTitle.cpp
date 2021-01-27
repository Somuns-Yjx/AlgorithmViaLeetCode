#include "ExcelSheetColumnTitle.h"
/*	Name:		string ExcelSheetColumnTitle(int n)
*	Function:	Given an integer, return its corresponding 
*				column name in the Excel table. 
*				If the column cannot be found in the Excel table, return "".
*	Return:		string
*	Example:	1->A 2->B ... 26->Z 27->AA...
*/
string ExcelSheetColumnTitle(int n)
{	
	/*	 Num_To_Str[Nmuber_Lenght_Max] ：输入数字转26进制字符串
	*	Conv_Str[Conv_Lenght_Max]	   ：26进制字符串进一步转换*/	
	int Conv_Str[Conv_Lenght_Max];
	char Neg_Str[Conv_Lenght_Max];
	/*	string Not_Found = "";			未找到对应列 返回""
	*	string Last_Str = "";			最终返回的string	*/
	string Not_Found = "";
	string Last_Str = "";

	uint i = 0;
	uint j = 0;
	uint k = 0;

	if (n == 0)
	{
		return Not_Found;
	}
	while (n > 0)
	{
		int tmp = n % 26;
		n /= 26;
		printf("\n tmp = %d", tmp);
		printf("\n n = %d", n);

		if (tmp == 0) 
		{
			tmp = 26;
			n = n - 1;
			Conv_Str[i] = 26 ;
			printf("\n \n n =  %d", n);
			i++;
		}
		else
		{
			Conv_Str[i] = tmp;
			i++;
		}
		
		j = i;		
		printf("\n\n");
	}

	printf("j = %d", j);

	while (j--)
	{
		printf("\nConv_Str = %d", Conv_Str[k]);
		Neg_Str[k] = (char)Conv_Str[j] + '@';
		printf("\nNegstr = %c", Neg_Str[k]);
		k++;
	}
	Neg_Str[k] = '\0';

	Last_Str = Neg_Str;
	return Last_Str;
}

