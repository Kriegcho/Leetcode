struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *p1 = head, *p2 = head;
		while (p1 != nullptr && p2 != nullptr)
		{
			p1 = p1->next;
			if (p2->next)
				p2 = p2->next->next;
			else
				return nullptr;
			if (p1 == p2)
			{
				ListNode* p3 = head;
				while (p3 != p1)
				{
					p3 = p3->next;
					p1 = p1->next;
				}
				return p3;
			}
		}
		return nullptr;
	}
};