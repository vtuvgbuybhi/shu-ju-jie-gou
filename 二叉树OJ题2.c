#define _CRT_SECURE_NO_WARNINGS

//#include<stdlib.h>
//#include<stdio.h>
//#include<assert.h>
//#include<stdbool.h>


//�������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��
//
//������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������


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
























































