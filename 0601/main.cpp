/*《数据结构与算法》实习06
 * created by RujiA on 2022/3/29
 * 实习要求：用栈实现十进制转换为任意进
 * 制的数*/
#include"Stack.h"

int main()
{

	cout << endl << "-----------进制转换器-----------" << endl << endl;
	cout << "请输入要进行进制转换的十进制数字：";
	int num;
	cin >> num;
	cout << endl << "请输入您要转换后的进制(2-36进制）:";
	int order;
	cin >> order;
	cout << endl << "------------正在转换------------" << endl << endl;
	IntToOther(num, order);

	return 0;
}
