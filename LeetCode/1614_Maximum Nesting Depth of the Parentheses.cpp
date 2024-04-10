#include <string>
using namespace std;

class Solution {
public:
	int maxDepth(string s) {
		int ans = 0;
		int cnt = 0;
		for (char c : s)
		{
			if (c == '(')
			{
				cnt++;
				if (cnt > ans)
					ans = cnt;
			}
			else if (c == ')')
				cnt--;
		}
		return ans;
	}
};