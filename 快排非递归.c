#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int SLTDataType;

typedef struct Stack
{
	SLTDataType* a;
	int top;
	int capacity;
}ST;


void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(ST* ps, SLTDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLTDataType* tmp = realloc(ps->a, sizeof(ST) * newcapacity);
		if (tmp == 0)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->top = 0;
	ps->capacity = 0;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

SLTDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int Stacksize(ST* ps)
{
	assert(ps);
	return ps->top;
}


void swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}


int GetMidIndex(int* a, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (a[left] > a[mid])
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
	else//a[left]<a[mid]
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}


int Partion3(int* a, int left, int right)
{
	int keyi = GetMidIndex(a, left, right);
	swap(&a[keyi], &a[left]);

	int cur = left + 1;
	int prev = left;
	while (cur <= right)
	{
		if (a[cur] < a[left] && ++prev!=cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[prev], &a[left]);
	return prev;
}


void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);

		int begin = StackTop(&st);
		StackPop(&st);

		int keyi = Partion3(a, begin, end);

		//  [begin  keyi-1]  keyi  [keyi+1  end]

		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}

int main()
{
	int a[] = { 2,4,6,2,3,8 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	int n = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);

	QuickSortNonR(a, 0, n - 1);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{ 
		printf("%d ", a[i]);
	}

	return 0;
}





































