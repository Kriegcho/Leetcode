#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0, m = grid.size(), n = grid[0].size();
		int cnt = m * n;
		for (int i = 0; i < cnt; i++)
		{
			if (grid[i / n][i % n] == '1')
			{
				queue<int> q;
				q.push(i);
				grid[i / n][i % n] = '2';
				while (!q.empty())
				{
					int f = q.front();
					if (f % n != n - 1 && grid[f / n][f % n + 1] == '1')
					{
						q.push(f + 1);
						grid[f / n][f % n + 1] = '2';
					}
					if (f % n != 0 && grid[f / n][f % n - 1] == '1')
					{
						q.push(f - 1);
						grid[f / n][f % n - 1] = '2';
					}
					if ((f + n < cnt) && grid[f / n + 1][f % n] == '1')
					{
						q.push(f + n);
						grid[f / n + 1][f % n] = '2';
					}
					if ((f - n >= 0) && grid[f / n - 1][f % n] == '1')
					{
						q.push(f - n);
						grid[f / n - 1][f % n] = '2';
					}
					q.pop();
				}
				ans++;
			}
		}
		return ans;
	}
};