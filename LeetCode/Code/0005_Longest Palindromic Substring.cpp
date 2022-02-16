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
		int sc = 0, sr = 0, ansc = 0, ansr = 0; // sc��ʾ��ǰlen����ȡ���ֵ��λ�� sr��ʾ��scΪ���ĵ�����Ӵ������Ҷ�λ��
		for (int i = 1; i < t.size(); i++) {
			len[i] = sr > i ? min(len[2 * sc - i], sr - i) : 1; // 2 * sc - i��i����sc�ԳƵ�λ��
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