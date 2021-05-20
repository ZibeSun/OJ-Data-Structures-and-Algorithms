#include<iostream>
using namespace std;
//二叉树的三叉链表结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	int balance;  //结点平衡因子
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
	int pos;
	int leaf_num;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
	BiTreeNode* Create_PreOrder(int i, string str);
	int LeafDepth(BiTreeNode* t, BiTreeNode* t_root);
	void Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h);
	void Balance_calculate(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LeafAndParent();  //找出二叉树的叶子结点及其双亲结点
	void CreatePreOrder(int i, string str);
	int HeightSubtree(BiTreeNode* t);   //计算子树高度
	void Balance_calculate();  //计算结点平衡因子
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
		cout << t->data << " " << t->balance << endl;
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
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //构造右子树
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}
//递归先序遍历顺序数组存储的二叉树
void BiTree::CreatePreOrder(int i, string str)
{
	Root=Create_PreOrder(i, str);
}
BiTreeNode* BiTree::Create_PreOrder(int i, string str)
{
	BiTreeNode* T;
	if (i < str.length())
	{
		if (str[i] != '0')
		{
			T = new BiTreeNode;
			T->data = str[i];
			T->LeftChild=Create_PreOrder(2 * i + 1, str);
			if (T->LeftChild != NULL)
				T->LeftChild->Parent = T;
			T->RightChild=Create_PreOrder(2 * i + 2, str);
			if (T->RightChild != NULL)
				T->RightChild->Parent = T;
		}
		else
		{
			T = NULL;
		}
	}
	else
	{
		T = NULL;
	}
	return T;
}
//计算叶子结点t相对于t_root结点的深度
int BiTree::LeafDepth(BiTreeNode* t, BiTreeNode* t_root)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T->Parent != t_root->Parent)
		{
			T = T->Parent;
			depth++;
		}
		else
		{
			depth++;
			return depth;
		}
	}
}
//计算子树高度
int BiTree::HeightSubtree(BiTreeNode* t)
{
	int h = 0;
	if (t != NULL)
	{
		BiTreeNode* t_root = t;
		Height_Subtree(t_root, t, h);
	}
	return h;
}
void BiTree::Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h)
{
	if (t != NULL)
	{
		Height_Subtree(t_root, t->LeftChild, h);
		Height_Subtree(t_root, t->RightChild, h);
		if (LeafDepth(t, t_root) >= h)
			h = LeafDepth(t, t_root);
	}
	else
		return;
}
//计算结点平衡因子
void BiTree::Balance_calculate()  //公有函数，对外接口
{
	Balance_calculate(Root);
}
void BiTree::Balance_calculate(BiTreeNode* t)
{
	if (t != NULL)
	{
		Balance_calculate(t->LeftChild);
		Balance_calculate(t->RightChild);
		t->balance = HeightSubtree(t->LeftChild) - HeightSubtree(t->RightChild);
	}
	else
		return;
}
int main()
{
	int t;
	cin >> t;
	string str;
	int n;
	while (t--)
	{
		cin >> n;
		cin >> str;
		BiTree bt;
		bt.CreatePreOrder(0,str);
		bt.Balance_calculate();
		bt.PostOrder();
	}
}
/*
题目描述
二叉树用数组存储，将二叉树的结点数据依次自上而下,自左至右存储到数组中，一般二叉树与完全二叉树对比，比完全二叉树缺少的结点在数组中用0来表示。
计算二叉树每个结点的平衡因子，并按后序遍历的顺序输出结点的平衡因子。
--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
测试次数t
每组测试数据一行，数组元素个数n，后跟n个字符，二叉树的数组存储。
输出
对每组测试数据，按后序遍历的顺序输出树中结点的平衡因子（测试数据没有空树）
样例输入
2
6 ABC00D
24 ABCD0EF0000H00000000000I


样例输出
B 0
D 0
C 1
A -1
D 0
B 1
I 0
H 1
E 2
F 0
C 2
A -2

*/