#pragma once
#ifndef _UNIT_TEST2_H
#define _UNIT_TEST2_H
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>

#define Path_Length      50
#define Array_Length_Max 10000
#define Exp_Index_Length 10       //���������Ϊ 10^10
#define Exp_Str_Length   20       //������(Example)+�������Ϊ 10^20 ��
#define Input_length     10
#define Output_Length    10
#define Expect_Length	 10

#pragma warning(disable: 4996)
void UnitTest2();

#endif