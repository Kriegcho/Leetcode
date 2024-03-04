#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	int binarySearch(const vector<int>& vec, int target) // 返回第一个大于target的下标
	{
		int n = vec.size();
		int l = 0, r = n - 1, m = (l + r) / 2;
		while (l <= r)
		{
			if (vec[m] > target)
				r = m;
			else
				l = m + 1;
			if (m == l)
				break;
			m = (l + r) / 2;
		}
		return l;
	}
public:
	int bagOfTokensScore(vector<int>& tokens, int power) {
		int n = tokens.size();
		if (n == 0)
			return 0;
		sort(tokens.begin(), tokens.end());
		if (tokens[0] > power)
			return 0;
		vector<int> vsum(n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += tokens[i];
			vsum[i] = sum;
		}
		int ans = binarySearch(vsum, power);
		for (int i = n - 1; i >= n / 2; i--)
		{
			power += tokens[i];
			int ind = binarySearch(vsum, power);
			ans = max(ans, ind - (n - i));
		}
		return ans;
	}
};