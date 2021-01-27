#ifndef __DEFBITREE_H
#define __DEFBITREE_H

#include <vector>
#include <queue>
using namespace std;

// �������ڵ㶨��
typedef struct treeNode
{
	int val;
	struct treeNode  *left, *right;
} TreeNode;


// �������Ļ�����������
void levelOrderCreateBiTree(TreeNode*& BT, vector<int>& IntVec, vector<int>& IsNullVec);	//���������� 
void preOrder(TreeNode*& BT);	// �������
void inOrder(TreeNode*& BT);	// �������
void postOrder(TreeNode*& BT);	// �������



#endif 