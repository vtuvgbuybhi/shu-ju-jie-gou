#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


//��ͨ��������ɾ���û��ʲô��ֵ����Ϊ����������̫������

//��ô�������ļ�ֵ���������Ļ���֮������һЩ���ʣ���������

//1.��������������( ��������ֵ��С�ڸ���ֵ����������ֵ�����ڸ���ֵ  )  --���������Ҹ߶ȴΣ�  ����(O(N))
//����  --> ƽ�������   AVLTree  �����  --> B��

//2. huffman tree 


//�������ı���
//������  --> ��  �� ������  ��������

//ǰ�����  --> ���ʸ��ڵ�Ĳ��������ڱ�������������֮ǰ
//������� --> ���ʸ��ڵ�Ĳ��������ڱ�������������֮��(��)
//�������-- > ���ʸ��ڵ�Ĳ��������ڱ�������������֮��


typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}


//����һ��������
BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');

	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	return nodeA;
}



//������ǰ�����
 
//����  : �ֶ���֮  -- ���»�С��С�»���
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}


//�������������

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

//�������������

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
printf("%c ", root->data);
}

//��������ڵ�ĸ���

//��һ���ñ�����˼���Ǵ��������
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	static count = 0;
//	count++;
//
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//	return count;
//}

//˼·2
//void  BinaryTreeSize(BTNode* root,int*pn)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	(*pn)++;
//
//	BinaryTreeSize(root->left,pn);
//	BinaryTreeSize(root->right,pn);
//}


//˼·3
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}




//int main()
//{
//	BTNode* root = CreatBinaryTree();
//	//PreOrder(root);
//	//printf("\n");
//	//InOrder(root);
//	//printf("\n");
//	//PostOrder(root);
//
//	//˼·1
//	//printf("BinaryTreeSize : %d ", BinaryTreeSize(root));
//
//	//˼·2
//	//int p = 0;
//	//BinaryTreeSize(root, &p);
//	//printf("BinaryTreeSize : %d ", p);
//
//
//	//˼·3
//	//printf("BinaryTreeSize : %d ", BinaryTreeSize(root));
//
//
//	return 0;
//}



//��Ҷ�ӽڵ����
//˼·1
//int BinaryTreeLeafSize(BTNode* root,int*p)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	if (root->left == NULL && root->right == NULL)
//	{
//		(*p)++;
//	}
//	BinaryTreeLeafSize(root->left, p);
//	BinaryTreeLeafSize(root->right, p);
//}

//˼·2
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->left == NULL && root->right == NULL ? 1 : BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


//���K��ڵ����
int BinarylevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinarylevelKSize(root->left, k - 1) + BinarylevelKSize(root->right, k - 1);
}



//int main()
//{
//	BTNode* root = CreatBinaryTree();
//
//	//˼·1
//	//int p = 0;
// //   BinaryTreeLeafSize(root, &p);
// //   printf("BinaryTreeLeafSize :%d ", p);
//
//
//	//˼·2
//	//printf("BinaryTreeLeafSize : %d ", BinaryTreeLeafSize(root));
//
//
//	printf("BinarylevelKSize :%d ", BinarylevelKSize(root, 2));
//
//	return 0;
//}


//����������/�߶�
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

}

int main()
{
	BTNode* root = CreatBinaryTree();

	printf("BinaryTreeDepth : %d ", BinaryTreeDepth(root));

	return 0;
}






































