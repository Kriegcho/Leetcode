#include <vector>
using namespace std;

class Solution {
	int solve(char c)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return 1;
		else
			return 0;
	}
public:
	int maxVowels(string s, int k) {
		int sum = 0;
		vector<int> vec;
		for (char c : s)
			vec.push_back(solve(c));
		for (int i = 0; i < k; i++)
			sum += vec[i];
		if (sum == k)
			return k;
		int ans = sum;
		for (int i = k; i < vec.size(); i++)
		{
			sum += vec[i];
			sum -= vec[i - k];
			if (sum == k)
				return k;
			if (sum > ans)
				ans = sum;
		}
		return ans;
	}
};