#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	struct st
	{
		int length() { return b - a; }
		int a, b;
	};
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		vector<int> len(t.size(), 0);
		int sc = 0, sr = 0, ansc = 0, ansr = 0; // sc表示当前len数组取最大值的位置 sr表示以sc为中心的最大子串的最右端位置
		for (int i = 1; i < t.size(); i++) {
			len[i] = sr > i ? min(len[2 * sc - i], sr - i) : 1; // 2 * sc - i是i关于sc对称的位置
			while (t[i + len[i]] == t[i - len[i]]) len[i]++;
			if (sr < i + len[i])
			{
				sr = i + len[i];
				sc = i;
			}
			if (ansr < len[i])
			{
				ansr = len[i];
				ansc = i;
			}
		}
		return s.substr((ansc - ansr) / 2, ansr - 1);
	}
};