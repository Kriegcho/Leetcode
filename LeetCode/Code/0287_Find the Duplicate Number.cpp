#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int n = nums.size();
		while (1)
		{
			if (nums[0] == nums[nums[0]])
				break;
			swap(nums[0], nums[nums[0]]);
		}
		return nums[0];
	}
};