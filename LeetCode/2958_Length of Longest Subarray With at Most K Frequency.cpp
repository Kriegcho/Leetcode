#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int maxSubarrayLength(vector<int>& nums, int k) {
		int n = nums.size();
		int  l = 0, r = 0;
		unordered_map<int, int> m;
		int ans = 0;
		bool flag = true;
		int cur;
		while (l < n && r < n)
		{
			if (flag)
			{
				m[nums[r]]++;
				if (m[nums[r]] > k)
				{
					flag = false;
					cur = nums[r];
				}
				else
				{
					if (ans < r - l + 1)
						ans = r - l + 1;
				}
				r++;
			}
			else
			{
				m[nums[l]]--;
				if (nums[l] == cur)
				{
					flag = true;
					r++;
				}
				l++;
			}
		}
		return ans;
	}
};