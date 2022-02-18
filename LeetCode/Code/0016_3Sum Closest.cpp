#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ansd = abs(nums[0] + nums[1] + nums[2] - target), ans = nums[0] + nums[1] + nums[2];
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end()) m[nums[i]] = 1;
			else m[nums[i]]++;
		}
		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			int ta = target - it->first;
			map<int, int>::iterator itr = it;
			if (it->second == 1) itr++;
			else it->second--;
			while (itr != m.end() && 2 * itr->first < ta + ansd)
			{
				if (m.find(ta - itr->first) != m.end() && (ta - itr->first > itr->first || ta - itr->first == itr->first && itr->second > 1))
					return target;
				else
				{
					bool be = m.find(ta - itr->first) == m.end();
					if (be) m[ta - itr->first] = 0;
					map<int, int>::iterator itf = m.find(ta - itr->first);
					map<int, int>::iterator itt = itf;
					itf++;
					if (itf != m.end() && (itf->first > itr->first || (itf->first == itr->first && itr->second > 1))) {}
					else
					{
						itf = itr;
						if (itr->second == 1) itf++;
					}
					if (itf != m.end() && itf->second && abs(itf->first + itr->first + it->first - target) < ansd)
					{
						ans = itf->first + itr->first + it->first;
						ansd = abs(itf->first + itr->first + it->first - target);
					}
					itt--;
					if (itt != m.end() && (itt->first > itr->first || (itt->first == itr->first && itr->second > 1))) {}
					else
					{
						itt = itr;
						if (itr->second == 1) itt++;
					}
					if (itt != m.end() && itt->second == 0) itt++;
					if (itt != m.end() && abs(itt->first + itr->first + it->first - target) < ansd)
					{
						ans = itt->first + itr->first + it->first;
						ansd = abs(itt->first + itr->first + it->first - target);
					}
					if (be) m.erase(m.find(ta - itr->first));
				}
				itr++;
			}
			it++;
		}
		return ans;
	}
};