#include <iostream>

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		bool f = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
		long long d1 = dividend, d2 = divisor, ans = 0;
		if (d1 < 0) d1 = -d1;
		if (d2 < 0) d2 = -d2;
		while (d1 >= d2)
		{
			long long temp = d2, m = 1;
			while ((temp << 1) < d1)
			{
				temp <<= 1;
				m <<= 1;
			}
			d1 -= temp;
			ans += m;
		}
		return f ? ans : -ans;
	}
};