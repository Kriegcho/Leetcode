#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		int n = nums.size();
		vector<int> ans;
		for (int i = 0; i < k - 1; i++)
		{
			while (!dq.empty() && dq.back() < nums[i])
				dq.pop_back();
			dq.push_back(nums[i]);
		}
		for (int i = k - 1; i < n; i++)
		{
			while (!dq.empty() && dq.back() < nums[i])
				dq.pop_back();
			dq.push_back(nums[i]);

			ans.push_back(dq.front());

			if (dq.front() == nums[i - k + 1])
				dq.pop_front();
		}
		return ans;
	}
};