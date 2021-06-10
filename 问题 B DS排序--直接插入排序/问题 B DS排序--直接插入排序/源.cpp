#include<iostream>
using namespace std;
//直接插入排序
void StraightInsertSort(int* item,int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k] <= item[k-1])
			{
				int m = item[k];
				item[k] = item[k-1];
				item[k-1] = m;
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
		StraightInsertSort(item, n);
		cout << endl;
	}
}
/*
题目描述
给出一个数据序列，使用直接插入排序算法进行降序排序。
输入
第一行输入t，表示有t个测试示例
第二行输入n，表示第一个示例有n个数据(n>1)
第三行输入n个数据，都是正整数，数据之间用空格隔开
以此类推
输出
对每组测试数据，输出每趟排序结果。不同组测试数据间用空行分隔。
样例输入
2
5
111 22 6 444 333
6
21 25 49 25 16 8
样例输出
22 111 6 444 333
6 22 111 444 333
6 22 111 444 333
6 22 111 333 444

21 25 49 25 16 8
21 25 49 25 16 8
21 25 25 49 16 8
16 21 25 25 49 8
8 16 21 25 25 49
提示

*/