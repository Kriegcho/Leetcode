#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end()) m[nums[i]] = 1;
			else m[nums[i]]++;
		}
		map<int, int>::iterator it = m.begin();
		if (it->first > 0) return ans;
		if (m.find(0) != m.end() && m[0] >= 3)
		{
			vector<int> v(3, 0);
			ans.push_back(v);
		}
		while (it != m.end() && it->first < 0)
		{
			int ta = -it->first;
			map<int, int>::iterator itr = it;
			if (it->second == 1) itr++;
			while (itr != m.end() && 2 * itr->first <= ta)
			{
				if (m.find(ta - itr->first) != m.end())
				{
					if (ta - itr->first > itr->first)
					{
						vector<int> v(3);
						v[0] = it->first;
						v[1] = itr->first;
						v[2] = ta - itr->first;
						ans.push_back(v);
					}
					else if (ta - itr->first == itr->first && itr->second > 1)
					{
						vector<int> v(3);
						v[0] = it->first;
						v[1] = itr->first;
						v[2] = ta - itr->first;
						ans.push_back(v);
					}
				}
				itr++;
			}
			it++;
		}
		return ans;
	}
};