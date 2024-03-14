#include <vector>

using namespace std; 

class Solution {
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		int n = nums.size();
		vector<int> vec{ 0 }; // 1之间0的数量
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			if (sum == vec.size())
				vec.push_back(0);
			else
				vec[sum]++;
		}
		if (sum < goal)
			return 0;
		int ans = 0;
		if (goal == 0)
			for (int i : vec)
				ans += i * (i + 1) / 2;
		else
			for (int i = 0; i <= sum - goal; i++)
				ans += (vec[i] + 1) * (vec[i + goal] + 1);
		return ans;
	}
};