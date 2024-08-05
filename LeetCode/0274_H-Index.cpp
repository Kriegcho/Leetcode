#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		vector<int> cnt(citations.size() + 1, 0);
		for (int n : citations)
			cnt[min(n,(int)citations.size())]++;
		int sum = 0;
		for (int i = citations.size(); i >= 0; i--)
		{
			sum += cnt[i];
			if (sum >= i)
				return i;
		}
		return 0;
	}
};