#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int> s;
		int n = nums.size();
		if (n == 0)
			return 0;
		for (auto i : nums)
			s.insert(i);
		int ans = 1, count = 1, beg = *(s.begin());
		for (auto i : s)
		{
			if (i == beg)
				continue;
			else if (i == beg + count)
			{
				count++;
				if (ans < count)
					ans = count;
			}
			else
			{
				beg = i;
				count = 1;
			}
		}
		return ans;
	}
};