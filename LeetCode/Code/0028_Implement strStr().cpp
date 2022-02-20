#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int> next;
	void getnext(string s)
	{
		int k = -1, i = 0;
		next[0] = -1;
		while (i < s.length() - 1)
		{
			if (k == -1 || s[i] == s[k])
			{
				k++;
				i++;
				next[i] = k;
			}
			else k = next[k];
		}
	}

public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		next.resize(needle.length());
		getnext(needle);
		int i = 0, j = 0;
		int hl = haystack.length(), nl = needle.length();
		while (i < hl && j < nl)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else j = next[j];
		}
		return j == needle.length() ? i - j : -1;
	}
};