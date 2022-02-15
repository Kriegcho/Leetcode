#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0, pos = 0, anst = 0;
		map<char, int> m;
		for (int i = 0; i < s.length(); i++)
		{
			if (m.find(s[i]) == m.end()) anst++;
			else if (m[s[i]] < pos) anst++; // �������ֹ������ڵ�ǰ������
			else
			{
				pos = m[s[i]] + 1;
				if (anst > ans) ans = anst;
				anst = i - pos + 1;
			}
			m[s[i]] = i;
		}
		if (anst > ans) ans = anst;
		return ans;
	}
};