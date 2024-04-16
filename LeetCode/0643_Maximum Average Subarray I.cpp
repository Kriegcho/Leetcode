#include <vector>
using namespace std; 

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += nums[i];
		int max = sum;
		for (int i = k; i < nums.size(); i++)
		{
			sum += nums[i];
			sum -= nums[i - k];
			if (sum > max)
				max = sum;
		}
		double ans = 1.0 * max / k;
		return ans;
	}
};