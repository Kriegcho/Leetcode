#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
	int longestIdealString(string s, int k) {
		int len = s.length();
		vector<int> dp(26, 0);
		for (int i = len - 1; i >= 0; i--)
		{
			int l = max(0, s[i] - 'a' - k);
			int r = min(25, s[i] - 'a' + k);
			int dmax = 0;
			for (int j = l; j <= r; j++)
				dmax = max(dmax, dp[j]);
			dp[s[i] - 'a'] = dmax + 1;
		}
		
		int ans = 1;
		for (auto i : dp)
			ans = max(ans, i);
		return ans;
	}
};