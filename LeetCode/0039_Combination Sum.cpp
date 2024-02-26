#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		set<int> cs;
		for (int i = 0; i < candidates.size(); i++) cs.insert(candidates[i]);
		set<int>::iterator it = cs.begin(), itr = cs.begin();
		while (it != cs.end())
		{
			it++;
		}
	}
};