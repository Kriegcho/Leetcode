#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() == 1)
		{
			if (amount % coins[0] == 0)
				return amount / coins[0];
			else
				return -1;
		}
		else
		{
			sort(coins.begin(), coins.end());
			vector<int> dp(amount + 1, -1);
			dp[0] = 0;
			for (int i = coins[0]; i <= amount; i++)
			{
				int minc = INT_MAX;
				for (auto j : coins)
				{
					if (j < i)
					{
						if (dp[i - j] < minc && dp[i -j] != -1)
							minc = dp[i - j];
					}
					else if (j == i)
						minc = 0;
					else
						break;
				}
				if (minc == INT_MAX)
					dp[i] = -1;
				else
					dp[i] = minc + 1;
			}
			return dp[amount];
		}
	}
};