#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����һ������nums��һ��ֵval������Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³���
//��Ҫʹ�ö��������ռ�



//˼·1  : �ҵ��˵���val������ֱ�ӽ����������ǰŲ�������滻
//ʱ�临�Ӷ�O��N^2��  �ռ临�Ӷ�O��1��
//int NumEraseVal(int* ps, int val,int sz)
//{
//	int i = 0;
//	while (i < sz)
//	{
//		if (ps[i] == val)
//		{
//			for (int j = i + 1; j < sz; j++)
//			{
//				ps[j - 1] = ps[j];
//			}
//			sz--;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return sz;
//}
//
//int main()
//{
//	int num[8] = { 1,2,2,3,4,5,2 ,8};
//	int sz = sizeof(num) / sizeof(num[0]);
//
//	int sum = NumEraseVal(num, 2,sz);
//
//	printf("%d ", sum);
//	return 0;
//}


//˼·2:  ����һ�������飬������Ų����ڲ��ҵ�ֵ��Ȼ���ڽ�ԭ��������滻
//ʱ�临�Ӷ���O��N��  �ռ临�Ӷ�O��N��-->�Կռ任ʱ��

//int SumEraseVal(int* ps, int val, int sz)
//{
//	int tmp[6] = { 0 };
//	int j = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (ps[i] != val)
//		{
//			tmp[j] = ps[i];
//			j++;
//		}
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		ps[i] = tmp[i];
//	}
//	return j;
//}
//int main()
//{
//	int sum[6] = { 1,2,2,3,4,6 };
//	int sz = sizeof(sum) / sizeof(sum[0]);
//
//	int num = SumEraseVal(sum, 2, sz);
//	printf("%d ", num);
//
//	return 0;
//}


//˼·3  :  ˫ָ��ķ���
//int SumEraseVal(int* ps, int val, int sz)
//{
//	int src = 0;
//	int dst = 0;
//	while (src < sz)
//	{
//		if (ps[src] != val)
//		{
//			ps[dst] = ps[src];
//			src++;
//			dst++;
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return dst;
//}
//
//
//int main()
//{
//	int sum[5] = { 1,2,2,3,4 };
//	int sz = sizeof(sum) / sizeof(sum[0]);
//	int num = SumEraseVal(sum,2, sz);
//
//	printf("%d ", num);
//
//	return 0;
//
//}


//��һ���������� nums������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ���������ɾ����ĳ���
//��Ҫʹ�ö���Ŀռ�

//int NumsPop(int* ps, int sz)
//{
//	int i = 0;
//	int j = 1;
//	int dst = 0;
//	while (j < sz)
//	{
//		if (ps[i] == ps[j])
//		{
//			j++;
//		}
//		else
//		{
//			ps[dst] = ps[i];
//			dst++;
//			i = j;
//			j++;
//		}
//	}
//	ps[dst] = ps[i];
//	dst++;
//	return dst;
//}
//int main()
//{
//	int nums[7] = {1,2,2,3,4,4,5};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int newsz = NumsPop(nums, sz);
//	printf("ɾ���ظ�Ԫ�غ����鳤��:%d", newsz);
//	return 0;
//}




//int  NumsPop(int* ps, int sz)
//{
//	int i = 0, j = 1;
//	while (j < sz)
//	{
//		if (ps[i] != ps[j])
//		{
//			i++;
//			ps[i] = ps[j];
//			j++;
//		}
//		else
//		{
//			j++;
//		}
//	}
//	return ++i;
//}
//
//int main()
//{
//	int nums[6] = {1,2,2,3,4,4};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int newsz = NumsPop(nums, sz);
//	printf("ɾ���ظ�Ԫ�غ����鳤��:%d", newsz);
//	return 0;
//}




//����nums1={1,2,3,0,0,0}   m=3       nums2.={2,5,6}   n=3     ���ϲ�
//���   nums1={1��2��2��3��5��6}
//
//int main()
//{
//	int nums1[7] = {1,2,3,8,0,0,0};
//	int nums2[3] = { 2,5,6 };
//	int m = 4, n = 3;
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = m + n - 1;
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//	if (end2 > 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", nums1[i]);
//	}
//}




















