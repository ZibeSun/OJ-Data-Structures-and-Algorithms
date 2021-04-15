#include<iostream>
using namespace std;
int string_repeat(string str)
{
	string s;
	int result = -1;
	for (int i = 0; i < str.length(); i++)
	{
		for (int k = i+1; k < str.length(); k++)
		{
			s = str.substr(i, k);
			if (str.find(s, k) != -1)
			{
				if (result == -1)
				{
					result = s.length();
				}
				else
				{
					if (result < s.length())
					{
						result = s.length();
						/*cout << "i=" << i << "k=" << k << endl;
						cout << "str.find(s,i)=" << str.find(s, i) << endl;
						cout << s << endl;*/
					}
				}
			}
		}
	}
	return result;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		cout << string_repeat(str) << endl;
	}
}
/*题目描述

求串的最长重复子串长度（子串不重叠）。例如：abcaefabcabc的最长重复子串是串abca，长度为4。

输入

测试次数t

t个测试串

输出

对每个测试串，输出最长重复子串长度，若没有重复子串，输出-1.

样例输入

3
abcaefabcabc
szu0123szu
szuabcefg
样例输出

4
3
-1
提示*/