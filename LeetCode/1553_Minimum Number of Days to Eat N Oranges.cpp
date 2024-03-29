#include <unordered_map>

using namespace std; 

class Solution {
	unordered_map<int, int> um;
public:
	int minDays(int n) {
		if (n <= 1)
			um[n] = n;
		else if (!um.count(n))
		{
			int ans = minDays(n / 3) + n % 3 + 1;
			int t = minDays(n / 2) + n % 2 + 1;
			if (ans > t)
				ans = t;
			um[n] = ans;
		}
		return um[n];
	}
};