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
		int c = 0, k = 0;
		ListNode* node = head;
		while (node != nullptr)
		{
			node = node->next;
			c++;
		}
		if (n == c)
			return head->next;
		node = head;
		while (node != nullptr)
		{
			k++;
			if (k == c - n)
			{
				ListNode* rem = node->next;
				if (rem)
					node->next = rem->next;
				break;
			}
			node = node->next;
		}
		return head;
	}
};