#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy = 0, ans = 0, n = prices.size();
		for (int i = 1; i < n; i++)
		{
			if (prices[i] < prices[buy])
				buy = i;
			else
			{
				int p = prices[i] - prices[buy];
				if (ans < p)
					ans = p;
			}
		}
		return ans;
	}
};