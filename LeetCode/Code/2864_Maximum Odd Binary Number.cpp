#include <string>

using namespace std;

class Solution {
public:
	string maximumOddBinaryNumber(string s) {
		int pos = -1, len = s.length();
		for (int i = 0; i < len - 1; i++)
			if (s[i] == '1')
			{
				if (pos == -1)
				{
					swap(s[i], s[len - 1]);
					i--;
				}
				else
					swap(s[pos], s[i]);
				pos++;
			}
		return s;
	}
};