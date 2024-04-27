#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {

	char up(char c)
	{
		if (c == '9')
			return '0';
		return ++c;
	}

	char down(char c)
	{
		if (c == '0')
			return '9';
		return --c;
	}

	void dfs(string str, int depth, unordered_set<string>& visit, unordered_map<string, int>& um, const unordered_set<string>& us, int& ans)
	{
		if (um.count(str) && depth >= um[str]) // 核心的剪枝：如果到这个节点深度不比上次到这里更小就不用继续搜索了
			return;
		um[str] = depth;
		if (str == "0000")
		{
			if (depth < ans)
				ans = depth;
			return;
		}
		if (depth + 1 >= ans)
			return;
		for (int i = 0; i < 4; i++)
		{
			if (str[i] == '0')
				continue;
			string str1 = str;
			if (str1[i] >= '5')
			{
				str1[i] = up(str1[i]);
				if (!visit.count(str1) && !us.count(str1))
				{
					visit.insert(str1);
					dfs(str1, depth + 1, visit, um, us, ans);
					visit.erase(str1);
				}
				else
				{
					str1[i] = down(str1[i]);
					str1[i] = down(str1[i]);
					if (!visit.count(str1) && !us.count(str1))
					{
						visit.insert(str1);
						dfs(str1, depth + 1, visit, um, us, ans);
						visit.erase(str1);
					}
				}
			}
			else
			{
				str1[i] = down(str1[i]);
				if (!visit.count(str1) && !us.count(str1))
				{
					visit.insert(str1);
					dfs(str1, depth + 1, visit, um, us, ans);
					visit.erase(str1);
				}
				else
				{
					str1[i] = up(str1[i]);
					str1[i] = up(str1[i]);
					if (!visit.count(str1) && !us.count(str1))
					{
						visit.insert(str1);
						dfs(str1, depth + 1, visit, um, us, ans);
						visit.erase(str1);
					}
				}
			}
		}
	}
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> us;
		unordered_map<string, int> um; // dfs到str的深度信息，用于剪枝
		for (string s : deadends)
			us.insert(s);
		unordered_set<string> visit;
		visit.insert(target);
		int ans = INT_MAX;
		dfs(target, 0, visit, um, us, ans);
		if (ans == INT_MAX)
			ans = -1;
		return ans;
	}
};