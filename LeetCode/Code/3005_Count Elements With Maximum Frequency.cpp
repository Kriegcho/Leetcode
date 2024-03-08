#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int maxFrequencyElements(vector<int>& nums) {
		unordered_map<int, int> um;
		int c = 0, ans = 0;
		for (auto i : nums)
		{
			um[i]++;
			if (c < um[i])
			{
				c = um[i];
				ans = c;
			}
			else if (c == um[i])
				ans += um[i];
		}
		return ans;
	}
};