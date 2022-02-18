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
	ListNode * swapPairs(ListNode* head) {
		ListNode *ans = head, *anse = 0;
		while (head)
		{
			if (head->next)
			{
				ListNode* temp = head->next->next;
				if (anse)
				{
					anse->next = head->next;
					anse->next->next = head;
				}
				else
				{
					ans = head->next;
					ans->next = head;
				}
				anse = head;
				anse->next = 0;
				head = temp;
			}
			else
			{
				if (anse) anse->next = head;
				head = head->next;
			}
		}
		return ans;
	}
};