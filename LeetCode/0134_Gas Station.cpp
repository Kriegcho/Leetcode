#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		vector<int> left(gas.size());
		int sum = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			left[i] = gas[i] - cost[i];
			sum += left[i];
		}
		if (sum < 0) return -1;
		sum = 0;
		int ans = -1;
		for (int i = 0; i < left.size(); i++)
		{
			sum += left[i];
			if (sum < 0)
			{
				ans = -1;
				sum = 0;
			}
			else if (ans == -1)
				ans = i;
		}
		return ans;
	}
};