#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, int> m;
		vector<vector<string>> ans;
		for (string str : strs)
		{
			string s(str);
			sort(s.begin(), s.end());
			if (m.find(s) == m.end())
			{
				m[s] = m.size();
				ans.resize(m.size());
			}
			ans[m[s]].push_back(str);
		}
		return ans;
	}
};