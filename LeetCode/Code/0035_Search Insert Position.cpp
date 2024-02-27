#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int ns = nums.size();
		int l = 0, h = ns - 1;
		while (l <= h)
		{
			if (l == h)
			{
				if (nums[l] >= target) return l;
				else return l + 1;
			}
			else if (l + 1 == h)
			{
				if (nums[l] >= target) return l;
				else if (nums[h] >= target) return h;
				else return h + 1;
			}
			else
			{
				int mid = (l + h) / 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] < target) l = mid;
				else h = mid;
			}
		}
		return 0;
	}
};