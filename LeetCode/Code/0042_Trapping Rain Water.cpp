#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		bool inc = false;
		int size = height.size();
		if (size < 2)
			return 0;
		stack<int> ls, rs;
		ls.push(0);
		rs.push(size - 1);
		// 从左往右和从右往左，记录下标
		for (int i = 1; i < size; i++)
		{
			if (height[i] > height[ls.top()])
				ls.push(i);
		}
		for (int i = size - 2; i >= 0; i--)
		{
			if (height[i] > height[rs.top()])
				rs.push(i);
		}
		// 计算结果
		int ans = 0;
		// 如果左右两边的最高值下标不一样，说明两者高度相等，计算这两者中间积蓄的雨水
		int lt = ls.top();
		int rt = rs.top();
		if (lt != rt)
		{
			int edge = height[lt];
			for (int i = lt + 1; i < rt; i++)
				ans += edge - height[i];
		}


		ls.pop();
		while (!ls.empty())
		{
			int edge = height[ls.top()];
			for (int i = ls.top() + 1; i < lt; i++)
				ans += edge - height[i];
			lt = ls.top();
			ls.pop();
		}

		rs.pop();
		while (!rs.empty())
		{
			int edge = height[rs.top()];
			for (int i = rt + 1; i < rs.top(); i++)
				ans += edge - height[i];
			rt = rs.top();
			rs.pop();
		}
		return ans;
	}
};