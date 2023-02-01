#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
//常见排序算法的实现

//插入排序
//基本思想   --> 把待排序的记录按其关键码值的大小逐个插入到一个已经排好序的有序序列中，直到所以的记录插完为止，得到一个新的
//有序序列    --> 扑克牌就用了插入排序的思想


//插入排序  --> 时间复杂度  O（N^2）    空间复杂度 O（1）

void InsertSort(int* a, int n)
{
	assert(a);
	int end = 0;
	for (end = 0; end < n-1; end++)
	{
		int val = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > val)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}

		}
		if (end < 0)
		{
			a[end+1] = val;
		}
		else
		{
			a[end+1] = val;
		}
	}
}

//希尔排序  (缩小增量的排序)     插入排序的改进
void ShellSort(int* a, int n)
{
	//多次预排序(gap  > 1)  + 直接插入 (gap  =1)
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap越大，预排越快，越不接近有序的
		//gap越小，预排越慢，越接近有序


		//多组一锅炖    --->  间距为gap多组预排序实现了 
		//gap=3
		//2   , 4  , 6  , 2  , 3   , 8  , 6  , 9  , 10

		//第一组  : 2 2 6         --                                              
		//第二组  : 4 3 9          |-->三组一块排序     这里时间复杂度最后O（N）  最坏 F（N，gap）=(1+2+3+…+N/gap）*gap
		//第三组  : 6 8 10        --           (1+2+3+…+N/gap)的意思 gap=3 最坏情况要挪动的次数  总100个数据gap为3 总共33个数据排最后一个数据挪32次(N/gap)
		//                                                              (1 + 2 + 3 + … + N /gap)*gap总共有3组(gap为1.2.3)

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = a[end + gap];
			while (end > 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = x;
		}
	}
}



void swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//选择排序  ---> 整体而言最差的排序

//时间复杂度 O（N^2）    最好 O(N^2)
void SelectSort(int* a, int n)
{
	//一次选择2个数出来  ，  一个最大的，一个最小的
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(&a[begin], &a[mini]);
		//begin==maxi 时最大的被换走了，修正一下maxi的值
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}



//int main()
//{
//	int a[] = { 2,4,6,2,3,8,6,9,10 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	//InsertSort(a, sizeof(a) / sizeof(a[0]));
//	//ShellSort(a, sizeof(a) / sizeof(a[0]));
//	//SelectSort(a, sizeof(a) / sizeof(a[0]));
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


//大堆向下调整
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出孩子中较大的哪个
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		//如果较大的孩子大于父亲交换两位置
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	//O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

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
	HeapSort(a, n);


	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}














//int main()
//{
//	int a[] = { 2,4,6,2,3,8,6,9,10 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	InsertSort(a, sizeof(a) / sizeof(a[0]));
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

















