#include<iostream>
#include<cmath>
using namespace std;
//2路归并排序，递归做法
class MergeSort
{
private:
	int* item;
	int* temp;
	int* item1;
	int len;
	int k;
	int p;
	void sort(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			sort(left, mid);//左边归并排序，使得左子序列有序
			sort(mid + 1, right);//右边归并排序，使得右子序列有序
			merge(left, mid, right);
		}
		p++;
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
	void Display_Children()
	{
		for (int i = k; i > 0; i--)
		{
			display_children(0, len - 1, 1, i);
		}
	}
	void display_children(int left, int right, int pos, int j)
	{
		//cout << "pos=" << pos << endl;
		if (left < right)
		{
			int mid = (left + right) / 2;
			display_children(left, mid, pos * 2, j);
			display_children(mid + 1, right, pos * 2 + 1, j);
		}
		if ((int)(log2(pos) + 1) == j)
		{
			int num = right - left + 1;
			int* item2 = new int[num];
			for (int i = left; i <= right; i++)
			{
				item2[i-left] = item1[i];
			}
			SelectSort(item2, num);
			for (int i = 0; i < num; i++)
			{
				cout << item2[i] << " ";
			}
			cout << endl;
		}
	}
	void SelectSort(int* arr, int n)
	{
		int min;
		for (int i = 0; i < n; i++)
		{
			min = i;
			for (int k = i + 1; k < n; k++)
			{
				if (arr[k] < arr[min])
				{
					min = k;
				}
			}

			int m = arr[i];
			arr[i] = arr[min];
			arr[min] = m;
		}
	}
public:
	MergeSort(int* str, int n)
	{
		p = 0;
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
		cout << p << endl;
		Display_Children();
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
	cin >> n;
	int* str = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	MergeSort ms(str, n);
}
/*
题目描述
给定一组正整数序列，执行2路归并排序算法得到由小到大的序列。要求按2路归并排序树，自下而上自左向右的次序，输出每个有序的子序列。
        [23 38 17 16 25]                        [16  17  23  25  38](9)
        /             \                         /                 \
    [23 38 17]       [16 25]                [17 23 38](7)         [16 25](8)
      /     \         /   \      =>           /     \             /   \
  [23 38]   [17]    [16] [25]            [23 38](3) [17](4)  [16](5) [25](6)
   /   \                                /      \
 [23] [38]                            [23](1) [38](2)
自顶向下进行，即递归调用 MergeSort(left, mid)、MergeSort(mid, right)
本题约定数组区间为[1, n]， mid = (left + right) / 2，递归子区间为 [left, mid]、[mid + 1, right]
输入
第1行该序列的正整数个数n
第2行n个正整数，元素之间由空格分开
输出
m: 表示2路归并排序树的结点个数
m行，每行是有序的子序列
样例输入
5
23 38 17 16 25
样例输出
9
23
38
23 38
17
16
25
17 23 38
16 25
16 17 23 25 38
提示

*/