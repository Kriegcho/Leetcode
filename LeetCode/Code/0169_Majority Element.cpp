#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int cur = nums[0], count = 0;
		for (auto i : nums)
		{
			if (i == cur)
				count++;
			else
			{
				count--;
				if (count < 0)
				{
					cur = i;
					count = 1;
				}
			}
		}
		return cur;
	}
};