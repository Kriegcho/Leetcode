#include <string>
#include <unordered_map>

using namespace std; 

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int l1 = s1.length(), l2 = s2.length();
		if (l1 > l2)
			return false;
		unordered_map<char, int> map;
		for (auto c : s1)
			map[c]++;
		for (int i = 0; i < l2; i++)
		{
			map[s2[i]]--;
			if (map[s2[i]] == 0)
				map.erase(s2[i]);
			if (map.empty())
				return true;
			if (i >= l1)
			{
				map[s2[i - l1]]++;
				if (map[s2[i - l1]] == 0)
					map.erase(s2[i - l1]);
				if (map.empty())
					return true;
			}
		}
		return false;
	}
};