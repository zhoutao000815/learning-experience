//207. 课程表
//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
//
//在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
//
//例如，先修课程对[0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
//请你判断是否可能完成所有课程的学习如果可以，返回 true ；否则，返回 false 。
//
//
//示例 1：
//
//输入：numCourses = 2, prerequisites = [[1, 0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
//示例 2：
//
//输入：numCourses = 2, prerequisites = [[1, 0], [0, 1]]
//输出：false
//解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
//
//
//提示：
//
//1 <= numCourses <= 105
//0 <= prerequisites.length <= 5000
//prerequisites[i].length == 2
//0 <= ai, bi < numCourses
//prerequisites[i] 中的所有课程对 互不相同
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/course-schedule
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//拓扑排序：BFS遍历
class Solution {
private:
	vector<vector<int>> edges;  //邻接表
	vector<int> indegs;         //统计入度
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		indegs.resize(numCourses);
		for (int i = 0; i<prerequisites.size(); i++)
		{
			edges[prerequisites[i][1]].push_back(prerequisites[i][0]);   //建表
			++indegs[prerequisites[i][0]];                               //统计入度
		}
		queue<int> q;
		for (int i = 0; i<numCourses; i++)                                   //入度为0，入队作为起始输出。
		{
			if (indegs[i] == 0)
				q.push(i);
		}
		int visted = 0;                                            //如果形成闭环，则环内没有度为0的起始节点。无法访问到
		while (!q.empty())
		{
			++visted;
			int b = q.front();
			q.pop();
			for (int i = 0; i<edges[b].size(); i++)                   //将入度为0的这个顶点的所有出度边删掉。
			{
				--indegs[edges[b][i]];                           //减去入度所指向的边，
				if (indegs[edges[b][i]] == 0)
					q.push(edges[b][i]);
			}
		}
		return visted == numCourses;                           //访问节点个数和总结点个数相同则无环。
	}
};