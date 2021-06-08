#include<iostream>
#include<string>
#include<queue>
using namespace std;
//Trie树结点类
class TrieTreeNode
{
public:
	string word;  //结点字符
	int num;    // 有多少单词通过这个节点,即由根至该节点组成的字符串模式出现的次数
	bool isEnd; // 是不是最后一个节点
	TrieTreeNode** Nextword = new TrieTreeNode*[26];
	TrieTreeNode()  
	{
		num = 0;
		isEnd = false;
		for (int i = 0; i < 26; i++)
		{
			Nextword[i] = NULL;
		}
	}
	//~TrieTreeNode();
};

//Trie树类
class TrieTree
{
private:
	TrieTreeNode* Root;   //根节点指针
public:
	TrieTree();
	//~TrieTree();
	void insert(string str); //在字典树中插入一个单词
	int find(string str);   //在字典树中查找以该字符串为公共前缀的单词数
	void show();            //层次遍历字典树
};
TrieTree::TrieTree()
{
	Root = new TrieTreeNode();
}
//在字典树中插入一个单词
void TrieTree::insert(string str)
{
	if (str == "" || str.length() == 0)
	{
		return;
	}
	TrieTreeNode* T = Root;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		//如果当前节点的儿子节点中没有该字符，则构建一个TrieTrieTreeNode并复值该字符
		if (T->Nextword[pos]==NULL)
		{
			T->Nextword[pos] = new TrieTreeNode();
			T->Nextword[pos]->word = str[i];
			T->Nextword[pos]->num++;
		}
		//如果已经存在，则将由根至该儿子节点组成的字符串模式出现的次数+1
		else
		{
			T->Nextword[pos]->num++;
		}
		T = T->Nextword[pos];
	}
	T->isEnd = true;
}
//在字典树中查找以该字符串为公共前缀的单词数
int TrieTree::find(string str)
{
	if (str == "" || str.length() == 0)
	{
		return 0;
	}
	TrieTreeNode* T = Root;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		//如果当前节点的儿子节点中没有该字符，则构建一个TrieTrieTreeNode并复值该字符
		if (T->Nextword[pos] != NULL)
		{
			T = T->Nextword[pos];
		}
		//如果已经存在，则将由根至该儿子节点组成的字符串模式出现的次数+1
		else
		{
			return 0;
		}
	}
	return T->num;
}
//层次遍历字典树
void TrieTree::show()
{
	if (!Root) return;
	deque<TrieTreeNode*> q;
	q.push_back(Root);
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			TrieTreeNode* tp = q.front(); q.pop_front();
			cout << tp->word;
			for (int i = 0; i < 26; i++)
				if (tp->Nextword[i]) q.push_back(tp->Nextword[i]);
		}
	}
	cout << endl;
}
int main()
{
	TrieTree T;
	//实现不限制组数无限循环输入字符串，以空格隔开，当按下回车键时结束输入
	while (1)
	{
		string str;
		char ar[11];
		int i = 0;
		char c;
		c = getchar();
		while (c != '\n' && c != ' ')
		{
			ar[i] = c;
			c = getchar();
			i++;
		}
		if (c == ' ')
		{
			ar[i] = '\0';
			str = ar;
			T.insert(str);
			continue;
		}
		if (c == '\n')
		{
			ar[i] = '\0';
			str = ar;
			T.insert(str);
			break;
		}
	}
	T.show();
	string str;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> str;
		cout << T.find(str) << endl;
	}
	return 0;
}
/*
题目描述
Trie树又称单词查找树，是一种树形结构，如下图所示。

它是一种哈希树的变种。典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。它的优点是：利用字符串的公共前缀来节约存储空间，最大限度地减少无谓的字符串比较，查询效率比哈希表高。
输入的一组单词，创建Trie树。输入字符串，计算以该字符串为公共前缀的单词数。
（提示：树结点有26个指针，指向单词的下一字母结点。）
输入
测试数据有多组
每组测试数据格式为：
第一行：一行单词，单词全小写字母，且单词不会重复，单词的长度不超过10
第二行：测试公共前缀字符串数量t
后跟t行，每行一个字符串
输出
每组测试数据输出格式为：
第一行：创建的Trie树的层次遍历结果
第2~t+1行：对每行字符串，输出树中以该字符串为公共前缀的单词数。
样例输入
abcd abd bcd efg hig
3
ab
bc
abcde
样例输出
abehbcficddggd
2
1
0

*/