#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class SeqList
{
private:
	int* list;
	int maxsize;
	int size;
public:
	SeqList();
	~SeqList();
	void list_int(int n);
	int list_size();
	void list_insert(int i, int item);
	void list_multiinsert(int i, int n, int* item);
	void list_del(int i);
	void list_multidel(int i, int n);
	void list_get(int i);
	void list_display();
	void list_move(int d,int n);
};
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
SeqList::~SeqList()
{
	delete[]list;
}
void SeqList::list_int(int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	size = n;
}
int SeqList::list_size()
{
	return size;
}
void SeqList::list_insert(int i, int item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size; k >= i; k--)
		{
			list[k] = list[k - 1];
		}
		list[i - 1] = item;
		size++;
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_multiinsert(int i, int n, int* item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size + n - 1; k > i; k--)
		{
			list[k] = list[k - n];
		}
		for (int k = i - 1; k < i - 1 + n; k++)
		{
			list[k] = item[k - i + 1];
		}
		size += n;
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_del(int i)
{
	if ((i > 0) && (i <= size))
	{
		size--;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + 1];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_multidel(int i, int n)
{
	if ((i > 0) && (i <= size))
	{
		size -= n;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + n];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_get(int i)
{
	if ((i > 0) && (i <= size))
		cout << list[i - 1] << endl;
	else
		cout << "error" << endl;
}
void SeqList::list_display()
{
	//cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
void SeqList::list_move(int d,int n)
{
	int* nlist = new int[size];
	if (d == 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (i - n < 0)
			{
				nlist[i - n + size] = list[i];
			}
			else
			{
				nlist[i - n] = list[i];
			}
		}
	}
	else if (d == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (i + n > size-1)
			{
				nlist[i + n - size] = list[i];
			}
			else
			{
				nlist[i + n] = list[i];
			}
		}
	}
	list = nlist;
}
int main()
{
	int n;
	cin >> n;
	SeqList a;
	a.list_int(n);
	a.list_display();
	int d1, x1, d2, x2;
	cin >> d1 >> x1;
	a.list_move(d1, x1);
	a.list_display();
	cin >> d2 >> x2;
	a.list_move(d2, x2);
	a.list_display();
	return 0;
}
/*题目描述
顺序表的移位是循环移位，例如顺序表：1，2，3，4，5，6。如果左移1位，即原来的头元素移动到末尾，其它元素向左移1位，变成2，3，4，5，6，1。同理，如果右移1位，即原来的尾元素移动到头，其它元素向右移1位，变成6，1，2，3，4，5。以下是移位的多个例子：

原数据：1，2，3，4，5，6

左移3位：4，5，6，1，2，3，与原数据对比

右移4位：3，4，5，6，1，2，与原数据对比

请编写程序实现顺序表的循环移位操作

输入
第1行输入n表示顺序表包含的·n个数据

第2行输入n个数据，数据是小于100的正整数

第3行输入移动方向和移动的位数，左移方向为0，右移方向为1

第4行输入移动方向和移动的位数，左移方向为0，右移方向为1

注意：移动操作是针对上一次移动后的结果进行的

输出
第一行输出创建后，顺序表内的所有数据，数据之间用空格隔开

第二行输出第一次移位操作后，顺序表内的所有数据，数据之间用空格隔开

第三行输出第二次移位操作后，顺序表内的所有数据，数据之间用空格隔开

样例输入
5
11 22 33 44 55
0 2
1 4
样例输出
11 22 33 44 55 
33 44 55 11 22 
44 55 11 22 33 */