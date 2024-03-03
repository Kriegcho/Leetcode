#include <vector>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums)
			sum += i;
		if (sum % 2 != 0)
			return false;

		int n = nums.size();
		int t = sum / 2;
		vector<bool> dp(t + 1, false); // 是否能组合成j
		if (nums[0] <= t)
			dp[nums[0]] = true;
		dp[0] = true;
		for (int i = 1; i < n; i++)
			for (int j = t; j > 0; j--)
				if (nums[i] <= j)
					dp[j] = dp[j] | dp[j - nums[i]];
		return dp[t];
	}
};