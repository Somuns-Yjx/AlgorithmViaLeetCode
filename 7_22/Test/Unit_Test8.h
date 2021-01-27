#pragma once
#ifndef _UNIT_TEST8_H
#define _UNIT_TEST8_H
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>


#define Path_Length      50
#define Exp_Index_Length 10       //样例数最大为 10^10
#define Exp_Str_Length   20       //样例名(Example)+索引最大为 10^20 长
//#define Unit8_Input_length     11
#define Unit8_Output_Length    3
//#define Unit8_Expect_Length	 3

#pragma warning(disable: 4996)

void UnitTest8();

#endif