#include<iostream>
using namespace std;
//希尔排序
void ShellSort(int* item,int n)
{
	int gap = n / 2;
	while (gap >= 1)
	{
		int t = gap;
		int pos = 0;
		while (t--)
		{
			for (int i = pos; i < n; i+=gap)
			{
				for (int k = pos; k < n - gap; k+=gap)
				{
					if (item[k] <= item[k + gap])
					{
						int m = item[k];
						item[k] = item[k + gap];
						item[k + gap] = m;
					}
				}
			}
			pos++;
		}

		//每趟排序完输出一次结果
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;

		gap = gap / 2;
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
		ShellSort(item, n);
		cout << endl;
	}
}
/*
题目描述
给出一个数据序列，使用希尔排序算法进行降序排序。
间隔gap使用序列长度循环除2直到1
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
111 22 6 444 333 55
8
77 555 33 1 444 77 666 2222
样例输出
444 333 55 111 22 6
444 333 111 55 22 6

444 555 666 2222 77 77 33 1
666 2222 444 555 77 77 33 1
2222 666 555 444 77 77 33 1
提示

*/