#include <string>

using namespace std;

class Solution {
public:
	int minimumLength(string s) {
		char c = 'd';
		int len = s.length(), l = 0, r = len - 1;
		while (l < r)
		{
			if (s[l] == s[r])
			{
				c = s[l];
				l++;
				r--;
			}
			else
			{
				if (s[l] == c)
					l++;
				else if (s[r] == c)
					r--;
				else
					break;
			}
		}
		if (l == r && s[l] == c)
			return 0;
		return r - l + 1;
	}
};