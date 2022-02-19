#include <vector>
#include <set>
using namespace std;

class Solution {public:	int removeDuplicates(vector<int>& nums) {		set<int> s;		for (int i = 0; i < nums.size(); i++) if (s.find(nums[i]) == s.end()) s.insert(nums[i]);		set<int>::iterator it = s.begin();		int ind = 0;		while (it != s.end())		{			nums[ind] = *it;			it++;			ind++;		}		return s.size();	}};