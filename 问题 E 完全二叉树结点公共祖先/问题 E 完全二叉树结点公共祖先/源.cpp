#include<iostream>
#include<cmath>
using namespace std;
//寻找顺序存储的完全二叉树两结点的最近公共祖先
int LCA(int a,int b)
{
	//计算两结点的深度
	int ka = (int)log2(a) + 1;
	int kb = (int)log2(b) + 1;
	
	if (ka == kb)//两结点在同一层
	{
		int pa = a;
		int pb = b;
		while (pa!=pb)
		{
			pa = pa / 2;
			pb = pb / 2;
		}
		return pa;
	}
	else//两结点在不同层
	{
		int pa = a;
		int pb = b;
		if (ka > kb)
		{
			for (int i = 0; i < ka - kb; i++)
			{
				pa = pa / 2;
			}

			if (pa == pb)
				return pa;

			while (pa != pb)
			{
				pa = pa / 2;
				pb = pb / 2;
			}
			return pa;
		}
		else if (ka < kb)
		{
			for (int i = 0; i < kb - ka; i++)
			{
				pb = pb / 2;
			}

			if (pa == pb)
				return pa;

			while (pa != pb)
			{
				pa = pa / 2;
				pb = pb / 2;
			}
			return pa;
		}
	}
}
int main()
{
	int i;
	int j;
	while (cin >> i >> j)
	{
		cout << LCA(i, j) << endl;
	}
}
/*
题目描述
一个顺序存储的完全二叉树：

任意给定两结点的编号，求两结点最近的公共祖先。
输入
每组数据一行，为空格隔开的两个数i和j，皆为32位有符号正整数
输出
每组数据对应一行，为给出的两个结点的最近公共祖先的编号
样例输入
4 5
4 7
样例输出
2
1
提示

*/