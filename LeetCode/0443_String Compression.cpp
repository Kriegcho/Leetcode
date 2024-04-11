#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		int ans = 0;
		char last = ' ';
		int cnt = 0;
		for (char c : chars)
		{
			if (last == ' ')
			{
				last = c;
				cnt = 1;
			}
			else if (c == last)
				cnt++;
			else
			{
				chars[ans++] = last;
				if (cnt > 1)
				{
					if (cnt < 10)
						chars[ans++] = '0' + cnt;
					else
					{
						stack<int> s;
						s.push(cnt % 10);
						while (cnt > 10)
						{
							cnt /= 10;
							s.push(cnt % 10);
						}
						while (!s.empty())
						{
							chars[ans++] = '0' + s.top();
							s.pop();
						}
					}
				}

				last = c;
				cnt = 1;
			}
		}
		chars[ans++] = last;
		if (cnt > 1)
		{
			if (cnt < 10)
				chars[ans++] = '0' + cnt;
			else
			{
				stack<int> s;
				s.push(cnt % 10);
				while (cnt > 10)
				{
					cnt /= 10;
					s.push(cnt % 10);
				}
				while (!s.empty())
				{
					chars[ans++] = '0' + s.top();
					s.pop();
				}
			}
		}
		return ans;
	}
};