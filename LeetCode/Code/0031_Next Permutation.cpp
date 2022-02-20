#include <vector>
using namespace std;

class Solution { // 思路：如果所求序列递减，则说明该序列已经是当前位置子序列排序的最后一项；否则当前序列首位不需要改变，直到找到一个递减序列为止
public:
	void nextPermutation(vector<int>& nums, int pos)
	{
		bool f = false;
		int ns = nums.size();
		for (int i = pos; i + 1 < nums.size(); i++)
			if (nums[i] < nums[i + 1])
			{
				f = true;
				break;
			}
		if (f) nextPermutation(nums, pos + 1);
		else
		{
			if (pos > 0) // 如果不是从首位开始，当前位置的上一个元素要换成第一个比该元素大的元素，后面的元素保持递增
			{
				int ind = ns - 1;
				while (nums[ind] <= nums[pos - 1] && ind >= pos) ind--;
				swap(nums[pos - 1], nums[ind]);
			}
			for (int i = pos; i < pos + (ns - pos) / 2; i++)
				swap(nums[i], nums[ns - i - 1 + pos]);
		}
	}

	void nextPermutation(vector<int>& nums) {
		nextPermutation(nums, 0);
	}
};