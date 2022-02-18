#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

class Solution {
	map<int, vector<string>> all;
public:
	vector<string> generateParenthesis(int n) { // 两种情况：1、n在n-1的结果上包一层()；2、n是i,n-i的组合。用set去重。
		vector<string> ans;
		if (n == 1) ans.push_back("()");
		else
		{
			vector<string> sn = generateParenthesis(n - 1);
			set<string> s;
			for (int i = 0; i < sn.size(); i++)
			{
				string t = "(" + sn[i] + ")";
				s.insert(t); // 可以确保sn是无重复的，这里可以不判断重复
				ans.push_back(t);
			}
			for (int i = 1; i < n; i++)
				for (int j = 0; j < all[i].size(); j++)
					for (int k = 0; k < all[n - i].size(); k++)
					{
						string t = all[i][j] + all[n - i][k];
						if (s.find(t) == s.end())
						{
							s.insert(t);
							ans.push_back(t);
						}
					}
		}
		all[n] = ans;
		return ans;
	}
};