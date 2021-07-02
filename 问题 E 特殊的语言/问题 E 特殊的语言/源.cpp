#include<iostream>
#include<cstring>
using namespace std;
int SpecialLanguage(string str, string str1)
{
	int num = 0;
	int len = str.length();
	int len1 = str1.length();
	for (int i = 0; i <= len-len1; i+=2)
	{
		if (str.substr(i, len1).compare(str1) == 0)
			num++;
	}
	return num;
}
int main()
{
	string str;
	string str1;
	while (cin >> str >> str1)
	{
		cout << SpecialLanguage(str, str1) << endl;
	}
}
/*
题目描述
某城邦的语言，每个字是由两个字母构成的。考古学家发现把他们的文字数字化之后，当想搜索特定的句子时，总会匹配到错误的地方。

比如一段文字是 aabcdaabcdef，想要搜索 abcd，应当搜到的是 aabcda abcd ef ，却会得到额外的一个并不符合该语言语法的结果 a abcd aabcdef（因为每个字由两个字符组成，这样匹配就把正确的“字”拆开了）。

请你帮他实现正确的匹配算法。

输入
每组数据两行，第一行为该语言的主串，第二行为模式串，都由大写或小写英文字母组成，长度都不超过 10000，且一定为偶数个。

输出
每组数据输出正确匹配的次数

样例输入
abcdaabbab
ab
AbdcAbdcAbqAbdcAbdcAbp
AbdcAb
样例输出
2
2
提示

*/