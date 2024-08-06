#include <vector>
using namespace std; 

class Solution {
	bool isAlphanumeric(char c)
	{
		return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
	}
	char convert(char c)
	{
		if (c >= 'A' && c <= 'Z')
			return c - 'A' + 'a';
		else return c;
	}
public:
	bool isPalindrome(string s) {
		string ns;
		for (char c : s)
			if (isAlphanumeric(c)) ns += convert(c);
		int l = 0, r = ns.length() - 1;
		while (l <= r)
		{
			if (ns[l] != ns[r]) return false;
			l++;
			r--;
		}
		return true;
	}
};