#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		bool f = true, ff = false;
		long long ans = 0;
		int b = -1, e = -1;
		for (int i = 0; i < s.length(); i++)
			if (!ff && s[i] == '-')
			{
				ff = true;
				if (b == -1)
				{
					f = false;
					b = i + 1;
				}
				else return 0;
			}
			else if (!ff && s[i] == '+')
			{
				ff = true;
				if (b == -1) b = i + 1;
				else return 0;
			}
			else
			{
				if (isdigit(s[i]))
				{
					ff = true;
					if (b == -1) b = i;
				}
				else if (b == -1)
				{
					if (s[i] != ' ') return 0;
				}
				else if (b != -1)
				{
					if (isdigit(s[b])) e = i - 1;
					else return 0;
					break;
				}
			}
		if (b == -1 || b >= s.length()) return 0;
		if (e == -1) e = s.length() - 1;
		while (b < e && s[b] == '0') b++;
		if (e - b > 11) e = b + 11; // 超int不超long long
		ans = stoll(s.substr(b, e - b + 1));
		if (!f) ans = -ans;
		ans = min(ans, (long long)pow(2, 31) - 1);
		ans = max(ans, (long long)-pow(2, 31));
		return ans;
	}
};