#pragma once
#ifndef _UNIT_TEST5_H
#define _UNIT_TEST5_H
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>

#include "../Qes/BinaryTree.h"


#define theSectionOfSampleNbr		"Number"	// ��¼����������Section����
#define theKeyOfSampleNbr			"number"	// ��¼����������Key����
#define theKeyOfSampleNbrBuffSize	   10		// �������������λ��

#define theSectionOfSampleName		"Example"	// �����Ļ�������
#define theSectionOfSampleNameBuffSize	12		// �������Ƶĳ���

#define theKeyOfSampleStr1Name		"Input"		// ��������һ��str��������
#define theKeyOfSampleStr1BuffSize	 65535		// ���������ж�ȡstr��󻺳峤��

#define theKeyOfSampleStr2Name		"Output"	// ��������һ��str��������
#define theKeyOfSampleStr2BuffSize	 65535		// ���������ж�ȡstr��󻺳峤��

#pragma warning(disable: 4996)
using namespace std;
void UnitTest5();
void UnitTest7();
void UnitTest10();
#endif