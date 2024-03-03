#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 1); // 以nums[i]为子序列结尾的最长递增子序列长度
		for (int i = 1; i < n; i++)
			for (int j = 0; j < i; j++)
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
		int ans = 1;
		for (auto i : dp)
			if (ans < i)
				ans = i;
		return ans;
	}
};