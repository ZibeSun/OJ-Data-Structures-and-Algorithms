#include<iostream>
using namespace std;
string matched_Prefix_Postfix(string str)
{
	string* f = new string[str.length() - 1];
	string* b = new string[str.length() - 1];
	for (int i = 0; i < str.length()-1; i++)
	{
		f[i] = str.substr(0, i + 1);
	}
	for (int i = str.length() - 1; i > 0; i--)
	{
		b[str.length() - i-1] = str.substr(i, str.length() - i);
	}
	string result;
	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int k = 0; k < str.length() - 1; k++)
		{
			if (f[i]==b[k])
			{
				if (result == "")
				{
					result = f[i];
				}
				else
				{
					if (f[i].length() > result.length())
					{
						result = f[i];
					}
				}
			}
		}
	}
	if (result == "")
	{
		return "empty";
	}
	else
	{
		return result;
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		cout << matched_Prefix_Postfix(str) << endl;
	}
}
/*题目描述

给定一个串，如ABCDAB，则 ABCDAB的真前缀有：{ A, AB,ABC, ABCD, ABCDA } ABCDAB的真后缀有：{ B, AB,DAB, CDAB, BCDAB } 因此，该串的真前缀和真后缀中最长的相等串为AB，我们称之为该串的“最长的真前后缀”。 试实现一个函数string matched_Prefix_Postfix(string str)，得到输入串str的最长的真前后缀。若不存在最长的真前后缀则输出empty
输入

第1行：串的个数 n 第2行到第n+1行：n个字符串
输出

n个最长的真前后缀，若不存在最长的真前后缀则输出empty。
样例输入

6
a
ab
abc
abcd
abcda
abcdab
样例输出

empty
empty
empty
empty
a
ab
提示*/