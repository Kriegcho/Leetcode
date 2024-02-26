#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if ((i + 1) != nums[i] && nums[i] <= size && nums[i] > 0 
				&& nums[nums[i] - 1] != nums[i]) // �Ի��������Ѿ�����ȷλ�þͲ����ˣ������һֱ���
			{
				int temp = nums[i];
				nums[i] = nums[temp - 1];
				nums[temp - 1] = temp;
				i--; // ��黻����������ǲ��ǶԵ�
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