#include <vector>

using namespace std;

class Solution {
	void solve(vector<vector<int>>& matrix, int l, int t, int r, int b, vector<int>& ans)
	{
		if (l == r && t == b)
			ans.push_back(matrix[l][t]);
		else if (l == r && t < b)
		{
			for (int i = t; i <= b; i++)
				ans.push_back(matrix[l][i]);
		}
		else if (l < r && t == b)
		{
			for (int i = l; i <= r; i++)
				ans.push_back(matrix[b][i]);
		}
		if (l <= r && t <= b)
		{
			for (int i = l; i < r; i++)
				ans.push_back(matrix[t][i]);
			for (int i = t; i < b; i++)
				ans.push_back(matrix[i][r]);
			for (int i = r; i > l; i--)
				ans.push_back(matrix[b][i]);
			for (int i = b; i > t; i--)
				ans.push_back(matrix[i][l]);
			solve(matrix, l + 1, t + 1, r - 1, b - 1, ans);
		}
	}
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int m = matrix.size(), n = matrix[0].size();
		solve(matrix, 0, 0, n - 1, m - 1, ans);
		return ans;
	}
};