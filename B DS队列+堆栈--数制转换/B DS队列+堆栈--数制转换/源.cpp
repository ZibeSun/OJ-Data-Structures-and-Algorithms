#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
struct Double_sp
{
	int zs;
	double xs;
};
char getnumber(int i)
{
	if (i == 0)
		return '0';
	else if (i == 1)
		return '1';
	else if (i == 2)
		return '2';
	else if (i == 3)
		return '3';
	else if (i == 4)
		return '4';
	else if (i == 5)
		return '5';
	else if (i == 6)
		return '6';
	else if (i == 7)
		return '7';
	else if (i == 8)
		return '8';
	else if (i == 9)
		return '9';
	else if (i == 10)
		return 'A';
	else if (i == 11)
		return 'B';
	else if (i == 12)
		return 'C';
	else if (i == 13)
		return 'D';
	else if (i == 14)
		return 'E';
	else if (i == 15)
		return 'F';
}
Double_sp double_separate(double d)
{
	Double_sp d_sp;
	d_sp.zs = 0;
	d_sp.xs = 0;
	while (d >= 1)
	{
		d--;
		d_sp.zs++;
	}
	d_sp.xs = d;
	return d_sp;
}
void Transform(double d,int k)
{
	Double_sp dd;
	dd = double_separate(d);

	stack<char> zs;
	queue<char> xs;
	do
	{
		int num;
		num = dd.zs % k;
		dd.zs = dd.zs / k;
		zs.push(getnumber(num));
	} while (dd.zs != 0);
	while (zs.empty() != true)
	{
		cout << zs.top();
		zs.pop();
	}
	cout << ".";
	for(int i=0;i<3;i++)
	{
		dd.xs = double_separate(dd.xs).xs * k;
		xs.push(getnumber(double_separate(dd.xs).zs));
	}
	while (xs.empty() != true)
	{
		cout << xs.front();
		xs.pop();
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double d;
		int k;
		cin >> d >> k;
		Transform(d, k);
	}
	return 0;
}
/*题目描述
对于任意十进制数转换为k进制，包括整数部分和小数部分转换。整数部分采用除k求余法，小数部分采用乘k取整法例如x=19.125，求2进制转换

整数部分19，					小数部分0.125
19 / 2 = 9 … 1					0.125 * 2 = 0.25 … 0
9 / 2 = 4 … 1					0.25 * 2 = 0.5   … 0
4 / 2 = 2 … 0 					0.5 * 2 = 1     … 1
2 / 2 = 1 … 0
1 / 2 = 0 … 1
所以整数部分转为 10011，小数部分转为0.001，合起来为10011.001

提示整数部分可用堆栈，小数部分可用队列实现

注意：必须按照上述方法来实现数制转换，其他方法0分

输入
第一行输入一个t，表示下面将有t组测试数据。

接下来每行包含两个参数n和k，n表示要转换的数值，可能是非整数；k表示要转换的数制，1<k<=16

输出
对于每一组测试数据，每行输出转换后的结果，结果精度到小数点后3位

输出小数点后几位的代码如下：

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double r = 123.56789;
  cout<<fixed<<setprecision(4)<<r<<endl;   //输出小数点后4

 return 0;
}

样例输入
2
19.125 2
15.125 16
样例输出
10011.001
F.200
提示
 例如：十进制数254.3879转换为6进制数。


整数部分254，

254 / 6 = 42 ... 2

42 / 6 = 7 ... 0

7 / 6 = 1 ... 1

1 / 6 = 0 ... 1


小数部分0.3879，	

0.3879 * 6 = 2.3274   ...  2

0.3274 * 6 = 1.9644 ... 1

0.9644 * 6 = 5.7864 ... 5

所以整数部分转为 1102，小数部分转为0.215，转换后的6进制数合起来为1102.215
*/