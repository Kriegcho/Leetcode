#include <vector>
#include <string>
using namespace std; 

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.empty()) return {};
		if (nums.size() == 1) return { to_string(nums[0]) };
		int beg = 0;
		vector<string> ans;
		for (int i = 1; i < nums.size(); i++)
			if (nums[i] != nums[i - 1] + 1)
			{
				if (i - 1 == beg)
					ans.push_back(to_string(nums[beg]));
				else
					ans.push_back(to_string(nums[beg]) + "->" + to_string(nums[i - 1]));
				beg = i;
			}
		if (beg == nums.size() - 1)
			ans.push_back(to_string(nums[beg]));
		else
			ans.push_back(to_string(nums[beg]) + "->" + to_string(nums.back()));
		return ans;
	}
};