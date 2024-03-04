#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		unordered_map<int, int> m;
		int sum = 0, ans = 0; // sum表示从0到i的和
		m[0] = 1;
		for (auto i : nums)
		{
			sum += i;
			if (m.find(sum - k) != m.end()) // sum(0 ... i) - sum (0 ... j) == k,说明(i, j]是所求的一个解
				ans += m[sum - k];
			m[sum]++;
		}
		return ans;
	}
};