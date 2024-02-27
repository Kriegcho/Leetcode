#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		int pos = 0, rval = intervals[0][1], n = intervals.size();
		for (int i = 0; i < n; i++)
		{
			if (rval < intervals[i][0])
			{
				ans.push_back({ intervals[pos][0], rval });
				pos = i;
				rval = intervals[i][1];
			}
			else
				if (rval < intervals[i][1])
					rval = intervals[i][1];
		}
		ans.push_back({ intervals[pos][0], max(rval, intervals[n - 1][1]) });
		return ans;
	}
};