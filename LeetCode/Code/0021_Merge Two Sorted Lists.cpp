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
	ListNode * mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode *ans = 0, *anse = 0;
		while (list1 || list2)
		{
			ListNode* temp = 0;
			if (list1 && list2)
			{
				if (list1->val < list2->val)
				{
					temp = list1;
					list1 = list1->next;
				}
				else
				{
					temp = list2;
					list2 = list2->next;
				}
			}
			else if (list1)
			{
				temp = list1;
				list1 = list1->next;
			}
			else if (list2)
			{
				temp = list2;
				list2 = list2->next;
			}
			if (ans)
			{
				anse->next = temp;
				anse = temp;
			}
			else ans = anse = temp;
		}
		return ans;
	}
};