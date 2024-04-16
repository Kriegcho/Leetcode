#include <vector>
using namespace std; 

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		int l = 0, r = 0, n = nums.size();
		int cnt = 0, ans = 0;
		bool flag = true;
		while (r < n)
		{
			if (flag)
			{
				if (nums[r] == 0)
					cnt++;
				r++;
				if (cnt > k)
					flag = false;
				else
				{
					int len = r - l + 1;
					if (len > ans)
						ans = len;
				}
			}
			else
			{
				if (nums[l] == 0)
				{
					cnt--;
					flag = true;
				}
				l++;
			}
		}
		return ans;
	}
};