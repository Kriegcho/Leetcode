#include <vector>

using namespace std; 

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = nums.size(), pos = size - 1;
		while (pos > 0)
		{
			int newpos = pos;
			bool find = false;
			for (int i = pos; i >= 0; i--)
			{
				if (nums[i] >= pos - i)
				{
					newpos = i;
					find = true;
				}
			}
			if (!find)
				return false;
			pos = newpos;
		}
		return true;
	}
};