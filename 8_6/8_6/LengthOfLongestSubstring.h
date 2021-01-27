#pragma once
#ifndef _LengthOfLongestSubstring_H
#define _LengthOfLongestSubstring_H


#include <unordered_set>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>

using namespace std;

#define LengthOfLongestSubstringMethod1
//#define LengthOfLongestSubstringMethod2
//#pragma warning(disable:4018)

#define uint unsigned int


int LengthOfLongestSubstring(string s);

#ifdef LengthOfLongestSubstringMethod2
int LengthOfLongestSubstring(char * s);
#endif 



#endif 