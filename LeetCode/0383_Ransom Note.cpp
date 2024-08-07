#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> mag(26, 0);
		for (char c : magazine)
			mag[c - 'a']++;
		for (char c : ransomNote)
		{
			mag[c - 'a']--;
			if (mag[c - 'a'] < 0) return false;
		}
		return true;
	}
};