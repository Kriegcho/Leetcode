#include <string>
using namespace std; 

class Solution {
	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
public:
	string gcdOfStrings(string str1, string str2) {
		int len1 = str1.length(), len2 = str2.length();
		int minlen = len1 < len2 ? len1 : len2;
		int maxlen = len1 < len2 ? len2 : len1;
		int step = gcd(maxlen, minlen);
		string& maxstr = len1 < len2 ? str2 : str1;
		for (int i = 0; i < maxlen; i++)
		{
			if (i < minlen && str1[i] != str2[i])
				return "";
			if (i >= step && maxstr[i] != maxstr[i - step])
				return "";
		}
		return str1.substr(0, step);
	}
};