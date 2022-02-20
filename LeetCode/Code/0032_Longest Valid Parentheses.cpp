#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		vector<pair<int, int>> v1, v2;
		for (int i = 0; i + 1 < s.length(); i++)
			if (s[i] == '(' && s[i + 1] == ')') v1.push_back(make_pair(i, i + 1));
		while (1) // 符合要求的子串要么是子串组合，要么是某子串左右包一层"()"，直到无法合并，得到所有的极长子串，再取最大长度
		{
			for (int i = 0; i < v1.size(); i++)
				while (v1[i].first > 0 && v1[i].second + 1 < s.length()
					&& s[v1[i].first - 1] == '(' && s[v1[i].second + 1] == ')')
				{
					v1[i].first--;
					v1[i].second++;
				}
			for (int i = 0; i < v1.size(); i++)
			{
				if (v2.empty() || v2[v2.size() - 1].second + 1 < v1[i].first) v2.push_back(v1[i]);
				else v2[v2.size() - 1].second = v1[i].second;
			}
			if (v1 == v2) break;
			v1 = v2;
			v2.clear();
		}
		int ans = 0;
		for (int i = 0; i < v2.size(); i++)
			if (v2[i].second - v2[i].first + 1 > ans) ans = v2[i].second - v2[i].first + 1;
		return ans;
	}
};