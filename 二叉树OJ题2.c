#define _CRT_SECURE_NO_WARNINGS

//#include<stdlib.h>
//#include<stdio.h>
//#include<assert.h>
//#include<stdbool.h>


//给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
//
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。


//struct TreeNode
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//bool _isSameTree(struct TreeNode* root1, struct TreeNode* root2)
//{
//	if (root1 == NULL && root2 == NULL)
//	{
//		return true;
//	}
//	if (root1 == NULL || root2 == NULL)
//	{
//		return false;
//	}
//	if (root1->val != root2->val)
//	{
//		return false;
//	}
//	return _isSameTree(root1->left, root2->left) && _isSameTree(root1->right, root2->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//	if (root == NULL)
//	{
//		return false;7
//	}
//	if (_isSameTree(root, subRoot))
//		return true;
//
//	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}
























































