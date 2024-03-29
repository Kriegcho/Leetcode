﻿#include <vector>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MIN, cur = 1;
		for (int i = 0; i < n; i++)
		{
			cur *= nums[i];
			if (ans < cur)
				ans = cur;
			if (cur == 0)
				cur = 1;
		}
		cur = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			cur *= nums[i];
			if (ans < cur)
				ans = cur;
			if (cur == 0)
				cur = 1;
		}
		return ans;
	}
};