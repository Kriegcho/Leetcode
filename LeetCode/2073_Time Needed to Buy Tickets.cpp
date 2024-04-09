#include <vector>

using namespace std;

class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		int n = tickets.size(), sum = n;
		vector<int> count(101, 0);
		for (int i : tickets)
			count[i]++;
		int ans = 0, last = 0;
		for (int i = 0; i < tickets[k]; i++)
		{
			if (count[i] > 0)
			{
				ans += sum * (i - last);
				sum -= count[i];
				last = i;
			}
		}
		int cnt = 0;
		for (int i = 0; i <= k; i++)
			if (tickets[i] >= tickets[k])
				cnt++;
		ans += sum * (tickets[k] - last - 1) + cnt;
		return ans;
	}
};