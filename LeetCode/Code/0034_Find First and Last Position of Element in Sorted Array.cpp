#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans(2, -1);
		int ns = nums.size();
		int l = 0, h = ns - 1;
		while (l <= h)
		{
			bool f = false;
			if (l == h && nums[l] != target) break;
			else if (l + 1 == h)
			{
				if (nums[l] == target)
				{
					f = true;
					ans[0] = l;
					ans[1] = l;
				}
				else if (nums[h] == target)
				{
					f = true;
					ans[0] = h;
					ans[1] = h;
				}
				else break;
			}
			int mid = (l + h) / 2;
			if (nums[mid] > target) h = mid;
			else if (nums[mid] < target) l = mid;
			else
			{
				f = true;
				ans[0] = mid;
				ans[1] = mid;
			}
			if (f)
			{
				while (ans[0] > 0 && nums[ans[0] - 1] == target) ans[0]--;
				while (ans[1] + 1 < ns && nums[ans[1] + 1] == target) ans[1]++;
				break;
			}
		}
		return ans;
	}
};