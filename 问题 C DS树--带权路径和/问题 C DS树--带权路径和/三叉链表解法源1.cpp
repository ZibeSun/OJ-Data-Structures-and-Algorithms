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
	int* wt;    //叶子结点权值指针数组
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray,int *iwt);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LeafAndParent();  //找出二叉树的叶子结点及其双亲结点
	int LeafDepth(BiTreeNode *t);    //计算叶子结点的深度
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
		if (t->weight != 0)
		{
			weightsum += t->weight * LeafDepth(t);
		}
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

void BiTree::WeightSum()
{
	PreOrder();
	cout << weightsum << endl;
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
void BiTree::CreateTree(string TreeArray,int *iwt) //公有函数，对外接口
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
		bt.CreateTree(str,wt);
		bt.WeightSum();
	}
}
/*
题目描述
计算一棵二叉树的带权路径总和，即求赫夫曼树的带权路径和。
已知一棵二叉树的叶子权值，该二叉树的带权案路径和APL等于叶子权值乘于根节点到叶子的分支数，然后求总和。如下图中，叶子都用大写字母表示，权值对应为：A-7，B-6，C-2，D-3
树的带权路径和 = 7*1 + 6*2 + 2*3 + 3*3 = 34

本题二叉树的创建参考前面的方法
输入
第一行输入一个整数t，表示有t个二叉树
第二行输入一棵二叉树的先序遍历结果，空树用字符‘0’表示，注意输入全是英文字母和0，其中大写字母表示叶子
第三行先输入n表示有n个叶子，接着输入n个数据表示n个叶子的权值，权值的顺序和前面输入的大写字母顺序对应
以此类推输入下一棵二叉树
输出
输出每一棵二叉树的带权路径和
样例输入
2
xA00tB00zC00D00
4 7 6 2 3
ab0C00D00
2 10 20
样例输出
34
40

*/