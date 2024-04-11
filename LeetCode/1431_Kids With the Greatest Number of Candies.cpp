#include <vector>
using namespace std;

class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max = 0;
		for (int i : candies)
			if (i > max)
				max = i;
		vector<bool> ans(candies.size());
		for (int i = 0; i < candies.size(); i++)
			ans[i] = candies[i] + extraCandies >= max;
		return ans;
	}
};