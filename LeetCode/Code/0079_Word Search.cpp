#include <vector>
#include <set>

using namespace std; 

class Solution {
	bool DFS(int i, int pos, int m, int n, int total, int len, vector<vector<char>>& board, string word, vector<bool> visit)
	{
		vector<int> next;
		if (i % n != 0)
			if (i - 1 >= 0 && i - 1 < total && !visit[i - 1])
				next.push_back(i - 1);
		if (i % n != n -1)
			if (i + 1 >= 0 && i + 1 < total && !visit[i + 1])
				next.push_back(i + 1);
		if (i + n >= 0 && i + n < total && !visit[i + n])
			next.push_back(i + n);
		if (i - n >= 0 && i - n < total && !visit[i - n])
			next.push_back(i - n);
		for (auto v : next)
		{
			if (board[v / n][v % n] == word[pos])
			{
				visit[v] = true;
				if (pos == len - 1)
					return true;
				else if (pos < len - 1)
				{
					bool flag = DFS(v, pos + 1, m, n, total, len, board, word, visit);
					if (flag)
						return true;
				}
				visit[v] = false;
			}
		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		char w = word[0];
		int m = board.size(), n = board[0].size(), total = m * n;
		int len = word.length();
		// 预先检查。。解决超时的用例
		set<char> s;
		for (int i = 0; i < total; i++)
			s.insert(board[i / n][i % n]);
		for (auto c : word)
			if (s.find(c) == s.end())
				return false;
		for (int i = 0; i < total; i++)
			if (board[i / n][i % n] == w)
			{
				if (1 == len)
					return true;
				vector<bool> visit(total, false);
				visit[i] = true;
				bool flag = DFS(i, 1, m, n, total, len, board, word, visit);
				if (flag)
					return flag;
			}
		return false;
	}
};