#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>


//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。

//struct TreeNode 
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};

//方法1
//bool isUnivalTree(struct TreeNode* root) 
//{
//	if (root == NULL)
//	{
//		return true;
//	}
//	if (root->left && root->left->val != root->val)
//	{
//		return false;
//	}
//	if (root->right && root->right->val != root->val)
//	{
//		return false;
//	}
//	return isUnivalTree(root->left) && isUnivalTree(root->right);
//}
//
//
////方法2
//
//
//int PreOrder(struct TreeNode* root, int val)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	if (val != root->val)
//	{
//		return 1;
//	}
//	return PreOrder(root->left, val) + PreOrder(root->right, val);
//}
//
//bool isUnivalTree(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return true;
//	}
//	int tmp = PreOrder(root, root->val);
//	if (tmp == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}




//给你二叉树的根节点 root ，返回它节点值的 前序 遍历

//struct TreeNode 
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//int TreeSize(struct TreeNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void _preorderTraversal(struct TreeNode* root, int* a, int* pi)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	a[(*pi)++] = root->val;
//	_preorderTraversal(root->left, a, pi);
//	_preorderTraversal(root->right, a, pi);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) 
//{
//	int size = TreeSize(root);
//	int* a = (int*)malloc(sizeof(int) * size);
//	int i = 0;
//	_preorderTraversal(root, a, &i);
//	*returnSize = size;
//	return a;
//}



//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。


//struct TreeNode 
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};

//int TreeSize(struct TreeNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
//{
//	//都为空
//	if (p == NULL && q == NULL)
//	{
//		return true;
//	}
//	//其中一个为空
//	if (p == NULL || q == NULL)
//	{
//		return false;
//	}
//	//都不为空
//	if (p->val != q->val)
//	{
//		return false;
//	}
//	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}



//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//
//例如，二叉树 [1, 2, 2, 3, 4, 4, 3] 是对称的。
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3

//struct TreeNode
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//bool _isSymmetricTree(struct TreeNode* root1, struct TreeNode* root2)
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
//	return _isSymmetricTree(root1->left, root2->right) && _isSymmetricTree(root1->right, root2->left);
//}
//
//bool isSymmetric(struct TreeNode* root) 
//{
//	if (root == NULL)
//	{
//		return true;
//	}
//	return _isSymmetricTree(root->left, root->right);
//}











































