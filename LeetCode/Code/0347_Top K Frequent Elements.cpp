#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> cnt;
		for (auto i : nums)
			cnt[i]++;
		priority_queue<pair<int, int>> pq;
		for (auto p : cnt)
			pq.push(make_pair(p.second, p.first));
		vector<int> ans;
		for (int i = 0; i < k; i++)
		{
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;
	}
};