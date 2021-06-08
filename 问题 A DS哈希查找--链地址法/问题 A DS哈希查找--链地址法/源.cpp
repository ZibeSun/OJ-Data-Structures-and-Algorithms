#include<iostream>
using namespace std;
class hash_node
{
public:
	int data;   //结点数据
	int order;
	hash_node* next;
	hash_node()
	{
		data = -1;
		order = 1;
		next = NULL;
	}
};
//以求余法为哈希函数
//哈希冲突用链地址法(表头插入)
class hash_map
{
private:
	hash_node* hashmap;   //哈希结点数组
public:
	hash_map(int n)
	{
		hashmap = new hash_node[n];
		int a;
		int key;
		while (n--)
		{
			cin >> a;
			key = a % 11;
			if (hashmap[key].data != -1)
			{
				hash_insert(&hashmap[key], a);
			}
			else
				hashmap[key].data = a;
		}
	}
	//递归查找哈希冲突
	int find_next(hash_node* hash, int target)
	{
		if (hash != NULL)
		{
			if (hash->data != target)
				return find_next(hash->next, target);
			else
				return hash->order;
		}
		else
			return 0;
	}
	//哈希查找函数
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		if (hashmap[key].data != target)
		{
			if (find_next(hashmap[key].next, target) != 0)
			{
				cout << key << " " << find_next(hashmap[key].next, target) << endl;
			}
			else
			{
				//查找失败，将数据插入到哈希表中
				hash_insert(&hashmap[key], target);
				cout << "error" << endl;
			}
		}
		else
		{
			cout << key << " " << hashmap[key].order << endl;
		}
	}
	//哈希插入函数
	//将数据target插人到哈希表中，哈希冲突用链地址法(表头插入)
	void hash_insert(hash_node* hash,int target)
	{
		if (hash->data == -1)
		{
			hash->data = target;
			return;
		}
		else
		{
			if (hash->next != NULL)
			{
				hash_insert(hash->next, target);
				hash->order++;
			}
			else
			{
				hash_node* h = new hash_node();
				h->data = target;
				hash->order++;
				hash->next = h;
			}
		}
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		hash_map h(n);
		int t;
		cin >> t;
		int target;
		while (t--)
		{
			cin >> target;
			h.hash_find(target);
		}
	}
}
/*
题目描述
 给出一个数据序列，建立哈希表，采用求余法作为哈希函数，模数为11，哈希冲突用链地址法和表头插入
如果首次查找失败，就把数据插入到相应的位置中
实现哈希查找功能
输入
第一行输入n，表示有n个数据
第二行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第三行输入t，表示要查找t个数据
从第四行起，每行输入一个要查找的数据，都是正整数
输出
每行输出对应数据的查找结果
样例输入
6
11 23 39 48 75 62
6
39
52
52
63
63
52
样例输出
6 1
error
8 1
error
8 1
8 2
提示
注意，当两次输入要相同的查找数据，如果第一次查找不成功就会执行插入，那么第二次查找必然成功，且查找次数为1次（因为做表头插入）

例如示例数据中输入两次52，第一次查找失败就把52插入到位置8，第二次查找就成功了，所以第一次输出error，第二次就输出8 1

为什么第三次输入52会输出8 2

*/