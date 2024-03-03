#include <vector>

using namespace std; 

class Solution {
	bool solve(int xl, int xr, int yl, int yr, vector<vector<int>>& matrix, int target)
	{
		if (xl > xr || yl > yr)
			return false;
		int mx = (xl + xr) / 2, my = (yl + yr) / 2;
		if (target == matrix[mx][my])
			return true;
		else if (xl == xr && yl == yr)
			return false;
		else if (target < matrix[mx][my])
		{
			bool ret = false;
			ret |= solve(mx + 1, xr, yl, my - 1, matrix, target);
			if (ret) return true;
			ret |= solve(xl, mx - 1, my + 1, yr, matrix, target);
			if (ret) return true;
			ret |= solve(xl, mx, yl, my, matrix, target);
			return ret;
		}
		else
		{
			bool ret = false;
			ret |= solve(mx + 1, xr, yl, my, matrix, target);
			if (ret) return true;
			ret |= solve(xl, mx, my + 1, yr, matrix, target);
			if (ret) return true;
			ret |= solve(mx + 1, xr, my + 1, yr, matrix, target);
			return ret;
		}
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		return solve(0, m - 1, 0, n - 1, matrix, target);
	}
};