#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

//ð������

void swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}


//ʱ�临�Ӷ� �����O��N^2��  ��õ����O��N��
//void BubbleSort(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		
//		int exchang = 0;//�Ż�
//
//		for (int j = i; j < n - i-1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				exchang = 1;
//				swap(&a[j], &a[j + 1]);
//			}
//		}
//		//˵��ð����һȦ��û�з������� ��������������ģ���û��Ҫ�ڽ��к����ð��������
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


//��������

//һ��ѡ������߻����ұߵ�ֵ��Ϊkey
//���������Ŀ��  : ��ߵ�ֵ��keyС���ұߵ�ֵ��key��   --> ��ߵ�ֵ��key�����ұ�����-->��������ʱ��keyС

//ʱ�临�Ӷ�O��N��
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
////ʱ�临�Ӷ� O(N*logN)    ����  : O(N^2)
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int keyi = Partion(a, left, right);
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi + 1, right);
//}//Ŀǰ��ȱ��  : �ӽ�����Ļ������׵���ջ���  (Խ��Խ�죬Խ����Խ��)

//�ݹ�����ȱ��
//1. ���ѭ���������ܲ� (������ڱ��������������ӵģ���Ϊ���ڵݹ���ã�����ջ֡�Ż����������±������Ż����ܺã��ݹ������ѭ�����ܲ�˶���)
//2.�ݹ����̫��ᵼ��ջ���


//��ν������������������ѡkey����  : 1.���ѡkey  2.����ȡ��(��ߣ��м䣬�ұ�)

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
//	//����ȡ��
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
////ʱ�临�Ӷ� O(N*logN)    ����  : O(N^2)
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



//�ڿӷ�
//int Partion2(int* a, int left, int right)
//{
//	int mid = GetMidIndex(a, left, right);
//	swap(&a[left], &a[mid]);
//
//	int key = a[left];
//	int pivot = left;
//	while (left < right)
//	{
//		//�ұ���С���ŵ���ߵĿ���
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


//ǰ��ָ��


//��ʼ���
//          cur-->�����ұ�keyС����(�ҵ���  prev++   -->  ������λ�õ�ֵ)
//    6      1      2       7       9      3        4        5       10       8    //��6Ϊkey
//  prev
//
////prev++  ������λ�õ�ֵ cur��ǰ�ߣ������ұ�keyС����
//		    cur
//    6      1      2       7       9      3        4        5       10       8    //��6Ϊkey
//          prev
//
////�ҵ���
//	               cur
//    6      1      2       7       9      3        4        5       10       8    //��6Ϊkey
//		    prev
//
////prev++  ������λ�õ�ֵ
//			       cur
//    6      1      2       7       9      3        4        5       10       8    //��6Ϊkey
//			       prev
//
////�ҵ���
//                                        cur
//    6      1      2       7       9      3        4        5       10       8    //��6Ϊkey
//			      prev
//
////  prev++  ��������λ�õ�ֵ
//                                         cur
//    6      1      2       3       9      7        4        5       10       8    //��6Ϊkey
//			              prev
//
////cur������ǰ��  --> �ҵ���
//                                                cur
//   6      1      2       3       9      7        4        5       10       8    //��6Ϊkey
//			             prev
// 
////  prev++  ��������λ�õ�ֵ
//			                                     cur
//   6      1      2       3       4      7        9        5       10       8    //��6Ϊkey
//			                     prev
//
////cur������ǰ��   --> �ҵ���
//                                                         cur
//   6      1      2       3       4      7        9        5       10       8    //��6Ϊkey
//                                prev
//
////  prev++  ��������λ�õ�ֵ
//			                                               cur
//   6      1      2       3       4      5        9        7       10       8    //��6Ϊkey
//			                            prev
////cur�������ߵ�����
//                                                                          cur
//   6      1      2       3       4       5        9        7       10       8    //��6Ϊkey
//                                        prev
////������ʼλ�ú�prev��ֵ������Ҫprev++��
//                                                                           cur
//   5      1      2       3       4       6        9        7       10       8    //��6Ϊkey
//                                        prev
//
//
//
////���ұ�Ϊ��׼��
//
////��ʼλ��
//    cur-- > �����ұ�keyС����(�ҵ���  prev++   -- > ������λ�õ�ֵ)
//     8      1      2       7       9      3        4        5       10       6    //��6Ϊkey
//prev
//
////�ҵ���  prev++ ��������λ�õ�ֵ
//           cur
//     8      1      2       7       9      3        4        5       10       6    //��6Ϊkey
//prev
//
////cur����������
//           cur
//     1      8      2       7       9      3        4        5       10       6    //��6Ϊkey
//    prev
////�ҵ���  prev++ ��������λ�õ�ֵ
//			      cur
//     1      8      2       7       9      3        4        5       10       6    //��6Ϊkey
//    prev
//
////cur���������
//			     cur
//	1      2      8       7       9      3        4        5       10       6    //��6Ϊkey
//		  prev
// 
////�ҵ���  prev++ ��������λ�õ�ֵ
//			                            cur
//	1      2      8       7       9      3        4        5       10       6    //��6Ϊkey
//		  prev
//
////cur������ǰ��
//			                              cur
//    1      2      3       7       9      8        4        5       10       6    //��6Ϊkey
//			      prev
//
////    ������������
////cur�ߵ�6��λ��ʱ
//                                                                           cur
//    1      2      3       4       5      8        7        9       10       6    //��6Ϊkey
//                                 prev
////���prev++  ����curλ���ϵ�ֵ
//                                                                          cur
//   1      2      3       4       5      6        7        9       10       8    //��6Ϊkey
//                                       prev


//�Լ�д��  --> ������
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

//��ʦ��д��
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






































