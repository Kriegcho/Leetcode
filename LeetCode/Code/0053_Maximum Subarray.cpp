#include <vector>

using namespace std; 

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pos = -1, sum = 0, ans = -10001, n = nums.size(), maxn = -10001;
		for (int i = 0; i < n; i++)
		{
			if (pos == -1)
			{
				if (nums[i] > 0)
				{
					pos = i; // 起点
					sum = nums[i];
				}
			}
			else
			{
				sum += nums[i];
				if (ans < sum)
					ans = sum;
				if (sum < 0)
					pos = -1; // 到这里前面的数字不可能构成后面的最大子数组了，重新找起点
			}
			if (nums[i] > maxn)
				maxn = nums[i];
		}
		if (ans < 0) // 没找到正数
			ans = maxn;
		return ans;
	}
};