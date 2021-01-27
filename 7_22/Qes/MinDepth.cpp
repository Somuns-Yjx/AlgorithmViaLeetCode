#include "BinaryTree.h"

/* Name:	 MinDepth(TreeNode* root)
*  Function: Calculate the Min Depth of Binary Tree
*  Example:  Input = 3,9,20,null,null,15,7
*			 Output = 2
*  Return:	 int
*/
int MinDepth(TreeNode* root)
{
	    if(root == NULL)
        return 0;
		int left = MinDepth(root->left);
		int right = MinDepth(root->right);
        return (left && right) ? 1+ min(left,right):1+left+right;
}
