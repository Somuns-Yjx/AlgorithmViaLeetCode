#pragma once
#ifndef _UNIT_TEST5_H
#define _UNIT_TEST5_H
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>

#include "../Qes/BinaryTree.h"


#define theSectionOfSampleNbr		"Number"	// 记录样例数量的Section名称
#define theKeyOfSampleNbr			"number"	// 记录样例数量的Key名称
#define theKeyOfSampleNbrBuffSize	   10		// 样例数量的最大位数

#define theSectionOfSampleName		"Example"	// 样例的基础名称
#define theSectionOfSampleNameBuffSize	12		// 样例名称的长度

#define theKeyOfSampleStr1Name		"Input"		// 样例其中一个str参数名称
#define theKeyOfSampleStr1BuffSize	 65535		// 测试样例中读取str最大缓冲长度

#define theKeyOfSampleStr2Name		"Output"	// 样例其中一个str参数名称
#define theKeyOfSampleStr2BuffSize	 65535		// 测试样例中读取str最大缓冲长度

#pragma warning(disable: 4996)
using namespace std;
void UnitTest5();
void UnitTest7();
void UnitTest10();
#endif