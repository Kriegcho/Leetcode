#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int pos = -1, n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == 0)
			{
				if (pos == -1)
					pos = i;
			}
			else if(pos != -1)
			{
				swap(nums[i], nums[pos]);
				pos++;
			}
		}
	}
};