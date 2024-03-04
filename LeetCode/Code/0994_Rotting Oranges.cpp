#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int ans = 0;
		unordered_set<int> s1, s2, s3; // s2, s3交替表示新一轮的rotten
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					s1.insert(i * n + j);
				else if (grid[i][j] == 2)
					s2.insert(i * n + j);
			}
		if (s1.empty())
			return 0;
		else if (s2.empty())
			return -1;
		while (1)
		{
			int c1 = s1.size();
			auto& s_i = s2.empty() ? s2 : s3;
			auto& s_o = s2.empty() ? s3 : s2;
			for (auto i : s_o)
			{
				if (i / n < m - 1 && grid[i / n + 1][i % n] == 1)
				{
					s_i.insert(i + n);
					s1.erase(i + n);
					grid[i / n + 1][i % n] = 2;
				}
				if (i / n > 0 && grid[i / n - 1][i % n] == 1)
				{
					s_i.insert(i - n);
					s1.erase(i - n);
					grid[i / n - 1][i % n] = 2;
				}
				if (i % n < n - 1 && grid[i / n][i % n + 1] == 1)
				{
					s_i.insert(i + 1);
					s1.erase(i + 1);
					grid[i / n][i % n + 1] = 2;
				}
				if (i % n > 0 && grid[i / n][i % n - 1] == 1)
				{
					s_i.insert(i - 1);
					s1.erase(i - 1);
					grid[i / n][i % n - 1] = 2;
				}
			}
			s_o.clear();
			ans++;
			int c2 = s1.size();
			if (c2 == 0)
				break;
			else if (c1 == c2)
				return -1;
		}
		return ans;
	}
};