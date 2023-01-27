#define _CRT_SECURE_NO_WARNINGS

//#include<stdlib.h>
//#include<stdio.h>
//#include<assert.h>
//
//
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//}BTNode;
//
////����һ����
//BTNode* BuyNode(BTDataType x)
//{
//	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	tmp->data = x;
//	tmp->left = tmp->right = NULL;
//	return tmp;
//}
//
//BTNode*CreatBinaryTree()
//{
//	BTNode* nodeA = BuyNode('A');
//	BTNode* nodeB = BuyNode('B');
//	BTNode* nodeC = BuyNode('C');
//	BTNode* nodeD = BuyNode('D');
//	BTNode* nodeE = BuyNode('E');
//	BTNode* nodeF = BuyNode('F');
//
//	nodeA->left = nodeB;
//	nodeA->right = nodeC;
//	nodeB->left = nodeD;
//	nodeC->left = nodeE;
//	nodeC->right = nodeF;
//
//	return nodeA;
//
//}
//
////ǰ�����������
//
//void PreOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	printf("%c ", root->data);
//	PreOrder(root->left);
//	PreOrder(root->right);
//}
//
////�������
//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	InOrder(root->left);
//	printf("%c ", root->data);
//	InOrder(root->right);
//}
//
////�������
//void PostOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%c ", root->data);
//}
//
////��ڵ����
//int BinaryTreeSize(BTNode* root)
//{
//	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
//}
//
////��Ҷ�ӽڵ����
//int BinaryTreelevelSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	return root->left == NULL && root->right == NULL ? 1 : BinaryTreelevelSize(root->left) + BinaryTreelevelSize(root->right);
//}
//
////���K��ڵ����
//int BinaryTreeKSize(BTNode* root,int k)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	if (k == 1)
//	{
//		return 1;
//	}
//	return BinaryTreeKSize(root->left,k-1) + BinaryTreeKSize(root->right,k-1);
//}
//
////���������
//int BinaryTreeDepth(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int leftheigh = BinaryTreeDepth(root->left);
//	int rightheigh = BinaryTreeDepth(root->right);
//	return leftheigh > rightheigh ? leftheigh + 1 : rightheigh + 1;
//}
//
////����������ֵΪx�Ľڵ�
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	BTNode* leftFind = NULL;
//	BTNode* rightFind = NULL;
//	if (root == NULL)
//	{
//		return NULL;
//	}
//	if (root->data == x)
//	{
//		return root;
//	}
//	leftFind = BinaryTreeFind(root->left, x);
//	if (leftFind != NULL)
//	{
//		return root;
//	}
//	rightFind = BinaryTreeFind(root->right, x);
//	if (rightFind != NULL)
//	{
//		return root;
//	}
//	return NULL;
//}
//
//int main()
//{
//	BTNode* root = CreatBinaryTree();
//	PreOrder(root);
//	printf("\n");
//	InOrder(root);
//	printf("\n");
//	PostOrder(root);
//
//	printf("\n");
//	printf("BinaryTreeSize : %d ", BinaryTreeSize(root));
//
//	printf("\n");
//	printf("BinaryTreelevelSize: %d", BinaryTreelevelSize(root));
//
//
//	printf("\n");
//	printf("BinaryTreeKSize : %d", BinaryTreeKSize(root,3));
//
//	printf("\n");
//	printf("BinaryTreeDepth : %d", BinaryTreeDepth(root));
//
//	printf("\n");
//	printf("BinaryTreeFind :  %s", BinaryTreeFind(root, 'A'));
//
//	return 0;
//}



















































































