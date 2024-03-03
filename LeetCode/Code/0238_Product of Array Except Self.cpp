#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int p_0 = 1, c_0 = 0; // 非0积，0数量
		for (auto i : nums)
		{
			if (i != 0)
				p_0 *= i;
			else
				c_0++;
		}
		for (auto& i : nums)
		{
			switch (c_0)
			{
			case 0:
				i = p_0 / i;
				break;
			case 1:
				if (i == 0)
					i = p_0;
				else
					i = 0;
				break;
			default:
				i = 0;
			}
		}
		return nums;
	}
};