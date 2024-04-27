#include <vector>
using namespace std; 

class Solution {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		vector<vector<int>> ans;
		int m = land.size(), n = land[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (land[i][j] == 1)
				{
					if ((i > 0 && land[i - 1][j] == 1) || (j > 0 && land[i][j - 1] == 1))
						continue;
					int m_r = i, n_r = j;
					while (m_r < m && land[m_r][j] == 1)
						m_r++;
					while (n_r < n && land[i][n_r] == 1)
						n_r++;
					ans.push_back({ i,j,m_r - 1,n_r - 1 });
				}
		return ans;
	}
};