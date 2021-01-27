/*
	[˼·]
	���ݲ�α���[0,0,0,0,0,0,0,null,null,0,null,null,0],����֪��null��������0�ᷢ������,
	���������������2��vector,��һ��vector��IntVec,���ڴ�����еĲ�α����Ľڵ�ֵ,��������null��
	�滻Ϊ0,�ڶ���vector��IsNullVec,�������¼��IntVec��Ϊnull�ڵ���±�ֵ.

	����:    һ�Ŷ�����������ʾ
;                    0                                 
;         ___________|__________         IntVec = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }  
;         |                    |      IsNullVec = { 7, 8, 10, 11 }
;         0                    0           ��˼��:  IntVec��,�±�Ϊ7��8��10��11��ֵΪ0��Ԫ��,
;    _____|______        ______|______             �ڹ���������ʱҪ�����սڵ㴦��
;    |          |        |           |               
;    0          0        0           0            
;  __|__      __|__    __|__       __|__            
;  |   |      |   |    |   |       |   |
;             0            0

	�������Ľ������̽��������������˼��,��Ϊ�������е����ӽڵ���±���� 2 * index + 1,
	���ӽڵ���±���� 2 * index + 2,���Կ�����������������ص�,������ǰ�ڵ��,�Ƚ�����
	����,�ٽ���������,������Ȼ��ʹ�õ��ݹ麯��,�ݹ�ֹͣ������Ϊ��ǰ�ڵ�Ϊ�սڵ�.

*/

#include <stdlib.h>

#include "DefBiTree.h"

// ��ν���һ�������� 
void levelOrderCreateBiTree(TreeNode*& BT, vector<int>& IntVec, vector<int>& IsNullVec)
{
	if (IntVec.size() == 0)		// �Ƿ��ǿ���
	{
		BT = nullptr;	// �ǿ���ֱ�ӷ���
		return;
	}

	// ������ǿ�����ʼ����
	queue  <TreeNode*> TreeQueue;	// ������ڵ�Ķ���
	TreeNode *rootbt, *bt, *tmpbt;
	int IntVec_index = 0;	// ����ԭ������±�
	int IsNullVec_Index = 0;	// ƥ���Ƿ�Ϊnull���±�
	bool IsNullVec_Index_is_notEnd = true;		// �Ƿ��Ѿ���IsNullVec������,trueΪ��û������
	rootbt = (TreeNode*)malloc(sizeof(TreeNode));
	rootbt->val = IntVec[IntVec_index++];	// ���ڵ���ֵ
	rootbt->left = nullptr;
	rootbt->right = nullptr;
	TreeQueue.push(rootbt);	// ���ڵ����
	while (!TreeQueue.empty())	// �Ӳ���ѭ��
	{
		// ���IntVec��������,�Ͳ���Ҫ�ٽ�����Ӳ�����,ֱ���˳���������,���ؼ���
		if (IntVec_index >= (int)IntVec.size())
			break;

		tmpbt = TreeQueue.front();	// ȡ���׵�Ԫ��(������ӵ�Ԫ��)
		TreeQueue.pop();	// ����

		/* ---- ������ڵ� ---- */
		if (IsNullVec_Index_is_notEnd && (IntVec[IntVec_index] == 0) && (IntVec_index == IsNullVec[IsNullVec_Index]))
		{
			// ����ڼ�¼null���������и��±������,��ýڵ���null�ڵ�
			IsNullVec_Index++;
			if (IsNullVec_Index >= (int)IsNullVec.size())	// ���null�����Ѿ���������
				IsNullVec_Index_is_notEnd = false;		// ����Ͳ���Ҫ�ٲ���null������
		}
		else	// ����Ƿ�null�ڵ�
		{
			bt = (TreeNode*)malloc(sizeof(TreeNode));
			bt->val = IntVec[IntVec_index];
			bt->left = nullptr;
			bt->right = nullptr;
			// ������һ���ڵ�
			tmpbt->left = bt;
			// ��Ч�ڵ����,�������Ӻ���Ľڵ�
			TreeQueue.push(bt);
		}
		IntVec_index++;	// �±��һ

		/* ---- �����ҽڵ� ---- */
		if (IsNullVec_Index_is_notEnd && (IntVec[IntVec_index] == 0) && (IntVec_index == IsNullVec[IsNullVec_Index]))
		{
			// ����ڼ�¼null���������и��±������,��ýڵ���null�ڵ�
			IsNullVec_Index++;
			if (IsNullVec_Index >= (int)IsNullVec.size())	// ���null�����Ѿ���������
				IsNullVec_Index_is_notEnd = false;		// ����Ͳ���Ҫ�ٲ���null������
		}
		else	// ����Ƿ�null�ڵ�
		{
			bt = (TreeNode*)malloc(sizeof(TreeNode));
			bt->val = IntVec[IntVec_index];
			bt->left = nullptr;
			bt->right = nullptr;
			// ������һ���ڵ�
			tmpbt->right = bt;
			// ��Ч�ڵ����,�������Ӻ���Ľڵ�
			TreeQueue.push(bt);
		}
		IntVec_index++;	// �±��һ
	}
	BT = rootbt;	// ��󷵻ؽ����õĶ�����
}


//�������
void preOrder(TreeNode*& BT)
{
	if (BT != NULL) {				//�жϲ�Ϊ�� 
		printf("%d ", BT->val);		//���ʸ��ڵ�
		preOrder(BT->left);			//�ݹ飬������������� 
		preOrder(BT->right);		//�ݹ飬������������� 
	}
}

//�������
void inOrder(TreeNode*& BT)
{
	if (BT != NULL) {
		inOrder(BT->left);
		printf("%d ", BT->val);
		inOrder(BT->right);
	}
}

//�������
void postOrder(TreeNode*& BT)
{
	if (BT != NULL) {
		postOrder(BT->left);
		postOrder(BT->right);
		printf("%d ", BT->val);
	}
}
