#include <vector>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int n = nums.size();
		vector<int> vs(1, 0);
		int sum = 0;
		for (int i : nums)
		{
			sum += i;
			vs.push_back(sum);
		}
		vs.push_back(0);
		for (int i = 1; i <= n; i++)
			if (sum - nums[i - 1] == vs[i - 1] * 2)
				return i - 1;
		return -1;
	}
};