#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		stack<string> st;
		int pos = -1;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == ' ' && pos != -1)
			{
				st.push(s.substr(pos, i - pos));
				pos = -1;
			}
			else if (s[i] != ' ' && pos == -1)
				pos = i;
		string ans;
		if (pos != -1)
			ans = s.substr(pos, s.length() - pos);
		while (!st.empty())
		{
			if (!ans.empty())
				ans += ' ';
			ans += st.top();
			st.pop();
		}
		return ans;
	}
};