#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int l = 0, r = 0;
		int sum = nums[0];
		while (sum < target && r < nums.size() - 1)
		{
			r++;
			sum += nums[r];
		}
		if (sum < target) return 0;
		int ans = r - l + 1;
		while (r < nums.size())
		{
			if (sum >= target)
			{
				ans = min(ans, r - l + 1);
				sum -= nums[l];
				l++;
			}
			else if (r < nums.size() - 1)
			{
				r++;
				sum += nums[r];
			}
			else break;
		}
		return ans;
	}
};