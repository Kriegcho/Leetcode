#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int, int> map;
		map[0] = -1;
		int s = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			s += nums[i] == 0 ? -1 : 1; // 0改成-1，转换为求和为0的最长子数组
			if (map.count(s))
			{
				if (ans < i - map[s])
					ans = i - map[s];
			}
			else
				map[s] = i;
		}
		return ans;
	}
};