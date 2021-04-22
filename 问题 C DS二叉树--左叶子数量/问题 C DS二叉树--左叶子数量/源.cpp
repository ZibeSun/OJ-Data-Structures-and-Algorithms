#include<iostream>
using namespace std;
//二叉树结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	BiTreeNode() :LeftChild(NULL), RightChild(NULL) {}
	//~BiTreeNode();
};

//二叉树类
class BiTree
{
private:
	BiTreeNode* Root;   //根节点指针
	int pos;
	int LeftLeaf_num;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t,int n);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	int LeftLeaf();  //计算二叉树包含的叶子数量
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
	LeftLeaf_num = 0;
}

//定义先序遍历函数
void BiTree::PreOrder() //公有函数，对外接口
{
	PreOrder(Root,0);
}
void BiTree::PreOrder(BiTreeNode* t,int n)
{
	if (t != NULL)
	{
		if ((n == 0) || (n == 2))
		{
			PreOrder(t->LeftChild,1);
			PreOrder(t->RightChild,2);
		}
		if (n == 1)
		{
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				LeftLeaf_num++;
			}
			else
			{
				PreOrder(t->LeftChild, 1);
				PreOrder(t->RightChild, 2);
			}
		}
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
		cout << t->data;
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
		cout << t->data;
	}
	else
		return;
}

int BiTree::LeftLeaf()
{
	PreOrder(Root, 0);
	return LeftLeaf_num;
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
	if (c == '0')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //生成根结点
		T->LeftChild = CreateBiTree();    //构造左子树
		T->RightChild = CreateBiTree();   //构造右子树
	}
	return T;
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
		cout << bt.LeftLeaf() << endl;
	}
}
/*
题目描述
计算一颗二叉树包含的叶子结点数量。
左叶子是指它的左右孩子为空，而且它是父亲的左孩子
提示：可以用三叉链表法，也可以用现有算法对两层结点进行判断
建树方法采用“先序遍历+空树用0表示”的方法
输入
第一行输入一个整数t，表示有t个测试数据
第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行
输出
逐行输出每个二叉树的包含的左叶子数量
样例输入
3
AB0C00D00
AB00C00
ABCD0000EF000

样例输出
0
1
2

*/