#include "BinaryTree.h"

/* Name:	 MaxDepth(TreeNode* root)
*  Function: Calculate the Max Depth of Binary Tree
*  Example:  Input = 3,9,20,null,null,15,7
*			 Output = 3 
*  Return:	 int
*/
int MaxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int left = MaxDepth(root->left);
	int right = MaxDepth(root->right);
	return (left && right) ? 1 + max(left, right) : 1 + left + right;
}