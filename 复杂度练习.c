#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//��ʧ������

//����num������0��n������������������ȱ��һ�������д�����ҳ�ȱ������������O��n��ʱ�������

//˼·1  : ���� --�� ��������ʱ�临�Ӷ�O(n*log N(��2Ϊ��))
//����������������   �ҳ��������1��ֵ  ��ô��һ��������ȱ����
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
//			printf("ȱ������:%d ", arr[i] - 1);
//		}
//	}
//	return 0;
//}


//˼·2   :   (0+1+2����+n)-(arr[0]+arr[1]+����+arr[n-1])
//����õ���������ȱ����

//ʱ�临�Ӷ� O��N��    �ռ临�Ӷ�O(1)

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
//	printf("ȱ������:%d ", sum);
//	return 0;
//}


//˼·3: ��һ��ֵx=0
//      x�ȸ�[0,n]������ֵ���
//      x�ڸ�������ÿһ��ֵ������x����ȱ���Ǹ�����

//ʱ�临�Ӷ�:O(N)    ʱ�临�Ӷ�: O(1)
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
//	printf("ȱ������:%d ", x);
//	return 0;
//}


//��ת����
//����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����k���ǷǸ���
//�ռ临�Ӷ�ΪO��1��

//˼·1  : ������⣬��תk��
//ʱ�临�Ӷ� :O(N*K)   �ռ临�Ӷ�:O(1)
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < 3; i++)//��ת3��
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


//˼·2  : ���ٶ���Ŀռ�  --�� �Կռ任ʱ��
//ʱ�临�Ӷ�  O(N)  �ռ临�Ӷ� O(N)

//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int arr1[5] = { 0 };
//	for (int i = 0; i < sz; i++)//��ת3��
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


//˼·3  : �ǳ�������㷨
//ǰn-k������     ��k������     ��������
   
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






















