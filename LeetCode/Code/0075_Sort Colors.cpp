#include <vector>

using namespace std; 

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int count = 0, n = nums.size();
		for (int i = 0; i < n; i++)
			if (nums[i] == 0)
			{
				if (i != count)
					swap(nums[count], nums[i]);
				count++;
			}
		for (int i = count; i < n; i++)
			if (nums[i] == 1)
			{
				if (i != count)
					swap(nums[count], nums[i]);
				count++;
			}
	}
};