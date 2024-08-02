#include <vector>
using namespace std;

class Solution {
public:
	int minSwaps(vector<int>& nums) {
		int k = 0;
		for (int n : nums)
			if (n == 1) k++;
		int cur = 0;
		for (int i = 0; i < k; i++)
			if (nums[i] == 0) cur++;
		int ans = cur;
		for (int i = k; i < k + nums.size(); i++)
		{
			if (nums[i % (nums.size())] == 0) cur++;
			if (nums[i - k] == 0) cur--;
			if (ans > cur) ans = cur;
		}
		return ans;
	}
};