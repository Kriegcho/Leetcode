#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumPushes(string word) {
		vector<int> vec(26, 0);
		for (char c : word)
			vec[c - 'a']++;
		sort(vec.begin(), vec.end(), [](int a, int b)->bool {return a > b; });
		int sum = 0;
		for (int i = 0; i < 26; i++)
		{
			sum += vec[i] * (i / 8 + 1);
		}
		return sum;
	}
};