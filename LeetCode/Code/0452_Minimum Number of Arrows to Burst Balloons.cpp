#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		sort(points.begin(), points.end());

		int ans = 1;
		int pos = points[0][1];
		for (auto v : points)
		{
			if (v[0] > pos)
			{
				ans++;
				pos = v[1];
			}
			else if (v[1] < pos)
				pos = v[1];
		}
		return ans;
	}
};