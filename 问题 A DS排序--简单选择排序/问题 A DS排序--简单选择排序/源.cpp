#include<iostream>
using namespace std;
//简单选择排序
void SelectSort(int* item, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int k = i+1; k < n; k++)
		{
			if (item[k] < item[min])
			{
				min = k;
			}
		}

		int m = item[i];
		item[i] = item[min];
		item[min] = m;

		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		SelectSort(item, n);
		cout << endl;
	}
}
/*
题目描述
给出一个数据序列，使用简单选择排序算法进行升序排序
输入
第一行输入t，表示有t个测试示例
第二行输入n，表示第一个示例有n个数据(n>1)
第三行输入n个数据，都是正整数，数据之间用空格隔开
以此类推
输出
 对每组测试数据，输出每趟排序结果。不同组测试数据间用空行分隔。
样例输入
2
6
21 25 49 25 16 8
8
30 13 70 85 39 42 6 20
样例输出
8 25 49 25 16 21
8 16 49 25 25 21
8 16 21 25 25 49
8 16 21 25 25 49
8 16 21 25 25 49
8 16 21 25 25 49

6 13 70 85 39 42 30 20
6 13 70 85 39 42 30 20
6 13 20 85 39 42 30 70
6 13 20 30 39 42 85 70
6 13 20 30 39 42 85 70
6 13 20 30 39 42 85 70
6 13 20 30 39 42 70 85
6 13 20 30 39 42 70 85
提示

*/