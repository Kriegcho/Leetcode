#include <vector>

using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> vec(26, 0);
		int maxc = 0;
		for (auto c : tasks)
		{
			vec[c - 'A']++;
			if (maxc < vec[c - 'A'])
				maxc = vec[c - 'A'];
		}
		int ans = (maxc - 1) * (n + 1);
		for (auto i : vec)
			if (i == maxc)
				ans++;
		// 剩余的插进去即可，不会破坏规则
		if (ans < tasks.size())
			ans = tasks.size();
		return ans;
	}
};