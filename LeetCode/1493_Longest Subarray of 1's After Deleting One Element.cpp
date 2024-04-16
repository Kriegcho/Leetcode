#include <vector>
using namespace std; 

class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int l = 0, r = 0, n = nums.size();
		bool flag = true;
		int ans = 0;
		while (r < n)
		{
			if (flag)
			{
				if (nums[r] == 0)
					flag = false;
				r++;
				if (r - l > ans)
					ans = r - l;
			}
			else
			{
				if (nums[r] == 0)
				{
					while (!flag)
					{
						if (nums[l] == 0)
							flag = true;
						l++;
					}
				}
				else
				{
					r++;
					if (r - l > ans)
						ans = r - l;
				}
			}
		}
		ans--;
		return ans;
	}
};