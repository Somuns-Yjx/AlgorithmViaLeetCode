#include "stdafx.h"
#include "CppUnitTest.h"

/*---5---*/
#include "../Qes/DefBiTree.h"	// ������ͷ�ļ�
#include "Unit_Test5.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
void levelOrderCreateBiTree1(TreeNode*& BT, vector<int>& IntVec, vector<int>& IsNullVec)
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
void UnitTest5()
{
	// ��ȡ��Ҫ�ܵĴ���,ȷ��ѭ������
	LPTSTR theIniPath = new char[50];        // ����·��
	strcpy(theIniPath, "../Test_Ini/MinDepth.ini");
	int theNum = GetPrivateProfileInt("Number", "number", 0, theIniPath);  // ini �������������

	for (int index = 1; index <= theNum; index++)
	{
		// ���� Example + ���
		char NumStr[theKeyOfSampleNbrBuffSize];	//����ַ���
		char ExamStr[theSectionOfSampleNameBuffSize] = { theSectionOfSampleName };	// �����Ļ�������

		_itoa(index, NumStr, 10);	// 10����ʮ����ת��
		strcat(ExamStr, NumStr);	//�ַ���ƴ��
		int Output = GetPrivateProfileInt(ExamStr, "Output", 0, theIniPath);
		// ����ExampleX�µ�Input��ʶ�����������
		LPTSTR StrInput = new char[theKeyOfSampleStr1BuffSize];     //�ַ�������
		GetPrivateProfileString(ExamStr, theKeyOfSampleStr1Name, "", StrInput, theKeyOfSampleStr1BuffSize, theIniPath);   //

		// �ַ������� StrArr1 ת���� int���� int_arr  
		int ArrLen = 0;
		char *Ptr = strtok(StrInput, ",");
		vector<int> IntVec;		// �������ڵ��� vector
		vector<int> IsNullVec;	// �սڵ�������� vector
		while (Ptr != NULL)
		{
			// �����ж�null
			if (*Ptr == 'n'&&*(Ptr + 1) == 'u'&&*(Ptr + 2) == 'l'&&*(Ptr + 3) == 'l')
			{
				// ��null
				IsNullVec.push_back(ArrLen);	// ��ǰ����ֵ����IsNullVec
				IntVec.push_back(atoi(Ptr));	// nullҲ��Ϊ0,����IntVec
			}
			else
			{
				// ��null,תint
				IntVec.push_back(atoi(Ptr));	// char*תint,���뵽vector
			}
			ArrLen++;	//ͳ�����鳤��
			Ptr = strtok(NULL, ",");
		}


		// ����������
		TreeNode* BT;
		levelOrderCreateBiTree1(BT, IntVec, IsNullVec);	// ����������BT

		int result = MinDepth(BT);

		bool Final = false;
		if (result == Output)
			Final = true;

		Assert::IsTrue(Final);

		delete[] StrInput;
	}
}
