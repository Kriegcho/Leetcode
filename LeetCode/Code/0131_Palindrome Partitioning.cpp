#include <vector>
#include <string>

using namespace std; 

class Solution {
	void DFS(string s, int pos, int n, vector<string> vec, vector<vector<string>>& ans, const vector<vector<bool>>& flag)
	{
		if (pos == n)
		{
			ans.push_back(vec);
			return;
		}
		for (int i = pos; i < n; i++)
		{
			if (flag[pos][i])
			{
				vec.push_back(s.substr(pos, i - pos + 1));
				DFS(s, i + 1, n, vec, ans, flag);
				vec.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		int n = s.length();
		vector<vector<bool>> flag(n, vector<bool>(n, true));
		for (int i = n - 2; i >= 0; i--)
			for (int j = i + 1; j < n; j++)
				flag[i][j] = (s[i] == s[j]) && flag[i + 1][j - 1];
		vector<vector<string>> ans;
		vector<string> vec;
		DFS(s, 0, n, vec, ans, flag);
		return ans;
	}
};