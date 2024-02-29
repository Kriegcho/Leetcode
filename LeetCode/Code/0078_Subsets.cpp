#include <vector>

using namespace std; 

class Solution {
	void solve(vector<int>& nums, int r, vector<vector<int>>& ans)
	{
		if (r == 0)
		{
			ans.push_back({});
			ans.push_back({ nums[r] });
		}
		else
		{
			solve(nums, r - 1, ans);
			int n = ans.size();
			for (int i = 0; i < n; i++)
			{
				auto v1(ans[i]);
				v1.push_back(nums[r]);
				ans.push_back(v1);
			}
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size() - 1;
		solve(nums, n, ans);
		return ans;
	}
};