#include <vector>

using namespace std; 

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool r0 = false, c0 = false; // 第0行或列是否需要置零
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					if (i == 0)
						r0 = true;
					if (j == 0)
						c0 = true;
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		for (int i = 1; i < m; i++)
		{
			if (matrix[i][0] == 0)
				for (int j = 1; j < n; j++)
					matrix[i][j] = 0;
		}
		for (int i = 1; i < n; i++)
		{
			if (matrix[0][i] == 0)
				for (int j = 1; j < m; j++)
					matrix[j][i] = 0;
		}
		if (r0)
			for (int j = 1; j < n; j++)
				matrix[0][j] = 0;
		if (c0)
			for (int j = 1; j < m; j++)
				matrix[j][0] = 0;
	}
};