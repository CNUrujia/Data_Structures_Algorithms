/*《数据结构与算法》第15周实习
* 
* created by RujiA on 2022/06/09
* 
* 实习要求：请在给定的参考程序文件基础上，
* 进一步将原普通数据类型的数据改编为地理坐
* 标数据，选用合适的存储方式，存储坐标数据
* （ID，X，Y），并选用直接插入排序、冒泡排
* 序、快速排序、简单选择排序法等以ID为关键
* 字进行排序，并输出结果。若有兴趣可以进一
* 步以（X，Y）双关键字进行排序。
*/

#include"SqListSort.h"

int main()
{
	SqList L;
	int n;

	cout << endl << "输入记录的个数n = ";
	cin >> n;
	CreatList(L, n);

	cout << endl << "排序前的记录" << endl;
	PrintList(L);

	cout << endl << endl << "以ID为关键字进行直接插入排序";
	InsertSort(L);
	cout << endl << "排序后的记录" << endl;
	PrintList(L);
	cout << endl;

	cout << endl << endl << "以ID为关键字进行快速排序";
	QuickSort(L, 1, n);
	cout << endl << "排序后的记录" << endl;
	PrintList(L);
	cout << endl;

	cout << endl << endl << "以(x,y)为双关键字进行冒泡排序";
	BubbleSort(L);
	cout << endl << "排序后的记录" << endl;
	PrintList(L);
	cout << endl;

	DestroyList_Sq(L);

	cout << "Print any key: ";
	char a;
	cin >> a;

	return 0;
}
