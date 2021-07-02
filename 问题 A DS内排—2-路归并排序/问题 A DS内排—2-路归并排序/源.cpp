#include<iostream>
#include<cmath>
using namespace std;
//2路归并排序，循环做法
class MergeSort
{
private:
	string* item;
	int len;
	string* temp;
	//归并两个有序子序列
	void merge(int L1, int R1, int L2, int R2)
	{
		int i = L1;
		int j = L2;
		int t = 0;
		while (i <= R1 && j <= R2)
		{
			if (item[i].compare(item[j]) > 0)
				temp[t++] = item[i++];
			else
				temp[t++] = item[j++];
		}

		while (i <= R1)
		{
			temp[t] = item[i];
			t++;
			i++;
		}
		while (j <= R2)
		{
			temp[t] = item[j];
			t++;
			j++;
		}

		for (int i = 0; i < t; i++)
			item[L1 + i] = temp[i];
	}
	void sort()
	{
		for (int step = 2; step / 2 <= len; step *= 2)
		{
			for (int i = 0; i <= len - 1; i += step)
			{
				int mid = i + step / 2 - 1;
				if (mid + 1 <= len - 1)
					merge(i, mid, mid + 1, min(i + step - 1, len - 1));
			}
			display();
		}
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
public:
	MergeSort(string* str, int n)
	{
		item = str;
		len = n;
		temp = new string[len];
		sort();
	}
};
int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		string* str = new string[n];
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		MergeSort ms(str, n);
		cout << endl;
	}
}
/*
题目描述
输入一组字符串，用2-路归并排序按字典顺序进行降序排序。
输入
 测试次数t
每组测试数据：数据个数n，后跟n个字符串，字符串不含空格。
输出
 对每组测试数据，输出2-路归并排序的每一趟排序结果。每组测试数据的输出之间有1空行。
样例输入
2
6 shenzhen beijing guangzhou futian nanshan baoan
10 apple pear peach grape cherry dew fig haw lemon marc


样例输出
shenzhen beijing guangzhou futian nanshan baoan
shenzhen guangzhou futian beijing nanshan baoan
shenzhen nanshan guangzhou futian beijing baoan

pear apple peach grape dew cherry haw fig marc lemon
pear peach grape apple haw fig dew cherry marc lemon
pear peach haw grape fig dew cherry apple marc lemon
pear peach marc lemon haw grape fig dew cherry apple
提示

*/