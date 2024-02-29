#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		vector<int> prev(n, -1), next(n, n);
		stack<int> s;
		// 从左向右找左边第一个小值
		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && heights[s.top()] >= heights[i])
				s.pop();
			if (!s.empty())
				prev[i] = s.top();
			s.push(i);
		}
		while (!s.empty())
			s.pop();
		// 从右向左找右边第一个小值
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && heights[s.top()] >= heights[i])
				s.pop();
			if (!s.empty())
				next[i] = s.top();
			s.push(i);
		}
		// 计算最终结果
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int s = (next[i] - prev[i] - 1) * heights[i];
			if (ans < s)
				ans = s;
		}
		return ans;
	}
};