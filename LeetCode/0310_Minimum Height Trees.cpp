#include <vector>
using namespace std; 

class Solution {
	void dfs(int pos, const vector<vector<int>>& ve, vector<int> path, vector<bool>& visit, vector<int>& maxd)
	{
		path.push_back(pos);
		for (auto vi : ve[pos])
		{
			if (!visit[vi])
			{
				for (int j = 0; j < path.size(); j++)
					if (maxd[path[j]] < path.size() - j)
						maxd[path[j]] = path.size() - j;
				if (maxd[vi] < path.size())
					maxd[vi] = path.size();
				visit[vi] = true;
				dfs(vi, ve, path, visit, maxd);
				visit[vi] = false;
			}
		}

		path.pop_back();
	}
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> path;
		vector<vector<int>> ve(n);
		for (auto e : edges)
		{
			ve[e[0]].push_back(e[1]);
			ve[e[1]].push_back(e[0]);
		}
		vector<bool> visit(n, false);
		visit[0] = true;
		vector<int> maxd(n, 0);
		dfs(0, ve, path, visit, maxd);
		int mind = n;
		for (int i : maxd)
			if (mind > i)
				mind = i;
		vector<int> ans;
		for (int i = 0; i < n; i++)
			if (maxd[i] == mind)
				ans.push_back(i);
		return ans;
	}
};