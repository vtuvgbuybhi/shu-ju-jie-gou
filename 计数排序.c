#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//唯一一个可以达到O(N  + range)的排序

//        2  ,5 , 3 , 0 , 2 , 3 , 0 , 3  -->待排数据

// count  2   0   2   3   0   1    --> 统计出现的次数
//        0   1   2   3   4   5      数据的范围

//        0   0   2   2  3   3   3  5    --> 根据统计的次数排序

void CountSort(int* a, int n)
{
	//找最大和最小
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	memset(count, 0, sizeof(int) * range);

	//统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = min +i;
		}
	}
}


int main()
{
	int a[] = { 2 ,5,3,0,2,3,0,3 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	int n = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);
	CountSort(a, n);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}























































































