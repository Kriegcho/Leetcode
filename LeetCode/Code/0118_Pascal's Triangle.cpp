#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans{ {1} };
		for (int l = 1; l < numRows; l++)
		{
			vector<int> vec;
			vec.push_back(1);
			for (int i = 0; i < l - 1; i++)
			{
				vec.push_back(ans[l - 1][i] + ans[l - 1][i + 1]);
			}
			vec.push_back(1);
			ans.push_back(vec);
		}
		return ans;
	}
};