#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string ans = s;
		if (numRows == 1) return ans;
		int nz = numRows * 2 - 2, len = s.length(), zc = len / nz, ai = 0;
		for (int i = 0; i < numRows; i++)
			for (int j = 0; j <= zc; j++)
			{
				if (j * nz + i < len)
				{
					ans[ai] = s[j * nz + i];
					ai++;
				}
				if (i > 0 && i < numRows - 1 && j * nz + nz - i < len)
				{
					ans[ai] = s[j * nz + nz - i];
					ai++;
				}
			}
		return ans;
	}
};