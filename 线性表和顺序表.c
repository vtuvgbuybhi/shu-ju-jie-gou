#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//���Ա�  : ��n��������ͬ���Ե�����Ԫ�ص���������
//���������Ա�: ˳�������ջ�����С��ַ�������

//                   | --����̬
//˳���  --�� ����--
//                   | --����̬
//
//���鵱��������û��Ҫ��ģ�˳���������Ҫ�����ݱ��������洢�������ͷ��ʼ��

//˳���  : ����һ�������ַ�������洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢


//#define N 1000
/*typedef int SLDataType;*/     //�ض���һ�����Ƴ���--�����char����  ֱ�ӽ�int��char  


//��̬˳���
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;//��ʾ�����д洢�˶��ٸ�����
//}SL;

//˳���ӿڣ��ӿں�����----��������������Ǹ���STL��c++��һ���⺯��
//void SeqListInit(SL* ps)//��ʼ��˳���
//{
//
//
//}
//
////��̬�ص�: ������˾Ͳ��ò���
//void SeqListPushBack(SL* ps, SLDataType x)//β������
//void SeqListPopBack(SL* ps, SLDataType x)//βɾ
//void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
//void SeqListPopFront(SL* ps, SLDataType x)//ͷɾ









//��̬˳���

//typedef int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType* a;
//	int size;      //��ʾ�����д洢�˶��ٸ�����
//	int capacity;  //����ʵ���ܴ����ݿռ������Ƕ��
//}SL;
//
//
//void SeqListInit(SL* ps)//��ʼ��˳���
//{
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
//
//void SeqListCheckCapacity(SL* ps)
//{
//	if (ps->size == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//
//		//realloc��һ���ص�: �����ԭ���Ŀռ����ݣ���ԭ���Ŀռ��ǿգ���ô�ͺ�malloc�Ĺ�����һ����
//		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//}
//

//void SeqListPushBack(SL* ps, SLDataType x)//β������
////1.����˳���û�пռ�
////2.�ռ䲻��  --> ����
////3.�ռ��㹻��ֱ�Ӳ������ݼ���
//{
//	//���û�пռ䣬���߿ռ䲻�����Ǿ�����
//	SeqListCheckCapacity(ps);
//
//	//�㹻�Ŀռ䣬ֱ�Ӳ���
//	ps->a[ps->size] = x;
//	ps->size++;
//}
//void SeqListPopBack(SL* ps)//βɾ
//{
//	//����1
//	//if (ps->size > 0)
//	//{
//	//	//ps->a[ps->size - 1] = 0;   //�ⲽ������
//	//	ps->size--;
//	//}
//	
//	//����2
//	assert(ps->size > 0);
//	ps->size--;
//
//}
//
//void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
//{
//	SeqListCheckCapacity(ps);
//	//Ų������
//	int end = ps->size - 1;
//	while (end >= 0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}
//
//void SeqListPopFront(SL* ps)//ͷɾ
//{
//	assert(ps->size > 0);
//	int begin = 1;
//	while (begin < ps->size)
//	{
//		ps->a[begin - 1] = ps->a[begin];
//		begin++;
//	}
//	ps->size--;
//}
//
//
//void SeqListPrint(SL* ps)//��ӡ
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
//
////����
//void SeqListDestory(SL* ps)
//{
//	free(ps->a);
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
////�ҵ��˷���xλ���±꣬û���ҵ�����-1
//void SeqListSearch(SL* ps, SLDataType x);
////ָ��pos�±�λ�ò���
//void SeqListInsert(SL* ps, int pos, SLDataType x);
////ɾ��posλ�õ�����
//void SeqListErase(SL* ps, int pos);
//
//
//
//void TestSeqList1()
//{
//	SL s1;
//	SeqListInit(&s1);//���ṹ��ĵ�ַ������ʵ�δ����β�ʵ����ֵ�Ŀ���
//	//β��  1 2 3 4 5  5������
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 3);
//	SeqListPushBack(&s1, 4);
//	SeqListPushBack(&s1, 5);
//
//
//	SeqListPrint(&s1);
//
//
//	SeqListDestory(&s1);
//}
//
//void TestSeqList2()
//{
//	SL s1;
//	SeqListInit(&s1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 5);
//
//	SeqListPrint(&s1);
//
//	SeqListPushFront(&s1, 10);
//	SeqListPushFront(&s1, 20);
//	SeqListPushFront(&s1, 30);
//	SeqListPushFront(&s1, 40);
//
//	SeqListPrint(&s1);
//
//	SeqListPopFront(&s1);
//
//	SeqListDestory(&s1);
//}
//
//int main()
//{ 
////	TestSeqList1();
////	TestSeqList2();
//
//	return 0;
//}















