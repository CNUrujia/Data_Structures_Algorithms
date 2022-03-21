/*《数据结构与算法》实习0202
* created by RujiA on 2022/3/21
* 实习要求：用顺序表存储数据，实现对线性表的增删查改操作
*/
#include"SqList.h"
#include<iostream>

using namespace std;
typedef int ElemType;

int main()
{
	SqList LA;
	int length;		//线性表长度
	int pos;		//元素的位置
	ElemType e;		//元素的值

	cout << "输入线性表A的元素个数N：";
	cin >> length;
	cout << endl << "输入线性表A的每个元素的值" << endl;
	CreatList_Sq(LA, length);

	cout << endl << "输出原始的线性表A的值：" << endl;
	for (int i = 0; i < LA.length; i++) {
		cout << LA.elem[i] << "	";
	}

	int Operation;
	do {
		cout << endl << endl << "对线性表A执行什么操作\n（0：退出；1：插入；2：删除；3：查找；4：逆置）：";
		cin >> Operation;
		switch (Operation) {
		case 0:			//退出
			break;
		case 1:			//插入算法
			cout << endl << endl << "输入插入元素的位置：" << endl;
			cin >> pos;

			cout << endl << endl << "插入元素的值 e = ";
			cin >> e;

			ListInsert_Sq(LA, pos, e);

			cout << endl << endl << "输出插入第" << pos << "元素后的线性表A的值：" << endl;
			for (int i = 0; i < LA.length; i++) {
				cout << LA.elem[i] << "	";
			}
			cout << endl << endl;
			break;

		case 2:			//删除算法
			cout << endl << endl << "输入删除元素的位置：" << endl;
			cin >> pos;

			ListDelete_Sq(LA, pos, e);

			cout << endl << endl << "删除的元素为：" << e;
			cout << endl << endl << "输出删除第" << pos << "元素后的线性表A的值：" << endl;
			for (int i = 0; i < LA.length; i++) {
				cout << LA.elem[i] << "	";
			}
			cout << endl << endl;
			break;
		case 3:			//查找算法
			cout << endl << endl << "输入查找元素的值：" << endl;
			cin >> e;

			pos = LocateElem_Sq(LA, e);
			if (pos == 0)
				cout << "您查找的元素不存在！！";
			else
				cout << endl << endl << "查找的元素位于：" << pos << endl;

			cout << endl << endl;
			break;
		case 4:			//逆置算法
			Invert(LA);

			cout << endl << endl << "输出逆置后的线性表A的值：" << endl;
			for (int i = 0; i < LA.length; i++) {
				cout << LA.elem[i] << "	";
			}
			cout << endl << endl;
		default:
			break;
		}
	} while (Operation);

	DestroyList_Sq(LA);
	return 0;
}