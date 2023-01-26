#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


//普通二叉树增删查改没有什么价值，因为用来存数据太复杂了

//那么二叉树的价值体现在他的基础之上增加一些性质，才有意义

//1.比如搜索二叉树( 左子树的值都小于根的值，右子树的值都大于跟的值  )  --》（最多查找高度次）  最坏情况(O(N))
//最坏情况  --> 平衡二叉树   AVLTree  红黑树  --> B树

//2. huffman tree 


//二叉树的遍历
//二叉树  --> 根  、 左子树  、右子树

//前序遍历  --> 访问跟节点的操作发生在遍历其左右子树之前
//中序遍历 --> 访问跟节点的操作发生在遍历其左右子树之中(间)
//后序遍历-- > 访问跟节点的操作发生在遍历其左右子树之后


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


//构建一颗树出来
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



//二叉树前序遍历
 
//分治  : 分而治之  -- 大事化小，小事化了
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


//二叉树中序遍历

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

//二叉树后序遍历

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

//求二叉树节点的个数

//第一种用遍历的思想是存在问题的
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

//思路2
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


//思路3
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
//	//思路1
//	//printf("BinaryTreeSize : %d ", BinaryTreeSize(root));
//
//	//思路2
//	//int p = 0;
//	//BinaryTreeSize(root, &p);
//	//printf("BinaryTreeSize : %d ", p);
//
//
//	//思路3
//	//printf("BinaryTreeSize : %d ", BinaryTreeSize(root));
//
//
//	return 0;
//}



//求叶子节点个数
//思路1
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

//思路2
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->left == NULL && root->right == NULL ? 1 : BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


//求第K层节点个数
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
//	//思路1
//	//int p = 0;
// //   BinaryTreeLeafSize(root, &p);
// //   printf("BinaryTreeLeafSize :%d ", p);
//
//
//	//思路2
//	//printf("BinaryTreeLeafSize : %d ", BinaryTreeLeafSize(root));
//
//
//	printf("BinarylevelKSize :%d ", BinarylevelKSize(root, 2));
//
//	return 0;
//}


//求二叉树深度/高度
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






































