#pragma once
#ifndef _UNIT_TEST1_H
#define _UNIT_TEST1_H

#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>

#pragma warning(disable: 4996)
#define Path_Length      50
#define Array_Length_Max 10000
#define Exp_Index_Length 10       //样例数最大为 10^10
#define Exp_Str_Length   20       //样例名(Example)+索引最大为 10^20 长
#define Output_Length    10

void UnitTest1();

#endif