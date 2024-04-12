#include <string>
using namespace std; 

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int si = 0, ti = 0, sl = s.length(), tl = t.length();
		while (si < sl && ti < tl)
		{
			if (s[si] == t[ti])
			{
				si++;
				ti++;
			}
			else
				ti++;
		}
		return (si == sl);
	}
};