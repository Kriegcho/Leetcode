#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int power) {
		int n = tokens.size();
		if (n == 0)
			return 0;
		sort(tokens.begin(), tokens.end());
		if (tokens[0] > power)
			return 0;
		int ans = 0, use = 0;
		for (int i = 0; i < n - use; i++)
		{
			power -= tokens[i];
			if (power < 0)
			{
				use++;
				power += tokens[n - use];
			}
			ans = max(i + 1 - use, ans);
		}
		return ans;
	}
};