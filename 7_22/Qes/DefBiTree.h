#ifndef __DEFBITREE_H
#define __DEFBITREE_H

#include <vector>
#include <queue>
using namespace std;

// 二叉树节点定义
typedef struct treeNode
{
	int val;
	struct treeNode  *left, *right;
} TreeNode;


// 二叉树的基本操作函数
void levelOrderCreateBiTree(TreeNode*& BT, vector<int>& IntVec, vector<int>& IsNullVec);	//创建二叉树 
void preOrder(TreeNode*& BT);	// 先序遍历
void inOrder(TreeNode*& BT);	// 中序遍历
void postOrder(TreeNode*& BT);	// 后序遍历



#endif 