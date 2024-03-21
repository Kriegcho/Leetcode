struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		int c = 0;
		ListNode* node = list2;
		ListNode* tail2 = nullptr;
		while (node != nullptr)
		{
			tail2 = node;
			node = node->next;
		}
		node = list1;
		while (node != nullptr)
		{
			ListNode* next = node->next;
			if (c == a - 1)
			{
				node->next = list2;
				node = next;
			}
			else if (c == b)
			{
				tail2->next = node->next;
				break;
			}
			c++;
			node = next;
		}
		return list1;
	}
};