#include <iostream>

using namespace std;

typedef struct Point
{
    double x;
    double y;
    int ID;
    Point()
    {
        x = 0.00;
        y = 0.00;
        ID = 10000;
    }
}Point;

void InputPoint(Point& P)
{
    cout << "输入点的x坐标" << endl;
    cin >> P.x;
    cout << "输入点的y坐标" << endl;
    cin >> P.y;
    cout << "输入点的ID" << endl;
    cin >> P.ID;
}

void OutPoint(Point P)
{
    cout << "点坐标为(" << P.x << "," << P.y << ")" << endl;
    cout << "ID:" << P.ID << endl;
}
