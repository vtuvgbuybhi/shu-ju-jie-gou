#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
////
//////����ȡ��
//int GetMidIndex(int* a, int left, int right)
//{
//	int mid = left+((right-left)>>1);
//	if (a[left] > a[mid])
//	{
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		else if (a[left] < a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//	else//a[left]<a[mid]
//	{
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		else if (a[left] > a[right])
//		{
//			return right;
//		}
//		else
//		{
//			return left;
//		}
//	}
//}
//
////ǰ��ָ��
//// cur��С��С������߷�
//// prev�Ѵ�����ұ���
//
//
////int Partion3(int* a, int left, int right)
////{
////	int mid = GetMidIndex(a, left, right);
////	swap(&a[left], &a[mid]);
////
////	int keyi = left;
////	int cur = left + 1;
////	int prev = left;
////	while (cur <= right)
////	{
////		while(cur<=right&&a[cur] >= a[keyi])
////		{
////			cur++;
////		}
////		if (cur <= right)
////		{
////			swap(&a[cur], &a[++prev]);
////			cur++;
////		}
////	}
////	swap(&a[prev], &a[keyi]);
////	return prev;
////}
//
////ǰ��ָ��Ľ�1
//int Partion3(int* a, int left, int right)
//{
//	int mid = GetMidIndex(a, left, right);
//	swap(&a[left], &a[mid]);
//
//	int keyi = left;
//	int cur = left + 1;
//	int prev = left;
//	while (cur <= right)
//	{
//		//a[++prev]!=a[cur]  ����Լ����Լ�������û��Ҫ
//		if (a[cur] < a[keyi]&&++prev!=cur)
//		{
//			swap(&a[cur], &a[prev]);
//		}
//		cur++;
//	}
//	swap(&a[prev], &a[keyi]);
//	return prev;
//}
//
//
//
//
////void QuickSort(int* a, int left, int right)
////{
////	if (left >= right)
////	{
////		return;
////	}
////	int mid = Partion3(a, left, right);
////	QuickSort(a, left, mid - 1);
////	QuickSort(a, mid + 1, right);
////}
//
//
//void InsertSort(int* a, int n)
//{
//	int end = 0;
//	for (int i = 0; i < n-1; i++)
//	{
//		end = i;
//		int val = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > val)
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (end < 0)
//		{
//			a[0] = val;
//		}
//		else
//		{
//			a[end + 1] = val;
//		}
//	}
//}
//
////��������С�����Ż�
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	//С�����Ż� --> ��ʹ�õݹ飨Ϊ�˼�����󼸲�ĵݹ飩
//	if (right - left + 1 < 10)
//	{
//		InsertSort(a + left, right - left + 1);
//	}
//
//	int mid = Partion3(a, left, right);
//	QuickSort(a, left, mid - 1);
//	QuickSort(a, mid + 1, right);
//}
//
//
//int main()
//{
//	int a[] = { 2,4,6,2,3,8,6,9,10,11,31,22 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	int n = sizeof(a) / sizeof(a[0]);
//	//BubbleSort(a, n);
//	QuickSort(a, 0, n - 1);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}





























































































