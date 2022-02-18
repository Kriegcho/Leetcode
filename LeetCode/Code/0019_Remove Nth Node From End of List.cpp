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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode *rl = 0, *th = head, *ans = 0;
		while (th)
		{
			ListNode* t = th->next;
			th->next = rl;
			rl = th;
			th = t;
		}
		int c = 1;
		ListNode *last = 0, *rlt = rl;
		while (rlt)
		{
			if (c == n)
			{
				if (last) last->next = rlt->next;
				else rl = rlt->next;
				break;
			}
			last = rlt;
			rlt = rlt->next;
			c++;
		}
		while (rl)
		{
			ListNode* t = rl->next;
			rl->next = ans;
			ans = rl;
			rl = t;
		}
		return ans;
	}
};