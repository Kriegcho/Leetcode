#include <vector>
#include <map>

using namespace std;

class Solution {
	map<pair<int, int>, int> map;
public:
	int uniquePaths(int m, int n) {
		if (m <= 1 || n <= 1)
			return 1;
		else
		{
			if (map.find(make_pair(m, n)) != map.end())
				return map[make_pair(m, n)];
			else
			{
				int val = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
				map[make_pair(m, n)] = val;
				return val;
			}
		}
	}
};