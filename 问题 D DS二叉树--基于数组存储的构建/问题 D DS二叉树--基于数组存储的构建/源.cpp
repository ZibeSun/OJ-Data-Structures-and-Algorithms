/*#include<iostream>
using namespace std;
//递归先序遍历顺序数组存储的二叉树
void PreOrder(int i, string str, int len)
{
	if (i < len)
	{
		if (str[i] != '0')
		{
			cout << str[i];
			PreOrder(2 * i + 1, str, len);
			PreOrder(2 * i + 2, str, len);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		PreOrder(0, str, str.length());
		cout << endl;
	}
	return 0;
}
/*
题目描述
任意二叉树可以根据完全二叉树性质保存在一个数组中。已知二叉树的数组存储，用程序构建该二叉树。
提示：用递归方法或非递归都可以
递归方法的代码框架如下：


输入
第一行输入一个整数t，表示有t个测试数据
第二行起输入二叉树的数组存储结果，空树用字符‘0’表示，输入t行
数组的数据由大写字母和0表示
输出
逐行输出每个二叉树的先序结果
样例输入
3
ABC0D
ABCDEF000G
ABEC0F0D0
样例输出
ABDC
ABDEGCF
ABCDEF

*/