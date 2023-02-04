#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//递归
//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int mid = (left + right) / 2;
//	_MergeSort(a, left, mid, tmp);
//	_MergeSort(a, mid + 1, right, tmp);
//
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int i = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];
//	}
//
//	//tmp数组拷贝到a数组
//	for (int j = left; j <= right; j++)
//	{
//		a[j] = tmp[j];
//	}
//}
//
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	_MergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//	tmp = NULL;
//}
//
//int main()
//{
//	int a[] = { 10 , 6  ,7 , 1 , 3  ,9,  4  ,2 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	int n = sizeof(a) / sizeof(a[0]);
//	//BubbleSort(a, n);
//
//	MergeSort(a,n);
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{ 
//		printf("%d ", a[i]);
//	}
//
//	return 0;
//}



//归并排序非递归

   //   10  6  7  1  3  9  4  2                     for(int i=0;i<n;i+=2*gap)     gap=1
   //             |    gap=1                         {
   //   6  10  1  7  9  3  2  4                            [i , i+gap-1]  [i+gap , i+2*gap-1]
		 //       |    gap=2                          }     0      0         1         1
                                                  //        2      2         3         3
	  //1  6   7  10 2  3  4  9
		 //       |    gap=4

	  //1  2   3  4  6  7  9  10




//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += gap * 2)
//		{
//			//[i,i+gap-1]  [i+gap,i+gap*2-1]
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + gap * 2 - 1;
//			int index = i;
//
//			
//			//printf("[%d  %d] [%d  %d]", begin1, end1, begin2, end2);
//
//			//end1越界  ，[begin2,end2]不存在
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//			}
//			//[begin1,end1]存在  [begin2,end2]不存在
//			if (begin2 >= n)
//			{
//				//设置一个不存在的区间，避免tmp越界的问题
//				begin2 = n;
//				end2 = n - 1;
//			}
//
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//			printf("[%d  %d] [%d  %d]", begin1, end1, begin2, end2);
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//		}
//		printf("\n");
//		for (int i = 0; i < n; i++)
//		{
//			a[i] = tmp[i];
//		}
//		gap *= 2;
//	}
//
//	free(tmp);
//	tmp = NULL;
//}
//
//int main()
//{
//	int a[] = { 10 , 6  ,7 , 1 , 3  ,9,  4,6,55  };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	int n = sizeof(a) / sizeof(a[0]);
//	//BubbleSort(a, n);
//
//	MergeSortNonR(a, n);
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//	return 0;
//}


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap * 2)
		{
			//[i,i+gap-1]  [i+gap,i+gap*2-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			int index = i;

			if (end1 >= n|| begin2>=n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			//把归并小区间拷贝回原数组
			for (int j = i; j <=end2; j++)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}

int main()
{
	int a[] = { 10 , 6  ,7 , 1 , 3  ,9,  4,6,55 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	int n = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);

	MergeSortNonR(a, n);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}













































































