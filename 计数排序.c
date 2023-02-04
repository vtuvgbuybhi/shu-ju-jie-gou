#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Ψһһ�����ԴﵽO(N  + range)������

//        2  ,5 , 3 , 0 , 2 , 3 , 0 , 3  -->��������

// count  2   0   2   3   0   1    --> ͳ�Ƴ��ֵĴ���
//        0   1   2   3   4   5      ���ݵķ�Χ

//        0   0   2   2  3   3   3  5    --> ����ͳ�ƵĴ�������

void CountSort(int* a, int n)
{
	//��������С
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

	//ͳ�ƴ���
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























































































