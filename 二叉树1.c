#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��α�ʾ���أ�(   ����ʵ�����Ķ���ṹ)

//��ʽ1   --������˵�������Ķ�ΪN

//struct TreeNode
//{
//	int data;
//	struct TreeNode* sub[N];
//};
//
//����:  ���ܻ���ڲ��ٿռ���˷�      ��һû���޶����Ķȶ�����?


//��ʽ��
//typedef struct TreeNode* SLDataType;
//struct TreeNode
//{
//	int data;
//	SeqList s;
//};

//�ṹ����



//��ʽ��    --���ṹ����洢
//struct TreeNode
//{
//	int parenti;
//	int data;
//};
//
//                                        A
//                                        |
//			 	��������������������������������������������������������
//			    |       |             |       |        ����
//                B       C             D       E
//                                      |       | 
//									  H     ��������
//											|      |
//											I      J
//
//struct TreeNode arr[10];
//
//ֻ���Լ���ֵ�͸��׵��±�   (˫�ױ�ʾ��)
//---------------------------------------------------------
//|A -1 | B 0 | C 0 | D 0 |                | H 3 |
//----------------------------------------------------------



//���Ϸ�ʽ  ������ȱ��   �����ŵķ���   --���������ֵ�   ��

//��緽��

//typedef int DataType;
//struct Node
//{
//	struct Node* _firstChild1;  //��Զָ���һ������
//	struct Node* _pNextBrother;//ָ�����ұߵ��ֵ�
//	DataType data;
//};
//                                                   A
//										           |	
//                            ����������������������������������������������
//                            |                                             |
//                            B                                             C
//                            |                                             |
//               ����������������������������                               |
//               |            |             |                               |
//               D            E             F                               G
//                            |
//                         ��������
//                        |       |
//                        H       I
//
//---------------
//|A|child |bro |
//---------------
//     |
//     |
//---------------             ---------------
//|B|child |bro |   ��������> |C|child |bro |---->NULL
//---------------             ---------------
//     |                            |
//     |                            ----------------------------------------------------------------------
//     |                                                                                                  |
//---------------             --------------        ---------------                               ---------------             
//|D|child |bro |  ��������> |E |child |bro|������> |F|child |bro |������>NULL                    |G |child|bro |������>NULL 
//---------------            ---------------        ---------------                               ---------------
//                                 |
//                           ---------------          -------------
//                           |H|child |bro | ������> |I| child|bro|������>NULL
//                           ---------------         --------------


//����ʵ���е�����(�ļ�ϵͳ��Ŀ¼���ṹ)




//˳��洢---> ˳��ṹ�洢����ʹ���������洢(һ��ʹ������ֻ�ʺϱ�ʾ��ȫ������)
//
//                      -----
//                      | A |
//                      -----
//                        |
//                 ������������������                                   ����parent�Ǹ��׽ڵ��������е��±�
//                 |                |                                    lefechild =parent*2+1
//                -----           -----                                  rightchild=parent*2+2
//               | B  |           | C |
//                -----           -----                                 ���躢�ӵ��±���child���������Һ��ӻ�������
//                  |                |                                       parent= ��child-1��/2
//         ����������������      ��������������
//         |              |        |         |
//       ------         -----     -----     -----
//       | D  |         | E  |    | F |     | G  |
//       ------         ------    -----    -------
//    ������˳��洢����������һ�����飬���߼�����һ�Ŷ�����
//    ----------------------------
//    | A | B | C | D | E |F | G |
//    ----------------------------


//��ʽ�洢�ṹ



//�ѵĸ���ṹ  --> ��������Ԫ�ذ���ȫ��������˳��洢��ʽ�洢��һ��һά������

//��� :����һ�����������У��κ�һ�����׶����ڵ��ں���
//С�� :����һ�����������У��κ�һ�����׶�С�ڵ��ں���

//1.������
//2.topK����  --�� ��N�����У��ҳ�����ǰK��/������С��ǰK��


//��ʵ����

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


















