﻿#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) { // 复杂度O(n²)，通过剪枝勉强ac
		int ans = 0, n = height.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (height[j] >= height[i])
				{
					ans = max(ans, height[i] * (j - i));
					break;
				}
				else if (ans >= height[i] * (j - i)) break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (height[j] >= height[i])
				{
					ans = max(ans, height[i] * (i - j));
					break;
				}
				else if (ans >= height[i] * (i - j)) break;
			}
		}
		return ans;
	}
};