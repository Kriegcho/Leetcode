#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1, mid = (l + r) / 2;
		while (l <= r)
		{
			if (matrix[mid / n][mid % n] == target)
				return true;
			else if (mid == l)
			{
				if (matrix[r / n][r % n] == target)
					return true;
				return false;
			}
			else if (matrix[mid / n][mid % n] < target)
				l = mid;
			else if (matrix[mid / n][mid % n] > target)
				r = mid;
			mid = (l + r) / 2;
		}
		return false;
	}
};