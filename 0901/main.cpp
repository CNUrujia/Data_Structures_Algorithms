/*《数据结构与算法》实习09
* created by RujiA on 2022/4/13
* 实习要求：利用三元组顺序表的方法存储
* 稀疏矩阵，并实现矩阵的转置。
*/

#include"TSMatrix.h"

int main()
{
	while (1) {
		cout << endl << "------稀疏矩阵矩阵转置------" << endl << endl;
		ifstream fp;
		fp.open("TEST.txt");
		if (!fp) {
			cout << "没有找到数据！" << endl;
			break;
		}

		TSMatrix M;
		TSMatrix T;
		M.ReadData(fp);

		cout << endl << "原始矩阵TSMatrix M:" << endl;
		M.OutputTri();

		cout << endl << "原始矩阵的三元组顺序表：" << endl;
		M.OutputTSM();

		M.Transpose(T);

		cout << endl << "按需点菜：矩阵转置后的三元组顺序表：" << endl;
		T.OutputTSM();

		cout << endl << "按需点菜：矩阵转置后的矩阵：" << endl;
		T.OutputTri();

		M.FastTranspose(T);

		cout << endl << "按位就座：矩阵转置后的三元组顺序表：" << endl;
		T.OutputTSM();

		cout << endl << "按位就座：矩阵转置后的矩阵：" << endl;
		T.OutputTri();

		cout << endl << "------转置完成退出程序------" << endl;
		fp.close();
		break;
	}
	return 0;
}
