#include "BinaryTree.h"

void Link(TreeNode* root, vector<string>& vec, string str)
{
	if (!root)
		return;
	if (!root->left && !root->right)
		vec.push_back(str + to_string(root->val));
	if (root->left)
		Link(root->left, vec, str + to_string(root->val) + "->");
	if (root->right)
		Link(root->right, vec, str + to_string(root->val) + "->");
}

/* Name:	 BinaryTreePaths(TreeNode* root)
*  Function: Output all the valid BinaryTreePaths
*  Example:  Input = 1,2,3,null,5
*			 Output = "1->2->5", "1->3"
*  Return:	 vector<string>
*/
vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> vec;
	string path;
	Link(root, vec, "");
	return vec;
}

