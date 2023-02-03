#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
////
//////三数取中
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
////前后指针
//// cur找小把小的往左边翻
//// prev把大的往右边推
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
////前后指针改进1
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
//		//a[++prev]!=a[cur]  相等自己跟自己交换，没必要
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
////快速排序小区间优化
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	//小区间优化 --> 不使用递归（为了减少最后几层的递归）
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





























































































