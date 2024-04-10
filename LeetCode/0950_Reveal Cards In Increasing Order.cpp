#include <vector>
#include <list>
#include <algorithm>

using namespace std; 

class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		sort(deck.begin(), deck.end(), [](int a, int b)-> bool {
			return a > b;
		});
		list<int> ls;
		for (int i : deck)
		{
			if (ls.empty())
				ls.push_back(i);
			else
			{
				ls.push_front(ls.back());
				ls.pop_back();
				ls.push_front(i);
			}
		}
		vector<int> ans;
		for (int i : ls)
			ans.push_back(i);
		return ans;
	}
};