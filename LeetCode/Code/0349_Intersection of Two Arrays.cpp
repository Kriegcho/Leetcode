#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> um;
		for (auto i : nums1)
			um[i]++;
		vector<int> ans;
		for (auto i : nums2)
			if (um[i] > 0)
			{
				ans.push_back(i);
				um[i] = 0;
			}
		return ans;
	}
};