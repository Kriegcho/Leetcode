class Solution {
public:
	int pivotInteger(int n) {
		int l = n / 2, r = n;
		int m = (l + r) / 2;
		int s = n * (n + 1) / 2;
		while (l <= r)
		{
			if (m * (m + 1) == s + m)
				return m;
			else if (m * (m + 1) < s + m)
				l = l + 1;
			else
				r = r - 1;
			m = (l + r) / 2;
		}
		return -1;
	}
};