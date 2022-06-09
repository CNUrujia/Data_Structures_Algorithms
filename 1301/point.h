#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct Point {
	double dx;
	double dy;
	double dz;
	int iPointID;
}Point;

void InputData(Point& PointData)
{
	cout << "输入点号：PointID = ";
	cin >> PointData.iPointID;
	cout << "输入点坐标：X = ";
	cin >> PointData.dx;
	cout << "输入点坐标：Y = ";
	cin >> PointData.dy;
	cout << "输入点坐标：Z = ";
	cin >> PointData.dz;
	cout << endl;
}

void OutputData(Point PointData)
{
	cout << "点号：" << PointData.iPointID << "\t\t";
	cout << "点坐标 X = " << PointData.dx << "\t\t";
	cout << "点坐标 Y = " << PointData.dy << "\t\t";
	cout << "点坐标 Z = " << PointData.dz << "\t\t";
	cout << endl;
}
#pragma once
