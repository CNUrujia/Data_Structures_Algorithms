#include<iostream>
#include<fstream>

using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int BlemType;
typedef int Status;



typedef struct {
	int i;			//行下标
	int j;			//列下标
	BlemType e;		//非零元素
}Triple;

class TSMatrix {
private:
	Triple data[MAXSIZE];
	int mu;			//行数
	int nu;			//列数
	int tu;			//非零元个数

public:
	~TSMatrix() { cout << "destory TSMatrix" << endl; }
	void ReadData(ifstream& fp);		//从文件读取数据
	void OutputTri();					//输出矩阵
	void OutputTSM();					//输出三元组
	void Transpose(TSMatrix& T);		//按需点菜
	void FastTranspose(TSMatrix& T);	//按位就座

};

void TSMatrix::ReadData(ifstream& fp)
{
	fp >> mu;
	fp >> nu;
	tu = 0;
	cout << "Non Zero Elements: " << endl;
	int m, n, p = 1;
	for (m = 0; m < mu; m++) {
		for (n = 0; n < nu; n++) {
			fp >> data[p].e;
			p++;
			if (data[p - 1].e == 0) {
				p = p - 1;
				continue;
			}
			data[p - 1].i = m;
			data[p - 1].j = n;
			cout << data[p - 1].e << "  ";

			if ((p - 1) % mu == 0)
				cout << endl;
			tu++;
		}
	}
	cout << endl;
}

void TSMatrix::OutputTri()
{
	int col, row, p = 1;
	for (col = 0; col < mu; col++) {
		for (row = 0; row < nu; row++) {
			if (p <= tu && data[p].i == col
				&& data[p].j == row) {
				cout << data[p].e << "\t";
				p++;
			}
			else
				cout << "0\t";
		}
		cout << endl;
	}
}

void TSMatrix::OutputTSM()
{
	int p;
	for (p = 1; p <= tu; p++) {
		cout << data[p].i << "\t";
		cout << data[p].j << "\t";
		cout << data[p].e << "\t";
		cout << endl;
	}
}

void TSMatrix::Transpose(TSMatrix& T)
{	//按需点菜：按一开始列的顺序，一个个转为新矩阵中行的顺序。
	T.mu = nu;
	T.nu = mu;
	T.tu = tu;
	if (T.tu) {
		int q = 1;
		for (int col = 0; col < nu; col++) {
			for (int p = 1; p <= tu; p++) {
				if (data[p].j == col) {
					T.data[q].i = data[p].j;
					T.data[q].j = data[p].i;
					T.data[q].e = data[p].e;
					q++;
				}
			}
		}
	}
}

void TSMatrix::FastTranspose(TSMatrix& T)
{	//按位就座：通过两个辅助数组，确定每一列中第一个非零元在稀疏矩阵中存储的位置。
	int num[MAXSIZE];
	int cpot[MAXSIZE];
	int col = 0, q = 0;

	T.mu = nu;
	T.nu = mu;
	T.tu = tu;
	if (T.tu) {
		for (int col = 0; col < nu; col++)
			num[col] = 0;
		for (int col = 0; col < tu; col++)
			num[data[col + 1].j]++;
		cpot[0] = 1;
		for (col = 1; col <= nu; col++)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (int p = 1; p <= tu; p++) {
			col = data[p].j;
			q = cpot[col];
			T.data[q].i = data[p].j;
			T.data[q].j = data[p].i;
			T.data[q].e = data[p].e;
			cpot[col]++;
		}
	}
}
