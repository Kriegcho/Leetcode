#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		string ans;
		int cnt = 0, len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
				cnt++;
			else if (s[i] == ')')
			{
				if (cnt == 0)
					continue;
				else
					cnt--;
			}
			ans += s[i];
		}

		if (cnt > 0)
		{
			len = ans.length();
			for (int i = len - 1; i >= 0; i--)
			{
				if (ans[i] == '(')
				{
					ans.erase(ans.begin() + i);
					cnt--;
					if (cnt == 0)
						break;
				}
			}
		}

		return ans;
	}
};