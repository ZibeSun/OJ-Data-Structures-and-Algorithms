#include<iostream>
using namespace std;
//带哨兵的顺序查找函数
//查找成功则返回元素在数组中的位置
//查找失败则返回0
int Sequential_Search(int* item,int n,int key)
{
	int i = n;
	item[0] = key;

	while (item[i] != key)
		i--;

	return i;
}
int main()
{
	int n;
	int t;
	int key;
	while (cin >> n)
	{
		int* item = new int[n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> item[i];
		}
		cin >> t;
		while (t--)
		{
			cin >> key;
			if (Sequential_Search(item, n, key) != 0)
				cout << Sequential_Search(item, n, key) << endl;
			else
				cout << "error" << endl;
		}
	}
}
/*
题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始
要求使用带哨兵的顺序查找算法
输入
第一行输入n，表示队列有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入t，表示有t个要查找的数值
第四行起，输入t个数值，输入t行
输出
每行输出一个要查找的数值在队列的位置，如果查找不成功，输出字符串error
样例输入
8 33 66 22 88 11 27 44 55 3 22 11 99
样例输出
3 5 error
提示
 考虑多轮输入的情况，例如while(cin>>......)

*/