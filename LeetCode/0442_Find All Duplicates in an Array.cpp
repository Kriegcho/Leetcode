#include <vector>
using namespace std; 

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == -1)
				continue;
			if (nums[i] != i + 1)
			{
				if (nums[nums[i] - 1] == -1 || nums[i] == nums[nums[i] - 1])
					nums[nums[i] - 1] = -1;
				else
				{
					swap(nums[i], nums[nums[i] - 1]);
					i--;
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < n; i++)
			if (nums[i] == -1)
				ans.push_back(i + 1);
		return ans;
	}
};