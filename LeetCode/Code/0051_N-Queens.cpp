#include <vector>

using namespace std;

class Solution {
	void solveNQueens(int depth, int n, vector<vector<bool>> flag, vector<int> path, vector<vector<string>>& ans)
	{
		if (path.size() == n)
		{
			vector<string> temp;
			for (int i = 0; i < n; i++)
			{
				string s(n, '.');
				s[path[i]] = 'Q';
				temp.push_back(s);
			}
			ans.push_back(temp);
			return;
		}
		// 对新加入path的值，将其覆盖的范围去掉
		if (!path.empty())
		{
			int y = path.back();
			for (int i = depth; i < n; i++)
				flag[i][y] = false;
			for (int i = depth; i < n; i++)
			{
				int y1 = y + (i - depth + 1);
				if (y1 < n)
					flag[i][y1] = false;
				int y2 = y - (i - depth + 1);
				if (y2 >= 0)
					flag[i][y2] = false;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (flag[depth][i])
			{
				path.push_back(i);
				solveNQueens(depth + 1, n, flag, path, ans);
				path.pop_back();
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<bool>> flag(n, vector<bool>(n, true));
		vector<int> path;
		vector<vector<string>> ans;
		solveNQueens(0, n, flag, path, ans);
		return ans;
	}
};