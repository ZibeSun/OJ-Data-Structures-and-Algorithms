#include<iostream>
using namespace std;
//直接插入排序
void StraightInsertSort(int* item, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k] <= item[k - 1])
			{
				int m = item[k];
				item[k] = item[k - 1];
				item[k - 1] = m;
			}
			else
				break;
		}

		//每趟排序后输出一次结果
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	int* item = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	StraightInsertSort(item, n);
}
/*
题目描述
给定一组数据，使用直插排序完成数据的升序排序。
--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
数据个数n，n个数据
输出
直插排序的每一趟排序结果
样例输入
7 34 23 677 2 1 453 3
样例输出
23 34 677 2 1 453 3
23 34 677 2 1 453 3
2 23 34 677 1 453 3
1 2 23 34 677 453 3
1 2 23 34 453 677 3
1 2 3 23 34 453 677
提示

*/