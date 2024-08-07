#include <unordered_set>

class Solution {
	int calc(int n)
	{
		int res = 0;
		while (n)
		{
			int t = n % 10;
			res += t * t;
			n /= 10;
		}
		return res;
	}
public:

	bool isHappy(int n) {
		std::unordered_set<int> s;
		int t = calc(n);
		while (t != 1)
		{
			if (s.count(t)) return false;
			s.insert(t);
			t = calc(t);
		}
		return true;
	}
};