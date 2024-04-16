#include <vector>
#include <stack>
using namespace std;

class Solution {
	int solve(vector<int> vec, int n) // 求直方图的最大面积
	{
		stack<int> s;
		vector<int> left(n, -1), right(n, n); // 左右两边第一个比vec[i]小的数的下标
		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && vec[s.top()] > vec[i])
			{
				right[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && vec[s.top()] > vec[i])
			{
				left[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp = vec[i] * (right[i] - left[i] - 1);
			if (tmp > ret)
				ret = tmp;
		}
		return ret;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int ans = 0;
		vector<int> vec(n, 0); // 以每一张为底的直方图
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
					vec[j]++;
				else
					vec[j] = 0;
			}
			int tmp = solve(vec, n);
			if (tmp > ans)
				ans = tmp;
		}
		return ans;
	}
};