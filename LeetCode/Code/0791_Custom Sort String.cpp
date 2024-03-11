#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string customSortString(string order, string s) {
		unordered_map<char, int> um;
		for (auto c : s)
			um[c]++;
		string ans;
		for (auto c : order)
			while (um[c] > 0)
			{
				ans += c;
				um[c]--;
			}
		for (auto p : um)
			while (p.second > 0)
			{
				ans += p.first;
				p.second--;
			}
		return ans;
	}
};