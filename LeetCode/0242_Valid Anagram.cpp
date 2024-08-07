#include <vector>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		vector<int> vec(26, 0);
		for (char c : s)
			vec[c - 'a']++;
		for (char c : t)
		{
			vec[c - 'a']--;
			if (vec[c - 'a'] < 0) return false;
		}
		return true;
	}
};