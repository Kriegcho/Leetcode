#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		if (source == destination)
			return true;
		vector<vector<int>> ve(n);
		for (auto e : edges)
		{
			ve[e[0]].push_back(e[1]);
			ve[e[1]].push_back(e[0]);
		}
		queue<int> q;
		q.push(source);
		vector<bool> visit(n, false);
		visit[source] = true;
		while (!q.empty())
		{
			int qf = q.front();
			for (int vi : ve[qf])
			{
				if (vi == destination)
					return true;
				if (!visit[vi])
				{
					q.push(vi);
					visit[vi] = true;
				}
			}
			q.pop();
		}
		return false;
	}
};