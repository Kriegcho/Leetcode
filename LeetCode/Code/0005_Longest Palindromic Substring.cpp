#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	struct st
	{
		int length() { return b - a; }
		int a, b;
	};
public:
	string longestPalindrome(string s) {
		int len = s.length();
		vector<vector<st>> dp(len + 1, vector<st>(len + 1));
		dp[len][len].a = dp[len][len].b = len - 1;
		for (int i = len - 1; i >= 1; i--)
			for (int j = i; j <= len; j++)
			{
				if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1].length() == max(0, j - i - 2))
				{
					dp[i][j].a = i - 1;
					dp[i][j].b = j - 1;
				}
				else
				{
					if (dp[i][j - 1].length() < dp[i + 1][j].length()) dp[i][j] = dp[i + 1][j];
					else dp[i][j] = dp[i][j - 1];
				}
			}
		return s.substr(dp[1][len].a, dp[1][len].length() + 1);
	}
};