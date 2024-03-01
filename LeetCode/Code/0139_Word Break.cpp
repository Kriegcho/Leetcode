#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
	bool DFS(string s, int pos, int n, unordered_map<string, int>& map, vector<bool>& flag)
	{
		if (flag[pos] == false)
			return false;
		if (pos == n)
			return true;
		for (int i = pos; i < n; i++)
		{
			if (map[s.substr(pos, i - pos + 1)] == 1)
				if (DFS(s, i + 1, n, map, flag))
					return true;
		}
		flag[pos] = false;
		return false;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, int> map;
		for (auto s : wordDict)
			map[s] = 1;
		int n = s.length();
		vector<bool> flag(n, true); // 从i开始到结尾能否匹配
		return DFS(s, 0, n, map, flag);
	}
};