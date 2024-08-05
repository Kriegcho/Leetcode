#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
	struct st { 
		int calc() {
			int l = b - a + 1;
			int r = c - b + 1;
			return l * (l + 1) / 2 + r * (r + 1) / 2 - 1;
		}
		int a, b, c; 
	};
public:
	int candy(vector<int>& ratings) {
		if (ratings.size() == 1)
			return 1;
		// 连成折线图找V形结构相加即可，包含重复，求和取大
		vector<st> vec;
		int cur_begin = 0;
		int cur_bottom = 0;
		bool flag = false;
		for (int i = 1; i < ratings.size(); i++)
		{
			if (ratings[i] < ratings[i - 1]) {
				if (flag) // 结束
				{
					vec.push_back({ cur_begin, cur_bottom, i - 1 });
					cur_begin = i - 1;
					cur_bottom = i;
					flag = false;
				}
				else
					cur_bottom = i;
				if (i == ratings.size() - 1)
					vec.push_back({ cur_begin, cur_bottom, i });
			}
			else if (ratings[i] > ratings[i - 1]) {
				if (!flag) flag = true;
				if (i == ratings.size() - 1)
					vec.push_back({ cur_begin, cur_bottom, i });
			}
			else { // 遇到相等就结束，方便处理
				vec.push_back({ cur_begin, cur_bottom, i - 1 });
				cur_begin = i;
				cur_bottom = i;
				flag = false;
				if (i == ratings.size() - 1)
					vec.push_back({ i, i, i });
			}
		}
		int sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			sum += vec[i].calc();
			if (i > 0 && vec[i].a == vec[i - 1].c)
				sum -= min(vec[i].b - vec[i].a + 1, vec[i - 1].c - vec[i - 1].b + 1);
		}
		return sum;
	}
};

int main() {
	Solution s;
	vector<int> vec{ 0 };
	s.candy(vec);
}