#include<iostream>
#include<stdio.h>
#include <iomanip>
#include<math.h>
using namespace std;
class Point
{
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	~Point();
	double getX();
	double getY();
	void setXY(double x1, double y1);
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(Point& p);
	Point(Point& p);
};
Point::Point()
{
	x = 0;
	y = 0;
	cout << "Constructor." << endl;
}
Point::Point(double x_value, double y_value)
{
	x = x_value;
	y = y_value;
}
Point::~Point()
{
	cout << "Distructor." << endl;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
void Point::setXY(double x1, double y1)
{
	x = x1;
	y = y1;
}
void Point::setX(double x_value)
{
	x = x_value;
}
void Point::setY(double y_value)
{
	y = y_value;
}
double Point::getDisTo(Point& p)
{
	double distance;
	distance = sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
	return distance;
}
Point::Point(Point &p)
{
	x = p.getX();
	y = p.getY();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Point *p = new Point[n];
		double x_value, y_value;
		for (int i = 0; i < n; i++)
		{
			cin >> x_value >> y_value;
			p[i].setXY(x_value, y_value);
		}
		double maxdis = 0;
		int p1 = 0, p2 = 0;
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				if (maxdis < p[k].getDisTo(p[i]))
				{
					maxdis = p[k].getDisTo(p[i]);
					p1 = k;
					p2 = i;
				}
			}
		}
		cout << fixed << setprecision(2) << "The longeset distance is " << maxdis <<
			",between p[" << p1 << "] and p[" << p2 << "]." << endl;
		delete[]p;
	}
}
/*题目描述


上面是我们曾经练习过的一个习题，请在原来代码的基础上作以下修改：1、增加自写的拷贝构造函数；2、增加自写的析构函数；3、将getDisTo方法的参数修改为getDisTo(const Point &p)；4、根据下面输出的内容修改相应的构造函数。

然后在主函数中根据用户输入的数目建立Point数组，求出数组内距离最大的两个点之间的距离值。

输入
测试数据的组数 t

第一组点的个数

第一个点的 x 坐标   y坐标

第二个点的 x坐标  y坐标

............

输出
输出第一组距离最大的两个点以及其距离

...........

在C++中，输出指定精度的参考代码如下：

#include <iostream>

#include <iomanip> //必须包含这个头文件

using namespace std;

void main( )

{ double a =3.141596;

  cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位

样例输入
2
4
0 0
5 0
5 5
2 10
3
-1 -8
0 9
5 0
样例输出
Constructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 10.44,between p[1] and p[3].
Distructor.
Distructor.
Distructor.
Distructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 17.03,between p[0] and p[1].
Distructor.
Distructor.
Distructor.*/