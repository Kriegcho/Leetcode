#include <vector>

using namespace std;

class Solution {
	void permute(vector<vector<int>>& ans, vector<int>& nums, vector<bool> flags, vector<int> path)
	{
		if (path.size() == nums.size())
		{
			ans.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (flags[i])
			{
				flags[i] = false;
				path.push_back(nums[i]);
				permute(ans, nums, flags, path);
				flags[i] = true;
				path.pop_back();
			}
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<bool> flags(nums.size(), true);
		vector<int> path;
		permute(ans, nums, flags, path);
		return ans;
	}
};