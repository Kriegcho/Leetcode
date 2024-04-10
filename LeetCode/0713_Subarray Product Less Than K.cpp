#include <vector>
using namespace std; 

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int ans = 0;
		int multi = nums[0];
		int l = 0, r = 1, n = nums.size();
		while (l <= r)
		{
			if (multi < k)
			{
				if (r == n)
					break;
				multi *= nums[r];
				r++;
			}
			else
			{
				if (r > l)
					ans += r - l - 1;
				multi /= nums[l];
				l++;
			}
		}
		if (multi < k && l < r && r == n)
			ans += (r - l + 1) * (r - l) / 2;
		return ans;
	}
};