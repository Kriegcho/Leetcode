#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 下标从1开始，分别以i, j 为末端的minDistance
		for (int i = 0; i <= m; i++)
			dp[i][0] = i;
		for (int i = 0; i <= n; i++)
			dp[0][i] = i;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					// 是子问题的增/删/换次数+1
					dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
					dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]) + 1;

				}
			}
		return dp[m][n];
	}
};