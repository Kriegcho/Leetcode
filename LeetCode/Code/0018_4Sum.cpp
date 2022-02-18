#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end()) m[nums[i]] = 1;
			else m[nums[i]]++;
		}
		map<int, int>::iterator it1 = m.begin();
		while (it1 != m.end())
		{
			long t3 = target - it1->first;
			map<int, int>::iterator it2 = it1;
			if (it1->second == 1) it2++;
			else it1->second--;
			while (it2 != m.end())
			{
				long t2 = t3 - it2->first;
				map<int, int>::iterator it3 = it2;
				bool bi = it2->second > 1;
				if (it2->second == 1) it3++;
				else it2->second--;
				while (it3 != m.end() && 2 * it3->first <= t2)
				{
					if (m.find(t2 - it3->first) != m.end() && (t2 - it3->first > it3->first || (t2 - it3->first == it3->first && it3->second > 1)))
					{
						vector<int> v;
						v.push_back(it1->first);
						v.push_back(it2->first);
						v.push_back(it3->first);
						v.push_back(t2 - it3->first);
						ans.push_back(v);
					}
					it3++;
				}
				if (bi) it2->second++;
				it2++;
			}
			it1++;
		}
		return ans;
	}
};