#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater_equal<int>> pq;
		for (int i = 0; i < k; i++)
			pq.push(nums[i]);
		int n = nums.size();
		for (int i = k; i < n; i++)
		{
			pq.push(nums[i]);
			pq.pop();
		}
		return pq.top();
	}
};