#include<iostream>
using namespace std;
void BubbleSort(int* item,int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n-1; k++)
		{
			if (item[k] >= item[k + 1])
			{
				int m = item[k];
				item[k] = item[k + 1];
				item[k + 1] = m;

				num++;   //交换次数+1
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << item[i] << " ";
	}
	cout << endl;*/
	cout << num << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		BubbleSort(item, n);
	}
}
/*
题目描述
给定一个包含从0到n-1各一次的数组，若使用冒泡排序将其排为升序，问其中需要进行多少次交换
输入
测试数据有多组，
每组由两行组成：第一行包含正整数n（n <= 5000）; 下一行包含从0到n-1的n个整数的序列。
输出
对于每组测试数据，
输出交换次数
样例输入
10
1 3 6 9 0 8 5 7 4 2
样例输出
22
提示

*/