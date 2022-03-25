#include <iostream>
#include "Point.h"

using namespace std;

typedef Point ElemType;

typedef struct LNode
{
	ElemType data; 					//链表的组成元素
	LNode* next;  					 //下一个指针
} LNode;
typedef LNode* LinkList; 				// 自定义LinkList单链表类型


LinkList CreatList(int n);				//创建线性表并初始化
void ListInsert(LinkList& L, int n, ElemType e);	//按位置增加元素
void ListDelete(LinkList& L, int ID);			//按值删除元素
LinkList ListLocate(LinkList L, int ID);		//按值查找元素
void ListAlter(LinkList& L, int ID, ElemType e);	//按值修改元素
void PrintList(LinkList L);				//打印线性表
void DestroyList(LinkList& L);				//摧毁线性表
LinkList ConnectList(LinkList L1, LinkList L2);		//连接两个链表

LinkList CreatList(int n)
{
	LinkList L, p, r;
	L = new LNode;
	L->next = NULL;			//初始化链表
	p, r = L;
	for (int i = 0; i < n; i++) {
		p = new LNode;
		InputPoint(p->data);
		r->next = p;
		r = p;
	}				//通过尾插法创建链表
	r->next = NULL;
	return L;			//返回链表L
}

void PrintList(LinkList L)
{
	if (L == NULL) {
		cout << "输出失败" << endl;
		return;
	}
	LinkList p = L->next; 		//从开始结点打印
	while (p) {
		OutPoint(p->data);
		p = p->next;
	}
	cout << endl;
}

void DestroyList(LinkList& L)
{
	LinkList p = L->next;
	while (p) {
		L->next = p->next;
		delete p;
		p = L->next;
	}
	delete L;
}

void ListDelete(LinkList& L, int ID)
{
	LinkList p = L;
	while (p->next) {
		if (ID == p->next->data.ID) {
			p->next = p->next->next;
			p = L;
			continue;
		}
		p = p->next;
	}
}

LinkList ListLocate(LinkList L, int ID)
{
	LinkList p = L->next;       		 //从第1个结点开始查找数据为ID的结点
	while (p && p->data.ID != ID)
		p = p->next;
	return p;       			 //找到后返回该结点指针，否则返回NULL
}

void ListInsert(LinkList& L, int n, ElemType e)
{
	LinkList p = L;
	int i = 0;
	while (p && i < n - 1) {		//找到增加位置的前一个节点位置
		p = p->next;
		i++;
	}
	if (!p || i > n - 1) {
		cout<<"找不到可插入的位置！";
		return;
	}
	LinkList s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;				//在第i位上插入增加元素的结点
}

void ListAlter(LinkList& L, int ID, ElemType e)
{
	LinkList p = L->next;       		 //从第1个结点开始查找数据为ID的结点
	while (p && p->data.ID != ID)
		p = p->next;
	p->data = e;
}

LinkList ConnectList(LinkList L1, LinkList L2)
{
	LinkList p = L1;
	while (p->next)
		p = p->next;
	p->next = L2->next;
	return L1;
}
