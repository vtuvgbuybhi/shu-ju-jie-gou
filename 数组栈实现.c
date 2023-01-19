#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//
//typedef int SLTDataType;
//
//typedef struct Stack
//{
//	SLTDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackPush(ST* ps, SLTDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = realloc(ps->a, sizeof(ST) * newcapacity);
//		if (tmp == 0)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
//SLTDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
//int Stacksize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//
//
//void TestStack1()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//
//
//	StackDestroy(&st);
//}
//
//
//int main()
//{
//	TestStack1();
//	return 0;
//}
































































































