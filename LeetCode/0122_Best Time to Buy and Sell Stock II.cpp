#include <vector>
using namespace std; 

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sum = 0;
		int n = prices.size();
		int buy = prices[0];
		for (int i = 1; i < n; i++)
		{
			if (prices[i] > buy)
				sum += prices[i] - buy;
			buy = prices[i];
		}
		return sum;
	}
};