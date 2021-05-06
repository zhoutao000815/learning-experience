//剑指 Offer 13. 机器人的运动范围
//地上有一个m行n列的方格，从坐标[0, 0] 到坐标[m - 1, n - 1] 。一个机器人从坐标[0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格[35, 37] ，因为3 + 5 + 3 + 7 = 18。但它不能进入方格[35, 38]，因为3 + 5 + 3 + 8 = 19。请问该机器人能够到达多少个格子？
//
//
//
//示例 1：
//
//输入：m = 2, n = 3, k = 1
//输出：3
//示例 2：
//
//输入：m = 3, n = 1, k = 0
//输出：1
//提示：
//
//1 <= n, m <= 100
//0 <= k <= 20

//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	struct Node{
		int x;
		int y;
		Node(int _x = 0, int _y = 0)
			:x(_x), y(_y) {}
	};

	int get(int x) //获得位数和
	{
		int rel = 0;
		while (x)
		{
			rel += x % 10;
			x /= 10;
		}
		return rel;
	}

	//BFS 广度优先搜索
	int movingCount(int m, int n, int k) {
		if (k == 0){ return 1; }
		vector<vector<int>> res(m, vector<int>(n, 0));
		queue<Node> q;
		q.push(Node(0, 0));
		int count = 0;
		while (!q.empty())
		{

			Node cur = q.front();
			q.pop();
			if (res[cur.x][cur.y] == 1)  //去重思路:即使有重复放入的，检测当前节点是否重复后再决定是否count++，
			{
				continue;
			}
			res[cur.x][cur.y] = 1;
			count++;
			if (cur.x + 1<m &&  get(cur.x + 1) + get(cur.y) <= k)
			{
				q.push(Node(cur.x + 1, cur.y));
			}
			if (cur.y + 1<n &&  get(cur.x) + get(cur.y + 1) <= k)
			{
				q.push(Node(cur.x, cur.y + 1));
			}

			// Node cur=q.front();
			// q.pop();
			// res[cur.x][cur.y]=1;
			// count++;            
			// //去重思路:防止标记过的重复放入队列
			// if(cur.x+1<m && res[cur.x+1][cur.y]==0 && get(cur.x+1)+get(cur.y)<=k) 
			// {q.push(Node(cur.x+1,cur.y));res[cur.x+1][cur.y]=1;}
			// if(cur.y+1<n && res[cur.x][cur.y+1]==0 && get(cur.x)+get(cur.y+1)<=k) 
			// {q.push(Node(cur.x,cur.y+1));res[cur.x][cur.y+1]=1;}   
		}
		return count;
	}
};