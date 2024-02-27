#include <vector>

using namespace std; 

class Solution {
	using cord = pair<int, int>;
	cord getNewPos(cord p, int n)
	{
		// 旋转矩阵[[0,1][-1,0]]
		// 转完了要向右平移n - 1个单位
		return make_pair(-p.second + n - 1, p.first);
	}
public:
	void rotate(vector<vector<int>>& matrix) {
		// 对一个象限内的点对换3次即可
		int n = matrix.size();
		for (int i = 0; i < (n + 1) / 2; i++) // n + 1是为了解决奇偶问题，奇数边长要多遍历中间的半条边
			for (int j = 0; j < n / 2; j++)
			{
				cord pos = make_pair(i, j);
				for (int k = 0; k < 3; k++)
				{
					cord newpos = getNewPos(pos, n);
					int val = matrix[newpos.first][newpos.second];
					matrix[newpos.first][newpos.second] = matrix[pos.first][pos.second];
					matrix[pos.first][pos.second] = val;
					pos = newpos;
				}
			}
	}
};

int main()
{
	vector<vector<int>> matrix{ {5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16} };
	Solution s;
	s.rotate(matrix);
}