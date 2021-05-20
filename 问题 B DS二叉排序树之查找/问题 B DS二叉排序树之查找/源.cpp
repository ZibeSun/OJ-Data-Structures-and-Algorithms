#include<iostream>
using namespace std;
//二叉排序树结点类
class BSTNode
{
public:
	int key;           //结点关键字
	BSTNode* Lchild;   //左孩子
	BSTNode* Rchild;   //右孩子
	BSTNode() :key(0),Lchild(NULL), Rchild(NULL) {}
};
//二叉排序树类
class BSTree
{
private:
	BSTNode* Root;  //根结点指针
	void InOrder(BSTNode* t);
	BSTNode* Search_BST(BSTNode* T, int key);
	BSTNode* Insert_BST(BSTNode* T, int key);
public:
	int search_times;   //每次查找次数
	BSTree();  //构造函数
	void InOrder();     //中序遍历
	BSTNode* Search_BST(int key);  //二叉排序树的递归查找
	void Insert_BST(int key);  //二叉排序树的递归插入
	void Create_BST(int* item, int n);   //构建二叉排序树

};
BSTree::BSTree()
{
	Root = NULL;
	search_times = 0;
}
//定义中序遍历函数
void BSTree::InOrder()  //公有函数，对外接口
{
	InOrder(Root);
}
void BSTree::InOrder(BSTNode* t)
{
	if (t != NULL)
	{
		InOrder(t->Lchild);
		cout << t->key << " ";
		InOrder(t->Rchild);
	}
	else
		return;
}
//定义二叉排序树的递归查找函数
BSTNode* BSTree::Search_BST(int key)  //公有函数，对外接口
{
	search_times = 0;
	return Search_BST(Root, key);
}
BSTNode* BSTree::Search_BST(BSTNode* T, int key)
{
	if (T == NULL)
		return NULL;  //搜索失败则返回NULL
	else
	{
		if (T->key == key)
		{
			search_times++;
			return T;         //搜索成功则返回结点指针
		}
		else if (T->key > key)
		{
			search_times++;
			Search_BST(T->Lchild, key);
		}
		else
		{
			search_times++;
			Search_BST(T->Rchild, key);
		}
	}
}
//定义二叉排序树的递归插入函数
void BSTree::Insert_BST(int key)  //公有函数，对外接口
{
	Root = Insert_BST(Root, key);
}
BSTNode* BSTree::Insert_BST(BSTNode* T, int key)
{
	if (T == NULL)
	{
		T = new BSTNode;
		T->key = key;
	}
	else
	{
		if (T->key == key)
			return NULL;
		else if (T->key > key)
			T->Lchild = Insert_BST(T->Lchild, key);
		else
			T->Rchild = Insert_BST(T->Rchild, key);
		return T;
	}
}
//构建二叉排序树
void BSTree::Create_BST(int* item, int n)
{
	for (int i = 0; i < n; i++)
	{
		Insert_BST(item[i]);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		BSTree BST;
		BST.Create_BST(item, n);
		BST.InOrder();
		cout << endl;
		int m;
		cin >> m;
		int key;
		while (m--)
		{
			cin >> key;
			if (BST.Search_BST(key) != NULL)
				cout << BST.search_times << endl;
			else
				cout << -1 << endl;
		}
	}
}
/*
题目描述
给出一个数据序列，建立二叉排序树，并实现查找功能
对二叉排序树进行中序遍历，可以得到有序的数据序列
输入
第一行输入t，表示有t个数据序列
第二行输入n，表示首个序列包含n个数据
第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第四行输入m，表示要查找m个数据
从第五行起，输入m行，每行一个要查找的数据，都是自然数
以此类推输入下一个示例
输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到
从第二行起，输出查找结果，如果查找成功输出查找次数，如果查找失败输出-1
以此类推输出下一个示例的结果
样例输入
1
6
22 33 55 66 11 44
7
11
22
33
44
55
66
77
样例输出
11 22 33 44 55 66
2
1
2
4
3
4
-1

*/