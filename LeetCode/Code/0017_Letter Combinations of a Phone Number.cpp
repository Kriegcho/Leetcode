#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		string m[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> t(4);
		for (int i = 0; i < digits.length(); i++) t[i] = m[digits[i] - '0'];
		vector<string> ans;
		string temp;
		for (int i = 0; i < t[0].length(); i++)
		{
			if (t[1].empty())
			{
				temp.clear();
				temp += t[0][i];
				ans.push_back(temp);
			}
			else for (int j = 0; j < t[1].length(); j++)
			{
				if (t[2].empty())
				{
					temp.clear();
					temp += t[0][i];
					temp += t[1][j];
					ans.push_back(temp);
				}
				else for (int k = 0; k < t[2].length(); k++)
				{

					if (t[3].empty())
					{
						temp.clear();
						temp += t[0][i];
						temp += t[1][j];
						temp += t[2][k];
						ans.push_back(temp);
					}
					else for (int l = 0; l < t[3].length(); l++)
					{
						temp.clear();
						temp += t[0][i];
						temp += t[1][j];
						temp += t[2][k];
						temp += t[3][l];
						ans.push_back(temp);
					}
				}
			}
		}
		return ans;
	}
};