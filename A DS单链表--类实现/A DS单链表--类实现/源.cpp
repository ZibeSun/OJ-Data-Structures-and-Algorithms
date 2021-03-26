#include<stdio.h>
#include<iostream>
using namespace std;
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode()
	{
		next = NULL;
		data = 0;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList();
	~LinkList();
	void LL_add(int x);
	ListNode* LL_index(int i);
	void LL_get(int i);
	void LL_insert(int i, int item);
	void LL_del(int i);
	void LL_display();
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
LinkList::~LinkList()
{
	head = NULL;
}
void LinkList::LL_add(int x)
{
	ListNode* l = new ListNode();
	l->data = x;
	if (head->next == NULL)
	{
		head->next = l;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= len; k++)
		{
			p = p->next;
		}
		p->next = l;
	}
	len++;
}
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
}
void LinkList::LL_get(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		int x;
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
			x = p->data;
		}
		cout << x << endl;
	}	
}
void LinkList::LL_insert(int i, int item)
{
	if ((i <= 0) || (i > len+1))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == len)
		{
			ListNode* l = new ListNode();
			l->data = i;
			ListNode* p;
			p = head;
			for (int k = 1; k <= len; k++)
			{
				p = p->next;
			}
			p->next = l;
			len++;
			LL_display();
		}
		else
		{
			ListNode* l = new ListNode();
			l->data = item;
			ListNode* p;
			p = head;
			for (int k = 1; k <= i; k++)
			{
				p = p->next;
			}
			l->next = p;
			p = head;
			for (int k = 1; k <= i - 1; k++)
			{
				p = p->next;
			}
			p->next = l;
			len++;
			LL_display();
		}
	}
}
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == 1)
		{
			ListNode* p;
			p = head;
			for (int k = 1; k <= 2; k++)
			{
				p = p->next;
			}
			head->next = p;
		}
		else if (i == len)
		{
			ListNode* p;
			p = head;
			for (int k = 1; k <= i-1; k++)
			{
				p = p->next;
			}
			p->next = NULL;
		}
		else
		{
			ListNode* m;
			m = head;
			for (int k = 1; k <= i - 1; k++)
			{
				m = m->next;
			}
			ListNode* n;
			n = head;
			for (int k = 1; k <= i + 1; k++)
			{
				n = n->next;
			}
			m->next = n;
		}
		len--;
		LL_display();
	}
}
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	LinkList L;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		L.LL_add(p[i]);
	}
	L.LL_display();
	int i1, i2;
	int d1, d2;
	int g1, g2;
	int x1, x2;
	cin >> i1 >> x1;
	L.LL_insert(i1, x1);
	cin >> i2 >> x2;
	L.LL_insert(i2, x2);
	cin >> d1;
	L.LL_del(d1);
	cin >> d2;
	L.LL_del(d2);
	cin >> g1;
	L.LL_get(g1);
	cin >> g2;
	L.LL_get(g2);
	return 0;
}
/*题目描述
用C++语言和类实现单链表，含头结点

属性包括：data数据域、next指针域

操作包括：插入、删除、查找

注意：单链表不是数组，所以位置从1开始对应首结点，头结点不放数据

类定义参考



输入
n
第1行先输入n表示有n个数据，接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置
输出
n
数据之间用空格隔开，

第1行输出创建后的单链表的数据

每成功执行一次操作（插入或删除），输出执行后的单链表数据

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出单链表

样例输入
6 11 22 33 44 55 66
3 777
1 888
1
11
0
5
样例输出
11 22 33 44 55 66 
11 22 777 33 44 55 66 
888 11 22 777 33 44 55 66 
11 22 777 33 44 55 66 
error
error
44*/