#include <vector>
#include <list>
using namespace std; 

class Solution {
	void dfs(int pos, const vector<list<int>>& ve, vector<int>& path, vector<int>& ans, vector<bool>& visit, int& max_d, int& maxd_i)
	{
		if (max_d < path.size())
		{
			max_d = path.size();
			maxd_i = pos;
			ans.clear();
			if (path.size() % 2 == 0)
				ans.push_back(path[path.size() / 2 - 1]);
			ans.push_back(path[path.size() / 2]);
		}
		for (int next : ve[pos])
		{
			if (!visit[next])
			{
				path.push_back(next);
				visit[next] = true;
				dfs(next, ve, path, ans, visit, max_d, maxd_i);
				visit[next] = false;
				path.pop_back();
			}
		}
	}
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> path, ans;
		vector<list<int>> ve(n);
		for (auto e : edges)
		{
			ve[e[0]].push_back(e[1]);
			ve[e[1]].push_back(e[0]);
		}
		vector<bool> visit(n, false);
		visit[0] = true;
		path.push_back(0);
		int max_d = 0, maxd_i = 0;
		dfs(0, ve, path, ans, visit, max_d, maxd_i);
		path.clear();
		visit.assign(n, false);
		max_d = 0;
		int start = maxd_i;
		visit[start] = true;
		path.push_back(start);
		dfs(start, ve, path, ans, visit, max_d, maxd_i);
		return ans;
	}
};