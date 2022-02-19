#include <stack>
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
	ListNode * reverseKGroup(ListNode* head, int k) {
		ListNode *last = head, *ans = 0, *anse = 0, *kb = 0;
		int c = 1;
		while (head)
		{
			ListNode* temp = head->next;
			head->next = kb;
			kb = head;
			if (c == 1) last = head;
			if (c < k) c++;
			else
			{
				if (anse) anse->next = kb;
				else ans = kb;
				anse = last;
				kb = 0;
				c = 1;
			}
			head = temp;
		}
		if (c > 1)
		{
			last = 0;
			while (kb)
			{
				ListNode* temp = kb->next;
				kb->next = last;
				last = kb;
				kb = temp;
			}
			anse->next = last;
		}
		else anse->next = 0;
		return ans;
	}
};