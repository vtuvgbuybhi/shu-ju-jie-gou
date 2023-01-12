#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//typedef  int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType* a;
//	int size;
//	int capacity;
//}SL;
//
//void SeqListCheckCapacity(SL*ps)
//{
//	int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//	SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
//	if (tmp == NULL)
//	{
//		printf("realloc fail\n");
//		exit(-1);
//	}
//	ps->a = tmp;
//	ps->capacity = newcapacity;
//}
//
//
//void SeqListPushBack(SL*ps)
//{
//	SLDataType x;
//	printf("������Ҫ��β�����������:>");
//	scanf("%d", &x);
//	SeqListCheckCapacity(ps);
//	ps->a[ps->size] = x;
//	ps->size++;
//}
//
//
//void SeqListPopBack(SL* ps)
//{
//	assert(ps->size > 0);
//	ps->size--;
//	printf("βɾ�ɹ�\n");
//}
//
//void SeqListInit(SL* ps)
//{
//	ps->a = NULL;
//	ps->capacity = ps->size = 0;
//}
//
//
//void SeqListPrint(SL* ps)
//{
//	if (ps->size == 0)
//	{
//		printf("�б�Ϊ��\n");
//	}
//
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
//
//
//void SeqListPushFront(SL* ps)
//{
//	SLDataType x;
//	printf("����Ҫͷ�������:>");
//	scanf("%d", &x);
//	SeqListCheckCapacity(ps);
//	int end = ps->size - 1;
//	while (end>=0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}
//
//void SeqListPopFront(SL* ps)
//{
//	assert(ps->size > 0);
//	int begin = 1;
//	while (begin < ps->size)
//	{
//		ps->a[begin-1] = ps->a[begin];
//		begin++;
//	}
//	ps->size--;
//}
//
//
//void SeqListInsert(SL* ps)
//{
//	SLDataType x;
//	printf("����Ҫ���������:>");
//	scanf("%d", &x);
//	int y;
//	printf("����Ҫ��������:>");
//	scanf("%d", &y);
//	SeqListCheckCapacity(ps);
//	int end = ps->size;
//	while (end >= y)
//	{
//		ps->a[end] = ps->a[end - 1];
//		end--;
//	}
//	ps->a[y-1] = x;
//	ps->size++;
//}
//
//
//int SeqListSearch1(SL* ps)
//{
//	SLDataType x;
//	printf("����Ҫ���ҵ�����:>");
//	scanf("%d", &x);
//	int i = 0;
//	while (i < ps->size)
//	{
//		if (ps->a[i] != x)
//		{
//			i++;
//		}
//		else
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//
//
//void SeqListSearch(SL* ps)
//{
//	assert(ps->size > 0);
//	int x = SeqListSearch1(ps);
//	if (x != -1)
//	{
//		printf("�ҵ��ˣ��±���:>%d \n", x);
//	}
//	else
//	{
//		printf("Ҫ���ҵ����ݲ�����\n");
//	}
//}
//
//
//void SeqListErase(SL* ps)
//{
//	assert(ps->size > 0);
//	int begin = 0;
//	printf("����Ҫɾ����Ԫ�����:>");
//	scanf("%d", &begin);
//	while (begin<ps->size)
//	{
//		ps->a[begin - 1] = ps->a[begin];
//		begin++;
//	}
//	ps->size--;
//}
//
//void ShellSort(SL* ps)
//{
//	int gap = ps->size;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < ps->size - gap; i++)
//		{
//			int end = i;
//			int tmp = ps->a[end + gap];
//			{
//				while (end >= 0)
//				{
//					if (ps->a[end] > tmp)
//					{
//						ps->a[end + gap] = ps->a[end];
//						end--;
//					}
//					else
//					{
//						break;
//					}
//
//				}
//			}
//			ps->a[end + gap] = tmp;
//		}
//	}
//}
//
//
//void SeqListSort(SL* ps)
//{
//	assert(ps->size >= 2);
//	ShellSort(ps);
//	printf("�������");
//}
//
//
//
//
//void menu()
//{
//	printf("*************************************\n");
//	printf("***1.ͷɾ        2.ͷ��  ************\n");
//	printf("***3.βɾ        4.β��  ************\n");
//	printf("***5.ָ������    6.��ָ������********\n");
//	printf("***7.ɾ��ָ��λ����Ϣ 8.��ӡ ********\n");
//	printf("***9.��������  0.�˳�****************\n");
//}
//
//int main()
//{
//	int input = 0;
//	SL s1;
//	SeqListInit(&s1);
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("�˳�����\n");
//			break;
//		case 1:
//			SeqListPopFront(&s1);
//			break;
//		case 2:
//			SeqListPushFront(&s1);
//			break;
//		case 3:
//			SeqListPopBack(&s1);
//			break;
//		case 4:
//			SeqListPushBack(&s1);
//			break;
//		case 5:
//			SeqListInsert(&s1);
//			break;
//		case 6:
//			SeqListSearch(&s1);
//			break;
//		case 7:
//			SeqListErase(&s1);
//			break;
//		case 8:
//			SeqListPrint(&s1);
//			break;
//		case 9:
//			SeqListSort(&s1);
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
































































































