#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	int gcd(int a, int b)
	{
		if (a == b)
			return a;
		else if (a < b)
			swap(a, b);
		return gcd(a - b, b);
	}
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		if (k == 0)
			return;
		// 需要执行的次数即为k和n的最大公约数
		int loop = gcd(k, n);
		for (int i = 0; i < loop; i++)
		{
			int pos = i + k;
			while (pos != i)
			{
				swap(nums[i], nums[pos]);
				pos = (pos + k) % n;
			}
		}
	}
};