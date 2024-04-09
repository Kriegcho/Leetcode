#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	int solve(vector<int>& nums, int k) // 求解不超过k种元素的子数组数量
	{
		int ans = 0;
		unordered_map<int, int> um;
		int l = 0, r = 0, n = nums.size();
		while (r < n)
		{
			um[nums[r]]++;
			while (um.size() > k)
			{
				if (um[nums[l]] > 1)
					um[nums[l]]--;
				else
					um.erase(nums[l]);
				l++;
			}
			ans += r - l + 1;
			r++;
		}
		return ans;
	}
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		int ak = solve(nums, k);
		int ak_1 = solve(nums, k - 1);
		return ak - ak_1;
	}
};