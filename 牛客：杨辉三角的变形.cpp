//链接：https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
//来源：牛客网
//
//杨辉三角的变形
//热度指数：46112时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//
//1
//
//1  1  1
//
//1  2  3  2  1
//
//1  3  6  7  6  3  1
//
//1  4  10 16 19  16 10  4  1
//
//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
//
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
//
//
//输入n(n <= 1000000000)
//本题有多组输入数据，输入到文件末尾，请使用while(cin >> )等方式读入
//
//输入描述 :
//输入一个int整数
//
//
//
//输出描述 :
//输出返回的int值
//
//示例1
//输入
//4
//2
//输出
//3
//- 1


/*#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> v(1,vector<int>(1,1));
void get_num(int n,vector<int> &flag)   //求出n行杨辉三角，并用一个vector记录每行第一个偶数，但是因为数据最后太大，会变成负数，导致记录表错误。
{
for(int i=0;i<n-1;i++)
{
v.push_back(vector<int>(v[i].size()+2,0));
bool have=false;
for(int j=0;j<(v[i+1].size()+1)/2;j++)
{
if(j==0)
{
v[i+1][j]=v[i][j];
}
else if(j==1)
{
v[i+1][j]=v[i][j]+v[i][j-1];
}
else
{
v[i+1][j]=v[i][j]+v[i][j-1]+v[i][j-2];
}
v[i+1][v[i+1].size()-j-1]=v[i+1][j];
if(!have && v[i+1][j]%2==0)
{
have=true;
flag[i+1]=j+1;
}
}
}
}

int main()
{
int n;
while(cin>>n)
{
vector<int> flag(n,-1);
get_num(n,flag);
cout<<flag[n-1]<<endl;
for(int i=0;i<n;i++)  //打印这个杨辉三角
{
for(int j=0;j<v[i].size();j++)
{
cout<<v[i][j]<<" ";
}
cout<<endl;
}
}
}*/



#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)   //上述打印出来后，找找规律。 前两行-1。  之后  2， 3， 2， 4     如此循环
	{
		if (n <= 2)         
			cout << -1 << endl;
		else
		{
			if (n % 2 == 1)
				cout << 2 << endl;
			else if (n % 4 == 2)
				cout << 4 << endl;
			else if (n % 4 == 0)
				cout << 3 << endl;
		}
	}
	return 0;
}
