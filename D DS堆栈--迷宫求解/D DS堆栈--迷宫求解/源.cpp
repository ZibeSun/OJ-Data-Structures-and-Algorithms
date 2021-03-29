#include<iostream>
#include<stack>
using namespace std;
//迷宫类
class Matrix
{
public:
	int m;
	int n;
	int** data;
public:
	Matrix(int x, int y)
	{
		m = x;
		n = y;
		data = new int* [m];			  //先创建m行
		for (int i = 0; i < m; i++)
		{
			data[i] = new int[n];       //再创建n列
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
	}
};
//用于存储通路坐标的结构
struct cpos
{
	int x;
	int y;
	int z;    //记录路径中该格的上一格在该格所在的行还是该格所在行的上一行
			  //z=0：表示该格的上一格在该格所在的行
			  //z=1：表示该格的上一格在该格所在行的上一行
};
//迷宫求解函数
void FindPath(Matrix& MiGong, stack<cpos>& path)
{
	if (MiGong.data[0][0] == 1)
	{
		cout << "no path" << endl;
		return;
	}
	else
	{
		cpos p;
		//从入口开始，从左到右地遍历迷宫；
		int i = 0;
		for (int j = 0; j <= MiGong.n; j++)
		{
			//如果该格可通且不碰壁，则压入path；
			if ((MiGong.data[i][j] == 0) && (j != MiGong.n))
			{
				if ((path.empty() != true) && (path.top().x != i))
				{
					p.x = i;
					p.y = j;
					p.z = 1;
					path.push(p);
				}
				else
				{
					p.x = i;
					p.y = j;
					p.z = 0;
					path.push(p);
				}
				if ((i == MiGong.n - 1) && (j == MiGong.n - 1))
					break;
			}
			else if ((MiGong.data[i][j] == 1) || (j == MiGong.n))
			{
				//如果已到最下面一行，则迷宫无解
				if (i + 1 == MiGong.n)
				{
					cout << "no path" << endl;
					//cout << "test1" << endl;
					return;
				}
				else
				{
					//如果该格被堵住或者碰壁，但该格下面一格可通，则往下走；
					if (MiGong.data[i + 1][j - 1] == 0)
					{
						i++;
						j -= 2;
					}
					// 如果该格被堵住或者碰壁，且该格下面一格被堵住，则往左退格；
					else if (MiGong.data[i + 1][j - 1] == 1)
					{
						int k = 0;
						//往左退格直到某一格的下面一格可通行，才往下走；
						//cout<<"test"<<endl;

						//若上一格在当前这一行时
						if (path.top().z == 0)
						{
							for (j -= 2; j >= 0; j--)
							{
								//cout<<"test1"<<endl;
								path.pop();
								if (MiGong.data[i][j] == 0)
								{
									if (MiGong.data[i + 1][j] == 0)
									{
										i++;
										j--;
										k++;
										break;
									}
									if (path.top().z == 1)
									{
										for (j -= 1; j >= 0; j--)
										{
											if (MiGong.data[i][j] == 0)
											{
												p.x = i;
												p.y = j;
												path.push(p);
												if (MiGong.data[i + 1][j] == 0)
												{
													i++;
													j--;
													k++;
													break;
												}
											}
											//往左退格时被堵住
											else if (MiGong.data[i][j] == 1)
											{
												cout << "no path" << endl;
												//cout << "test2" << endl;
												return;
											}
										}
									}
								}
								//往左退格时被堵住
								else if (MiGong.data[i][j] == 1)
								{
									cout << "no path" << endl;
									//cout << "test3" << endl;
									return;
								}
							}
						}
						//若上一格在上面一行时
						else if (path.top().z == 1)
						{
							for (j -= 2; j >= 0; j--)
							{
								//cout<<"test2"<<endl;
								if (MiGong.data[i][j] == 0)
								{
									p.x = i;
									p.y = j;
									path.push(p);
									if (MiGong.data[i + 1][j] == 0)
									{
										i++;
										j--;
										k++;
										break;
									}
								}
								//往左退格时被堵住
								else if (MiGong.data[i][j] == 1)
								{
									cout << "no path" << endl;
									//cout << "test4" << endl;
									return;
								}
							}
						}
						//若往左退至无路可退，也无法往下走时，该迷宫无解；
						if (k == 0)
						{
							cout << "no path" << endl;
							//cout << "i=" << i << "j=" << j << endl;
							//cout << "test5" << endl;
							return;
						}
					}
				}
			}
		}
	}
	//将路径压入peth1，转变成正序
	stack<cpos> path1;
	while (path.empty() != true)
	{
		path1.push(path.top());
		path.pop();
	}
	//将路径正序输出
	int i = 0;
	while (path1.empty() != true)
	{
		cpos c = path1.top();
		if ((++i) % 4 == 0)
			cout << "[" << c.x << "," << c.y << "]" << "--" << endl;
		else
			cout << "[" << c.x << "," << c.y << "]" << "--";
		path1.pop();
	}
	cout << "END" << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Matrix MiGong(n, n);
		stack<cpos> path;
		FindPath(MiGong, path);
	}
	return 0;
}
/*
题目描述
给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]

要求使用堆栈对象来实现，具体算法参考课本3.2.4节51页

输入
第一行输入t，表示有t个迷宫

第二行输入n，表示第一个迷宫有n行n列

第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过

输入n行

以此类推输入下一个迷宫

输出
逐个输出迷宫的路径

如果迷宫不存在路径，则输出no path并回车

如果迷宫存在路径，将路径中每个方格的x和y坐标输出，从起点到终点，每输出四个方格就换行，最终以单词END结尾，具体格式参考示范数据

输出的代码参考如下：

//path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示

//path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出

	if (!path.empty())	//找到路径

	{	//......若干代码，实现path的数据导入path1

		i=0;  //以下是输出路径的代码

		while (!path1.empty())

		{	cpos = path1.top();

			if ( (++i)%4 == 0 )

				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;

			else

				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";

			path1.pop();

		}

		cout<<"END"<<endl;

	}

	else

		cout<<"no path"<<endl; //找不到路径输出no path

样例输入
2
8
0 0 0 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 0 1 0 0 0
1 1 0 0 0 0 0 1
0 0 1 1 0 1 1 0
0 0 0 0 0 0 1 1
1 1 1 1 1 0 0 1
0 0 0 0 1 0 0 0
7
0 0 0 1 1 1 1
1 0 0 1 0 0 1
1 0 0 1 0 0 0
1 1 0 0 0 0 1
0 0 1 1 0 1 0
1 0 0 0 0 1 0
0 0 0 0 1 1 0
样例输出
[0,0]--[0,1]--[0,2]--[1,2]--
[1,3]--[2,3]--[3,3]--[3,4]--
[4,4]--[5,4]--[5,5]--[6,5]--
[6,6]--[7,6]--[7,7]--END
no path
*/