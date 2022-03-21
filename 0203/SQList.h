#define TRUE 1
#define FALSE 0
#define  OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define  LIST_INIT_SIZE 100  
#define  LISTINCREMENT 10 
typedef int ElemType;
typedef int Status;

#include<iostream>

using namespace std;

typedef struct
{
	ElemType* elem;		//存储空间基址
	int length;			//长度
} SqList;

void InitList_Sq(SqList& L)
{						//初始化顺序表
	L.elem = new ElemType[LIST_INIT_SIZE];		//为线性表分配容量为LIST_INIT_SIZE大小
	L.length = 0;								//长度为0
}	// InitList_Sq

void DestroyList_Sq(SqList& L)
{					//释放顺序表
	delete[] L.elem;						//释放内存
	L.length = 0;							//长度恢复0
}	// DestroyList_Sq

void CreatList_Sq(SqList& L, int Length)
{					//向顺序表赋值
	int i = 0;
	InitList_Sq(L);						//初始化顺序表L
	for (i = 1; i <= Length; i++) {
		cout << "请输入第" << i << "个元素的值：";
		cin >> L.elem[i - 1];
		L.length++;
	}
}	// CteatList_Sq


void Invert(SqList & L)
{				//逆置顺序表
	ElemType temp;											//转换时中间值
		for (int i = 0; i < L.length/ 2; i++) {
			temp = L.elem[i];								//将第一项元素给中间值
			L.elem[i] = L.elem[L.length - i - 1];		    //将最后一项元素给第一项
			L.elem[L.length - i - 1] = temp;			    //将中间值给最后一项元素
		}
}	// Invert


void ListInsert_Sq(SqList& L, int pos, ElemType e)
{				//向顺序表插入元素
	if (pos<1 || pos>L.length + 1) {			//位置不能比第一项还前不能比最后一项后一项还后
		cout << "插入元素的位置信息错误";
		return;
	}
	for (int j = L.length - 1; j >= pos - 1; --j) {
		L.elem[j + 1] = L.elem[j];		        //将插入元素后面的元素向后位移一项
	}
	L.elem[pos - 1] = e;
	++L.length;				                    //插入一项后顺序表长度加1
}	// ListInsert_Sq

void ListDelete_Sq(SqList& L, int pos, ElemType &e)
{				//顺序表中删除元素
	if (pos < 1 || pos > L.length) {		//删除的元素位置要存在
		cout << "删除元素的位置信息错误";
		return;
	}
	e = L.elem[pos - 1];			    	//将该位置的元素提取并保存在e中
	for (int j = pos; j < L.length; ++j) {
		L.elem[j - 1] = L.elem[j];	    	//将删除项后面的元素向前位移一项
	}
	--L.length;			                    //删除后顺序表长度减1
}	//ListDelete_Sq

int LocateElem_Sq(SqList& L, ElemType e)
{				//顺序表中查找元素
	for (int i = 0; i <= L.length; i++) {			//通过循环一项一项查找元素
		if (L.elem[i] == e) {
			return i+1;			                    //如果列表中元素值与e相同，则返回计算机显示的位置（即为列表位置+1）
		}
	}
	return 0;		                            	//如果超出顺序表长度则返回值0
}	//LocateElem_Sq