#include<iostream>
using namespace std;
class hash_map
{
private:
	int* hashmap;
	int len;

	//哈希插入冲突时递归散列
	//私有函数，类内调用
	void next_insert(int& key, int p)
	{
		key++;
		if (key >= len)
			key = 0;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
			next_insert(key, p);
	}
	//哈希查找冲突时递归散列
	//私有函数，类内调用
	int next_find(int& key, int target, int& num)
	{
		num++;
		key++;
		if (key >= len)
			key = 0;
		if (hashmap[key] < 0)
			return 0;
		else if (hashmap[key] == target)
			return key + 1;
		else
			next_find(key, target, num);
	}
public:
	hash_map(int m)
	{
		len = m;
		hashmap = new int[m];
	}
	//哈希遍历展示函数
	void hash_display()
	{
		for (int i = 0; i < len; i++)
		{
			if (hashmap[i] >= 0)
				cout << hashmap[i] << " ";
			else
			{
				cout << "NULL ";
				//cout << hashmap[i] << " ";
			}
		}
		cout << endl;
	}
	//哈希插入函数
	void hash_insert(int p)
	{
		int key;
		key = p % 11;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
			next_insert(key, p);
	}
	
	//哈希查找函数
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		int num;  //查找次数
		num = 1;
		if (hashmap[key] < 0)
		{
			cout << 0 << " ";
			cout << num << endl;
		}
		else if (hashmap[key] == target)
		{
			cout << 1 << " ";
			cout << num << " ";
			cout << key + 1 << endl;
		}
		else 
		{
			int result = next_find(key, target, num);
			if (result != 0)
			{
				cout << 1 << " ";
				cout << num << " ";
				cout << result << endl;
			}
			else
			{
				cout << 0 << " ";
				cout << num << endl;
			}
		}
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m;   //哈希表长m
		int n;   //关键字个数n
		cin >> m >> n;

		hash_map h(m);

		int item;
		for (int i = 0; i < n; i++)
		{
			cin >> item;
			h.hash_insert(item);
		}

		h.hash_display();

		int k;   //查找次数k
		cin >> k;
		int target;
		while (k--)
		{
			cin >> target;
			h.hash_find(target);
		}
	}
}
/*
题目描述
 定义哈希函数为H(key) = key%11，输入表长（大于、等于11）。输入关键字集合，用线性探测再散列构建哈希表，并查找给定关键字。
--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
 测试次数t
每组测试数据为：
哈希表长m、关键字个数n
n个关键字
查找次数k
k个待查关键字
输出
对每组测试数据，输出以下信息：
构造的哈希表信息，数组中没有关键字的位置输出NULL
对k个待查关键字，分别输出：0或1（0—不成功，1—成功）、比较次数、查找成功的位置（从1开始）
样例输入
1
12 10
22 19 21 8 9 30 33 4 15 14
4
22
56
30
17
样例输出
22 30 33 14 4 15 NULL NULL 19 8 21 9
1 1 1
0 6
1 6 2
0 1

*/