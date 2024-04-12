#include <vector>
#include <map>
using namespace std; 

class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		map<int, int> m;
		for (int i : nums)
			m[i]++;
		int ans = 0;
		for (auto p : m)
		{
			if (p.first < (k + 1) / 2)
			{
				while (p.second > 0)
				{
					if (m.count(k - p.first))
					{
						ans++;
						m[k - p.first]--;
						p.second--;
						if (m[k - p.first] == 0)
							break;
					}
					else
						break;
				}
			}
			else
				break;
		}
		if (k % 2 == 0 && m.count(k / 2))
			ans += m[k / 2] / 2;
		return ans;
	}
};