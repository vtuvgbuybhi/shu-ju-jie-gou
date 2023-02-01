#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
//���������㷨��ʵ��

//��������
//����˼��   --> �Ѵ�����ļ�¼����ؼ���ֵ�Ĵ�С������뵽һ���Ѿ��ź�������������У�ֱ�����Եļ�¼����Ϊֹ���õ�һ���µ�
//��������    --> �˿��ƾ����˲��������˼��


//��������  --> ʱ�临�Ӷ�  O��N^2��    �ռ临�Ӷ� O��1��

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

//ϣ������  (��С����������)     ��������ĸĽ�
void ShellSort(int* a, int n)
{
	//���Ԥ����(gap  > 1)  + ֱ�Ӳ��� (gap  =1)
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gapԽ��Ԥ��Խ�죬Խ���ӽ������
		//gapԽС��Ԥ��Խ����Խ�ӽ�����


		//����һ����    --->  ���Ϊgap����Ԥ����ʵ���� 
		//gap=3
		//2   , 4  , 6  , 2  , 3   , 8  , 6  , 9  , 10

		//��һ��  : 2 2 6         --                                              
		//�ڶ���  : 4 3 9          |-->����һ������     ����ʱ�临�Ӷ����O��N��  � F��N��gap��=(1+2+3+��+N/gap��*gap
		//������  : 6 8 10        --           (1+2+3+��+N/gap)����˼ gap=3 ����ҪŲ���Ĵ���  ��100������gapΪ3 �ܹ�33�����������һ������Ų32��(N/gap)
		//                                                              (1 + 2 + 3 + �� + N /gap)*gap�ܹ���3��(gapΪ1.2.3)

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

//ѡ������  ---> ���������������

//ʱ�临�Ӷ� O��N^2��    ��� O(N^2)
void SelectSort(int* a, int n)
{
	//һ��ѡ��2��������  ��  һ�����ģ�һ����С��
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
		//begin==maxi ʱ���ı������ˣ�����һ��maxi��ֵ
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


//������µ���
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ������нϴ���ĸ�
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		//����ϴ�ĺ��Ӵ��ڸ��׽�����λ��
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

















