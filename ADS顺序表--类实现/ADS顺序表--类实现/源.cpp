#include<iostream>
#include<stdio.h>
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
	void list_del(int i);
	void list_get(int i);
	void list_display();
};
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
SeqList::~SeqList()
{
	delete []list;
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
	for (int i = 0; i < 1000; i++)
	{
		if (list[i] == '\0')
			size = i + 1;
	}
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
void SeqList::list_get(int i)
{
	if ((i > 0) && (i <= size))
		cout << list[i - 1] << endl;
	else
		cout << "error" << endl;
}
void SeqList::list_display()
{
	cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	SeqList s;
	s.list_int(n);
	s.list_display();
	int a1, a2, b1, b2, c1, c2;
	int item1, item2;
	cin >> a1 >> item1;
	s.list_insert(a1, item1);
	cin >> a2 >> item2;
	s.list_insert(a2, item2);
	cin >> b1;
	s.list_del(b1);
	cin >> b2;
	s.list_del(b2);
	cin >> c1;
	s.list_get(c1);
	cin >> c2;
	s.list_get(c2);
	return 0;
}
/*题目描述
用C++语言和类实现顺序表

属性包括：数组、实际长度、最大长度（设定为1000）

操作包括：创建、插入、删除、查找

类定义参考



输入
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置

输出
数据之间用空格隔开

第1行输出创建后的顺序表内容，包括顺序表实际长度和数据

每成功执行一次操作（插入或删除），输出执行后的顺序表内容

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容

样例输入
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5
样例输出
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44
提示
第i个位置是逻辑意义的位置，从1开始，在实际编程用数组，从0开始，对应数组i-1位置*/