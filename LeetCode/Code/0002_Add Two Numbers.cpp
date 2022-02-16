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
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ansl = 0, *anse;
		int c = 0;
		while (l1 || l2)
		{
			int t = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
			if (t > 9)
			{
				c = 1;
				t -= 10;
			}
			else c = 0;
			ListNode* p = new ListNode(t);
			if (!ansl)
			{
				ansl = p;
				anse = p;
			}
			else
			{
				anse->next = p;
				anse = p;
			}
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (c == 1) anse->next = new ListNode(1);
		return ansl;
	}
};