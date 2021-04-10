//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
class ListNode
{
public:
	int data;
	int position;
	ListNode* next;
	ListNode()
	{
		next = NULL;
		data = 0;
		position = 0;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList();
	void LL_add(int x);
	ListNode* LL_index(int i);
	void LL_del(int i);
	void out(int n, int s, int k);
	void sort();
	void LL_display();
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
void LinkList::LL_add(int x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == NULL)
	{
		head->next = l;
	}
	else
	{
		LL_index(len)->next = l;
	}
	len++;
}
ListNode* LinkList::LL_index(int i)
{
	if (i > len)
	{
		i = i - len;
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
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
			head->next = LL_index(2);
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
		}
		len--;
	}
}
void LinkList::out(int n, int s, int k)
{
	ListNode* p;
	p = LL_index(s);
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i < k; i++)
		{
			p = p->next;
			if (p == head)
				p = p->next;
		}
		cout << p->data << " ";
		LL_del(p->position);
		sort();
		p = p->next;
		if (p == head)
			p = p->next;
	}
	cout << endl;
}
void LinkList::sort()
{
	ListNode* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		p->position = i;
	}
}

void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		cout << p->data << " " << p->position << endl;
	}
	cout << endl;
}
int main()
{
	int n, k, s;
	while (scanf_s("%d %d %d", &n, &k, &s) != EOF)
	{
		cin >> n >> k >> s;
		LinkList r;
		for (int i = 1; i <= n; i++)
		{
			r.LL_add(i);
		}
		r.sort();
		r.out(n, s, k);
	}
	return 0;
}
/*题目描述
N个人坐成一个圆环（编号为1 - N），从第S个人开始报数，数到K的人出列，后面的人重新从1开始报数。问最后剩下的人的编号。
例如：N = 3，K = 2，S = 1。2号先出列，然后是1号，最后剩下的是3号。
要求使用循环链表实现。
输入
测试数据有多组

每组包括3个数N、K、S，表示有N个人，从第S个人开始，数到K出列。(1 <= N <= 10^6，1 <= K <= 10,  1 <= S <= N)

输出
出列的人的编号

样例输入
13 3 1
3 2 1
样例输出
3 6 9 12 2 7 11 4 10 5 1 8 13
2 1 3
提示*/