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
	uint len = (uint)str.length();			      /*��õ��ַ�������*/
	uint str2_len = 0;					      /*ת���ַ�������*/
	long long int result = 0;				  /*-9223372036854775808-9223372036854775807*/
	bool Positive_Flag = false;
	bool Negative_Flag = false;
	bool Num_Flag = false;
	bool End_Flag = false;
	char A2I[100000];					      /*Int �������޽���������ʹ��char��   �ɶ�ȡ100000���ַ�*/
	
	/*��������*/
	while (len--)
	{
		if (str[i] == ' ' && Num_Flag == false && Negative_Flag == false && Positive_Flag == false)					            //�ո� ֻ����������ǰ���Դ��ڶ�������ո�
			i++;					//      +10 2 1 w
		else if (str[i] == '0' && Num_Flag == false)
		{
			i++;
			Num_Flag = true;
		}
		else if (str[i] >= '0' && str[i] <= '9')		/* 0-9 �����������������ֱ�־λ��1*/
		{
			Num_Flag = true;							/*      000000123456789			*/	
			A2I[j] = str[i] - '0';
			i++, j++;
		}
		else if (str[i] == '-' && Negative_Flag == false && Num_Flag == false && Positive_Flag == false)	   //��һ���������ţ���־λ��1 ���ҵڶ�����������
		{											    /* -32-33  */
			Negative_Flag = true;						/* - --32  */
			i++;
		}
		else if (str[i] == '+' && Positive_Flag == false && Num_Flag == false && Negative_Flag == false)	   //��һ���������ţ���־λ��1 ���ҵڶ�����������
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

	/*ת��Ϊ LONG LONG INT��*/
	while (str2_len--)
	{
		result *= 10;
		result = result + A2I[i];
		i++;
		if (result > INT_MAX)
			break;
	}

	printf("\n%llu", result);

	/*����ж�*/
	if ((result > INT_MAX && Negative_Flag == true))	 /*������� ���ֵ ��Ϊ ����*/
	{													 /* ���� INT_MIN */
		return INT_MIN;
	} 
	/*������� ���ֵ */
	if (result > INT_MAX)//|| len > 10)							
	{													 /* ���� INT_MAX  */
		return INT_MAX;
	}
	else if (Negative_Flag == true)
		return -result;
	else
		return result;

}