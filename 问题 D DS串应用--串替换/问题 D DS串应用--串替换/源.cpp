#include<iostream>
using namespace std;
void get_next(string t, int* next)
{
	int i = 0, j = -1;
	next[i] = j;
	while (i < (int)t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			++i; ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(string s, string t)
{
	int i = 0, j = 0;
	int* next = new int[t.length() + 1];
	get_next(t, next);
	while (i < (int)s.length() && j < (int)t.length())
	{
		if (j == -1 || s[i] == t[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j == (int)t.length())
	{
		return i - j;
	}
	else
		return -1;
}
string string_replace(string str, string t, string rs)
{
	if (KMP(str, t) != -1)
	{
		str.replace(KMP(str, t), t.length(), rs);
	}
	return str;
}
/*
不使用KMP做法
string string_replace(string str, string t, string rs)
{
	if (str.find(t, 0) != -1)
	{
		str.replace(str.find(t, 0), t.length(), rs);
	}
	return str;
}
*/
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		string t;
		string rs;
		cin >> str >> t >> rs;
		cout << str << endl;
		cout << string_replace(str,t,rs) << endl;
	}
}
/*题目描述

给出主串、模式串、替换串，用KMP算法找出模式串在主串的位置，然后用替换串的字符替换掉模式串

本题只考虑一处替换的情况，如果你想做的完美一些，能够实现多处替换那

可能需要考虑模式串和替换串长度不一致的情况

输入

第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串，第四行输入第1个实例的替换串

以此类推

输出

第一行输出第1个实例的主串

第二行输出第1个实例的主串替换后结果，如果没有发生替换就输出主串原来的内容。

以此类推

样例输入

3
aabbccdd
bb
ff
aaabbbccc
ddd
eee
abcdef
abc
ccccc
样例输出

aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef
提示*/