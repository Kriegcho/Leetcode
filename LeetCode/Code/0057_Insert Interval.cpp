#include <vector>

using namespace std; 

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;
		vector<int> merge(newInterval);
		bool flag = true;
		for (auto v : intervals)
		{
			if (v[1] < newInterval[0])
				ans.push_back(v);
			else
			{
				if (v[0] < newInterval[0])
					merge[0] = v[0];

				if (v[0] > newInterval[1])
				{
					if (flag)
					{
						ans.push_back(merge);
						flag = false;
					}
					ans.push_back(v);
				}
				else if (v[1] > merge[1])
					merge[1] = v[1];
			}
		}
		if (flag)
			ans.push_back(merge);
		return ans;
	}
};