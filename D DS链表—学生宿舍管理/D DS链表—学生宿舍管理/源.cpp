#include<stdio.h>
#include<iostream>
using namespace std;
//学生宿舍结点
class StuD
{
public:
	int number;
	string name;
	StuD* next;
	StuD()
	{
		number = 0;
		name = "无";
		next = NULL;
	}
};
//已用宿舍链表
class StuDList_used
{
public:
	StuD* head;
	int len;
	StuDList_used();
	~StuDList_used();
	StuD* index(int i);
	void swap(int pa, int pb);
	void range();
	void display();
	void StuD_assign(string name, int number);
	void StuD_return(int number);
};
StuDList_used::StuDList_used()
{
	head = new StuD();
	len = 0;
}
StuDList_used::~StuDList_used()
{
	head = NULL;
}
StuD* StuDList_used::index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		StuD* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
}
void StuDList_used::swap(int pa, int pb)
{
	if ((((pa - pb) * (pa - pb)) > 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		StuD* p;
		p = index(pa);

		StuD* q;
		q = index(pb);

		StuD* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = index(pa - 1);
		}

		StuD* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = index(pa + 1);
		}

		StuD* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = index(pb - 1);
		}

		StuD* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = index(pb + 1);
		}

		p_before->next = q;
		q->next = p_after;

		q_before->next = p;
		p->next = q_after;
	}
	else if ((((pa - pb) * (pa - pb)) == 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		StuD* p;
		p = index(pa);

		StuD* q;
		q = index(pb);

		StuD* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = index(pa - 1);
		}

		StuD* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = index(pa + 1);
		}

		StuD* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = index(pb - 1);
		}

		StuD* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = index(pb + 1);
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
void StuDList_used::range()
{
	for (int i = 1; i <= len; i++)
	{
		for (int k = i; k <= len; k++)
		{
			if (index(i)->number > index(k)->number)
			{
				swap(i, k);
			}
		}
	}
}
void StuDList_used::display()
{
	StuD* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		if (i == 1)
			cout << p->name << "(" << p->number << ")";
		else
			cout<<"-" << p->name << "(" << p->number << ")";
	}
	cout << endl;
}
void StuDList_used::StuD_assign(string name,int number)
{
	StuD* d = new StuD();
	d->name = name;
	d->number = number;
	if (head->next == NULL)
	{
		head->next = d;
	}
	else
	{
		index(len)->next = d;
	}
	len++;
	range();
}
void StuDList_used::StuD_return(int number)
{
	StuD* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		if (p->number == number)
		{
			if (i == 1)
				head->next = index(2);
			else if (i == len)
				index(i-1)->next = NULL;
			else
				index(i-1)->next = index(i + 1);
			len--;
		}
	}
}

//可用宿舍链表
class StuDList_unused
{
public:
	StuD* head;
	int len;
	StuDList_unused();
	~StuDList_unused();
	StuD* index(int i);
	void swap(int pa, int pb);
	void range();
	void display();
	int StuD_use();
	void StuD_back(int number);
	void StuD_use(int number);
};
StuDList_unused::StuDList_unused()
{
	head = new StuD();
	for (int i = 1; i <= 20; i++)
	{
		StuD_back(100 + i);
	}
	range();
}
StuDList_unused::~StuDList_unused()
{
	head = NULL;
}
StuD* StuDList_unused::index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		StuD* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
}
void StuDList_unused::swap(int pa, int pb)
{
	if ((((pa - pb) * (pa - pb)) > 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		StuD* p;
		p = index(pa);

		StuD* q;
		q = index(pb);

		StuD* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = index(pa - 1);
		}

		StuD* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = index(pa + 1);
		}

		StuD* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = index(pb - 1);
		}

		StuD* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = index(pb + 1);
		}

		p_before->next = q;
		q->next = p_after;

		q_before->next = p;
		p->next = q_after;
	}
	else if ((((pa - pb) * (pa - pb)) == 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		StuD* p;
		p = index(pa);

		StuD* q;
		q = index(pb);

		StuD* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = index(pa - 1);
		}

		StuD* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = index(pa + 1);
		}

		StuD* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = index(pb - 1);
		}

		StuD* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = index(pb + 1);
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
void StuDList_unused::range()
{
	for (int i = 1; i <= len; i++)
	{
		for (int k = i; k <= len; k++)
		{
			if (index(i)->number > index(k)->number)
			{
				swap(i, k);
			}
		}
	}
}
void StuDList_unused::display()
{
	StuD* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		if (i == 1)
			cout << p->number;
		else
			cout << "-" << p->number;
	}
	cout << endl;
}
int StuDList_unused::StuD_use()
{
	int number;
	number = index(1)->number;
	head->next = index(2);
	len--;
	return number;
}
void StuDList_unused::StuD_back(int number)
{
	StuD* d = new StuD();
	d->number = number;
	if (head->next == NULL)
	{
		head->next = d;
	}
	else
	{
		index(len)->next = d;
	}
	len++;
}
void StuDList_unused::StuD_use(int number)
{
	StuD* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		if (p->number == number)
		{
			if (i == 1)
				head->next = index(2);
			else if (i == len)
				index(i - 1)->next = NULL;
			else
				index(i - 1)->next = index(i + 1);
			len--;
		}
	}
}

//申请宿舍操作封装
void assign(StuDList_used &used,StuDList_unused &unused,string name)
{
	used.StuD_assign(name, unused.StuD_use());
}
//归还宿舍操作封装
void rreturn(StuDList_used& used, StuDList_unused& unused, int number)
{
	used.StuD_return(number);
	unused.StuD_back(number);
}
int main()
{
	int n;
	cin >> n;
	StuDList_used used;
	StuDList_unused unused;
	for (int i = 0; i < n; i++)
	{
		string s;
		int ii;
		cin >> s;
		cin >> ii;
		used.StuD_assign(s,ii);
		unused.StuD_use(ii);
	}
	int m;
	cin >> m;
	string s1, s2;
	int ii;
	s1 = " ";
	s2 = " ";
	ii = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> s1;
		if (s1 == "assign")
		{
			cin >> s2;
			assign(used, unused, s2);
		}
		else if (s1 == "return")
		{
			cin >> ii;
			rreturn(used, unused, ii);
		}
		else if (s1 == "display_used")
			used.display();
		else if (s1 == "display_free")
			unused.display();
	}
	return 0;
}
/*题目描述
假设某校有20间宿舍，宿舍编号101，102，...,120。每间只住一名学生。初始部分宿舍已用。用两个链表（已用宿舍链表和可用宿舍链表）维护宿舍的管理，实现宿舍分配、宿舍交回。

约定已用宿舍链表按宿舍号升序链接。初始可用宿舍链表也按宿舍号升序链接。

宿舍分配从可用宿舍链表中摘取第一间宿舍分配给学生。学生交回的宿舍挂在可用宿舍链表最后。

备注：使用list容器或静态链表。不用考虑宿舍分配和交回不成功的情况。

输入
初始宿舍状态，第一行输入n，表示已用宿舍n间

后跟n行数据，每行格式为：宿舍号 学生姓名

操作次数m，后跟m行操作，操作格式如下：

assign 学生  //为学生分配宿舍，从可用宿舍链表头摘取一间宿舍，

                    //按宿舍号升序挂在已用宿舍链表中。

return  宿舍号   //学生退宿舍，删除已用宿舍链表中对应结点，

                         //挂在可用宿舍链表尾部。

display_free   //输出可用宿舍链表信息。

display_used   //输出已用宿舍链表信息。



输出
 display_free依次输出当前可用宿舍链表中的宿舍号，具体格式见样例。

 display_used依次输出当前已用宿舍链表中的学生和宿舍号，具体格式见样例。

样例输入
5
李明  103
张三  106
王五  107
钱伟  112
章立  118
8
assign 李四
assign 赵六
return 118
return 101
assign 马山
display_used
assign 林立
display_free
样例输出
赵六(102)-李明(103)-马山(104)-张三(106)-王五(107)-钱伟(112)
108-109-110-111-113-114-115-116-117-119-120-118-101

提示
list是一种序列式容器, list实际上就构成了一个双向循环链,

List类使用的参考代码

包含头文件<list>  ：  #include <list>

List定义和初始化：

    list<int>lst1;          //创建空list

    list<int> lst2(5);       //创建含有5个元素的list

    list<int>lst3(3,2);  //创建含有3个元素的list

    list<int>lst4(lst2);    //使用lst2初始化lst4

    list<int>lst5(lst2.begin(),lst2.end());  //同lst4


创建一个list对象l（注意list是模板类）：list<char>  l; //堆栈的数据类型是字符型

把一个字符ct添加到链表末尾： s.push_back(ct);

把一个字符ct插入到链表头部： s.push_front(ct);

获取链表第一个元素和最后一个元素：front()和back()，获取链表第一个元素，放入变量c2： c2 = s.front();

删除链表第一个元素和最后一个元素pop_front()和pop_back();

判断 判断list是否为空:empty()： l.empty()，如果为空则函数返回true，如果不空则返回false

begin() 返回指向第一个元素的迭代器 

end() 返回末尾的迭代器

rbegin() 返回指向第一个元素的逆向迭代器 

rend() 指向list末尾的逆向迭代器


程序示列：

#include <iostream> 

using namespace std;

typedef list<int> LISTINT; 

    

 void main() 

 { 

   //用LISTINT创建一个list对象 

   LISTINT listOne; 

   //声明i为迭代器 

   LISTINT::iterator i; 

    

   listOne.push_front(3); 

   listOne.push_front(2); 

   listOne.push_front(1); 

    

   listOne.push_back(4); 

   listOne.push_back(5); 

   listOne.push_back(6); 

    

   cout << "listOne.begin()--- listOne.end():" << endl; 

   for (i = listOne.begin(); i != listOne.end(); ++i) 

     cout << *i << " "; 

   cout << endl;    //正向输出

    

   LISTINT::reverse_iterator ir; 

   cout << "listOne.rbegin()---listOne.rend():" << endl; 

   for (ir = listOne.rbegin(); ir != listOne.rend(); ir++) { 

     cout << *ir << " "; 

   }   

   cout << endl;    //反向输出

}
*/