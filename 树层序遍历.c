#define _CRT_SECURE_NO_WARNINGS


//树的层序遍历

//   --》 先入根
//   -->当前节点出来，把孩子带进去，这样上一层节点出的时候，代入下一层
//   -->队列为空，说明最后一层没有节点了，遍历结束

//#include<stdio.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdlib.h>
//
////前置声明
//struct BinaryTreeNode;
//
//typedef struct BinarytreeNode* QDataType;
//
////typedef BTNode* Qdatatype;
//
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;
//	QueueNode* tail;
//}Queue;
//
//void QueueInit(Queue*pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//
//void QueuePush(Queue* pq,QDataType x)
//{
//	assert(pq);
//	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//	if (newNode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newNode->next = NULL;
//	newNode->data = x;
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newNode;
//	}
//	else
//	{
//		pq->tail->next = newNode;
//		pq->tail = newNode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* cur = pq->head->next;
//	free(pq->head);
//	pq->head = cur;
//	if (pq->head == NULL)
//	{
//		pq->tail = NULL;
//	}
//}
//
//QDataType QueueFront(Queue*pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//
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
//BTNode* BuyNode(BTDataType x)
//{
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//	if (node == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	node->data = x;
//	node->left = node->right = NULL;
//	return node;
//}
//
////构建一颗树出来
//BTNode* CreatBinaryTree()
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
//}
//
//
////层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c ", front->data);
//
//		if (front->left)
//		{
//			QueuePush(&q, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(&q, front->right);
//		}
//
//	}
//	printf("\n");
//	QueueDestroy(&q);
//}

//int main()
//{
//	BTNode* root = CreatBinaryTree();
//
//	BinaryTreeLevelOrder(root);
//
//	return;
//}


//判断一颗二叉树是否是一颗 --> 完全二叉树

//完全二叉树  --> 非空节点是连续的
//非完全二叉树  --> 非空节点是不连续的

bool BinaryTreeComplete(BTNode* root)
{

	if (root == NULL)
	{
		return false;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}


int main()
{
	BTNode* root = CreatBinaryTree();
	printf("BinaryTreeComplete :%d ", BinaryTreeComplete(root));
	return;
}



//二叉树销毁

//后序遍历
//void BinaryTreeDestroy(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	BinaryTreeDestroy(root->left);
//	BinaryTreeDestroy(root->right);
//	free(root);
//}























































