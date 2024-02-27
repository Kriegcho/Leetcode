#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == 1)
					for (int k = 1; k <= j; k++)
						dp[i][j] += grid[i - 1][k - 1];
				else if (j == 1)
					for (int k = 1; k <= i; k++)
						dp[i][j] += grid[k - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
			}
		return dp[m][n];
	}
};