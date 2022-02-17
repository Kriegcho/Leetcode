#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(string s1, string s2)
	{
		int i = 0;
		for (; i < s1.length() && i < s2.length(); i++)
			if (s1[i] != s2[i]) break;
		return s1.substr(0, i);
	}

	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 1) return strs[0];
		else if (strs.size() == 2) return longestCommonPrefix(strs[0], strs[1]);
		else
		{
			vector<string> ts;
			int i = 0;
			while (i < strs.size())
			{
				if (i + 1 < strs.size()) ts.push_back(longestCommonPrefix(strs[i], strs[i + 1]));
				else ts.push_back(strs[i]);
				i += 2;
			}
			return longestCommonPrefix(ts);
		}
	}
};