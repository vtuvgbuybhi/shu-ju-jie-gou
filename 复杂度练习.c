#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//消失的数字

//数组num包含从0到n的所有整数，但其中缺了一个，请编写代码找出缺的整数，并在O（n）时间内完成

//思路1  : 排序 --》 快速排序时间复杂度O(n*log N(以2为底))
//排序完后再俩俩相减   找出相减不是1的值  那么第一个数就是缺的数
//void Quick_sort(int arr[], int star, int end)
//{
//	if (star > end)
//	{
//		return 0;
//	}
//	int temp = arr[star];
//	int i = star;
//	int j = end;
//	while (i != j)
//	{
//		while (arr[j] >= temp && i < j)
//		{
//			j--;
//		}
//		while (arr[i] <= temp&&i < j)
//		{
//			i++;
//		}
//		if (i < j)
//		{
//			int t = arr[i];
//			arr[i] = arr[j];
//			arr[j] = t;
//		}
//	}
//	arr[star] = arr[i];
//	arr[i] = temp;
//	Quick_sort(arr, 0, i - 1);
//	Quick_sort(arr, i + 1, end);
//}
//int main()
//{
//	int arr[5] = { 4,3,5,0,1 };
//	Quick_sort(arr, 0, 4);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	for (int i = 1; i < 5; i++)
//	{
//		if (arr[i] - arr[i - 1] != 1)
//		{
//			printf("缺的数是:%d ", arr[i] - 1);
//		}
//	}
//	return 0;
//}


//思路2   :   (0+1+2……+n)-(arr[0]+arr[1]+……+arr[n-1])
//相减得到的数就是缺的数

//时间复杂度 O（N）    空间复杂度O(1)

//int main()
//{
//	int arr[4] = { 2,3,1 };
//	int sum = 0;
//	for (int i = 1; i <= 4; i++)
//	{
//		sum += i;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		sum -= arr[i];
//	}
//	printf("缺的数是:%d ", sum);
//	return 0;
//}


//思路3: 给一个值x=0
//      x先跟[0,n]的所有值异或
//      x在跟数组中每一个值异或，最后x就是缺的那个数字

//时间复杂度:O(N)    时间复杂度: O(1)
//
//int main()
//{
//	int x = 0;
//	int arr[4] = { 2,4,1 };
//	for (int i = 1; i < 5; i++)
//	{
//		x ^= i;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		x ^= arr[i];
//	}
//	printf("缺是数是:%d ", x);
//	return 0;
//}


//旋转数组
//给定一个数组，将数组中的元素向右移动k个位置，其中k是是非负数
//空间复杂度为O（1）

//思路1  : 暴力求解，旋转k次
//时间复杂度 :O(N*K)   空间复杂度:O(1)
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < 3; i++)//旋转3次
//	{
//		int tmp = arr[sz - 1];
//		for (int j = sz - 1; j >= 1; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[0] = tmp;
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//思路2  : 开辟额外的空间  --》 以空间换时间
//时间复杂度  O(N)  空间复杂度 O(N)

//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int arr1[5] = { 0 };
//	for (int i = 0; i < sz; i++)//旋转3次
//	{
//		if (i < 3)
//		{
//			arr1[i] = arr[sz - 3 + i];
//		}
//		else
//		{
//			arr1[i] = arr[i-3];
//		}
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}


//思路3  : 非常神奇的算法
//前n-k个逆序     后k个逆序     整体逆序
   
//void Reverse(int* arr, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//
//		++left;
//		--right;
//	}
//}
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	Reverse(arr, 0, 1);
//	Reverse(arr, 2, 4);
//	Reverse(arr, 0, 4);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}






















