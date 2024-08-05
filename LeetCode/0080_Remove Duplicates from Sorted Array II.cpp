#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int ind = 0;
		int cur = nums[0];
		int cur_cnt = -1;
		for (int n : nums)
		{
			if (n == cur)
			{
				cur_cnt++;
				if (cur_cnt < 2)
					nums[ind++] = n;
			}
			else
			{
				cur = n;
				cur_cnt = 0;
				nums[ind++] = n;
			}
		}
		return ind;
	}
};