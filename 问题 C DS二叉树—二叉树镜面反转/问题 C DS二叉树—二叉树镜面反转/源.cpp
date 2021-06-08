#include<iostream>
using namespace std;
//二叉树结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	BiTreeNode* Parent;      //双亲指针
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), data(' '), Parent(NULL) {}
	//~BiTreeNode();
};

//二叉树类
class BiTree
{
private:
	BiTreeNode* Root;   //根节点指针
	int pos;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
	void LevelOrder(BiTreeNode* t, int i);
	void MirrorTree(BiTreeNode* t);
	int LeafDepth(BiTreeNode* t);   //计算叶子结点的深度
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LevelOrder();  //层次遍历
	void MirrorTree();  //二叉树镜像反转
	bool CheckTree();   //检查二叉树是否为空
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
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
		cout << t->data << " ";
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

//定义中序遍历函数
void BiTree::InOrder()  //公有函数，对外接口
{
	InOrder(Root);
}
void BiTree::InOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		InOrder(t->LeftChild);
		cout << t->data << " ";
		InOrder(t->RightChild);
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
		cout << t->data << " ";
	}
	else
		return;
}

//构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray) //公有函数，对外接口
{
	pos = 0;
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}
//递归建树，私有函数，类内实现
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	char c;
	c = strTree[pos++];
	if (c == '#')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //生成根结点
		T->LeftChild = CreateBiTree();    //构造左子树
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //构造右子树
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}

//层次遍历函数
void BiTree::LevelOrder()    //公有函数，对外接口
{
	for (int i = 0; i < 10; i++)
	{
		LevelOrder(Root,i);
	}
}
void BiTree::LevelOrder(BiTreeNode* t,int i)
{
	if (t != NULL)
	{
		if (LeafDepth(t) == i)
		{
			cout << t->data << " ";
		}
		LevelOrder(t->LeftChild,i);
		LevelOrder(t->RightChild, i);
	}
	else
		return;
}

//二叉树镜像反转
void BiTree::MirrorTree()    //公有函数，对外接口
{
	MirrorTree(Root);
}
void BiTree::MirrorTree(BiTreeNode* t)
{
	if (t != NULL)
	{
		BiTreeNode* p = t->LeftChild;
		t->LeftChild = t->RightChild;
		t->RightChild = p;
		MirrorTree(t->LeftChild);
		MirrorTree(t->RightChild);
	}
	else
		return;
}

//检查二叉树是否为空
bool BiTree::CheckTree()
{
	if (Root == NULL)
		return true;
	else
		return false;
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
int main()
{
	int t;
	cin >> t;
	string str;
	while (t--)
	{
		cin >> str;
		BiTree bt;
		bt.CreateTree(str);
		if (bt.CheckTree())
		{
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
		}
		else
		{
			bt.MirrorTree();
			bt.PreOrder();
			cout << endl;
			bt.InOrder();
			cout << endl;
			bt.PostOrder();
			cout << endl;
			bt.LevelOrder();
			cout << endl;
		}
	}
}
/*
题目描述
假设二叉树用二叉链表存储，用先序序列结果创建。输入二叉树的先序序列，请你先创建二叉树，并对树做个镜面反转，再输出反转后的二叉树的先序遍历、中序遍历、后序遍历和层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。
--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
测试次数t
每组测试数据是一个二叉树的先序遍历序列，#表示空树
输出
对每棵二叉树，输出镜面反转后的先序、中序、后序和层次遍历序列。如果空树，输出四个NULL（后面不加空格）。如下：
NULL
NULL
NULL
NULL
样例输入
3
41#32###65##7##
AB#C##D##
AB##C##
样例输出
4 6 7 5 1 3 2
7 6 5 4 3 2 1
7 5 6 2 3 1 4
4 6 1 7 5 3 2
A D B C
D A C B
D C B A
A D B C
A C B
C A B
C B A
A C B
提示

*/