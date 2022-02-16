#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, vector<int>> m;
		vector<int> v, ans;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end()) m[nums[i]] = v;
			m[nums[i]].push_back(i);
		}
		map<int, vector<int>>::iterator it = m.begin();
		while (it != m.end())
		{
			if (m.find(target - it->first) != m.end())
			{
				if (target == 2 * it->first && it->second.size() == 2)
				{
					ans = it->second;
					break;
				}
				else
				{
					ans.push_back(it->second[0]);
					ans.push_back(m[target - it->first][0]);
					break;
				}
			}
			it++;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	int N, target;
	cin >> N >> target;
	vector<int> nums(N), ans;
	for (int i = 0; i < N; i++) cin >> nums[i];
	ans = s.twoSum(nums, target);
	cout << ans[0] << " " << ans[1];
	system("pause");
	return 0;
}