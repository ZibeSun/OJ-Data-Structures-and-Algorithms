#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char x;
		int n;
		cin >> x;
		cin >> n;
		if (x == 'I')
		{
			int* p = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
				sum += p[i];
			}
			cout << sum / n << endl;
		}
		else if (x == 'C')
		{
			char* p = new char[n];
			char max = 'A';
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
				if (max < p[i])
					max = p[i];
			}
			cout << max << endl;
		}
		else if (x == 'F')
		{
			float* p = new float[n];
			float min = 99999;
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
				if (min > p[i])
					min = p[i];
			}
			cout << min << endl;
		}
	}
}
/*题目描述
一开始未知数组长度，根据要求创建不同类型的指针，并且使用指针创建相应长度的数组，然后再完成不同的要求

若要求创建整数数组，计算数组内所有数据的平均值

若要求创建字符数组，找出数组内的最大字母

若要求创建浮点数数组，找出数组的最小值

要求程序整个过程不能使用数组下标，从数组创建、输入到搜索、比较、计算，到输出都必须使用指针

提示：使用new关键字

输入
第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数组类型，I表示整数类型，C表示字符类型，F表示浮点数类型；然后输入n表示数组长度。

第三行输入n个数据

依次输入t个实例

输出
每个根据不同的数组类型输出相应的结果

样例输入
3
C 5
A D E B C
I 6
22 55 77 33 88 55
F 4
3.1 1.9 6.5 4.8
样例输出
E
55
1.9*/