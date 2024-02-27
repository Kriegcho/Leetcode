#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int ans = 0, size = nums.size(), pos = size - 1;
		while (pos > 0)
		{
			int newpos = pos;
			for (int i = pos; i >= 0; i--)
			{
				if (nums[i] >= pos - i)
					newpos = i;
			}
			pos = newpos;
			ans++;
		}
		return ans;
	}
};