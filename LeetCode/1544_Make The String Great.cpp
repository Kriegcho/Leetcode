#include <string>
#include <stack>

using namespace std;

class Solution {
	char to_lower(char c)
	{
		if (c >= 'a' && c <= 'z')
			return c;
		else
			return 'a' + c - 'A';
	}
public:
	string makeGood(string s) {
		int len = s.length();
		int pos = 0;
		while (pos < len - 1 || s.empty())
			if (s[pos] != s[pos + 1] && to_lower(s[pos]) == to_lower(s[pos + 1]))
			{
				if (len == 2)
				{
					s.clear();
					break;
				}
				else
				{
					s.erase(s.begin() + pos + 1);
					s.erase(s.begin() + pos);
					len = s.length();
					if (pos > 0)
						pos--;
				}
			}
			else
				pos++;
		return s;
	}
};