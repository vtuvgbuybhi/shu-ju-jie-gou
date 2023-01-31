#define _CRT_SECURE_NO_WARNINGS


//���Ĳ������

//   --�� �����
//   -->��ǰ�ڵ�������Ѻ��Ӵ���ȥ��������һ��ڵ����ʱ�򣬴�����һ��
//   -->����Ϊ�գ�˵�����һ��û�нڵ��ˣ���������

//#include<stdio.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdlib.h>
//
////ǰ������
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
////����һ��������
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
////�������
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


//�ж�һ�Ŷ������Ƿ���һ�� --> ��ȫ������

//��ȫ������  --> �ǿսڵ���������
//����ȫ������  --> �ǿսڵ��ǲ�������

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



//����������

//�������
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























































