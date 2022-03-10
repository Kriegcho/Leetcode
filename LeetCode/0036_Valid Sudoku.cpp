#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<set<int>> vs(27);
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') continue;
				else if (board[i][j] >= '0' && board[i][j] <= '9')
				{
					if (vs[i].find(board[i][j]) == vs[i].end()
						&& vs[j + 9].find(board[i][j]) == vs[j + 9].end()
						&& vs[j / 3 + (i / 3) * 3 + 18].find(board[i][j]) == vs[j / 3 + (i / 3) * 3 + 18].end())
					{
						vs[i].insert(board[i][j]);
						vs[j + 9].insert(board[i][j]);
						vs[j / 3 + (i / 3) * 3 + 18].insert(board[i][j]);
					}
					else return false;
				}
				else
				{
					return false;
				}
			}
		return true;
	}
};