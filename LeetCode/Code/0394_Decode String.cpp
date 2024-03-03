#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int len = s.length();
		stack<pair<int, int>> st; // 数量，位置
		bool find = false;
		int cnt = 0;
		string ans;
		for (int i = 0; i < len; i++)
		{
			if (isdigit(s[i]))
			{
				find = true;
				cnt *= 10;
				cnt += s[i] - '0';
			}
			else if (isalpha(s[i]))
			{
				if (!find)
					ans.push_back(s[i]);
			}
			else if (s[i] == '[')
			{
				st.push(make_pair(cnt, i + 1));
				cnt = 0;
			}
			else if (s[i] == ']')
			{
				int c = st.top().first, pos = st.top().second;
				string temp = decodeString(s.substr(pos, i - pos));
				if (st.size() == 1)
					for (int j = 0; j < c; j++)
						ans += temp;
				st.pop();
				if (st.empty())
					find = false;
			}
		}
		return ans;
	}
};