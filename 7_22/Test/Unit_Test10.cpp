#include "stdafx.h"
#include "CppUnitTest.h"

#include  "Unit_Test10.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
void levelOrderCreateBiTree3(TreeNode*& BT, vector<int>& IntVec, vector<int>& IsNullVec)
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
void UnitTest10()
{
	LPTSTR theIniPath = new char[50];        // 定义路径
	strcpy(theIniPath, "../Test_Ini/BinaryTreePaths.ini");
	int theNum = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini 里面的样例个数
	
	for (int index = 1; index <= theNum; index++)	
	{
		// 解析 Example + 编号
		char NumStr[theKeyOfSampleNbrBuffSize];	//编号字符串
		char ExamStr[theSectionOfSampleNameBuffSize] = { theSectionOfSampleName };	// 样例的基础名称
		_itoa(index, NumStr, 10);	// 10代表十进制转换
		strcat(ExamStr, NumStr);	//字符串拼接

		// 解析ExampleX下的Input标识符后面的内容
		LPTSTR StrInput = new char[theKeyOfSampleStr1BuffSize];     //字符串数组
		GetPrivateProfileString(ExamStr, theKeyOfSampleStr1Name, "", StrInput, theKeyOfSampleStr1BuffSize, theIniPath);   //

		LPTSTR Output1 = new char[theKeyOfSampleStr1BuffSize];     //字符串数组
		GetPrivateProfileString(ExamStr, "Output", "", Output1, theKeyOfSampleStr1BuffSize, theIniPath);   //
		//string Output2 = Output1;
		vector <string> Output;

		char *Ptr1 = strtok(Output1, ",");

		while (Ptr1 != NULL)
		{

			Output.push_back(Ptr1);
			Ptr1 = strtok(NULL, ",");
		}

																														// 字符串数组 StrArr1 转换到 int数组 int_arr  
		int ArrLen = 0;
		char *Ptr = strtok(StrInput, ",");
		vector<int> IntVec;		// 二叉树节点存放 vector
		vector<int> IsNullVec;	// 空节点索引存放 vector
		while (Ptr != NULL)
		{
			// 加入判定null
			if (*Ptr == 'n'&&*(Ptr + 1) == 'u'&&*(Ptr + 2) == 'l'&&*(Ptr + 3) == 'l')
			{
				// 是null
				IsNullVec.push_back(ArrLen);	// 当前索引值存入IsNullVec
				IntVec.push_back(atoi(Ptr));	// null也记为0,计入IntVec
			}
			else
			{
				// 非null,转int
				IntVec.push_back(atoi(Ptr));	// char*转int,插入到vector
			}
			ArrLen++;	//统计数组长度
			Ptr = strtok(NULL, ",");
		}

		// 构建二叉树
		TreeNode* BT;
		levelOrderCreateBiTree3(BT, IntVec, IsNullVec);	// 构建的数是BT

		vector<string> result = BinaryTreePaths(BT);	// 计算路径

		bool Final = false;
		if (result == Output)
			Final = true;

	

		delete[] StrInput;
		delete[] Output1;
	}
}