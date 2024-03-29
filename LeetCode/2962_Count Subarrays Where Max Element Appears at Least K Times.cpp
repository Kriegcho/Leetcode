#include <vector>

using namespace std;

class Solution {
public:
	long long countSubarrays(vector<int>& nums, int k) {
		int maxn = nums[0], cnt = 0;
		vector<int> pos;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == maxn)
			{
				cnt++;
				pos.push_back(i);
			}
			else if (nums[i] > maxn)
			{
				maxn = nums[i];
				cnt = 1;
				pos.clear();
				pos.push_back(i);
			}
		}
		if (pos.size() < k)
			return 0;
		long long ans = 0;
		int np = pos.size();
		pos.push_back(n);
		for (int i = 0; i <= np - k; i++)
			ans += (long long)(pos[i] + 1) * (long long)(pos[i + k - 1 + 1] - pos[i + k - 1]);
		return ans;
	}
};