#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		unordered_map<char, int> mapp;
		for (auto c : p)
			mapp[c]++;
		int ls = s.length(), lp = p.length();
		vector<int> ans;
		for (int i = 0; i < ls; i++)
		{
			mapp[s[i]]--;
			if (mapp[s[i]] == 0)
				mapp.erase(s[i]);
			if (mapp.empty())
				ans.push_back(i - lp + 1);

			if (i >= lp)
			{
				mapp[s[i - lp]]++;
				if (mapp[s[i - lp]] == 0)
					mapp.erase(s[i - lp]);
				if (mapp.empty())
					ans.push_back(i - lp + 1);
			}
		}
		return ans;
	}
};