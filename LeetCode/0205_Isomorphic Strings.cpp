#include <string>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int len = s.length();
		unordered_map<char, char> mts, mst;
		for (int i = 0; i < len; i++)
		{
			if (mts.count(t[i]) && mst.count(s[i]))
			{
				if (mts[t[i]] != s[i])
					return false;
			}
			else if (mts.count(t[i]) || mst.count(s[i]))
				return false;
			else
			{
				mts[t[i]] = s[i];
				mst[s[i]] = t[i];
			}
		}
		return true;
	}
};