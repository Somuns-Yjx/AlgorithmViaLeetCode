#pragma once
#ifndef _Partition_Test_H
#define _Partition_Test_H

#include <stdio.h>
#include <windows.h>

#pragma warning(disable: 4996)
#define Path_Length      50
#define Exp_Index_Length 10       //样例数最大为 10^10
#define Exp_Str_Length   20       //样例名(Example)+索引最大为 10^20 长

#define PartitionInput1_Length_Max   65535
#define PartitionOutput_Length_Max   50

void Partition_Test(void);

#endif