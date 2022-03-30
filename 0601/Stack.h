#include <iostream>
using namespace std;


#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef char ElemType;
typedef int Status;

typedef struct Stack
{
	ElemType* base;
	ElemType* top;
	int size;
};

Status InitStack(Stack& L);
Status DestroyStack(Stack& L);
Status GetTop(const Stack L, ElemType e);
Status Push(Stack& L, ElemType e);
Status Pop(Stack& L, ElemType& e);
void IntToOther(int num, int e);

Status InitStack(Stack& L)
{
	L.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!L.base)
		return ERROR;
	L.top = L.base;
	L.size = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(Stack& L)
{
	L.top = NULL;
	free(L.base);
	L.size = 0;
	return OK;
}

Status GetTop(const Stack L, ElemType e)
{
	if (L.top == L.base)
		return ERROR;
	e = *(L.top - 1);
	return OK;
}

Status Push(Stack& L, ElemType e)
{
	if (L.top - L.base >= L.size) {
		L.base = (ElemType*)realloc(L.base, (L.size + STACKINCREMENT) * sizeof(ElemType));
		if (!L.base)
			return ERROR;
		L.top = L.base + STACK_INIT_SIZE;
		L.size += STACKINCREMENT;
	}
	*L.top = e;
	L.top++;
	return OK;
}

Status Pop(Stack& L, ElemType& e)
{
	if (L.top == L.base)
		return ERROR;
	L.top--;
	e = *L.top;
	return OK;
}


void IntToOther(int num, int r)
{
	Stack ito;
	InitStack(ito);
	ElemType e;
	if (!r) {
		cout << "转换进制错误！！" << endl;
		return;
	}
	do {
		if (num % r > 9)
			Push(ito, num % r + 55);
		else
			Push(ito, num % r + 48);
		num = num / r;
	} while (num);
	cout << "转换为" << r << "进制: ";
	while (ito.top != ito.base) {
		Pop(ito, e);
		cout << e;
	}
	cout << endl;
}
#pragma once
