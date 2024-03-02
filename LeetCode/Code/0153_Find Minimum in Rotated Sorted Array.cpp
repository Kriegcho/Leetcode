#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int l = 0, r = n - 1;
		if (nums[l] < nums[r])
			return nums[l];
		else
		{
			int m = (l + r) / 2;
			while (l < r)
			{
				if (nums[m] < nums[r])
					r = m;
				else
					l = m + 1;
				m = (l + r) / 2;
			}
			return nums[l];
		}
	}
};