//链接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
//来源：牛客网
//
//红与黑
//
//
//有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
//
//输入描述 :
//输入包含多组数据。
//
//每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：
//
//1. “.”：黑色的瓷砖；
//2. “#”：白色的瓷砖；
//3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
//
//
//输出描述 :
//对应每组数据，输出总共能够到达多少块黑色的瓷砖。
//
//示例1
//
//输入
//9 6
//....#.
//.....#
//......
//......
//......
//......
//......
//#@...#
//.#..#.
//
//输出
//45

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int row, col;

bool check(int x, int y, vector<vector<char>>& room)
{
	return x >= 0 && x < row && y >= 0 && y < col && room[x][y] == '.';
}

void bfs(vector<vector<char>> &exc, queue<pair<int, int>> &q)
{
	int count = 1;  //由于初始位置为@并且为黑砖，所以从1开始。
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		if (check(pos.first, pos.second, exc))
			count++;
		exc[pos.first][pos.second] = '#';
		if (check(pos.first - 1, pos.second, exc))
			q.push(make_pair(pos.first - 1, pos.second));
		if (check(pos.first + 1, pos.second, exc))
			q.push(make_pair(pos.first + 1, pos.second));
		if (check(pos.first, pos.second - 1, exc))
			q.push(make_pair(pos.first, pos.second - 1));
		if (check(pos.first, pos.second + 1, exc))
			q.push(make_pair(pos.first, pos.second + 1));
	}
	cout << count << endl;
}

void dfs(vector<vector<char>> &exc, int x, int y, int &count)
{
	if (x<0 || x == row || y<0 || y == col || exc[x][y] == '#') //由于初始位置为@，！check（）会直接退出。
		return;
	count++;
	exc[x][y] = '#';
	dfs(exc, x - 1, y, count);
	dfs(exc, x + 1, y, count);
	dfs(exc, x, y - 1, count);
	dfs(exc, x, y + 1, count);
}

int main()
{
	while (cin >> row >> col)
	{
		vector<vector<char>> exc(row, vector<char>(col));
		int begin_row, begin_col;
		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<col; j++)
			{
				cin >> exc[i][j];
				if (exc[i][j] == '@')
				{
					begin_row = i;
					begin_col = j;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push(make_pair(begin_row, begin_col));

		bfs(exc, q);

		/*int count=0;
		dfs(exc,begin_row, begin_col,count);
		cout<<count<<endl;*/
	}
	return 0;
}