#include <string>
using namespace std;

class Solution {
public:
	string count(string s)
	{
		string ret = "";
		int len = s.length(), c = 0;
		char temp = s[0];
		for (int i = 0; i < len; i++)
		{
			if (s[i] == temp) c++;
			else
			{
				ret += to_string(c);
				ret += temp;
				temp = s[i];
				c = 1;
			}
		}
		if (c)
		{
			ret += to_string(c);
			ret += temp;
		}
		return ret;
	}

	string countAndSay(int n) {
		if (n == 1) return "1";
		else return count(countAndSay(n - 1));
	}
};