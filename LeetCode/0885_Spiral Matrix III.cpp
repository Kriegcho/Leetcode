#include <vector>
using namespace std; 

class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
		vector<vector<int>> ans;
		int edge = 1, total = rows * cols;
		auto solve = [&ans, rows, cols, total](int r, int c)->bool {
			if (r >= 0 && r < rows && c >= 0 && c < cols)
			{
				ans.push_back({ r, c });
				return ans.size() == total;
			}
			return false;
		};
		while (1) {
			rStart++;
			for (int i = 0; i < edge; i++)
			{
				rStart--;
				if (solve(rStart, cStart)) return ans;
			}

			for (int i = 0; i < edge; i++)
			{
				cStart++;
				if (solve(rStart, cStart)) return ans;

			}

			for (int i = 0; i < edge; i++)
			{
				rStart++;
				if (solve(rStart, cStart)) return ans;

			}

			for (int i = 0; i < edge; i++)
			{
				cStart--;
				if (solve(rStart, cStart)) return ans;

			}
			cStart--;
			edge += 2;
		}
	}
};