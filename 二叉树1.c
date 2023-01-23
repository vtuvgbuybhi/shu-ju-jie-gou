#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//如何表示树呢？(   代码实现树的定义结构)

//方式1   --》假设说明了树的度为N

//struct TreeNode
//{
//	int data;
//	struct TreeNode* sub[N];
//};
//
//问题:  可能会存在不少空间的浪费      万一没有限定树的度多少呢?


//方式二
//typedef struct TreeNode* SLDataType;
//struct TreeNode
//{
//	int data;
//	SeqList s;
//};

//结构复杂



//方式三    --》结构数组存储
//struct TreeNode
//{
//	int parenti;
//	int data;
//};
//
//                                        A
//                                        |
//			 	————————————————————————————
//			    |       |             |       |        ……
//                B       C             D       E
//                                      |       | 
//									  H     ————
//											|      |
//											I      J
//
//struct TreeNode arr[10];
//
//只存自己的值和父亲的下标   (双亲表示法)
//---------------------------------------------------------
//|A -1 | B 0 | C 0 | D 0 |                | H 3 |
//----------------------------------------------------------



//以上方式  各右优缺点   （最优的方法   --》左孩子右兄弟   ）

//大哥方法

//typedef int DataType;
//struct Node
//{
//	struct Node* _firstChild1;  //永远指向第一个孩子
//	struct Node* _pNextBrother;//指向孩子右边的兄弟
//	DataType data;
//};
//                                                   A
//										           |	
//                            ———————————————————————
//                            |                                             |
//                            B                                             C
//                            |                                             |
//               ——————————————                               |
//               |            |             |                               |
//               D            E             F                               G
//                            |
//                         ————
//                        |       |
//                        H       I
//
//---------------
//|A|child |bro |
//---------------
//     |
//     |
//---------------             ---------------
//|B|child |bro |   ————> |C|child |bro |---->NULL
//---------------             ---------------
//     |                            |
//     |                            ----------------------------------------------------------------------
//     |                                                                                                  |
//---------------             --------------        ---------------                               ---------------             
//|D|child |bro |  ————> |E |child |bro|———> |F|child |bro |———>NULL                    |G |child|bro |———>NULL 
//---------------            ---------------        ---------------                               ---------------
//                                 |
//                           ---------------          -------------
//                           |H|child |bro | ———> |I| child|bro|———>NULL
//                           ---------------         --------------


//树在实际中的运用(文件系统的目录树结构)




//顺序存储---> 顺序结构存储就是使用数组来存储(一般使用数组只适合表示完全二叉树)
//
//                      -----
//                      | A |
//                      -----
//                        |
//                 —————————                                   假设parent是父亲节点在数组中的下标
//                 |                |                                    lefechild =parent*2+1
//                -----           -----                                  rightchild=parent*2+2
//               | B  |           | C |
//                -----           -----                                 假设孩子的下标是child，不管是右孩子还是左孩子
//                  |                |                                       parent= （child-1）/2
//         ————————      ———————
//         |              |        |         |
//       ------         -----     -----     -----
//       | D  |         | E  |    | F |     | G  |
//       ------         ------    -----    -------
//    二叉树顺序存储在物理上是一个数组，在逻辑上是一颗二叉树
//    ----------------------------
//    | A | B | C | D | E |F | G |
//    ----------------------------


//链式存储结构



//堆的概念及结构  --> 把它所有元素按完全二叉树的顺序存储方式存储在一个一维数组中

//大堆 :树中一个树及子树中，任何一个父亲都大于等于孩子
//小堆 :树中一个树及子树中，任何一个父亲都小于等于孩子

//1.堆排序
//2.topK问题  --》 在N个数中，找出最大的前K个/或者最小的前K个


//堆实现树

//typedef int HpDataType;
//
//typedef struct Heap
//{
//	HpDataType* a;
//	int size;
//	int capacity;
//}Hp;
//
//void HpInit(Hp* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
//void HpDestroy(Hp* ps)
//{
//	assert(ps);
//	free(ps->a);
//}
//
//void AdjustUp(int* a, int size, int child)
//{
//	assert(a);
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] > a[parent])
//		{
//			HpDataType tmp = a[child];
//			a[child] = a[parent];
//			a[parent] = tmp;
//
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void HpPush(Hp* hp, HpDataType x)
//{
//	assert(hp);
//	if (hp->size == hp->capacity)
//	{
//		size_t newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
//		HpDataType* tmp = realloc(hp->a, sizeof(HpDataType)*newcapacity);
//		if (tmp == 0)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		hp->a = tmp;
//		hp->capacity = newcapacity;
//	}
//	hp->a[hp->size] = x;
//	hp->size++;
//
//	AdjustUp(hp->a, hp->size, hp->size - 1);
//}
//
//
//void HpPrint(Hp* hp)
//{
//	assert(hp);
//	for (int i = 0; i < hp->size; i++)
//	{
//		printf("%d ", hp->a[i]);
//	}
//	printf("\n");
//}
//
//
//int main()
//{
//	int a[] = { 70,56,30,25,15,10,75 };
//	Hp hp;
//	HpInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HpPush(&hp, a[i]);
//	}
//
//	HpPrint(&hp);
//
//	return 0;
//}


















