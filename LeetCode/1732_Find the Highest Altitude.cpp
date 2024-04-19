#include <vector>
using namespace std;

class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int sum = 0, ans = 0;
		for (int i : gain)
		{
			sum += i;
			if (ans < sum)
				ans = sum;
		}
		return ans;
	}
};