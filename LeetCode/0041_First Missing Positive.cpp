#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if ((i + 1) != nums[i] && nums[i] <= size && nums[i] > 0 
				&& nums[nums[i] - 1] != nums[i]) // 对换的数字已经是正确位置就不换了，否则会一直检查
			{
				int temp = nums[i];
				nums[i] = nums[temp - 1];
				nums[temp - 1] = temp;
				i--; // 检查换回来的这个是不是对的
			}
		}
		for (int i = 0; i < size; i++)
		{
			if (i + 1 != nums[i])
				return i + 1;
		}
		return size + 1;
	}
};