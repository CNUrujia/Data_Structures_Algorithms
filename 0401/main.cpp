/*《数据结构与算法》作业0401
* created by RujiA on 2022/3/22
* 实习要求：用链表存储数据，实现对
* 线性表的增删查改操作。输入的数据
* 为“点”数据，包括：x, y, ID */

#include"LinkList.h"


int main()
{
	LinkList p1;			//链表1
	LinkList p2;			//链表2
	LinkList p3;			//链表3
	int pos = 0;			//链表中的位置
	ElemType e;			//链表中的元素
	int ID = 0;			//点坐标的ID


	cout << "第一个链表点的个数：";
	int num;			//输入点的个数
	cin >> num;
	p1 = CreatList(num);		//使用尾插法创建链表并初始化
	PrintList(p1);

	cout << "第二个链表点的个数：";
	cin >> num;
	p2 = CreatList(num);		//使用尾插法创建链表并初始化
	PrintList(p2);

	while (1) {			//输入不符合的命令则从此循环
		cout << "是否连接两个链表？y/n:";
		char ch;
		cin >> ch;
		if (ch == 'y') {
			p3 = ConnectList(p1, p2);		//连接链表
			PrintList(p3);
			break;
		}
		else if (ch == 'n') {
			cout << "接下来操作哪个链表？1/2:";
			cin >> ch;
			if (ch == '1') {
				p3 = p1;
				break;
			}	
			else if (ch == '2') {
				p3 = p2;
				break;
			}
		}
	}
	
	int order = 1;
	do {
		cout << endl << "要进行的操作：" << endl <<
			"0：退出； 1：增加点； 2：删除点； 3：查找点； 4：修改点" << endl;
		cin >> order;
		switch (order) {
		case 0:		//退出程序
			break;
		case 1:		//增加坐标操作
			cout << "增加点的位置：" << endl;
			cin >> pos;
			InputPoint(e);
			ListInsert(p3, pos, e);
			PrintList(p3);
			break;
		case 2:		//删除坐标操作
			cout << "删除点的ID" << endl;
			cin >> ID;
			ListDelete(p3, ID);
			PrintList(p3);
			break;
		case 3:		//查找坐标操作
			cout << "查找点的ID" << endl;
			cin >> ID;
			OutPoint(ListLocate(p3, ID)->data);
			break;
		case 4:		//修改坐标操作
			cout << "修改点的ID" << endl;
			cin >> ID;
			InputPoint(e);
			ListAlter(p3, ID, e);
			PrintList(p3);
			break;

		default:
			break;
		}
	} while (order);

	DestroyList(p1);
	DestroyList(p2);
	DestroyList(p3);
	return 0;
}

