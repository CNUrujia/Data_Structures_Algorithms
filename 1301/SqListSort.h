#include<iostream>
#include"point.h"

#define MAXSIZE 20


typedef struct {
	Point r[MAXSIZE + 1];
	int iLength;
} SqList;


void InitList_Sq(SqList& L)
{
	L.iLength = 0;
}

void DestroyList_Sq(SqList& L)
{
	L.iLength = 0;
}

void CreatList(SqList& L, int n)
{
	InitList_Sq(L);
	for (int i = 1; i <= n; i++) {
		InputData(L.r[i]);
		L.iLength++;
	}
}

void PrintList(SqList& L)
{
	for (int i = 1; i <= L.iLength; ++i) {
		OutputData(L.r[i]);
	}
}

//========直接插入排序========
void InsertSort(SqList& L)
{	
	int i, j;
	for (i = 2; i <= L.iLength; ++i) {
		if (L.r[i].iPointID < L.r[i - 1].iPointID) {
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[0].iPointID < L.r[j].iPointID; --j)
				L.r[j + 1] = L.r[j];
			L.r[j + 1] = L.r[0];
		}
	}
}

//========冒泡排序========
typedef enum { FALSE, TRUE } Boolean;  //FALSE为0，TRUE为1
void BubbleSort(SqList& L) {             //自下向上扫描对L做冒泡排序
	int i, j;     Boolean exchange;
	for (i = 1; i < L.iLength; i++) {
		exchange = FALSE;
		//对当前无序区L[i..n]进行扫描
		for (j = L.iLength - 1; j >= i; j--) {
			if (L.r[j + 1].dx < L.r[j].dx) {
				Point temp;
				temp = L.r[j + 1];
				L.r[j + 1] = L.r[j];
				L.r[j] = temp;
				exchange = TRUE;
			}
			else if (L.r[j + 1].dx == L.r[j].dx)
				if (L.r[j + 1].dy < L.r[j].dy) {
					Point temp;
					temp = L.r[j + 1];
					L.r[j + 1] = L.r[j];
					L.r[j] = temp;
					exchange = TRUE;
				}
		}
		if (!exchange)           //本趟排序未发生交换，提前终止算法
			return;
	}
}

//1.========划分函数=======
int Partition(SqList L, int i, int j)
{   //对R[i..j]做一次划分，并返回基准记录的位置
	Point pivot = L.r[i];       //用第一个记录作为基准
	while (i < j) {
		while (i < j && L.r[j].iPointID >= pivot.iPointID)
			j--;
		if (i < j)
			L.r[i++] = L.r[j];
		while (i < j && L.r[i].iPointID <= pivot.iPointID)
			i++;
		if (i < j)
			L.r[j--] = L.r[i];
	}
	L.r[i] = pivot;
	return i;
}
//2.=========快速排序========
void QuickSort(SqList L, int low, int high)
{   //R[low..high]快速排序
	int pivotpos;            //划分后基准记录的位置
	if (low < high) {           //仅当区间长度大于1时才排序
		pivotpos = Partition(L, low, high);  //对R[low..high]做一次划分，得到基准记录的位置
		QuickSort(L, low, pivotpos - 1);
		QuickSort(L, pivotpos + 1, high);
	}
}



#pragma once
