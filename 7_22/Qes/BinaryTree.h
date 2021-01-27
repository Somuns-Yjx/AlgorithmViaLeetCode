#pragma once
#ifndef _BinaryTree_H
#define _BinaryTree_H
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include "DefBiTree.h"
using namespace std;

/*struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};*/

int MinDepth(TreeNode* root);
int MaxDepth(TreeNode* root);

void Link(TreeNode* root, vector<string>& vec, string str);
vector<string> BinaryTreePaths(TreeNode* root);


#endif