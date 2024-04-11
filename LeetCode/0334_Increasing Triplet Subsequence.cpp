#include <vector>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		int mincurmax = INT_MAX, mincurmin = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] > mincurmax)
				return true;
			if (mincurmin > nums[i])
				mincurmin = nums[i];
			if (nums[i] > mincurmin && mincurmax > nums[i])
				mincurmax = nums[i];
		}
		return false;
	}
};