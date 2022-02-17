#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ans = 0;
		char last = ' ';
		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
			case 'M':
				if (last == 'C') ans += 800;
				else ans += 1000;
				break;
			case 'D':
				if (last == 'C') ans += 300;
				else ans += 500;
				break;
			case 'C':
				if (last == 'X') ans += 80;
				else ans += 100;
				break;
			case 'L':
				if (last == 'X') ans += 30;
				else ans += 50;
				break;
			case 'X':
				if (last == 'I') ans += 8;
				else ans += 10;
				break;
			case 'V':
				if (last == 'I') ans += 3;
				else ans += 5;
				break;
			case 'I':
				ans++;
			}
			last = s[i];
		}
		return ans;
	}
};