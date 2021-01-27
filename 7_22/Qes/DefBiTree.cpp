/*
	[思路]
	根据层次遍历[0,0,0,0,0,0,0,null,null,0,null,null,0],我们知道null和真正的0会发生混淆,
	解决方法就是设置2个vector,第一个vector叫IntVec,用于存放所有的层次遍历的节点值,并且其中null被
	替换为0,第二个vector叫IsNullVec,这里面记录了IntVec中为null节点的下标值.

	举例:    一颗二叉树如下所示
;                    0                                 
;         ___________|__________         IntVec = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }  
;         |                    |      IsNullVec = { 7, 8, 10, 11 }
;         0                    0           意思是:  IntVec中,下标为7、8、10、11的值为0的元素,
;    _____|______        ______|______             在构建二叉树时要当作空节点处理。
;    |          |        |           |               
;    0          0        0           0            
;  __|__      __|__    __|__       __|__            
;  |   |      |   |    |   |       |   |
;             0            0

	二叉树的建立过程借用了先序遍历的思想,因为二叉树中的左子节点的下标符合 2 * index + 1,
	右子节点的下标符合 2 * index + 2,所以可以利用先序遍历的特点,建立当前节点后,先建立左
	子树,再建立右子树,理所当然就使用到递归函数,递归停止的条件为当前节点为空节点.

*/

#include <stdlib.h>

#include "DefBiTree.h"

// 层次建立一个二叉树 
void levelOrderCreateBiTree(TreeNode*& BT, vector<int>& IntVec, vector<int>& IsNullVec)
{
	if (IntVec.size() == 0)		// 是否是空树
	{
		BT = nullptr;	// 是空树直接返回
		return;
	}

	// 如果不是空树则开始建树
	queue  <TreeNode*> TreeQueue;	// 存放树节点的队列
	TreeNode *rootbt, *bt, *tmpbt;
	int IntVec_index = 0;	// 遍历原数组的下标
	int IsNullVec_Index = 0;	// 匹配是否为null的下标
	bool IsNullVec_Index_is_notEnd = true;		// 是否已经将IsNullVec遍历完,true为还没遍历完
	rootbt = (TreeNode*)malloc(sizeof(TreeNode));
	rootbt->val = IntVec[IntVec_index++];	// 根节点数值
	rootbt->left = nullptr;
	rootbt->right = nullptr;
	TreeQueue.push(rootbt);	// 根节点入队
	while (!TreeQueue.empty())	// 队不空循环
	{
		// 如果IntVec遍历完了,就不需要再进行入队操作了,直接退出建树程序,返回即可
		if (IntVec_index >= (int)IntVec.size())
			break;

		tmpbt = TreeQueue.front();	// 取队首的元素(最先入队的元素)
		TreeQueue.pop();	// 出队

		/* ---- 操作左节点 ---- */
		if (IsNullVec_Index_is_notEnd && (IntVec[IntVec_index] == 0) && (IntVec_index == IsNullVec[IsNullVec_Index]))
		{
			// 如果在记录null的数组中有该下标的索引,则该节点是null节点
			IsNullVec_Index++;
			if (IsNullVec_Index >= (int)IsNullVec.size())	// 如果null数组已经索引完了
				IsNullVec_Index_is_notEnd = false;		// 后面就不需要再查找null数组了
		}
		else	// 如果是非null节点
		{
			bt = (TreeNode*)malloc(sizeof(TreeNode));
			bt->val = IntVec[IntVec_index];
			bt->left = nullptr;
			bt->right = nullptr;
			// 接上上一个节点
			tmpbt->left = bt;
			// 有效节点入队,用于链接后面的节点
			TreeQueue.push(bt);
		}
		IntVec_index++;	// 下标加一

		/* ---- 操作右节点 ---- */
		if (IsNullVec_Index_is_notEnd && (IntVec[IntVec_index] == 0) && (IntVec_index == IsNullVec[IsNullVec_Index]))
		{
			// 如果在记录null的数组中有该下标的索引,则该节点是null节点
			IsNullVec_Index++;
			if (IsNullVec_Index >= (int)IsNullVec.size())	// 如果null数组已经索引完了
				IsNullVec_Index_is_notEnd = false;		// 后面就不需要再查找null数组了
		}
		else	// 如果是非null节点
		{
			bt = (TreeNode*)malloc(sizeof(TreeNode));
			bt->val = IntVec[IntVec_index];
			bt->left = nullptr;
			bt->right = nullptr;
			// 接上上一个节点
			tmpbt->right = bt;
			// 有效节点入队,用于链接后面的节点
			TreeQueue.push(bt);
		}
		IntVec_index++;	// 下标加一
	}
	BT = rootbt;	// 最后返回建立好的二叉树
}


//先序遍历
void preOrder(TreeNode*& BT)
{
	if (BT != NULL) {				//判断不为空 
		printf("%d ", BT->val);		//访问根节点
		preOrder(BT->left);			//递归，先序遍历左子树 
		preOrder(BT->right);		//递归，先序遍历右子树 
	}
}

//中序遍历
void inOrder(TreeNode*& BT)
{
	if (BT != NULL) {
		inOrder(BT->left);
		printf("%d ", BT->val);
		inOrder(BT->right);
	}
}

//后序遍历
void postOrder(TreeNode*& BT)
{
	if (BT != NULL) {
		postOrder(BT->left);
		postOrder(BT->right);
		printf("%d ", BT->val);
	}
}
