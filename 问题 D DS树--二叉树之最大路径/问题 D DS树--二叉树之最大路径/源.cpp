#include<iostream>
using namespace std;
//二叉树的三叉链表结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	int weight; //叶子结点权值
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	BiTreeNode* Parent;      //双亲指针
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), Parent(NULL) {}
	//~BiTreeNode();
};

//二叉树的三叉链表类
class BiTree
{
private:
	BiTreeNode* Root;   //根节点指针
	int weightsum;
	int pos;
	int wtpos;
	int leaf_num;
	string strTree;
	int* wt;            //叶子结点权值指针数组
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
	void WeightSum(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray, int* iwt);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LeafAndParent();  //找出二叉树的叶子结点及其双亲结点
	int LeafDepth(BiTreeNode* t);    //计算叶子结点的深度
	void WeightSum();  //利用先序遍历计算叶子结点权值之和并输出
};
BiTree::BiTree()
{
	pos = 0;
	wtpos = 0;
	strTree = "";
	leaf_num = 0;
	weightsum = 0;
}

//定义先序遍历函数
void BiTree::PreOrder() //公有函数，对外接口
{
	PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

void BiTree::WeightSum()   //公有函数，对外接口
{
	WeightSum(Root);
	cout << weightsum << endl;
}
// 利用先序遍历计算叶子结点权值之和并输出
void BiTree::WeightSum(BiTreeNode* t)
{
	if (t != NULL)
	{
		if (t->weight != 0)
		{
			weightsum += t->weight * LeafDepth(t);
		}
		WeightSum(t->LeftChild);
		WeightSum(t->RightChild);
	}
	else
		return;
}

//定义中序遍历函数
void BiTree::InOrder()  //公有函数，对外接口
{
	InOrder(Root, 0);
}
void BiTree::InOrder(BiTreeNode* t, int n)
{
	if (t != NULL)
	{
		//n=0，输出叶子结点
		if (n == 0)
		{
			InOrder(t->LeftChild, 0);
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				cout << t->data << " ";
			}
			InOrder(t->RightChild, 0);
		}
		//n=1，输出叶子结点的双亲结点
		else if (n == 1)
		{
			InOrder(t->LeftChild, 1);
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				if (t->Parent == NULL)
					cout << t->data << " ";
				else
					cout << t->Parent->data << " ";
			}
			InOrder(t->RightChild, 1);
		}
	}
	else
		return;
}

//定义后序遍历函数
void BiTree::PostOrder()  //公有函数，对外接口
{
	PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout << t->data;
	}
	else
		return;
}

void BiTree::LeafAndParent()
{
	InOrder(Root, 0);
	cout << endl;
	InOrder(Root, 1);
	cout << endl;
}

//计算叶子结点的深度
int BiTree::LeafDepth(BiTreeNode* t)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T->Parent != NULL)
		{
			T = T->Parent;
			depth++;
		}
		else
		{
			return depth;
		}
	}
}

//构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray, int* iwt) //公有函数，对外接口
{
	pos = 0;
	strTree.assign(TreeArray);
	wt = iwt;
	Root = CreateBiTree();
}
//递归建树，私有函数，类内实现
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	char c;
	c = strTree[pos++];
	if (c == '0')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //生成根结点
		if ((c >= 'A') && (c <= 'Z'))
		{
			T->weight = wt[wtpos];
			wtpos++;
		}
		T->LeftChild = CreateBiTree();    //构造左子树
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //构造右子树
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}
int main()
{
	int t;
	cin >> t;
	string str;
	int n;
	while (t--)
	{
		cin >> str;
		int n;
		cin >> n;
		int* wt = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> wt[i];
		}
		BiTree bt;
		bt.CreateTree(str, wt);
		
	}
}
/*
题目描述
给定一颗二叉树的逻辑结构（先序遍历的结果，空树用字符‘0’表示，例如AB0C00D00），建立该二叉树的二叉链式存储结构
二叉树的每个结点都有一个权值，从根结点到每个叶子结点将形成一条路径，每条路径的权值等于路径上所有结点的权值和。编程求出二叉树的最大路径权值。如下图所示，共有4个叶子即有4条路径，
路径1权值=5 + 4 + 11 + 7 = 27          路径2权值=5 + 4 + 11 + 2 = 22
路径3权值=5 + 8 + 13 = 26                路径4权值=5 + 8 + 4 + 1 = 18
可计算出最大路径权值是27。
该树输入的先序遍历结果为ABCD00E000FG00H0I00，各结点权值为：
A-5，B-4，C-11，D-7，E-2，F-8，G-13，H-4，I-1

输入
第一行输入一个整数t，表示有t个测试数据
第二行输入一棵二叉树的先序遍历，每个结点用字母表示
第三行先输入n表示二叉树的结点数量，然后输入每个结点的权值，权值顺序与前面结点输入顺序对应
以此类推输入下一棵二叉树
输出
每行输出每棵二叉树的最大路径权值，如果最大路径权值有重复，只输出1个
样例输入
2
AB0C00D00
4 5 3 2 6
ABCD00E000FG00H0I00
9 5 4 11 7 2 8 13 4 1
样例输出
11
27
提示

*/