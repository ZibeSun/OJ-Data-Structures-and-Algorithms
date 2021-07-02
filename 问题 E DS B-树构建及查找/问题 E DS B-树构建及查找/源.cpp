#include <iostream>     
#include <queue> 
using namespace std;

int m;

class BTNode
{
public:
	int keyNum; // 关键字个数 
	BTNode* parent; // 指向双亲结点 
	int* keys; // 关键字向量 
	BTNode** ptr; // 子树指针向量 
	BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}

	~BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}
};

class Result
{
public:
	BTNode* pt; // 指向找到的结点
	int i;
	int tag;
	Result(BTNode* p, int m, int t)
	{
		pt = p;
		i = m;
		tag = t;
	}

	~Result()
	{
		pt = NULL;
		i = 0;
		tag = 0;
	}
};

class BTree
{
private:
	BTNode* root;
	void insert(BTNode* t, int i, int k, BTNode* ap); // 将k和ap分别插入t->key[i+1]和t->ptr[i + 1] 
	int search(BTNode* t, int k); // 在p->key[1...keynum]中查找 k
	void split(BTNode* q, int s, BTNode*& ap); // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap 
	void newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap); // 生成含信息(t, x, ap)的新根结点t*ap, 原t和 ap为子树指针
	void insertBT(BTNode*& t, int k, BTNode* q, int i); // 在结点t的子结点q的key[i]与key[i+1]之间插入k 
	Result* searchBT(BTNode* t, int k); // 在结点t中查找k 
public:
	BTree();
	~BTree();
	void insertBT(int key); // B-树插入操作 
	void searchBT(int key); // B-树查找操作 
	void levelOrder(); // B-树层次遍历 
};

void BTree::insert(BTNode* t, int i, int k, BTNode* ap)
{
	// 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
}

int BTree::search(BTNode* t, int k)
{
	// 在p->key[1...keynum]中查找 k
}

void BTree::split(BTNode* q, int s, BTNode*& ap)
{
	// 将q->key[s+1...m],q->ptr[s...m]移入新结点ap 
}

void BTree::newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap)
{
	// 生成含信息(t, x, ap)的新根结点t, 原t和 ap为子树指针
}

Result* BTree::searchBT(BTNode* t, int k)
{
	// 参考课本240页算法9.13
}

void BTree::insertBT(BTNode*& t, int k, BTNode* q, int i)
{
	// 参考课本244页算法9.14
}

// B树初始化 
BTree::BTree()
{
	root = NULL;
}

BTree::~BTree()
{
	root = NULL;
}

// B-树插入操作
void BTree::insertBT(int key)
{
	Result* r = searchBT(root, key);
	if (!r->tag)
	{
		insertBT(root, key, r->pt, r->i);
	}
	return;
}

// B-树查找操作
void BTree::searchBT(int key)
{
	Result* r = searchBT(root, key);
	if (!r->tag)
	{
		cout << "-1" << endl;
	}
	else
	{
		BTNode* p = r->pt;
		cout << p->keys[1];
		for (int i = 2; i <= p->keyNum; i++)
		{
			cout << ':' << p->keys[i];
		}
		cout << ' ' << r->i << endl;
	}
	return;
}

// B-树层次遍历输出关键字 
void BTree::levelOrder()
{
	queue<BTNode*> tq;
	BTNode* p = root;
	// 首结点入队 
	if (p)
	{
		tq.push(p);
	}
	// 层次遍历树 
	while (!tq.empty())
	{
		p = tq.front();
		tq.pop();
		// 输出结点p的key 
		cout << p->keys[1];
		for (int i = 2; i <= p->keyNum; i++)
		{
			cout << ':' << p->keys[i];
		}
		cout << ' ';
		// 自结点入栈 
		for (int i = 0; i <= p->keyNum; i++)
		{
			if (!p->ptr[i])
			{
				break;
			}
			tq.push(p->ptr[i]);
		}
	}
	return;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> m;
		int n, k, key;
		// 构建B-树 
		cin >> n;
		BTree bTree;
		while (n--)
		{
			cin >> key;
			bTree.insertBT(key);
		}
		// 按层次遍历输出B-树 
		bTree.levelOrder();
		cout << endl;
		// 查找B-树结点 
		cin >> k;
		while (k--)
		{
			cin >> key;
			bTree.searchBT(key);
		}
	}
	return 0;
}
/*
题目描述
在初始为空的m阶B-树中依次插入n个结点，按层次遍历输出关键字，然后再查找m个关键字在所在结点的关键字中的位置。
要求实现B-树，不可以使用各类库函数。
代码参考模板：
#include <iostream>     #include <queue>
using namespace std;

int m;

class BTNode
{
	public:
		int keyNum; // 关键字个数
	BTNode *parent; // 指向双亲结点
	int *keys; // 关键字向量
	BTNode **ptr; // 子树指针向量
	BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}

	~BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}
};

class Result
{
	public:
		BTNode *pt; // 指向找到的结点
	int i;
	int tag;
	Result(BTNode *p, int m, int t)
	{
		pt = p;
		i = m;
		tag = t;
	 }

	~Result()
	{
		pt = NULL;
		i = 0;
		tag = 0;
	}
};

class BTree
{
	 private:
		 BTNode *root;
	 void insert(BTNode *t, int i, int k, BTNode *ap); // 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
	 int search(BTNode *t, int k); // 在p->key[1...keynum]中查找 k
	 void split(BTNode *q, int s, BTNode *&ap); // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap
	 void newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap); // 生成含信息(t, x, ap)的新根结点t*ap, 原t和 ap为子树指针
	 void insertBT(BTNode *&t, int k, BTNode *q, int i); // 在结点t的子结点q的key[i]与key[i+1]之间插入k
	 Result *searchBT(BTNode *t, int k); // 在结点t中查找k
	 public:
	 BTree();
	~BTree();
	 void insertBT(int key); // B-树插入操作
	 void searchBT(int key); // B-树查找操作
	 void levelOrder(); // B-树层次遍历
};

void BTree::insert(BTNode *t, int i, int k, BTNode *ap)
{
	// 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
}

int BTree::search(BTNode *t, int k)
{
	// 在p->key[1...keynum]中查找 k
}

void BTree::split(BTNode *q, int s, BTNode *&ap)
{
	// 将q->key[s+1...m],q->ptr[s...m]移入新结点ap 
}

void BTree::newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap)
{
	// 生成含信息(t, x, ap)的新根结点t, 原t和 ap为子树指针
}

Result *BTree::searchBT(BTNode *t, int k)
{
	// 参考课本240页算法9.13
}

void BTree::insertBT(BTNode *&t, int k, BTNode *q, int i)
{
	// 参考课本244页算法9.14
}

// B树初始化
BTree::BTree()
{
	 root = NULL;
}

BTree::~BTree()
{
	 root = NULL;
}

// B-树插入操作
void BTree::insertBT(int key)
{
	 Result *r = searchBT(root, key);
	 if(!r->tag)
	 {
		  insertBT(root, key, r->pt, r->i);
	 }
	 return;
}

// B-树查找操作
void BTree::searchBT(int key)
{
	Result *r = searchBT(root, key);
	if(!r->tag)
	{
		 cout << "-1" << endl;
	}
	 else
	{
		 BTNode *p = r->pt;
	 cout << p->keys[1];
	 for(int i = 2; i <= p->keyNum; i ++)
	{
		 cout << ':' << p->keys[i];
	 }
	 cout <<' '<< r->i << endl;
	}
	return;
}

// B-树层次遍历输出关键字
void BTree::levelOrder()
{
	 queue<BTNode *> tq;
	 BTNode *p = root;
	 // 首结点入队
	 if(p)
	 {
		  tq.push(p);
	 }
	 // 层次遍历树
	 while(!tq.empty())
	 {
		  p = tq.front();
	  tq.pop();
	  // 输出结点p的key
	  cout << p->keys[1];
	  for(int i = 2; i <= p->keyNum; i ++)
	  {
		   cout << ':' << p->keys[i];
	   }
		   cout << ' ';
	  // 自结点入栈
		  for(int i = 0; i <= p->keyNum; i ++)
		  {
			   if(!p->ptr[i])
			   {
				break;
		}
			   tq.push(p->ptr[i]);
	  }
	 }
	 return;
}

int main(void)
{
	 int t;
	 cin >> t;
	 while(t --)
	 {
		  cin >> m;
	  int n, k, key;
	  // 构建B-树
	  cin >> n;
	  BTree bTree;
	  while(n --)
	  {
		   cin >> key;
		   bTree.insertBT(key);
	  }
	 // 按层次遍历输出B-树
	  bTree.levelOrder();
	  cout << endl;
	  // 查找B-树结点
	  cin >> k;
	  while(k --)
	 {
		  cin >> key;
		  bTree.searchBT(key);
	  }
	  }
	  return 0;
}
输入
第一行输入t，表示有t个数据序列
第二行输入m, 表示要构建m阶B-树
第三行输入n，表示首个序列包含n个数据
第四行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第五行输入k，表示要查找k个数据
从第五行起，输入k行，每行一个要查找的数据，都是自然数
以此类推输入下一个示例
输出
第一行输出B-树的关键字，同一个结点的关键字之间用:间隔，不同结点之间的关键字用一个空格间隔，对树进行层次遍历可以得到。
从第二行起，输出查找结果，如果查找成功，输出所在结点的关键字，关键字之间用:间隔，及在所在结点关键字中的位置，如果查找失败输出-1。
以此类推输出下一个示例的结果
样例输入
3
3
3
21 45 65
2
45
-10
3
7
21 45 65 25 31 52 55
2
55
35
4
6
45 24 53 90 46 47
4
46
45
90
20
样例输出
45 21 65
45 1
-1
45 25 55 21 31 52 65
55 1
-1
46:53 24:45 47 90
46:53 1
24:45 2
90 1
-1
提示

*/
