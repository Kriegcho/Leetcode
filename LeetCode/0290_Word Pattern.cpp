#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {
		vector<string> vec(26, "");
		unordered_map<string, int> um;
		string tmp = "";
		int ind = 0;
		for (char c : s)
		{
			if (c != ' ')
				tmp += c;
			else
			{
				if (vec[pattern[ind] - 'a'].empty())
				{
					if (um.count(tmp)) return false;
					vec[pattern[ind] - 'a'] = tmp;
					um[tmp] = pattern[ind] - 'a';
				}
				else if (vec[pattern[ind] - 'a'] != tmp)
					return false;
				tmp = "";
				ind++;
				if (ind >= pattern.size()) return false;
			}
		}
		if (pattern.size() - 1 != ind) return false;
		if (vec[pattern[ind] - 'a'].empty() && um.count(tmp)) return false;
		if (!vec[pattern[ind] - 'a'].empty() && vec[pattern[ind] - 'a'] != tmp)
			return false;
		return true;
	}
};