#include <vector>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode*> ans;
		while (1)
		{
			bool f = true;
			ListNode* lmin = 0;
			int ind = 0;
			for (int i = 0; i < lists.size(); i++)
				if (lists[i] && ((lmin && lists[i]->val < lmin->val) || lmin == 0))
				{
					f = false;
					lmin = lists[i];
					ind = i;
				}
			if (f) break;
			ans.push_back(lmin);
			lists[ind] = lists[ind]->next;
		}
		if (ans.empty()) return 0;
		for (int i = 0; i + 1 < ans.size(); i++) ans[i]->next = ans[i + 1];
		return ans[0];
	}
};