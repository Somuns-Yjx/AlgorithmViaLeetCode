#pragma once
#ifndef _RestoreAddresses_H
#define _RestoreAddresses_H
#include <string>
#include <vector>
using namespace std;
#define RestoreAddressesMethod1
#pragma warning(disable:4018)
#define uint unsigned int



vector<string> RestoreIpAddresses(string s);
void Recursion(string s, vector<string>&result, string tmp, int depth);

#endif 