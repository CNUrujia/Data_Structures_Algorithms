/*《数据结构与算法》作业0401
* created by RujiA on 2022/3/22
* 实习要求：用链表存储数据，实现对
* 线性表的增删查改操作。输入的数据
* 为“点”数据，包括：x, y, ID */

#include"LinkList.h"


int main()
{
	LinkList pl;			//链表
	int pos = 0;			//链表中的位置
	ElemType e;			//链表中的元素
	int ID = 0;			//点坐标的ID
	cout << "点的个数：";
	int num;			//输入点的个数
	cin >> num;
	pl = CreatList(num);		//使用尾插法创建链表并初始化
	PrintList(pl);
	int order = 1;
	do {
		cout << "要进行的操作：" << endl <<
			"0：退出； 1：增加点； 2：删除点； 3：查找点； 4：修改点" << endl;
		cin >> order;
		switch (order) {
		case 0:		//退出程序
			break;
		case 1:		//增加坐标操作
			cout << "增加点的位置：" << endl;
			cin >> pos;
			InputPoint(e);
			ListInsert(pl, pos, e);
			PrintList(pl);
			break;
		case 2:		//删除坐标操作
			cout << "删除点的ID" << endl;
			cin >> ID;
			ListDelete(pl, ID);
			PrintList(pl);
			break;
		case 3:		//查找坐标操作
			cout << "查找点的ID" << endl;
			cin >> ID;
			OutPoint(ListLocate(pl, ID)->data);
			break;
		case 4:		//修改坐标操作
			cout << "修改点的ID" << endl;
			cin >> ID;
			InputPoint(e);
			ListAlter(pl, ID, e);
			PrintList(pl);
			break;

		default:
			break;
		}
	} while (order);

	DestroyList(pl);
	return 0;
}

