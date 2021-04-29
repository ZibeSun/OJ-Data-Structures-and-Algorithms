#include<iostream>
using namespace std;
//二叉树的三叉链表结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	BiTreeNode* Parent;      //双亲指针
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), Parent(NULL){}
	//~BiTreeNode();
};

//二叉树的三叉链表类
class BiTree
{
private:
	BiTreeNode* Root;   //根节点指针
	int pos;
	int leaf_num;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t,int c,int* s, char* l);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LeafAndParent();  //找出二叉树的叶子结点及其双亲结点
	int LeafDepth(BiTreeNode* t);    //计算叶子结点的深度
	int subtree_LeafMaxDistance(BiTreeNode* t, char* l1, char* l2);   //计算以t结点为根结点的子树的左子树结点和右子树结点之间的最大距离
	void LeafMaxDistance();    //计算二叉树结点的最大距离
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
	leaf_num = 0;
}

//定义先序遍历函数
void BiTree::PreOrder() //公有函数，对外接口
{
	//PreOrder(Root,0);
}
//c是附加操作数，s是地址传递的最大深度
void BiTree::PreOrder(BiTreeNode* t,int c,int* s,char *l)
{
	if (t != NULL)
	{
		//c=0，表示普通先序遍历
		if (c == 0)
		{
			if (*s < LeafDepth(t))
			{
				*s = LeafDepth(t);
				*l = t->data;
			}
			PreOrder(t->LeftChild,0,s,l);
			PreOrder(t->RightChild,0,s,l);
		}
		//c=1，表示遍历结点t下的左子树
		else if (c == 1)
		{
			if (*s == -1)
			{
				if (t->LeftChild == NULL)
				{
					*s = 0;
					return;
				}
				else
					t = t->LeftChild;
			}
			if (*s < LeafDepth(t))
			{
				*s = LeafDepth(t);
				*l = t->data;
			}
			PreOrder(t->LeftChild, 0, s, l);
			PreOrder(t->RightChild, 0, s, l);
		}
		//c=2，表示遍历结点t下的右子树
		else if (c == 2)
		{
			if (*s == -1)
			{
				if (t->RightChild == NULL)
				{
					*s = 0;
					return;
				}
				else
					t = t->RightChild;
			}
			if (*s < LeafDepth(t))
			{
				*s = LeafDepth(t);
				*l = t->data;
			}
			PreOrder(t->LeftChild, 0, s, l);
			PreOrder(t->RightChild, 0, s, l);
		}
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

//计算叶子结点相对于根结点的深度
int BiTree::LeafDepth(BiTreeNode* t)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T == Root)
		{
			return depth;
		}
		else
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
}

//计算以t结点为根结点的子树的左子树结点和右子树结点之间的最大距离
//结点t仅限根结点的左孩子和右孩子
int BiTree::subtree_LeafMaxDistance(BiTreeNode* t,char *l1,char *l2)
{
	int sl, sr;
	sl = -1;
	sr = -1;
	*l1 = '#';
	*l2 = '#';
	PreOrder(t, 1, &sl,l1);
	PreOrder(t, 2, &sr,l2);
	//cout << "sl=" << sl << "sr=" << sr << endl;
	return sl + sr;
}

//计算二叉树结点的最大距离
void BiTree::LeafMaxDistance()
{
	int MaxD;
	char l1, l2, l3, l4, l5, l6;
	char leaf1, leaf2;
	int A = subtree_LeafMaxDistance(Root,&l1,&l2);
	int l = subtree_LeafMaxDistance(Root->LeftChild, &l3, &l4) - 2;
	int r = subtree_LeafMaxDistance(Root->RightChild, &l5, &l6) - 2;
	//cout << "l=" << l << "r=" << r << endl;
	int B = l > r ? l : r;
	//cout << "A=" << A << endl;
	//cout << "B=" << B << endl;
	if (A > B)
	{
		MaxD = A;
		leaf1 = l1;
		leaf2 = l2;
	}
	else
	{
		MaxD = B;
		if (B == l)
		{
			leaf1 = l3;
			leaf2 = l4;
		}
		else if (B == r)
		{
			leaf1 = l5;
			leaf2 = l6;
		}
	}
	cout << MaxD << ":";
	if (MaxD != 0)
		cout << leaf1 << " " << leaf2 << endl;
	else
		cout << endl;
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
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		BiTree bt;
		bt.CreateTree(str);
		bt.LeafMaxDistance();
	}
}
/*
题目描述
	二叉树两个结点的距离是一个结点经过双亲结点，祖先结点等中间结点到达另一个结点经过的分支数。
二叉树结点的最大距离是所有结点间距离的最大值。例如，下图所示二叉树结点最大距离是3，C和D的距离。
	二叉树用先序遍历顺序创建，#表示空树。
计算二叉树结点最大距离和最大距离的两个结点(假设二叉树中取最大距离的两个结点唯一）。

输入
测试次数T
第2行之后的T行，每行为一棵二叉树先序遍历结果（#表示空树）
输出
对每棵二叉树，输出树的结点最大距离和最大距离的结点，输出格式见样例。

样例输入
3
A##
ABC##EF#G###D##
ABEH###F#K###
样例输出
0:
5:G D
4:H K

*/