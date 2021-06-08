#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//二叉树结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), data(' ') {}
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
	void LevelOrder(BiTreeNode* t);
	void PostOrder_stack(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LevelOrder();  //层次遍历
	void PostOrder_stack();  //后序遍历非递归算法
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
		cout << t->data;
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

//层次遍历函数
void BiTree::LevelOrder()    //公有函数，对外接口
{
	LevelOrder(Root);
}
void BiTree::LevelOrder(BiTreeNode* t)
{//用队列实现
	queue<BiTreeNode*> tq;
	BiTreeNode* p = t;
	if (p != NULL)
	{
		tq.push(p);
	}
	while (!tq.empty())
	{
		p = tq.front();
		tq.pop();
		if (p != NULL)
		{
			cout << p->data;
			tq.push(p->LeftChild);
			tq.push(p->RightChild);
		}
	}
}

//后序非递归遍历
void BiTree::PostOrder_stack()   //公有函数，对外接口
{
	PostOrder_stack(Root);
}
void BiTree::PostOrder_stack(BiTreeNode* t)
{
	stack<BiTreeNode*> s1;
	stack<int> s2;
	int tag;
	BiTreeNode* p = t;
	do
	{
		while (1)
		{
			if (p != NULL)
			{
				s1.push(p);
				tag = 0;
				s2.push(tag);
				p = p->LeftChild;
			}
			else
				break;
		}
		
		if (s1.empty())
			break;
		if (p == NULL)
		{
			tag = s2.top();
			if (tag == 0)
			{
				s2.top() = 1;
				p = s1.top()->RightChild;
			}
			else
			{
				p = s1.top();
				s1.pop();
				s2.pop();
				cout << p->data;
				p = NULL;
			}
		}
	} while (!s1.empty());
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
		bt.PostOrder_stack();
		cout << endl;
	}
}
/*
题目描述
求一颗树的后序遍历的非递归算法
要求：必须是非递归算法，使用堆栈对象来实现
建树方法采用“先序遍历+空树用0表示”的方法
算法流程：

输入
第一行输入一个整数t，表示有t个测试数据
第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行
输出
逐行输出每个二叉树的后序遍历结果
样例输入
3
AB0C00D00
ABC00D00EF000
ABCD0000E0F00
样例输出
CBDA
CDBFEA
DCBFEA

*/