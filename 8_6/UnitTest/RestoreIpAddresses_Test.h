#pragma once
#ifndef _RestoreAddresses_Test_H
#define _RestoreAddresses_Test_H

#include <stdio.h>
#include <windows.h>

#pragma warning(disable: 4996)
#define Path_Length      50
#define Exp_Index_Length 10       //���������Ϊ 10^10
#define Exp_Str_Length   20       //������(Example)+�������Ϊ 10^20 ��

#define RestoreAddressesInput_Length_Max   50
#define RestoreAddressesOutput_Length_Max  50

void RestoreIpAddresses_Test(void);

#endif