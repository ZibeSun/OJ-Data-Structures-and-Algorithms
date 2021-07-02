#include<iostream>
using namespace std;
//堆排序
class HeapSort
{
private:
	int* item;  //数组指针
	int len;    //数组长度
public:
	HeapSort(int n)
	{
		len = n;
		item = new int[len];
		for (int i = 0; i < len; i++)
		{
			cin >> item[i];
		}
	}
	void sort()
	{
		//构建小堆顶
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			//从最后一个非叶子结点开始，从下至上，从左至右调整结构
			adjustHeap(i,len);
		}
		display();
		//将堆顶元素和末尾元素进行交换，然后再重新对堆进行调整
		for (int j = len - 1; j > 0; j--)
		{
			swap(0,j);      //将堆顶元素和末尾元素进行交换
			adjustHeap(0,j);  //重新对堆进行调整
			display();
		}
	}
	void adjustHeap(int i,int length)
	{
		int temp = item[i];  //先取出当前元素
		for (int k = i * 2 + 1; k < length; k = k * 2 + 1)
		{
			if (k + 1 < length && item[k] > item[k + 1])//从i结点的左子结点开始，也就是2i+1处开始
			{
				//如果右结点存在，且左结点大于右结点，那么k指向右结点
				k++;
			}
			if (item[k] < temp)
			{
				//如果子节点小于父节点，将子节点值赋给父节点
				item[i] = item[k];
				i = k;
			}
		}
		item[i] = temp;
	}
	void swap(int a,int b)
	{
		int m = item[a];
		item[a] = item[b];
		item[b] = m;
	}
	void display()
	{
		cout << len << " ";
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
	HeapSort hs(n);
	hs.sort();
}
/*
题目描述
给定一组数据，使用堆排序完成数据的降序排序。（建小顶堆)。
输入
数据个数n，n个整数数据
输出
初始创建的小顶堆序列
每趟交换、筛选后的数据序列，输出格式见样例
样例输入
8 34 23 677 2 1 453 3 7

样例输出
8 1 2 3 7 23 453 677 34
8 2 7 3 34 23 453 677 1
8 3 7 453 34 23 677 2 1
8 7 23 453 34 677 3 2 1
8 23 34 453 677 7 3 2 1
8 34 677 453 23 7 3 2 1
8 453 677 34 23 7 3 2 1
8 677 453 34 23 7 3 2 1
提示

*/