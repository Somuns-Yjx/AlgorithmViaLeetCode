#pragma once
#ifndef _WordBreak_Test_H
#define _WordBreak_Test_H

#include <stdio.h>
#include <windows.h>

#pragma warning(disable: 4996)
#define Path_Length      50
#define Exp_Index_Length 10       //样例数最大为 10^10
#define Exp_Str_Length   20       //样例名(Example)+索引最大为 10^20 长

#define Input1_len		 1000
#define Input2_len		 5000
#define WBOut_len		 10


void WordBreak_Test(void);

#endif