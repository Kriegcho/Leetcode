#include <map>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		map<char, int> m;
		m['('] = 1;
		m[')'] = -1;
		m['{'] = 2;
		m['}'] = -2;
		m['['] = 3;
		m[']'] = -3;
		stack<char> st;
		for (int i = 0; i < s.length(); i++)
		{
			if (m[s[i]] > 0) st.push(s[i]);
			else
			{
				if (st.empty()) return false;
				if (m[st.top()] + m[s[i]] == 0) st.pop();
				else return false;
			}
		}
		return st.empty();
	}
};