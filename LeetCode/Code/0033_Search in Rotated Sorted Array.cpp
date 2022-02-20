#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int ns = nums.size(), nf = nums[0];
		int l = 0, h = ns - 1;
		if (nf == target) return 0;
		bool f = target > nums[0];
		while (l < h)
		{
			if (l == h)
			{
				if (nums[l] == target) return l;
				else break;
			}
			else if (l + 1 == h)
			{
				if (nums[l] == target) return l;
				if (nums[h] == target) return h;
				else break;
			}
			int mid = (l + h) / 2;
			if (f)
			{
				if (nums[mid] > target) h = mid;
				else if (nums[mid] < target)
				{
					if (nums[mid] > nf) l = mid;
					else h = mid;
				}
				else return mid;
			}
			else
			{
				if (nums[mid] > target)
				{
					if (nums[mid] > nf) l = mid;
					else h = mid;
				}
				else if (nums[mid] < target) l = mid;
				else return mid;
			}
		}
		return -1;
	}
};