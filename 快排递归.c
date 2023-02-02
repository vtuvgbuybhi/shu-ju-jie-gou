#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

//冒泡排序

void swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}


//时间复杂度 经典的O（N^2）  最好的情况O（N）
//void BubbleSort(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		
//		int exchang = 0;//优化
//
//		for (int j = i; j < n - i-1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				exchang = 1;
//				swap(&a[j], &a[j + 1]);
//			}
//		}
//		//说明冒泡了一圈，没有发生交换 ，本来就是有序的，就没必要在进行后面的冒泡排序了
//		if (exchang == 0)
//		{
//			break;
//		}
//	}
//}


//int main()
//{
//	int a[] = { 2,4,6,2,3,8,6,9,10 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	
//	int n = sizeof(a) / sizeof(a[0]);
//	//BubbleSort(a, n);
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


//快速排序

//一般选择最左边或最右边的值作为key
//单趟排序的目标  : 左边的值比key小，右边的值比key大   --> 左边的值作key，让右边先走-->左右相遇时比key小

//时间复杂度O（N）
//int Partion(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left<right && a[right]>=a[keyi])
//		{
//			right--;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			left++;
//		}
//		swap(&a[right], &a[left]);
//	}
//	swap(&a[right], &a[keyi]);
//	return left;
//}
//
////时间复杂度 O(N*logN)    最坏情况  : O(N^2)
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int keyi = Partion(a, left, right);
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi + 1, right);
//}//目前的缺陷  : 接近有序的话，容易导致栈溢出  (越乱越快，越有序越慢)

//递归程序的缺陷
//1. 相比循环程序，性能差 (针对早期编译器，是这样子的，因为对于递归调用，建立栈帧优化不大，现在新编译器优化都很好，递归相比于循环性能差不了多少)
//2.递归深度太深，会导致栈溢出


//如何解决快速排序面对有序的选key问题  : 1.随机选key  2.三数取中(左边，中间，右边)

int GetMidIndex(int* a, int left, int right)
{
	//int mid=left+(right-left)/2
	int mid = left + ((right - left) >> 1);
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//a[left]>a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//int Partion(int* a, int left, int right)
//{
//	//三数取中
//	int mid = GetMidIndex(a, left, right);
//	swap(&a[mid], &a[left]);
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//		{
//			right--;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			left++;
//		}
//		swap(&a[right], &a[left]);
//	}
//	swap(&a[right], &a[keyi]);
//	return left;
//}
//
////时间复杂度 O(N*logN)    最坏情况  : O(N^2)
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int keyi = Partion(a, left, right);
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi + 1, right);
//}
//
//
//int main()
//{
//	int a[] = { 2,4,6,2,3,8,6,9,10 };
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



//挖坑法
//int Partion2(int* a, int left, int right)
//{
//	int mid = GetMidIndex(a, left, right);
//	swap(&a[left], &a[mid]);
//
//	int key = a[left];
//	int pivot = left;
//	while (left < right)
//	{
//		//右边找小，放到左边的坑里
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		a[pivot] = a[right];
//		pivot = right;
//		while (left < right && a[left] <= key)
//		{
//			left--;
//		}
//		a[pivot] = a[left];
//		pivot = left;
//	}
//	a[pivot] = key;
//	return pivot;
//}


//前后指针


//起始情况
//          cur-->向右找比key小的数(找到了  prev++   -->  交换两位置的值)
//    6      1      2       7       9      3        4        5       10       8    //以6为key
//  prev
//
////prev++  交换两位置的值 cur向前走，继续找比key小的数
//		    cur
//    6      1      2       7       9      3        4        5       10       8    //以6为key
//          prev
//
////找到了
//	               cur
//    6      1      2       7       9      3        4        5       10       8    //以6为key
//		    prev
//
////prev++  交换两位置的值
//			       cur
//    6      1      2       7       9      3        4        5       10       8    //以6为key
//			       prev
//
////找到了
//                                        cur
//    6      1      2       7       9      3        4        5       10       8    //以6为key
//			      prev
//
////  prev++  交换两个位置的值
//                                         cur
//    6      1      2       3       9      7        4        5       10       8    //以6为key
//			              prev
//
////cur继续向前走  --> 找到了
//                                                cur
//   6      1      2       3       9      7        4        5       10       8    //以6为key
//			             prev
// 
////  prev++  交换两个位置的值
//			                                     cur
//   6      1      2       3       4      7        9        5       10       8    //以6为key
//			                     prev
//
////cur继续向前走   --> 找到了
//                                                         cur
//   6      1      2       3       4      7        9        5       10       8    //以6为key
//                                prev
//
////  prev++  交换两个位置的值
//			                                               cur
//   6      1      2       3       4      5        9        7       10       8    //以6为key
//			                            prev
////cur接下来走到底了
//                                                                          cur
//   6      1      2       3       4       5        9        7       10       8    //以6为key
//                                        prev
////交换起始位置和prev的值（不需要prev++）
//                                                                           cur
//   5      1      2       3       4       6        9        7       10       8    //以6为key
//                                        prev
//
//
//
////以右边为基准点
//
////起始位置
//    cur-- > 向右找比key小的数(找到了  prev++   -- > 交换两位置的值)
//     8      1      2       7       9      3        4        5       10       6    //以6为key
//prev
//
////找到了  prev++ 交换两个位置的值
//           cur
//     8      1      2       7       9      3        4        5       10       6    //以6为key
//prev
//
////cur继续向右走
//           cur
//     1      8      2       7       9      3        4        5       10       6    //以6为key
//    prev
////找到了  prev++ 交换两个位置的值
//			      cur
//     1      8      2       7       9      3        4        5       10       6    //以6为key
//    prev
//
////cur继续向后走
//			     cur
//	1      2      8       7       9      3        4        5       10       6    //以6为key
//		  prev
// 
////找到了  prev++ 交换两个位置的值
//			                            cur
//	1      2      8       7       9      3        4        5       10       6    //以6为key
//		  prev
//
////cur继续向前走
//			                              cur
//    1      2      3       7       9      8        4        5       10       6    //以6为key
//			      prev
//
////    ………………
////cur走到6的位置时
//                                                                           cur
//    1      2      3       4       5      8        7        9       10       6    //以6为key
//                                 prev
////最后prev++  交换cur位置上的值
//                                                                          cur
//   1      2      3       4       5      6        7        9       10       8    //以6为key
//                                       prev


//自己写的  --> 理解错了
//int Partion3(int* a, int left, int right)
//{
//	int x=left, y=left;
//	int key = a[left];
//	int* px=a[left], * py=a[left+1];
//	while (y<right)
//	{
//		if (y<right && *py>=key)
//		{
//			y++;
//			*py++;
//		}
//		x++;
//		*px++;
//		swap(&a[x], &a[y]);
//	}
//	swap(&a[x], &a[0]);
//	return x;
//}

//老师的写法
int Partion3(int* a, int left, int right)
{
	int keyi = left;
	int cur = left + 1;
	int prev = left;
	while (cur <= right)
	//2, 4, 6, 2, 3, 8, 6, 9, 10
	//2  3  2  4  6  8  6  9  10
	{
		while(cur <= right  && a[cur] >= a[keyi])
		{
			cur++;
		}
		if (cur <= right )
		{
			swap(&a[cur], &a[++prev]);
			cur++;
		}
	}
	swap(&a[prev], &a[keyi]);
	return prev;
}


void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyi = Partion3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}


int main()
{
	int a[] = { 2,4,6,2,3,8,6,9,10 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	int n = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}






































