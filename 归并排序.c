#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
//归并排序  -->  分治的思想
//将有序的子列合并  ， 得到一个完全有序的序列，即先使每个子序列有序，再使每个子序列段间有序

       //                      10  6  7  1  3  9  4  2                    ------
       //           10  6  7  1                    3  9  4  2                |
       //    10  6             7  1              3   9         4   2         |    分解
       //10        6         7       1        3        9     4        2   ------

       //  6 10                1 7                 3 9          2 4        ---
       //       1 6 7 10                              2 3 4 9              合并
       //                 1  2  3  4 6  7  9 10                            ---


void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int end1 = mid, begin1 = left;
	int end2 = right, begin2 = mid + 1;
	int i = left;
	while (begin1<=end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1<=end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2<=end2)
	{
		tmp[i++] = a[begin2++];
	}

	//tmp数组拷贝回a
	for (int j = left; j <=right; j++)
	{
		a[j] = tmp[j];
	}

}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

int main()
{
	int a[] = { 10 , 6  ,7 , 1 , 3  ,9,  4  ,2 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	int n = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);

	MergeSort(a,n);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{ 
		printf("%d ", a[i]);
	}

	return 0;
}




















































