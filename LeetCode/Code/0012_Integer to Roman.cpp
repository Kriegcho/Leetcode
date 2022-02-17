#include <string>
using namespace std;

class Solution {
public:
	const string s1[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	const string s2[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	const string s3[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	const string s4[4] = { "", "M", "MM", "MMM" };
	string intToRoman(int num) {
		string sn = to_string(num), ans;
		int len = sn.length();
		for (int i = 0; i < len; i++)
		{
			switch (len - i)
			{
			case 1:
				ans += s1[sn[i] - '0'];
				break;
			case 2:
				ans += s2[sn[i] - '0'];
				break;
			case 3:
				ans += s3[sn[i] - '0'];
				break;
			case 4:
				ans += s4[sn[i] - '0'];
				break;
			}
		}
		return ans;
	}
};