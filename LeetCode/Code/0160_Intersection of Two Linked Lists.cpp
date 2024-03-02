#include <cmath>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		int c1 = 0, c2 = 0;
		ListNode* node = headA;
		while (node != nullptr)
		{
			c1++;
			node = node->next;
		}
		node = headB;
		while (node != nullptr)
		{
			c2++;
			node = node->next;
		}
		bool flag = (c1 > c2);
		node = flag ? headA : headB;
		int c = std::abs(c1 - c2), c3 = 0;
		while (node != nullptr && c3 < c)
		{
			node = node->next;
			c3++;
		}
		ListNode* node1 = flag ? headB : headA;
		while (node != nullptr && node1 != nullptr)
		{
			if (node == node1)
				return node;
			node = node->next;
			node1 = node1->next;
		}
		return nullptr;
	}
};