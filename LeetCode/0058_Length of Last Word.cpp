#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.length();
		int pos = -1;
		int beg = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (pos == -1 && s[i] != ' ')
				pos = i;
			else if (pos != -1 && s[i] == ' ')
			{
				beg = i;
				break;
			}
		}
		if (beg == 0 && s[beg] != ' ')
			beg--;
		return pos - beg;
	}
};