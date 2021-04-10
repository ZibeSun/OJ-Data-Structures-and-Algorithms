#include<iostream>
using namespace std;
class ListNode
{
public:
	ListNode* front;
	char data;
	ListNode* next;
	ListNode()
	{
		front = this;
		next = this;
		data = 0;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList();
	void LL_add(char x);
	ListNode* LL_index(int i);
	void LL_insert(int i, char item);
	void LL_del(int i);
	void zm_del(int i);
	void LL_display();
	void eliminate();
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//在双向链表末尾添加一个结点
void LinkList::LL_add(char x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == head)
	{
		l->front = head;
		head->next = l;
		head->front = l;
	}
	else
	{
		l->front = LL_index(len);
		LL_index(len)->next = l;
		head->front = l;
	}
	len++;
}
//返回第i个结点
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "index_error" << endl;
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
//删除双向链表中的第i个结点
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "del_error" << endl;
	}
	else
	{
		if (i == 1)
		{
			if (len == 1)
			{
				head->next = head;
				head->front = head;
			}
			else
			{
				head->next = LL_index(2);
				LL_index(2)->front = head;
			}
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
			head->front = LL_index(i - 1);
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
			LL_index(i)->front = LL_index(i - 1);
		}
		len--;
	}
}
void LinkList::zm_del(int i)
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
			LL_index(2)->front = head;
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
			head->front = LL_index(i - 1);
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
			LL_index(i + 1)->front = LL_index(i - 1);
		}
		len--;
	}
}
//将item插入双向链表的第i个结点
void LinkList::LL_insert(int i, char item)
{
	if (i == len)
	{
		LL_add(item);
	}
	else if (i == 1)
	{
		if (len == 0)
		{
			LL_add(item);
		}
		else
		{
			ListNode* l = new ListNode();
			l->data = item;
			l->front = head;
			l->next = LL_index(1);
			LL_index(1)->front = l;
			head->next = l;
			len++;
		}
	}
	else
	{
		ListNode* l = new ListNode();
		l->data = item;
		l->next = LL_index(i);
		LL_index(i)->front = l;
		LL_index(i - 1)->next = l;
		l->front = LL_index(i - 1);
		len++;
	}
}
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	if (p->next == head)
	{
		cout << "-";
	}
	while (p->next != head)
	{
		p = p->next;
		cout << p->data;
	}
	cout << endl;
}
void LinkList::eliminate()
{
	if (len<3)
	{
		return;
	}
	else
	{
		ListNode* p;
		int k = 1;
		while (k != 0)
		{
			if (len < 3)
				break;
			for (int i = 2; i <= len - 1; i++)
			{
				k = 0;
				p = LL_index(i);
				//cout << p->front->data << " " << p->data << " " << p->next->data << endl;
				//LL_display();
				if ((p->front->data == p->data) && (p->next->data == p->data))
				{
					//LL_display();
					//cout << "i=" << i << endl;
					//cout << p->front->data << " " << p->data << " " << p->next->data << endl;
					if (p->next->next->data == p->data)
					{
						LL_del(i);
						if(p->next->next->next->data==p->data)
							LL_del(i);
					}
					LL_del(i);
					LL_del(i);
					LL_del(i - 1);
					k = 1;
					break;
				}
			}
		}
	}
}
int main()
{
	string z;
	cin >> z;
	LinkList p;
	for (int i = 0; i < z.length(); i++)
	{
		p.LL_add(z[i]);
	}
	int n;
	cin >> n;
	int m;
	char c;
	while (n--)
	{
		cin >> m >> c;
		p.LL_insert(m+1, c);
		p.eliminate();
		p.LL_display();
	}
}
/*题目描述
祖玛是一款曾经风靡全球的游戏，其玩法是：在一条轨道上初始排列着若干个彩色珠子，其中任意三个相邻的珠子不会完全同色。此后，你可以发射珠子到轨道上并加入原有序列中。一旦有三个或更多同色的珠子变成相邻，它们就会立即消失。这类消除现象可能会连锁式发生，其间你将暂时不能发射珠子。
给定轨道上初始的珠子序列，然后是玩家所做的一系列操作。你的任务是，在各次操作之后及时计算出新的珠子序列。
输入
第一行是一个由大写字母'A'~'Z'组成的字符串，表示轨道上初始的珠子序列，不同的字母表示不同的颜色。

第二行是一个数字n，表示玩家共有n次操作。

接下来的n行依次对应于各次操作。每次操作由一个数字k和一个大写字母描述，以空格分隔。其中，大写字母为新珠子的颜色。若插入前共有m颗珠子，位置0至m-1，则k ∈ [0, m]表示新珠子嵌入在轨道上的位置。

输出
 输出共n行，依次给出各次操作（及可能随即发生的消除现象）之后轨道上的珠子序列。

如果轨道上已没有珠子，则以“-”表示。

样例输入
ACCBA
5
1 B
0 A
2 B
4 C
0 A
样例输出
ABCCBA
AABCCBA
AABBCCBA
-
A*/