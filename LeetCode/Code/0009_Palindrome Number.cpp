#include <cmath>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		long tx = x, temp = x, ty = 0, d = 0;
		while (x)
		{
			d++;
			x /= 10;
		}
		for (int i = 1; i <= d; i++)
		{
			ty += (temp % 10) * pow(10, d - i);
			temp /= 10;
		}
		return tx == ty;
	}
};