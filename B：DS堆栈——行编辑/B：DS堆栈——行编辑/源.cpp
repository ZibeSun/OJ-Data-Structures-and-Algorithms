#include<iostream>
#include<stack>
using namespace std;
void del(stack<char> &s)
{
	s.pop();
	int n = 1;
	if (s.empty() != true)
	{
		while (s.top() == '#')
		{
			n++;
			s.pop();
			if (s.empty() == true)
				break;
		}
		for (int i = 0; i < n; i++)
		{
			if (s.empty() != true)
			{
				if (s.top() == '#')
					del(s);
				else
					s.pop();
			}
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
		int len;
		cin >> str;
		len = str.length();
		stack<char> s;
		stack<char> ss;     //用于存储最终正序输出的字符；
		for (int i = 0; i < len; i++)
		{
			s.push(str[i]);
		}
		while (s.empty() != true)
		{
			if (s.top() == '#')
			{
				/*s.pop();
				int n = 1;
				while (s.top() == '#')
				{
					n++;
					s.pop();
					if (s.empty() == true)
						break;
				}
				for (int i = 0; i < n; i++)
				{
					if (s.empty() != true)
					{
						if (s.top() == '#')
						{
							s.pop();
							int n = 1;
							while (s.top() == '#')
							{
								n++;
								s.pop();
								if (s.empty() == true)
									break;
							}
							for (int i = 0; i < n; i++)
							{
								if (s.empty() != true)
									s.pop();
								else
									break;
							}
						}
						else
						{
							s.pop();
						}
					}
					else
						break;
				}*/
				del(s);
			}
			else
			{
				ss.push(s.top());
				s.pop();
			}
		}
		if (ss.empty() == true)
			cout << "NULL" << endl;
		else
		{
			while (ss.empty() != true)
			{
				cout << ss.top();
				ss.pop();
			}
			cout << endl;
		}
	}
	return 0;
}
/*题目描述
使用C++的STL堆栈对象，编写程序实现行编辑功能。行编辑功能是：当输入#字符，则执行退格操作；如果无字符可退就不操作，不会报错

本程序默认不会显示#字符，所以连续输入多个#表示连续执行多次退格操作

每输入一行字符打回车则表示字符串结束

注意：必须使用堆栈实现，而且结果必须是正序输出

输入
第一行输入一个整数t，表示有t行字符串要输入
第二行起输入一行字符串，共输入t行

输出
每行输出最终处理后的结果，如果一行输入的字符串经过处理后没有字符输出，则直接输出NULL

样例输入
4
chinaa#
sb#zb#u
##shen###zhen###
chi##a#####
样例输出
china
szu
sz
NULL*/