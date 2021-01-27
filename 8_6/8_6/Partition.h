#pragma once
#ifndef _Partition_H
#define _Partition_H
#include <stdio.h>
#include <vector>

#pragma warning(disable: 4996)
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
};
#define uint unsigned int
ListNode* Partition(ListNode* head, int x);

#endif 