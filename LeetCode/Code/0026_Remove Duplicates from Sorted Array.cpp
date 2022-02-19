#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		bool f[210] = { false };
		int ans = 0;
		for (int i = 0; i < nums.size(); i++)
			if (!f[nums[i] + 100])
			{
				f[nums[i] + 100] = true;
				nums[ans] = nums[i];
				ans++;
			}
		return ans;
	}
};