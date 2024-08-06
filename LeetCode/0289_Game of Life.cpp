#include <vector>
using namespace std;


class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		// 0 -> 2, 1 -> 3
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int cnt = 0;
				if (i > 0 && j > 0)
					cnt += (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3);
				if (i > 0)
					cnt += (board[i - 1][j] == 1 || board[i - 1][j] == 3);
				if (i > 0 && j < n - 1)
					cnt += (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3);
				if (j > 0)
					cnt += (board[i][j - 1] == 1 || board[i][j - 1] == 3);
				if (j < n - 1)
					cnt += (board[i][j + 1] == 1 || board[i][j + 1] == 3);
				if (i < m - 1 && j > 0)
					cnt += (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 3);
				if (i < m - 1)
					cnt += (board[i + 1][j] == 1 || board[i + 1][j] == 3);
				if (i < m - 1 && j < n - 1)
					cnt += (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 3);
				if (board[i][j] && (cnt < 2 || cnt > 3))
					board[i][j] = 3;
				else if (!board[i][j] && cnt == 3)
					board[i][j] = 2;
			}
		for (auto& vec : board)
			for (auto& n : vec)
				if (n == 2)
					n = 1;
				else if (n == 3)
					n = 0;
		return;
	}
};