#pragma once
#ifndef _UNIT_TEST9_H
#define _UNIT_TEST9_H
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>


#define Path_Length      50
#define Exp_Index_Length 10       //样例数最大为 10^10
#define Exp_Str_Length   20       //样例名(Example)+索引最大为 10^20 长
#define Unit9_Input_Len			 10000
#define Unit9_Output_Len		 10000


#pragma warning(disable: 4996)

void UnitTest9();

#endif