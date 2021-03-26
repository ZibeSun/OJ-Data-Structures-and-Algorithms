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
	//~LinkList();
	void LL_add(int x);
	ListNode* LL_index(int i);
	void LL_get(int i);
	void LL_insert(int i, int item);
	void LL_del(int i);
	void LL_display();
	void swap(int pa, int pb);
	LinkList LL_merge(LinkList& La, LinkList& Lb);
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
/*LinkList::~LinkList()
{
	head = NULL;
}*/
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
	if ((i <= 0) || (i > len + 1))
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
			for (int k = 1; k <= i - 1; k++)
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
void LinkList::swap(int pa, int pb)
{
	if ((((pa - pb) * (pa - pb))>1)&&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		ListNode* p;
		p = LL_index(pa);

		ListNode* q;
		q = LL_index(pb);

		ListNode* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = LL_index(pa - 1);
		}

		ListNode* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = LL_index(pa + 1);
		}

		ListNode* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = LL_index(pb - 1);
		}

		ListNode* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = LL_index(pb + 1);
		}

		p_before->next = q;
		q->next = p_after;

		q_before->next = p;
		p->next = q_after;
	}
	else if ((((pa - pb) * (pa - pb)) == 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		ListNode* p;
		p = LL_index(pa);

		ListNode* q;
		q = LL_index(pb);

		ListNode* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = LL_index(pa - 1);
		}

		ListNode* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = LL_index(pa + 1);
		}

		ListNode* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = LL_index(pb - 1);
		}

		ListNode* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = LL_index(pb + 1);
		}

		p_before->next = q;
		q->next = p;
		p->next = q_after;
	}
	else
	{
		cout << "error" << endl;
	}
}
LinkList LinkList::LL_merge(LinkList &La, LinkList &Lb)
{
	LinkList L;

	ListNode* p;
	p = La.head;
	for (int i = 1; i <= La.len; i++)
	{
		p = p->next;
		L.LL_insert(i, p->data);
	}

	p = Lb.head;
	for (int i = 1; i <= Lb.len; i++)
	{
		p = p->next;
		L.LL_insert(i, p->data);
	}
	//cout << L.len << endl;
	//L.LL_display();
	for (int i = 1; i <= L.len; i++)
	{
		for (int k = i; k <= L.len; k++)
		{
			//cout << "i=" << i << endl;
			//cout << "k=" << k << endl;
			if (L.LL_index(i)->data > L.LL_index(k)->data)
			{
				L.swap(i, k);
				//L.LL_display();
			}
		}
	}
	return L;
}
int main()
{
	int m;
	cin >> m;
	LinkList La;
	int* p1 = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> p1[i];
		La.LL_add(p1[i]);
	}
	
	int n;
	cin >> n;
	LinkList Lb;
	int* p2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p2[i];
		Lb.LL_add(p2[i]);
	}

	La.LL_merge(La, Lb).LL_display();
	return 0;
}
/*题目描述
假定两个单链表是递增有序，定义并实现以下函数，完成两个单链表的合并，继续保持递增有序

int LL_merge(ListNode *La, ListNode *Lb)

输入
第1行先输入n表示有n个数据，接着输入n个数据
第2行先输入m表示有M个数据，接着输入m个数据
输出
输出合并后的单链表数据，数据之间用空格隔开

样例输入
3 11 33 55
4 22 44 66 88
样例输出
11 22 33 44 55 66 88 
提示*/