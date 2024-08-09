#include <vector>
using namespace std;

class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 5 && i > 0 && i < m - 1 && j > 0 && j < n - 1)
				{
					vector<int> vec(9, 0);
					bool flag = true;
					for (int k = i - 1; k <= i + 1; k++)
					{
						for (int l = j - 1; l <= j + 1; l++)
						{
							if (grid[k][l] <= 0 || grid[k][l] > 9 || vec[grid[k][l] - 1] != 0)
							{
								flag = false;
								break;
							}
							vec[grid[k][l] - 1] = grid[k][l];
						}
						if (!flag) break;
					}
					if (!flag) continue;

					for (int k = i - 1; k <= i + 1; k++)
					{
						int sum = 0;
						for (int l = j - 1; l <= j + 1; l++)
							sum += grid[k][l];
						if (sum != 15)
						{
							flag = false;
							break;
						}
					}
					if (!flag) continue;

					for (int l = j - 1; l <= j + 1; l++)
					{
						int sum = 0;
						for (int k = i - 1; k <= i + 1; k++)
							sum += grid[k][l];
						if (sum != 15)
						{
							flag = false;
							break;
						}
					}
					if (!flag) continue;

					if (grid[i - 1][j - 1] + grid[i + 1][j + 1] != 10 || grid[i - 1][j + 1] + grid[i + 1][j - 1] != 10)
						continue;

					ans++;
				}
			}
		return ans;
	}
};