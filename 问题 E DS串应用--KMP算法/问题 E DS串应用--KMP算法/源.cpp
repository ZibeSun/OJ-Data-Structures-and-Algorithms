#include<iostream>
using namespace std;
void get_next(string t, int *next) 
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
	int *next=new int[t.length() + 1];
	get_next(t, next);

	for (int i = 0; i < t.length(); i++)
		cout << next[i] << " ";
	cout << endl;

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
		return i - j + 1;
	}
	else
		return 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		string t;
		cin >> str >> t;
		cout << KMP(str, t) << endl;
	}
}
/*题目描述
学习KMP算法，给出主串和模式串，求模式串在主串的位置

算法框架如下，仅供参考

#include <iostream>
#include <string>
using namespace std;
class myString
{
private:
	string mainstr;      //串
	int size;                 //串长度

	void GetHext(string p, int next[]);
	int KMPFind(string p, int pos, int next[]);
public:
	myString();                //构造函数
	~myString();             //析构函数
	void SetUal(string sp);                 //设定主串字符内容和长度
	int KMPFindSubstr(string p, int pos);
};
myString::myString()
{
	size = 0;
mainstr = "";
}
myString::~myString()
{
	size = 0;
	mainstr = "";
}
void myString::SetUal(string sp)
{
	mainstr = "";
	mainstr.assign(sp);
	size = mainstr.length();
}

int wyString::KMPFindSubstr(string p, int pos)
//主串中从pos开始查找子串p。找到返回p在主串的开始位置，否则返回-1
{
	int i;
	int L = p.length();
	int *next = new int[L];
	Gettlext(p, next);
	for (i=0; i<L; i++)
		cout<<next[i]<<' ';
	cout<<endl;
	int v = -1;
	v = KMPFind(p, pos, next);

	delete []next;

	return v;
}

输入
第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串

以此类推

输出
第一行输出第1个实例的模式串的next值

第二行输出第1个实例的匹配位置，位置从1开始计算，如果匹配成功输出位置，匹配失败输出0

以此类推

样例输入
3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac
样例输出
-1 0 0 
5
-1 0 1 
0
-1 0 0 1 
8
提示
 为什么next值和课本的不一样？？？*/