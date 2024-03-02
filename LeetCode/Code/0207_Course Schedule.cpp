#include <vector>
#include <queue>

using namespace std;

class Solution {
	bool DFS(int pos, const vector<vector<int>>& pre, vector<bool> visit, vector<bool>& visited)
	{
		visit[pos] = false;
		for (auto i : pre[pos])
		{
			if (visited[i])
				continue;
			if (!visit[i])
				return false;
			if (!DFS(i, pre, visit, visited))
				return false;
		}
		visit[pos] = true;
		visited[pos] = true;
		return true;
	}

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> pre(numCourses);
		for (auto vec : prerequisites)
			pre[vec[0]].push_back(vec[1]);
		vector<bool> visit(numCourses, true);
		vector<bool> visited(numCourses, false); // 标记已经访问过的课程，从这个课程开始向后找都是合法的
		for (int i = 0; i < numCourses; i++)
		{
			if (visit[i] && !pre[i].empty())
			{
				if (!DFS(i, pre, visit, visited))
					return false;
			}
		}
		return true;
	}
};