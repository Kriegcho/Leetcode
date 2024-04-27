#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findRotateSteps(string ring, string key) {
		vector<vector<int>> pos(26);
		int rlen = ring.length();
		for (int i = 0; i < rlen; i++)
			pos[ring[i] - 'a'].push_back(i);
		int klen = key.length();
		vector<unordered_map<int, int>> dp(klen); // 摇到key的第i位的字符，在ring中所处位置的次数
		for (int pi : pos[key[0] - 'a'])
			dp[0][pi] = min(pi, rlen - pi) + 1;
		for (int i = 1; i < klen; i++)
			for (int pi : pos[key[i] - 'a'])
				for (auto p : dp[i - 1])
				{
					int delta = abs(pi - p.first);
					if (dp[i].count(pi))
						dp[i][pi] = min(dp[i][pi], p.second + min(delta, rlen - delta) + 1);
					else
						dp[i][pi] = p.second + min(delta, rlen - delta) + 1;
				}
		int ans = INT_MAX;
		for (auto p : dp[klen - 1])
			ans = min(ans, p.second);
		return ans;
	}
};