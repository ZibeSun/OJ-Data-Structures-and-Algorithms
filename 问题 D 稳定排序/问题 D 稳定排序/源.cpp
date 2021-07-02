#include<iostream>
using namespace std;
//直接插入排序
void StraightInsertSort(int** item, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k][0] < item[k - 1][0])
			{
				int* m = item[k];
				item[k] = item[k - 1];
				item[k - 1] = m;
			}
			else
				break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << item[i][0] << " " << item[i][1] << endl;
	}
}
//2路归并排序，递归做法
class MergeSort
{
private:
	int* item;
	int* temp;
	int* item1;
	int len;
	int k;
	void sort(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			sort(left, mid);//左边归并排序，使得左子序列有序
			sort(mid + 1, right);//右边归并排序，使得右子序列有序
			merge(left, mid, right);
		}
	}
	//归并
	void merge(int left, int mid, int right)
	{
		int i = left;//左序列指针
		int j = mid + 1;//右序列指针
		int t = 0;//临时数组指针
		while (i <= mid && j <= right)
		{
			if (item[i] < item[j])
			{
				temp[t] = item[i];
				t++;
				i++;
			}
			else
			{
				temp[t] = item[j];
				t++;
				j++;
			}
		}
		while (i <= mid)
		{
			//将左子序列剩余元素填入temp中
			temp[t] = item[i];
			t++;
			i++;
		}
		while (j <= right)
		{
			//将右子序列剩余元素填入temp中
			temp[t] = item[j];
			t++;
			j++;
		}
		//将temp中的元素全部拷贝到原数组中
		t = 0;
		while (left <= right)
		{
			item[left] = temp[t];
			t++;
			left++;
		}
	}
	bool IsInteger(double a)
	{
		if (a - (int)a == 0)
			return true;
		else
			return false;
	}
public:
	MergeSort(int* str, int n)
	{
		item = str;
		len = n;
		item1 = new int[len];
		for (int i = 0; i < len; i++)
		{
			item1[i] = str[i];
		}
		temp = new int[len];
		if (IsInteger(log2(len)))
			k = (int)log2(len) + 1;
		else
			k = (int)log2(len) + 2;
		sort(0, len - 1);
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	int n;
	while (cin >> n)
	{
		int** item = new int* [n];
		for (int i = 0; i < n; i++)
		{
			item[i] = new int[2];
			cin >> item[i][0] >> item[i][1];
		}
		//StraightInsertSort(item, n);
	}
}
/*
题目描述
给出二元数组a[MAXN][2]，按第一个关键值从小到大排序后输出，要求第一关键值相同情况下不改变原数组次序

输入
每组数据第一行为整数n，1 <= n <= 10 ^ 5。

接下来n行每行两个整数空格隔开。

输出
输出排序后的数组

样例输入
3
2 4
1 0
2 3
3
4 2
0 4
0 2
样例输出
1 0
2 4
2 3
0 4
0 2
4 2
提示
*/