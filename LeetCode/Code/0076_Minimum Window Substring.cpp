#include <vector>
#include <string.h>
#include <unordered_map>

using namespace std; 

class Solution {
public:
	string minWindow(string s, string t) {
		if (t.length() > s.length())
			return "";
		vector<int> vecs(128, 0), vect(128, 0); // 字符出现的次数
		unordered_map<char, int> mapt; // 字符出现的次数，mapt用于找第一个答案
		for (auto c : t)
		{
			mapt[c]++;
			vect[c]++;
		}
		string ans = "";
		int  l = 0, r = 0;
		while (r < s.length())
		{
			if (mapt[s[r]] <= 1)
				mapt.erase(s[r]);
			else mapt[s[r]]--;
			vecs[s[r]]++;
			if (mapt.empty())
				break;
			r++;
		}
		// 向右滑动窗口
		if (mapt.empty())
		{
			// 已经找到答案了，向右移动找最佳的答案
			int minlen = s.length(), minl, minr;
			minl = l, minr = r;
			//ans = s.substr(0, r + 1); // 第一个答案

			bool flag = true;
			char lose;
			while (r < s.length())
			{
				if (flag)
				{
					// 上一次匹配，移动左端继续找答案
					vecs[s[l]]--;
					if (vecs[s[l]] < vect[s[l]]) // 是构成t的元素
					{
						lose = s[l];
						flag = false;
					}
					else
					{
						if (r - l < minr - minl + 1)
							minl = l + 1, minr = r;
							//ans = s.substr(l + 1, r - l);
					}
					l++;
				}
				else
				{
					// 移动右端
					r++;
					vecs[s[r]]++;
					if (lose == s[r]) // 又找到了缺失的字符
						flag = true;
				}
			}
			// 先记录索引再返回是为了解决内存超限的问题
			return s.substr(minl, minr - minl + 1);
		}
		return "";
	}
};