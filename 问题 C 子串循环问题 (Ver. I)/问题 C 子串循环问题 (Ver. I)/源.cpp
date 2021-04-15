#include<iostream>
using namespace std;
int string_loop(string str)
{
	string loop;
	for (int i = 1; i < str.length(); i++)
	{
		//当遍历到第一个与首字符相同的字符时
		if (str[i] == str[0])
		{
			//检查此字符与其后跟的字符能否构成与前面一样的字符串
			loop = str.substr(0, i);
			//循环检查至无法构成循环子串为止
			while (1)
			{
				if (str.find(loop, i) == -1)
				{
					int j;
					if (str.length() - i < loop.length())
					{
						for (j=i; j < str.length(); j++)
						{
							if (str[j] != loop[j - i])
							{
								break;
							}
						}
						if (j == str.length())
						{
							return loop.length() - str.length() + i;
						}
						else
						{
							loop = "";
							break;
						}
					}
					else
					{
						loop = "";
						break;
					}
				}
				else if (str.find(loop, i) != i)
				{
					break;
				}
				else
				{
					if (i == str.length() - loop.length())
					{
						return 0;
					}
					else
					{
						i += loop.length();
					}
				}
			}
		}
	}
	if (loop == "")
		return str.length();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		cout << string_loop(str) << endl;
	}
}
/*题目描述

给定一个字符串，求需要添加至少几个字符到字符串末尾才能使得整个字符串串由某一个不为本身的子串循环构成？
如"abca"，添加"bc"后构成"abcabc"，其由子串"abc"循环构成;也可以添加"abca"后构成"abcaabca"，其由子串"abca"循环构成，相比之下"bc"只有2个字符，添加的字符量最少。

输入

第一行包括一个整数T(1 <= T <= 100)，代表测试组数

每组测试数据包括一行字符串，其长度范围为 [3, 104]

输出

对于每组测试数据

输出一个整数N，代表添加的最小字符数量

样例输入

5
aaa
abca
abcdefg
abcabcabca
qweaqwec
样例输出

0
2
7
2
8*/