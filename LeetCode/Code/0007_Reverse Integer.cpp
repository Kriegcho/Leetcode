#include <cmath>

class Solution {
public:
	int reverse(int x) {
		long ans = 0;
		int d = 0, t = x;
		while (t)
		{
			d++;
			t /= 10;
		}
		for (int i = 1; i <= d; i++)
		{
			ans += (x % 10) * pow(10, d - i);
			x /= 10;
		}
		if (ans >= -pow(2, 31) && ans < pow(2, 31)) return ans;
		else return 0;
	}
};