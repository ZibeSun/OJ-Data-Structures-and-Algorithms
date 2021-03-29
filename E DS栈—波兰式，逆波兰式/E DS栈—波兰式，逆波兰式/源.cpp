#include<iostream>
#include<stack>
using namespace std;
struct InPut
{
	int number;
	char op;
};
int getnumber(char c)
{
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
}
//判断输入符是否为数字
bool JudgeNumber(char c)
{
	if ((c >= '0') && (c <= '9'))
		return true;
	else
		return false;
}
//判断输入符是否为运算符
bool JudgeOP(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/')|| (c == '(') || (c == ')'))
		return true;
	else
		return false;
}
//比较两运算符的优先级
//若运算符c1的优先级较高则返回true；否则返回false
bool CompareLevel(char c1,char c2)
{
	if (c1 == '+')
	{
		if (c2 == '+')
		{
			return false;
		}
		else if (c2 == '-')
		{
			return false;
		}
		else if (c2 == '*')
		{
			return false;
		}
		else if (c2 == '/')
		{
			return false;
		}
	}
	else if (c1 == '-')
	{
		if (c2 == '+')
		{
			return false;
		}
		else if (c2 == '-')
		{
			return false;
		}
		else if (c2 == '*')
		{
			return false;
		}
		else if (c2 == '/')
		{
			return false;
		}
	}
	else if (c1 == '*')
	{
		if (c2 == '+')
		{
			return true;
		}
		else if (c2 == '-')
		{
			return true;
		}
		else if (c2 == '*')
		{
			return false;
		}
		else if (c2 == '/')
		{
			return false;
		}
	}
	else if (c1 == '/')
	{
		if (c2 == '+')
		{
			return true;
		}
		else if (c2 == '-')
		{
			return true;
		}
		else if (c2 == '*')
		{
			return false;
		}
		else if (c2 == '/')
		{
			return false;
		}
	}
}
void PolishChange(InPut* input,int len)
{
	stack<InPut> output;
	stack<InPut> OPTR;
	//从后往前开始扫描input
	for (int i = 0; i < len; i++)
	{
		//若扫描到的input[i]是操作数
		if ((input[i].number != -999) && (input[i].op == 'N'))
		{
			output.push(input[i]);
		}
		//若扫描到的input[i]是闭括号')'
		if ((input[i].number == -999) && (input[i].op == ')'))
		{
			OPTR.push(input[i]);
		}
		//若扫描到的input[i]是运算符
		if ((input[i].number == -999) && (input[i].op != 'N') && (input[i].op != '(') && (input[i].op != ')'))
		{
			if (OPTR.empty() == true)
			{
				OPTR.push(input[i]);
			}
			else
			{
				if ((OPTR.top().op == ')') || (CompareLevel(OPTR.top().op, input[i].op) == false))
				{
					OPTR.push(input[i]);
				}
				else
				{
					output.push(OPTR.top());
					OPTR.pop();
					i--;
					continue;
				}
			}
		}
		//若扫描到的input[i]是开括号'('

		if ((input[i].number == -999) && (input[i].op == '('))
		{
			while (OPTR.top().op != ')')
			{
				output.push(OPTR.top());
				OPTR.pop();
			}
			OPTR.pop();
		}
	}
	//若扫描结束后运算符栈不为空
	if (OPTR.empty() != true)
	{
		while (OPTR.empty() != true)
		{
			output.push(OPTR.top());
			OPTR.pop();
		}
	}
	//输出结果
	int k = 0;
	while (output.empty() != true)
	{
		if (k == 0)
		{
			if ((output.top().number != -999) && (output.top().op == 'N'))
				cout << output.top().number;
			else if ((output.top().number == -999) && (output.top().op != 'N'))
				cout << output.top().op;
			output.pop();
			k++;
		}
		else
		{
			if ((output.top().number != -999) && (output.top().op == 'N'))
				cout << " " << output.top().number;
			else if ((output.top().number == -999) && (output.top().op != 'N'))
				cout << " " << output.top().op;
			output.pop();
		}
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		InPut* input = new InPut[500];
		string ip;
		cin >> ip;
		int n = 0;
		int k = 1;
		int j = 0;
		for (int i = ip.length()-1; i >=0 ; i--)
		{
			n = 0;
			k = 1;
			while (JudgeNumber(ip[i]))
			{
				int sum = getnumber(ip[i]);
				for (int h = 1; h < k; h++)
					sum = sum * 10;
				n += sum;
				k++;
				if (i > 0)
					i--;
				else
					break;
			}
			if (k != 1)
			{
				input[j].number = n;
				input[j].op = 'N';
				j++;
				if (i == 0)
					break;
			}
			if (JudgeOP(ip[i]))
			{
				input[j].op = ip[i];
				input[j].number = -999;
				j++;
			}
		}
		PolishChange(input, j);
	}
}
/*题目描述
       表达式有三种表示方法，分别为：

    前缀表示(波兰式)：运算符+操作数1+操作数2

    中缀表示：操作数1+运算符+操作数2

    后缀表示(逆波兰式)：操作数1+操作数2+运算符

    例如：a +b * (c -d ) - e/f

    波兰式：-+a*b-cd/ef     （运算符在操作数的前面，用递归计算波兰式）

    中缀式：a+b*c-d-e/f  

    逆波兰式：abcd-*+ef/   （运算符在操作数的后面，用栈计算逆波兰式）

       中缀表示就是原表达式去掉扣号。       

     根据表达式求波兰式、逆波兰式都是教材第三章表达式求值的思想。     

      求波兰式，需要操作数栈(注意不是计算结果入栈，有计算式入栈)，运算符栈。区别在于从后往前扫描表达式，‘(’ 换成')','('换成‘)’。栈顶运算符优先级>新读入运算符优先级出栈，教材第三章表3.1中的相同运算符优先级>（从左往右计算）改为<，例如栈顶为‘+‘，新读入的为‘+’，则栈顶优先级<新读入的优先级。

     求逆波兰式，只需要运算符栈。操作数直接输出，操作符按表3.1优先级顺序出栈，输出。

       输入表达式，求其波兰式和逆波兰式。

输入
 测试次数

每组测试数据一行，一个合法表达式

输出
 对每组测试数据，输出两行

第一行，表达式的波兰表示

第二行，表达式的逆波兰表示

不同组测试数据间以空行分隔。

样例输入
2
4+2*3-10/5
12+3*5+(2+10)*5 
样例输出
- + 4 * 2 3 / 10 5
4 2 3 * + 10 5 / -

+ + 12 * 3 5 * + 2 10 5
12 3 5 * + 2 10 + 5 * +*/