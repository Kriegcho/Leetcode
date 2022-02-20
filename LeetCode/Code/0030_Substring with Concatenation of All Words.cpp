#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		map<string, int> m;
		vector<int> ans;
		int wlen = words[0].length(), slen = s.length(), ws = words.size();
		for (int i = 0; i < ws; i++)
		{
			if (m.find(words[i]) == m.end()) m[words[i]] = 1;
			else m[words[i]]++;
		}
		for (int i = 0; i <= slen - wlen * ws; i++)
		{
			map<string, int> mt = m;
			for (int j = 0; j < ws; j++)
			{
				string t = s.substr(i + j * wlen, wlen);
				if (mt.find(t) != mt.end())
				{
					if (mt[t] > 1) mt[t]--;
					else mt.erase(mt.find(t));
				}
				else break;
			}
			if (mt.empty()) ans.push_back(i);
		}
		return ans;
	}
};