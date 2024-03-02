#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		// 将输入分割为两部分，负值取绝对值，两者合并为一个新数组
		int n = nums.size(), pos = n;
		for (int i = 0; i < n; i++)
			if (nums[i] >= 0)
			{
				pos = i;
				break;
			}
		vector<int> ans;
		int l = pos - 1, r = pos;
		while (l >= 0 || r < n)
		{
			if (l < 0)
			{
				ans.push_back(nums[r] * nums[r]);
				r++;
			}
			else if (r >= n)
			{
				ans.push_back(nums[l] * nums[l]);
				l--;
			}
			else
			{
				if ((-nums[l]) < nums[r])
				{
					ans.push_back(nums[l] * nums[l]);
					l--;
				}
				else
				{
					ans.push_back(nums[r] * nums[r]);
					r++;
				}
			}
		}
		return ans;
	}
};